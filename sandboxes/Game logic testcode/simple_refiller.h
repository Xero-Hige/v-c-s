/*
 * simple_refiller.h
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

#ifndef SIMPLE_REFILLER_H_
#define SIMPLE_REFILLER_H_

#include "simple_product.h"

#include <map>
#include <vector>
#include <string>

class ProductGenerator {
private:
    static std::map<std::string, unsigned int> convertion_table;
    std::vector<int> probabilities;
    int limit;

public:
    static void setConvertionTable(std::vector<std::string>& colors);
    ProductGenerator(std::map<std::string, int>& probabilities);
    Product* getNewProduct();

private:
    int getRandomNumber();
};

#endif /* SIMPLE_REFILLER_H_ */
