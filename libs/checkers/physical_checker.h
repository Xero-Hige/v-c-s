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

class PhysicalChecker {
private:
    unsigned int board_width;
    unsigned int board_height;

public:
    PhysicalChecker(unsigned int board_width, unsigned int board_height)
        : board_width(board_width), board_height(board_height) {}
    bool isValidPosition(Position& pos);
    bool checkSwap(Position& pos1, Position& pos2);
};

#endif /* PHYSICAL_CHECKER_H_ */
