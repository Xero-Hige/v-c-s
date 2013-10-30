/*
 * simple_tile.h
 *
 * Created on: Oct 27, 2013
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

#ifndef SIMPLE_TILE_H_
#define SIMPLE_TILE_H_

#include <cstdlib>

#include "simple_product.h"

// Type constants
#define HOLE 0
#define CELL 1

class Tile {
    int type;
    Product* product;
    // TODO la posición hacerla una estructura o una clase?
    unsigned int x;
    unsigned int y;

public:
    Tile(int type, unsigned int x, unsigned int y)
        : type(type), product(NULL), x(x), y(y) {}
    Tile(int type, Product* product, unsigned int x, unsigned int y)
        : type(type), product(product), x(x), y(y) {}
    unsigned int getX();
    unsigned int getY();
    bool isHole();
    bool isCell();
    bool isEmpty();
    int getProductColor();
    void eliminateProduct();

};

#endif /* SIMPLE_CELL_H_ */
