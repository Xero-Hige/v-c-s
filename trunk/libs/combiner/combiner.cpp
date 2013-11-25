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
#include "../combination_effects/take_out_column_effect.h"
#include "../combination_effects/take_out_row_effect.h"

#include <list>

using std::list;

list<CombinationEffect> Combiner::makeCombinations(Position pos1, Position pos2, bool chained) {
    if (! chained) {
        last_combination_points = 0;
        multiplier = 1;
    } else {
        multiplier++;
    }
    list<CombinationEffect> result_list;
    // Si alguno de los productos es una estrella, se maneja aparte
    if (board.getProductType(pos1) == Product::STAR) {
        makeStarCombination(pos1, pos2);
    } else if (board.getProductType(pos2) == Product::STAR) {
        makeStarCombination(pos2, pos1);
    }
    makeCombination(pos1, result_list);
    makeCombination(pos2, result_list);
    return result_list;
}

int Combiner::makeStarCombination(Position star_pos, Position product_pos, list<CombinationEffect>& result_list) {
    return 0;
}

int Combiner::makeCombination(Position pos, std::list<CombinationEffect>& result_list) {
    int products_eliminated = 0;
    list<Position> vertical_combination;
    int vertical_count = 0;
    list<Position> horizontal_combination;
    int horizontal_count = 0;
    if (checker.getVerticalCombination(pos, vertical_combination)) {
        vertical_count = vertical_combination.size();
        products_eliminated += activateCombination(vertical_combination.front(), vertical_combination.back(), result_list);
    }
    if (checker.getHorizontalCombination(pos, horizontal_combination)) {
        horizontal_count = horizontal_combination.size();
        products_eliminated += activateCombination(horizontal_combination.front(), horizontal_combination.back(), result_list);
    }
    int points_per_product = getPointsPerProduct(std::max(vertical_count, horizontal_count));
    return products_eliminated * points_per_product * multiplier;
}

int Combiner::activateCombination(Position initial_pos, Position ending_pos, list<CombinationEffect>& result_list) {
    return 0;
}

int activateProduct(Position product_pos, list<CombinationEffect>& result_list) {
    return 0;
}

int Combiner::getPointsPerProduct(int longest_combination_size) {
    switch(longest_combination_size) {
    case 3:
        return THREE_COMB_SCORE;
    case 4:
        return FOUR_COMB_SCORE;
    case 5:
        return FIVE_COMB_SCORE;
    default:
        return 0;
    }
}
