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

list<CombinationEffect*> Combiner::makeCombinations(Position pos1, Position pos2, bool chained) {
    if (! chained) {
        last_combination_points = 0;
        multiplier = 1;
    } else {
        multiplier++;
    }
    list<CombinationEffect*> result_list;
    // Si alguno de los productos es una estrella, se maneja aparte
    if (board.getProductType(pos1) == Product::STAR) {
        makeStarCombination(pos1, pos2, result_list);
    } else if (board.getProductType(pos2) == Product::STAR) {
        makeStarCombination(pos2, pos1, result_list);
    }
    std::cout << "Haciendo primera combinación, posición (" << pos1.getX() << "," << pos1.getY() << ")" << std::endl;
    last_combination_points += makeCombination(pos1, result_list);
    std::cout << "Haciendo segunda combinación, posición (" << pos2.getX() << "," << pos2.getY() << ")" << std::endl;
    last_combination_points += makeCombination(pos2, result_list);
    return result_list;
}

int Combiner::getLastCombinationsPoints() {
    return last_combination_points;
}

int Combiner::makeStarCombination(Position star_pos, Position product_pos, list<CombinationEffect*>& result_list) {
    return 0;
}

int Combiner::makeCombination(Position pos, std::list<CombinationEffect*>& result_list) {
    int products_eliminated = 0;
    list<Position> vertical_combination;
    int vertical_count = 0;
    list<Position> horizontal_combination;
    int horizontal_count = 0;
    int origin_product_color = board.getProductColor(pos);
    if (checker.getVerticalCombination(pos, vertical_combination)) {
        std::cout << "Activando combinación vertical" << std::endl;
        vertical_count = vertical_combination.size();
        std::cout << "Tamaño de la combinación: " << vertical_count << std::endl;
        products_eliminated += activateCombination(vertical_combination.front(), vertical_combination.back(), pos, result_list);
    }
    if (checker.getHorizontalCombination(pos, horizontal_combination)) {
        std::cout << "Activando combinación horizontal" << std::endl;
        horizontal_count = horizontal_combination.size();
        std::cout << "Tamaño de la combinación: " << horizontal_count << std::endl;
        products_eliminated += activateCombination(horizontal_combination.front(), horizontal_combination.back(), pos, result_list);
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
    int longest_combination_size = max(vertical_combination_size, horizontal_combination_size);
    if (longest_combination_size == 4) {
        if (vertical_combination_size > horizontal_combination_size) {
            result_list.push_front(new ChangeProductEffect(origin, color, Product::V_BAR));
        } else {
            result_list.push_front(new ChangeProductEffect(origin, color, Product::H_BAR));
        }
    } else {
        result_list.push_front(new ChangeProductEffect(origin, color, Product::STAR));
    }
}
