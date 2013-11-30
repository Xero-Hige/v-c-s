/*
 * refiller.h
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

#ifndef REFILLER_H_
#define REFILLER_H_

#include "board.h"
#include "product.h"

#include <list>
#include <vector>

class Refiller {
private:
    Board* board;
    Board* replacement_board;
    std::vector<std::list<Product*> > replacements;

public:
    Refiller() {}
    Refiller(Board* board, Board* replacement_board);
    void realocateBoard();
    void addReplacements(int column, std::list<Product*> products);

private:
    void refillReplacementsBoard();
    void refillColumn(int column, int empty_cells);
};

#endif /* REFILLER_H_ */
