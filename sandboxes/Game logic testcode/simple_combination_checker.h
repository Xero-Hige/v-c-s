/*
 * simple_combination_checker.h
 *
 * Created on: Nov 6, 2013
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

#ifndef SIMPLE_COMBINATION_CHECKER_H_
#define SIMPLE_COMBINATION_CHECKER_H_

#include "simple_product.h"
#include "simple_board.h"
#include "position.h"

#include <list>

class CombinationChecker {
private:
    Board& board;

public:
    CombinationChecker(Board& board)
        : board(board) {}
    bool check(Position& pos);
    std::list<Position> getVerticalCombination(Position& pos);
    std::list<Position> getHorizontalCombination(Position& pos);
    int checkAll();

private:
    bool isValidPosition(Position& pos);
    std::list<Position> getNeighbours(Position& pos);
    Position getNeighbourUp(Position& pos);
    Position getNeighbourDown(Position& pos);
    Position getNeighbourRight(Position& pos);
    Position getNeighbourLeft(Position& pos);
    int checkCombinationUp(Position& pos, int color, std::list<Position>* combination_list);
    int checkCombinationDown(Position& pos, int color, std::list<Position>* combination_list);
    int checkCombinationRight(Position& pos, int color, std::list<Position>* combination_list);
    int checkCombinationLeft(Position& pos, int color, std::list<Position>* combination_list);
};

#endif /* SIMPLE_COMBINATION_CHECKER_H_ */
