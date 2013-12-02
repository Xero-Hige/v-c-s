/*
 * replacements_generator.h
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

#ifndef REPLACEMENTS_BOARD_H_
#define REPLACEMENTS_BOARD_H_

#include "board.h"
#include "product.h"
#include "product_generator.h"

#include <vector>
#include <list>

class ReplacementsGenerator {
private:
    Board* replacements_board;
    std::vector<ProductGenerator*> product_generators;

public:
    /* Dummy, el objeto queda en un estado inválido */
    ReplacementsGenerator()
        : replacements_board(NULL) {}
    ReplacementsGenerator(Board* replacements_board, std::vector<ProductGenerator*>& product_generators);
    std::list<Product*> getReplacements(int n, int column_number);
    ~ReplacementsGenerator();
};

#endif /* REPLACEMENTS_BOARD_H_ */
