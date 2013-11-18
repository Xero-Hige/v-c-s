/*
 * physical_checker.cpp
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

#include "physical_checker.h"

#include "../position/position.h"

bool PhysicalChecker::isValidPosition(Position& pos) {
    int x = pos.getX();
    int y = pos.getY();
    if (x < 0 || x >= (int)board_width) {
        return false;
    }
    if (y < 0 || y >= (int)board_height) {
        return false;
    }
    return true;
}

bool PhysicalChecker::checkSwap(Position& pos1, Position& pos2) {
    if ((! isValidPosition(pos1)) || (! isValidPosition(pos2))) {
        return false;
    }
    int x_difference = pos1.getX() - pos2.getX();
    int y_difference = pos1.getY() - pos2.getY();
    if (x_difference == 0) {
        if (y_difference == 1 || y_difference == -1) {
            return true;
        }
    } else if (y_difference == 0) {
        if (x_difference == 1 || x_difference == -1) {
            return true;
        }
    }
    return false;
}
