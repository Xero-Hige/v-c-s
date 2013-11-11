/*
 * simple_tile.cpp
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

#include "simple_tile.h"

void Tile::setType(int type) {
    this->type = type;
}

unsigned int Tile::getX() {
    return pos.getX();
}

unsigned int Tile::getY() {
    return pos.getY();
}

bool Tile::isHole() {
    return type == HOLE;
}

bool Tile::isCell() {
    return type == CELL;
}

bool Tile::isEmpty() {
    return (type == HOLE || product == NULL);
}

int Tile::getProductColor() {
    return product->getColor();
}

int Tile::getProductType() {
    return product->getType();
}

Effect& Tile::getProductEffect() {
    return product->getEffect();
}

Product* Tile::popProduct(){
    Product* product = this->product;
    this->product = NULL;
    return product;
}

bool Tile::setProduct(Product* product) {
    if (type == HOLE || this->product != NULL) {
        return false;
    }
    this->product = product;
    return true;
}

void Tile::eliminateProduct() {
    delete(product);
}

Tile::~Tile() {
    delete(product);
}
