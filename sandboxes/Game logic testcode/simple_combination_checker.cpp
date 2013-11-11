/*
 * simple_combination_checker.cpp
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

#include "simple_combination_checker.h"

#include "simple_board.h"
#include "simple_product.h"
#include "position.h"

#include <list>

using std::list;

bool CombinationChecker::check(Position& pos) {
    if (! isValidPosition(pos)) {
        return false;
    }
    int product_color = board.getProductColor(pos);
    int combination_count;
    combination_count = checkCombinationUp(pos, product_color, NULL);
    combination_count += checkCombinationDown(pos, product_color, NULL);
    if (combination_count >= 2) {
        return true;
    }
    combination_count = checkCombinationRight(pos, product_color, NULL);
    combination_count += checkCombinationLeft(pos, product_color, NULL);
    if (combination_count >= 2) {
        return true;
    }
    return false;
}

list<Position> CombinationChecker::getVerticalCombination(Position& pos) {
    int product_color = board.getProductColor(pos);
    list<Position> vertical_combination = list<Position>();
    vertical_combination.push_back(pos);
    checkCombinationUp(pos, product_color, &vertical_combination);
    checkCombinationDown(pos, product_color, &vertical_combination);
    return vertical_combination;
}

std::list<Position> CombinationChecker::getHorizontalCombination(Position& pos) {
    int product_color = board.getProductColor(pos);
    list<Position> horizontal_combination = list<Position>();
    horizontal_combination.push_back(pos);
    checkCombinationRight(pos, product_color, &horizontal_combination);
    checkCombinationLeft(pos, product_color, &horizontal_combination);
    return horizontal_combination;
}

int CombinationChecker::checkAll() {
    return 0;
}

bool CombinationChecker::isValidPosition(Position& pos) {
    unsigned int x = pos.getX();
    unsigned int y = pos.getY();
    if (x < 0 || x >= board.getLength()) {
        return false;
    } else if (y < 0 || y >= board.getHeight()) {
        return false;
    }
    return true;
}

list<Position> CombinationChecker::getNeighbours(Position& pos) {
    list<Position> neighbours = list<Position>();
    neighbours.push_back(getNeighbourUp(pos));
    neighbours.push_back(getNeighbourDown(pos));
    neighbours.push_back(getNeighbourRight(pos));
    neighbours.push_back(getNeighbourLeft(pos));
    return neighbours;
}

// TODO Esto es muy choto, después hay que refactorizar para hacer que sea un solo método
Position CombinationChecker::getNeighbourUp(Position& pos) {
    unsigned int y = pos.getY() - 1;
    if (y < 0) {
        return Position(-1, -1);
    }
    return Position(pos.getX(), y);
}

Position CombinationChecker::getNeighbourDown(Position& pos) {
    unsigned int y = pos.getY() + 1;
    if (y >= board.getHeight()) {
        return Position(-1, -1);
    }
    return Position(pos.getX(), y);
}

Position CombinationChecker::getNeighbourRight(Position& pos) {
    unsigned int x = pos.getX() + 1;
    if (x >= board.getLength()) {
        return Position(-1, -1);
    }
    return Position(x, pos.getY());
}

Position CombinationChecker::getNeighbourLeft(Position& pos) {
    unsigned int x = pos.getX() - 1;
    if (x <= 0) {
        return Position(-1, -1);
    }
    return Position(x, pos.getY());
}

// TODO Esto es muy choto, después hay que refactorizar para hacer que sea un solo método
int CombinationChecker::checkCombinationUp(Position& pos, int color, list<Position>* combination_list) {
    Position neighbour_pos = getNeighbourUp(pos);
    if (! isValidPosition(neighbour_pos)) {
        return 0;
    }
    if (board.getProductColor(neighbour_pos) != color) {
        return 0;
    }
    if (combination_list != NULL) {
        combination_list->push_back(neighbour_pos);
    }
    return 1 + checkCombinationUp(neighbour_pos, color, combination_list);
}

int CombinationChecker::checkCombinationDown(Position& pos, int color, list<Position>* combination_list) {
    Position neighbour_pos = getNeighbourDown(pos);
    if (! isValidPosition(neighbour_pos)) {
        return 0;
    }
    if (board.getProductColor(neighbour_pos) != color) {
        return 0;
    }
    if (combination_list != NULL) {
        combination_list->push_back(neighbour_pos);
    }
    return 1 + checkCombinationDown(neighbour_pos, color, combination_list);
}

int CombinationChecker::checkCombinationRight(Position& pos, int color, list<Position>* combination_list) {
    Position neighbour_pos = getNeighbourRight(pos);
    if (! isValidPosition(neighbour_pos)) {
        return 0;
    }
    if (board.getProductColor(neighbour_pos) != color) {
        return 0;
    }
    if (combination_list != NULL) {
        combination_list->push_back(neighbour_pos);
    }
    return 1 + checkCombinationRight(neighbour_pos, color, combination_list);
}

int CombinationChecker::checkCombinationLeft(Position& pos, int color, list<Position>* combination_list) {
    Position neighbour_pos = getNeighbourLeft(pos);
    if (! isValidPosition(neighbour_pos)) {
        return 0;
    }
    if (board.getProductColor(neighbour_pos) != color) {
        return 0;
    }
    if (combination_list != NULL) {
        combination_list->push_back(neighbour_pos);
    }
    return 1 + checkCombinationLeft(neighbour_pos, color, combination_list);
}
