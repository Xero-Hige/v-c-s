/*
 * combiner.cpp
 *
 * Created on: Nov 19, 2013
 * 
 * Copyright 2013 Bruno Merlo Schurmann <brunomerloschurmann@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses 
 */

#include "combiner.h"

#include "../position/position.h"
#include "../boards/board.h"
#include "../boards/product.h"
#include "../checkers/combination_checker.h"
#include "../combination_effects/combination_effect.h"
#include "../combination_effects/change_product_effect.h"
#include "../combination_effects/clean_board_effect.h"
#include "../combination_effects/take_out_product_effect.h"
#include "../combination_effects/take_out_column_effect.h"
#include "../combination_effects/take_out_row_effect.h"

#include <list>

#include <iostream> //FIXME borrame

using std::list;
using std::max;

list<CombinationEffect*> Combiner::makeCombinations(Position pos1, Position pos2) {
    last_combination_points = 0;
    multiplier = 1;
    last_combination_positions.clear();
    list<CombinationEffect*> result_list;
    // Si alguno de los productos es una estrella, se maneja aparte
    if (board.getProductType(pos1) == Product::STAR) {
        last_combination_points += makeStarCombination(pos1, pos2, result_list);
    } else if (board.getProductType(pos2) == Product::STAR) {
        last_combination_points += makeStarCombination(pos2, pos1, result_list);
    }
    std::cout << "Haciendo primera combinación, posición (" << pos1.getX() << "," << pos1.getY() << ")" << std::endl;
    last_combination_points += makeCombination(pos1, result_list);
    std::cout << "Haciendo segunda combinación, posición (" << pos2.getX() << "," << pos2.getY() << ")" << std::endl;
    last_combination_points += makeCombination(pos2, result_list);
    return result_list;
}

list<CombinationEffect*> Combiner::makeChainedCombinations() {
    multiplier++;
    list<CombinationEffect*> result_list;
    while (last_combination_positions.size() > 0) {
        Position pos = last_combination_positions.front();
        if (board.getProductType(pos) != Product::STAR) {
            makeCombination(pos, result_list);
        }
        last_combination_positions.pop_front();
    }
    return result_list;
}

int Combiner::getLastCombinationsPoints() {
    return last_combination_points;
}

int Combiner::makeStarCombination(Position star_pos, Position product_pos, list<CombinationEffect*>& result_list) {
    int product_type = board.getProductType(product_pos);
    int eliminated_products = 0;
    list<CombinationEffect*> dummy_list;
    int color_to_eliminate;
    switch (product_type) {
    case Product::STAR:
        result_list.push_back(new CleanBoardEffect(star_pos));
        for (int x = 0; x < board.getWidth(); x++) {
            for (int y = 0; y < board.getHeight(); y++) {
                activateProduct(Position(x, y), dummy_list);
            }
        }
        eliminated_products = board.getHeight() * board.getWidth();
        break;
    case Product::BUTTON:
        color_to_eliminate = board.getProductColor(product_pos);
        eliminated_products += eliminateAllProductsColor(color_to_eliminate, result_list);
        break;
    default:  // Alguna mini-bar, es lo mismo para las dos
        color_to_eliminate = board.getProductColor(product_pos);
        eliminated_products += eliminateAllProductsColor(color_to_eliminate, result_list);
        result_list.push_back(new TakeOutRowEffect(product_pos, board.getWidth()));
        result_list.push_back(new TakeOutColumnEffect(product_pos, board.getHeight()));
        for (int x = 0; x < board.getWidth(); x++) {
            eliminated_products += activateProduct(Position(x, product_pos.getY()), result_list);
        }
        for (int y = 0; y < board.getHeight(); y++) {
            eliminated_products += activateProduct(Position(product_pos.getX(), y), result_list);
        }
        break;
    }
    return eliminated_products * STAR_COMB_SCORE * multiplier;
}

int Combiner::makeCombination(Position pos, std::list<CombinationEffect*>& result_list) {
    int products_eliminated = 0;
    list<Position> vertical_combination;
    int vertical_count = 0;
    list<Position> horizontal_combination;
    int horizontal_count = 0;
    int origin_product_color = board.getProductColor(pos);
    int origin_product_type = board.getProductType(pos);
    if (checker.getVerticalCombination(pos, vertical_combination)) {
        std::cout << "Activando combinación vertical" << std::endl;
        vertical_count = vertical_combination.size();
        std::cout << "Tamaño de la combinación: " << vertical_count << std::endl;
        products_eliminated += activateCombination(vertical_combination.front(), vertical_combination.back(), pos, result_list);
    }
    // Si hubo combinación vertical y se eliminó el producto origen, se vuelve
    // a insertar para probar la combinación horizontal
    if (vertical_count != 0) {
        Product* origin_product = new Product(origin_product_color, origin_product_type);
        board.setProduct(origin_product, pos);
    }
    if (checker.getHorizontalCombination(pos, horizontal_combination)) {
        std::cout << "Activando combinación horizontal" << std::endl;
        horizontal_count = horizontal_combination.size();
        std::cout << "Tamaño de la combinación: " << horizontal_count << std::endl;
        products_eliminated += activateCombination(horizontal_combination.front(), horizontal_combination.back(), pos, result_list);
    }
    // Si hubo alguna combinación, hay que asegurar que se sacó el producto
    // origen (en el caso de combinación vertical pero no horizontal)
    if (products_eliminated != 0) {
        board.takeOutProduct(pos);
    }
    int longest_combination_size = max(vertical_count, horizontal_count);
    int points_per_product = getPointsPerProduct(longest_combination_size);
    if (longest_combination_size > 3) {
        upgradeProduct(pos, origin_product_color, vertical_count, horizontal_count, result_list);
    }
    std::cout << "Productos eliminados: " << products_eliminated << " - Puntos por producto: " << points_per_product << " - Multiplicador: " << multiplier << std::endl;
    return products_eliminated * points_per_product * multiplier;
}

