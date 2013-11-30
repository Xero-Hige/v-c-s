/*
 * combiner.h
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

#ifndef COMBINER_H_
#define COMBINER_H_

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

// Constantes de puntaje
// Representa el puntaje por producto combinado, tomando el mayor involucrado
#define THREE_COMB_SCORE 10
#define FOUR_COMB_SCORE 20
#define FIVE_COMB_SCORE 30
#define STAR_COMB_SCORE 40

class Combiner {
private:
    Board& board;
    CombinationChecker checker;
    int last_combination_points;
    int multiplier;

public:
    Combiner(Board& board)
        : board(board), last_combination_points(0), multiplier(1) {
        checker = CombinationChecker(&(this->board));
    }
    //TODO devuelve los puntos y tiene un efecto adentro? devuelve el efecto? HACE EXPLOTAR EL MUNDO?
    std::list<CombinationEffect*> makeCombinations(Position pos1, Position pos2, bool chained = false);
    int getLastCombinationsPoints();

private:
    int makeStarCombination(Position star_pos, Position product_pos, std::list<CombinationEffect*>& result_list);
    int makeCombination(Position pos, std::list<CombinationEffect*>& result_list);
    int activateCombination(Position initial_pos, Position ending_pos, Position origin, std::list<CombinationEffect*>& result_list);
    int activateProduct(Position product_pos, std::list<CombinationEffect*>& result_list);
    int getPointsPerProduct(int longest_combination_size);
    void upgradeProduct(Position origin, int color, int vertical_combination_size, int horizontal_combination_size, std::list<CombinationEffect*>& result_list);
//    getCombinationTypes();
};

#endif /* COMBINER_H_ */
