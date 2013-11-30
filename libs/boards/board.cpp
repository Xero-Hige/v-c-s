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
#include "../position/position.h"

#include <vector>
#include <list>

#include <iostream> //FIXME borrar

using std::vector;
using std::list;

Board::Board(int n_rows, int n_columns)
    : rows(n_rows), columns(n_columns), tiles(vector<Tile>()) {
    initTiles();
    cellsInColumn.resize(n_columns, 0);
    productsInColumn.resize(n_columns, 0);
}

void Board::setSchema(vector<vector<int> >& schema) {
    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < rows; y++) {
            int tile_type = schema[x][y];
            if (tile_type == Tile::HOLE) {
                tiles[getIndexFromPos(x, y)].setType(Tile::HOLE);
            } else {
                // Se inicializa en CELL, por lo que no hay que cambiar el tipo
                cellsInColumn[x]++;
            }
        }
    }
}

void Board::setUp(list<Product*> products) {
    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < rows; y++) {
            if (products.size()) {
                return;
            }
            int index = getIndexFromPos(x, y);
            Tile& tile = tiles[index];
            if (tile.isCell()) {
                tile.setProduct(products.front());
                products.pop_front();
                productsInColumn[x]++;
            }
        }
    }
}

int Board::getHeight() {
    return rows;
}

int Board::getWidth() {
    return columns;
}

int Board::getTileType(int x, int y) {
    int pos = getIndexFromPos(x, y);
    return tiles[pos].getType();
}

int Board::getProductColor(int x, int y) {
    int pos = getIndexFromPos(x, y);
    return tiles[pos].getProductColor();
}

int Board::getProductType(int x, int y) {
    int pos = getIndexFromPos(x, y);
    return tiles[pos].getProductType();
}

Product* Board::takeOutProduct(int x, int y) {
    int pos = getIndexFromPos(x, y);
    if (tiles[pos].hasProduct()) {
        productsInColumn[x]--;
    }
    return tiles[pos].popProduct();
}

bool Board::setProduct(Product* product, int x, int y) {
    int pos = getIndexFromPos(x, y);
    if (tiles[pos].isEmpty()) {
        productsInColumn[x]++;
    }
    return tiles[pos].setProduct(product);
}

int Board::getTileType(Position& pos) {
    return getTileType(pos.getX(), pos.getY());
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

void Board::swapProducts(Position& pos1, Position& pos2) {
    Product* swap_aux = takeOutProduct(pos1);
    setProduct(takeOutProduct(pos2), pos1);
    setProduct(swap_aux, pos2);
}

//void Board::rearrangeColumn(vector<int> column_numbers) {
//    vector<int>::iterator it;
//    for (it = column_numbers.begin(); it != column_numbers.end(); ++it) {
//        rearrangeColumn(*it);
//    }
//}

void Board::rearrangeColumn(int column_number) {
    //TODO revisar esta cosa
    std::cout << "Reacomodando columna " << column_number;
    // If not a valid value, it is ignored
    if (0 > column_number || column_number >= columns) {
        std::cout << " - Número de columna inválido (válidos de 0 a " << columns << "): " << column_number << std::endl;;
        return;
    }
    std::cout << std::endl;
    int x = column_number;
    int y = rows-1;
    while (y >= 0) {
        Position initial_pos = Position(x,y);
        if (getTileType(initial_pos) != Tile::CELL) {
            y--;
            continue;
        }
        int empty_tiles = countEmpty(initial_pos);
        if (empty_tiles > 0) {
            // No hay más productos para rellenar
            if (empty_tiles > y) {
                return;
            }
            Position product_pos = Position(x, y-empty_tiles);
            Product* product = takeOutProduct(product_pos);
            setProduct(product, initial_pos);
        }
        y--;
    }
}

void Board::rearrangeBoard() {
    for (int column = 0; column < columns; column++) {
        if (productsInColumn[column] < cellsInColumn[column]) {
            rearrangeColumn(column);
        }
    }
}

list<Product*> Board::takeOutRow(int row) {
    list<Product*> products;
    for (int x = 0; x < columns; x++) {
        Product* product = takeOutProduct(x, row);
        if (product != NULL) {
            products.push_back(product);
        }
    }
    return products;
}

list<Product*> Board::takeOutColumn(int column) {
    list<Product*> products;
    for (int y = 0; y < rows; y++) {
        Product* product = takeOutProduct(column, y);
        if (product != NULL) {
            products.push_back(product);
        }
    }
    return products;
}

int Board::pushInColumn(list<Product*> products, int column) {
    int inserted = 0;
    for (int y = rows-1; y >= 0; y--) {
        if (products.size() == 0) {
            break;
        }
        int index = getIndexFromPos(column, y);
        if (tiles[index].isEmpty()) {
            tiles[index].setProduct(products.front());
            products.pop_front();
            productsInColumn[column]++;
            inserted++;
        }
    }
    return inserted;
}

list<Product*> Board::popFromColumn(int n, int column) {
    list<Product*> products;
    int y = rows-1;
    while (n > 0 && y >= 0) {
        int index = getIndexFromPos(column, y);
        if (tiles[index].hasProduct()) {
            products.push_back(tiles[index].popProduct());
            productsInColumn[column]--;
            n--;
        }
        y--;
    }
    return products;
}

int Board::getEmptyCellsInColumn(int column_number) {
    if (column_number < 0 || column_number >= columns) {
        return -1;
    }
    return cellsInColumn[column_number] - productsInColumn[column_number];
}

Board::~Board() {
    tiles.clear();
}

int Board::getIndexFromPos(int x, int y) {
    return (x + (y*columns));
}

void Board::initTiles() {
    int length = rows * columns;
    tiles.reserve(length);
    for (int i = 0; i < length; i++) {
        Tile tile = Tile(Tile::CELL);
        tiles.push_back(tile);
    }
}

int Board::countEmpty(Position pos) {
    int x = pos.getX();
    int y = pos.getY();
    if (y < 0) {
        return 0;
    }
    int pos_index = getIndexFromPos(x, y);
    if (tiles[pos_index].hasProduct()) {
        return 0;
    }
    return 1 + countEmpty(Position(x, y-1));
}
