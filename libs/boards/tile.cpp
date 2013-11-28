/*
 * tile.cpp
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

#include "tile.h"

#include "product.h"
#include "../position/position.h"

int Tile::getX() {
    return pos.getX();
}

int Tile::getY() {
    return pos.getY();
}

void Tile::setType(int type) {
    this->type = type;
}

int Tile::getType() {
    return type;
}

bool Tile::isHole() {
    return type == HOLE;
}

bool Tile::isCell() {
    return type != HOLE;
}

bool Tile::isEmpty() {
    return (type == CELL && product == NULL);
}

bool Tile::hasProduct() {
    return (type == CELL && product != NULL);
}

int Tile::getProductColor() {
    if (product == NULL) {
        return Product::NO_COLOR;
    }
    return product->getColor();
}

int Tile::getProductType() {
    if (product == NULL) {
        return Product::NO_TYPE;
    }
    return product->getType();
}

Product* Tile::popProduct(){
    Product* ret_product = product;
    product = NULL;
    return ret_product;
}

bool Tile::setProduct(Product* product) {
    if (type == HOLE || this->product != NULL) {
        return false;
    }
    this->product = product;
    return true;
}

void Tile::eliminateProduct() {
    Product* del_product = popProduct();
    delete(del_product);
}

Tile::~Tile() {
    delete(product);
}
