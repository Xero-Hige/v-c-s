/*
 * refiller.h
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

#ifndef REFILLER_H_
#define REFILLER_H_

#include "product.h"

#include <map>
#include <vector>
#include <string>

class Refiller {
private:
    static std::map<std::string, unsigned int> convertion_table;
    std::map<std::string, int> probabilities;
    int limit;

public:
    static void setConvertionTable(std::map<std::string, unsigned int>& colors);
    Refiller(std::map<std::string, int>& probabilities);
    Product* getNewProduct();

private:
    int getRandomNumber();
};

#endif /* REFILLER_H_ */
