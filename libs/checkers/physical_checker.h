/*
 * physical_checker.h
 *
 * Created on: Nov 17, 2013
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

#ifndef PHYSICAL_CHECKER_H_
#define PHYSICAL_CHECKER_H_

#include "../position/position.h"
#include "../boards/board.h"

class PhysicalChecker {
private:
    unsigned int board_width;
    unsigned int board_height;

public:
    /* Solo se usa como dummy, no queda de forma válida ni usable */
    PhysicalChecker()
        : board_width(-1), board_height(-1) {}
    explicit PhysicalChecker(Board& board)
        : board_width(board.getWidth()), board_height(board.getHeight()) {}
    bool isValidPosition(Position& pos);
    bool checkSwap(Position& pos1, Position& pos2);
};

#endif /* PHYSICAL_CHECKER_H_ */
