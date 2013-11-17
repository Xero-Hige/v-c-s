/*
 * tile.h
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

#ifndef TILE_H_
#define TILE_H_

#include "product.h"
#include "../position.h"

#include <cstdlib>

// Type constants
#define HOLE 0
#define CELL 1

class Tile {
    int type;
    Product* product;
    // TODO la posición no seria necesaria para nada
    Position pos;

public:
    Tile(int type, unsigned int x, unsigned int y)
        : type(type), product(NULL), pos(Position(x, y)) {}
    Tile(int type, Product* product, unsigned int x, unsigned int y)
        : type(type), product(product), pos(Position(x, y)) {}
    explicit Tile(int type)
        : type(type), product(NULL), pos(Position(-1, -1)) {}
    Tile(int type, Product* product)
        : type(type), product(product), pos(Position(-1, -1)) {}
    explicit Tile(Product* product)
        : type((product==NULL)?HOLE:CELL), product(product), pos(Position(-1, -1)) {}
//    explicit Tile(Tile& tile)
//        : type(tile.type), product(tile.product), x(tile.x), y(tile.y) {}
//    explicit Tile(const Tile& tile)
//        : type(tile.type), product(tile.product), x(tile.x), y(tile.y) {}
//    explicit Tile(const Tile& tile)
//        : type(tile.type), product(tile.product), pos(Position(tile.pos)) {}
    // Esto creo que no vale la pena tenerlo, no se usa
    unsigned int getX();
    unsigned int getY();
    ////////////////////
    void setType(int type);
    bool isHole();
    bool isCell();
    bool isEmpty();
    int getProductColor();
    int getProductType();
    Product* popProduct();
    bool setProduct(Product* product);
    // No se si hace falta
    void eliminateProduct();
    ~Tile();
};

#endif /* TILE_H_ */
