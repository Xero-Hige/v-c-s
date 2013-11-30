/*
 * product_generator.cpp
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

#include "product_generator.h"

#include "product.h"

#include <map>
#include <vector>
#include <string>
#include <cstdlib>

using std::map;
using std::vector;
using std::string;

map<string, unsigned int> ProductGenerator::convertion_table = map<string, unsigned int>();

void ProductGenerator::setConvertionTable(map<string, unsigned int>& colors) {
    map<string, unsigned int>::iterator it;
    for (it = colors.begin(); it != colors.end(); ++it) {
        convertion_table[it->first] = it->second;
    }
}

ProductGenerator::ProductGenerator(map<string, int>& probabilities) {
    limit = 0;
    this->probabilities = map<string, int>();
    map<string, int>::iterator it;
    for (it = probabilities.begin(); it != probabilities.end(); ++it) {
        limit+= it->second;
        this->probabilities[it->first] = it->second;
    }
}

Product* ProductGenerator::getNewProduct() {
    int n = getRandomNumber();
    int color = -1;
    map<string, int>::iterator it;
    for (it = probabilities.begin(); it != probabilities.end(); ++it) {
        if (n <= it->second) {
            color = convertion_table[it->first];
            break;
        }
        n-= it->second;
    }
    return (new Product(color, Product::BUTTON));
}

// Devuelve un número aleatorio entre 1 y el atributo limit (incluidos)
int ProductGenerator::getRandomNumber() {
    int divisor = RAND_MAX/(limit+1);
    int retval;
    do {
        retval = std::rand() / divisor;
    } while (retval >= limit);
    return retval+1;
}
