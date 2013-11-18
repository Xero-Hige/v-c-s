/*
 * replacements_board.cpp
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

#include "replacements_board.h"

#include "product.h"
#include "refiller.h"

#include <vector>
#include <list>
#include <algorithm>  // Para min()

using std::vector;
using std::list;
using std::min;

ReplacementsBoard::ReplacementsBoard(unsigned int n_rows, unsigned int n_columns, vector<Refiller*>& refillers)
    : Board(n_rows, n_columns){
    this->refillers = refillers;
}

//TODO arreglar para agujeros
list<Product*> ReplacementsBoard::getReplacements(int n, int column_number) {
    int x = column_number;
    int y = getHeight();
    list<Product*> ret_list = list<Product*>();
    for (int c = min(n, (int)getHeight()); c > 0; c--) {
        ret_list.push_back(takeOutProduct(x, y));
        y--;
    }
    rearrangeColumn(column_number);
    refill(column_number, n);
    return ret_list;
}

ReplacementsBoard::~ReplacementsBoard() {
    refillers.clear();
}

//TODO arreglar para agujeros
void ReplacementsBoard::refill(int column_number, int n_extracted) {
    int x = column_number;
    int y = min(n_extracted, (int)getHeight()) - 1;
    Refiller* refiller = refillers[column_number];
    while (y >= 0) {
        Product* product = refiller->getNewProduct();
        setProduct(product, x, y);
        y--;
    }
}
