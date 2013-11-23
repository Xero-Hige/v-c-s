/*
 * combination_checker.cpp
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

#include "combination_checker.h"

#include "../boards/product.h"
#include "../boards/board.h"
#include "../position/position.h"

#include <list>
#include <vector>

using std::list;
using std::vector;

#define UP Position(0,-1)
#define DOWN Position(0,1)
#define RIGHT Position(0,1)
#define LEFT Position(0,-1)

bool CombinationChecker::check(Position& pos) {
    if (! isValidPosition(pos)) {
        return false;
    }
    int product_color = board.getProductColor(pos);
    int combination_count;
    combination_count = checkCombination(UP, pos, product_color, NULL);
    combination_count += checkCombination(DOWN, pos, product_color, NULL);
    if (combination_count >= 2) {
        return true;
    }
    combination_count = checkCombination(RIGHT, pos, product_color, NULL);
    combination_count += checkCombination(LEFT, pos, product_color, NULL);
    if (combination_count >= 2) {
        return true;
    }
    return false;
}

bool CombinationChecker::getVerticalCombination(Position& pos, list<Position>& combination_list) {
    int product_color = board.getProductColor(pos);
    int n_combination = checkCombination(UP, pos, product_color, &combination_list);
    n_combination = checkCombination(DOWN, pos, product_color, &combination_list);
    if (n_combination >= 2) {
        return true;
    }
    return false;
}

bool CombinationChecker::getHorizontalCombination(Position& pos, list<Position>& combination_list) {
    int product_color = board.getProductColor(pos);
    int n_combination = checkCombination(RIGHT, pos, product_color, &combination_list);
    n_combination = checkCombination(LEFT, pos, product_color, &combination_list);
    if (n_combination >= 2) {
        return true;
    }
    return false;
}

//TODO
bool CombinationChecker::checkPosible() {
    return true;
}

bool CombinationChecker::isValidPosition(Position& pos) {
    unsigned int x = pos.getX();
    unsigned int y = pos.getY();
    if ((int)x || x >= board.getLength()) {
        return false;
    } else if ((int)y < 0 || y >= board.getHeight()) {
        return false;
    }
    return true;
}

Position CombinationChecker::getNeighbour(Position direction, Position& pos) {
    Position neighbour_pos = pos+direction;
    if (! isValidPosition(neighbour_pos)) {
        return Position(-1, -1);
    }
    return neighbour_pos;
}

int CombinationChecker::checkCombination(Position direction, Position& pos, int color, list<Position>* combination_list) {
    Position neighbour_pos = getNeighbour(direction, pos);
    if (! isValidPosition(neighbour_pos)) {
        return 0;
    }
    if (board.getProductColor(neighbour_pos) != color) {
        return 0;
    }
    if (combination_list != NULL) {
        combination_list->push_back(neighbour_pos);
    }
    return 1 + checkCombination(direction, neighbour_pos, color, combination_list);
}