int Combiner::activateCombination(Position initial_pos, Position ending_pos, Position origin, list<CombinationEffect*>& result_list) {
    int products_eliminated = 0;
    result_list.push_back(new TakeOutProductEffect(origin, initial_pos, ending_pos));
    for (int x = initial_pos.getX(); x <= ending_pos.getX(); x++) {
        for (int y = initial_pos.getY(); y <= ending_pos.getY(); y++) {
            Position current_pos = Position(x,y);
            products_eliminated += activateProduct(current_pos, result_list);
        }
    }
    return products_eliminated;
}

int Combiner::activateProduct(Position product_pos, list<CombinationEffect*>& result_list) {
    std::cout << "Activando posición (" << product_pos.getX() << "," << product_pos.getY() << ")" << std::endl;
    int products_eliminated = 0;
    int product_type = board.getProductType(product_pos);
    std::cout << "Tipo de producto al activar: " << product_type << std::endl;
    delete board.takeOutProduct(product_pos);
    products_eliminated++;
    last_combination_positions.push_back(product_pos);
    if (product_type == Product::V_BAR) {
        result_list.push_back(new TakeOutColumnEffect(product_pos, board.getHeight()));
        for (int y = 0; y < board.getHeight(); y++) {
            int current_product_type = board.getProductType(product_pos.getX(), y);
            if (current_product_type == Product::V_BAR || current_product_type == Product::H_BAR) {
                products_eliminated += activateProduct(Position(product_pos.getX(), y), result_list);
            }
        }
        list<Product*> eliminated_products = board.takeOutColumn(product_pos.getX());
        products_eliminated+= eliminated_products.size();
        eliminated_products.clear();
    } else if (product_type == Product::H_BAR) {
        result_list.push_back(new TakeOutRowEffect(product_pos, board.getWidth()));
        for (int x = 0; x < board.getWidth(); x++) {
            int current_product_type = board.getProductType(x, product_pos.getY());
            if (current_product_type == Product::V_BAR || current_product_type == Product::H_BAR) {
                products_eliminated += activateProduct(Position(x, product_pos.getY()), result_list);
            }
        }
        list<Product*> eliminated_products = board.takeOutRow(product_pos.getY());
        products_eliminated+= eliminated_products.size();
        eliminated_products.clear();
    }
    return products_eliminated;
}

int Combiner::getPointsPerProduct(int longest_combination_size) {
    if (longest_combination_size == 3) {
        return THREE_COMB_SCORE;
    } else if (longest_combination_size == 4) {
        return FOUR_COMB_SCORE;
    } else if (longest_combination_size >= 5) {
        return FIVE_COMB_SCORE;
    } else {
        return 0;
    }
}

void Combiner::upgradeProduct(Position origin, int color, int vertical_combination_size, int horizontal_combination_size, list<CombinationEffect*>& result_list) {
    Product* product;
    int product_new_type;
    int longest_combination_size = max(vertical_combination_size, horizontal_combination_size);
    if (longest_combination_size == 4) {
        if (vertical_combination_size > horizontal_combination_size) {
            product_new_type = Product::V_BAR;
        } else {
            product_new_type = Product::H_BAR;
        }
    } else {
        color = Product::NO_COLOR;
        product_new_type = Product::STAR;
    }
    //FIXME descomentar cuando no se rompa al hacerlo, hay que chequear la interfaz gráfica
//    product = new Product(color, product_new_type);
//    board.setProduct(product, origin);
    result_list.push_back(new ChangeProductEffect(origin, color, product_new_type));
}

int Combiner::eliminateAllProductsColor(int color_to_eliminate, std::list<CombinationEffect*>& result_list) {
    int eliminated_products = 0;
    for (int x = 0; x < board.getWidth(); x++) {
        for (int y = 0; y < board.getHeight(); y++) {
            Position current_pos = Position(x, y);
            if (board.getProductColor(current_pos) == color_to_eliminate) {
                if (board.getProductType(current_pos) == Product::BUTTON) {
                    result_list.push_back(new TakeOutProductEffect(current_pos));
                }
                eliminated_products += activateProduct(current_pos, result_list);
            }
        }
    }
    return eliminated_products;
}
