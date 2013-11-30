/*
 * simple_refiller.cpp
 *
 * Created on: Nov 11, 2013
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

#include "simple_refiller.h"

#include "simple_product.h"

#include <map>
#include <vector>
#include <string>
#include <cstdlib>

using std::map;
using std::vector;
using std::string;

map<string, unsigned int> ProductGenerator::convertion_table = map<string, unsigned int>();

void ProductGenerator::setConvertionTable(vector<string>& colors) {
    vector<string>::iterator it;
    unsigned int i = 0;
    for (it = colors.begin(); it != colors.end(); ++it) {
        convertion_table[*it] = i;
        i++;
    }
}

ProductGenerator::ProductGenerator(std::map<string, int>& probabilities) {
    limit = 0;
    this->probabilities = vector<int>();
    this->probabilities.resize(convertion_table.size());
    map<string, int>::iterator it;
    for (it = probabilities.begin(); it != probabilities.end(); ++it) {
        limit+= it->second;
        unsigned int pos = convertion_table[it->first];
        this->probabilities[pos] = it->second;
    }
}

Product* ProductGenerator::getNewProduct() {
    int n = getRandomNumber();
    int color = -1;
    for (unsigned int i = 0; i < probabilities.size(); i++) {
        if (n <= probabilities[i]) {
            color = i;
            break;
        }
        n-= probabilities[i];
    }
    return (new Product(color, BUTTON));
}

// return a random number between 1 and limit (inclusive)
int ProductGenerator::getRandomNumber() {
    int divisor = RAND_MAX/(limit+1);
    int retval;
    do {
        retval = std::rand() / divisor;
    } while (retval >= limit);
    return retval+1;
}
