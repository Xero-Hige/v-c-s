/*
 * replacements_generator.cpp
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

#include "replacements_generator.h"

#include "board.h"
#include "product.h"
#include "product_generator.h"

#include <vector>
#include <list>

using std::vector;
using std::list;

ReplacementsGenerator::ReplacementsGenerator(Board& replacements_board, vector<ProductGenerator*>& product_generators)
    : replacements_board(replacements_board){
    this->product_generators = vector<ProductGenerator*>();
    vector<ProductGenerator*>::iterator it;
    for (it = product_generators.begin(); it != product_generators.end(); ++it) {
        this->product_generators.push_back(*it);
    }
}

list<Product*> ReplacementsGenerator::getReplacements(int n, int column_number) {
    if (column_number < 0 || column_number >= replacements_board.getWidth()) {
        return list<Product*>();
    }
    list<Product*> ret_list = list<Product*>();
    while (n > 0) {
        Product* product = product_generators[column_number]->getNewProduct();
        ret_list.push_back(product);
        n--;
    }
    return ret_list;
}

ReplacementsGenerator::~ReplacementsGenerator() {
    product_generators.clear();
}
