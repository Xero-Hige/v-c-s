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

#include "../product_constants.h"
#include "../position/position.h"
#include "../boards/board.h"
#include "../checkers/combination_checker.h"

class Combiner {
private:
    Board& board;
    CombinationChecker checker;

public:
    Combiner(Board& board)
        : board(board), checker(CombinationChecker(board)) {}
    int activateCombination(Position pos1, Position pos2);

private:
    int makeCombination(Position pos);
//    getCombinationTypes();
};

#endif /* COMBINER_H_ */
