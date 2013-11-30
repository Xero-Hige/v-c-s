/*
 * refiller.cpp
 *
 * Created on: Nov 29, 2013
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

#include "refiller.h"

#include "board.h"
#include "product.h"

#include <list>
#include <vector>

using std::list;

Refiller::Refiller(Board* board, Board* replacement_board)
    : board(board), replacement_board(replacement_board) {
}

void Refiller::realocateBoard() {
    board->rearrangeBoard();
    for (int x = 0; x < board->getWidth(); x++) {
        int emptyCells = board->getEmptyCellsInColumn(x);
        list<Product*> products = replacement_board->popFromColumn(emptyCells, x);
        board->pushInColumn(products, x);
    }
    replacement_board->rearrangeBoard();
    refillReplacementsBoard();
}

void Refiller::addReplacements(int column, list<Product*> products) {
    if (column >= (int)replacements.size()) {
        replacements.resize(column+1, list<Product*>());
    }
    list<Product*>::iterator it;
    replacements[column].splice(replacements[column].end(), products, products.begin(), products.end());
}

void Refiller::refillReplacementsBoard() {
    for (int column = 0; column < replacement_board->getWidth(); column++) {
        int empty_cells = replacement_board->getEmptyCellsInColumn(column);
        if (empty_cells > 0) {
            refillColumn(column, empty_cells);
        }
    }
}

void Refiller::refillColumn(int column, int empty_cells) {
    if (column >= (int)replacements.size()) {
        return;
    }
    list<Product*> products;
    list<Product*>& replacements = this->replacements[column];
    list<Product*>::iterator it = replacements.begin();
    for (int c = 0; c < empty_cells; c++) {
        ++it;
    }
    products.splice(products.end(), replacements, replacements.begin(), it);
    replacement_board->pushInColumn(products, column);
}
