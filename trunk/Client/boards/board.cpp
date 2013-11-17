/*
 * board.cpp
 *
 * Created on: Nov 16, 2013
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

#include "board.h"

#include "tile.h"
#include "product.h"

#include <vector>
#include <list>

using std::vector;
using std::list;

Board::Board(unsigned int n_rows, unsigned int n_columns)
    : rows(n_rows), columns(n_columns), tiles(vector<Tile>()) {
    initTiles();
}

void Board::setUp(list<Product*> products) {
    unsigned int length = rows * columns;
    for (unsigned int i = 0; i < length; i++) {
        Product* product = products.front();
        products.pop_front();
        if (product != NULL) {
            tiles[i].setProduct(product);
        } else {
            tiles[i].setType(HOLE);
        }
    }
}

// Product* getProduct(unsigned int x, unsigned int y);

unsigned int Board::getHeight() {
    return rows;
}

unsigned int Board::getLength() {
    return columns;
}

int Board::getProductColor(unsigned int x, unsigned int y) {
    unsigned int pos = getIndexFromPos(x, y);
    return tiles[pos].getProductColor();
}

int Board::getProductType(unsigned int x, unsigned int y) {
    unsigned int pos = getIndexFromPos(x, y);
    return tiles[pos].getProductType();
}

Product* Board::takeOutProduct(unsigned int x, unsigned int y) {
    unsigned int pos = getIndexFromPos(x, y);
    return tiles[pos].popProduct();
}

bool Board::setProduct(Product* product, unsigned int x, unsigned int y) {
    unsigned int pos = getIndexFromPos(x, y);
    return tiles[pos].setProduct(product);
}

int Board::getProductColor(Position& pos) {
    return getProductColor(pos.getX(), pos.getY());
}

int Board::getProductType(Position& pos) {
    return getProductType(pos.getX(), pos.getY());
}

Product* Board::takeOutProduct(Position& pos) {
    return takeOutProduct(pos.getX(), pos.getY());
}

bool Board::setProduct(Product* product, Position& pos) {
    return setProduct(product, pos.getX(), pos.getY());
}

void Board::rearrage(vector<int> column_numbers) {
    vector<int>::iterator it;
    for (it = column_numbers.begin(); it != column_numbers.end(); ++it) {
        // If not a valid value, it is ignored
        if (0 < *it || *it >= columns) {
            continue;
        }

    }
}

Board::~Board() {
    tiles.clear();
}

unsigned int Board::getIndexFromPos(unsigned int x, unsigned int y) {
    return (x + (y*columns));
}

void Board::initTiles() {
    unsigned int length = rows * columns;
    tiles.reserve(length);
    for (unsigned int i = 0; i < length; i++) {
        Tile tile = Tile(CELL);
        tiles.push_back(tile);
    }
}
