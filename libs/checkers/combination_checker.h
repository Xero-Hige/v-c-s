/*
 * combination_checker.h
 *
 * Created on: Nov 18, 2013
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

#ifndef COMBINATION_CHECKER_H_
#define COMBINATION_CHECKER_H_

#include "../boards/product.h"
#include "../boards/board.h"
#include "../position/position.h"

#include <list>
#include <vector>

class CombinationChecker {
private:
    Board* board;

public:
    /* Solo se usa como dummy, no queda de forma válida ni usable */
    CombinationChecker()
        : board(NULL) {}
    explicit CombinationChecker(Board* board)
        : board(board) {}
    bool check(Position& pos);
    bool getVerticalCombination(Position& pos, std::list<Position>& combination_list);
    bool getHorizontalCombination(Position& pos, std::list<Position>& combination_list);
    bool checkPosible();

private:
    bool isValidPosition(Position& pos);
    Position getNeighbour(Position direction, Position& pos);
    int checkCombination(Position direction, Position& pos, int color, std::list<Position>* combination_list);
};


#endif /* COMBINATION_CHECKER_H_ */
