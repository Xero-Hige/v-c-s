/*
 * board.h
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

#ifndef BOARD_H_
#define BOARD_H_

#include "tile.h"
#include "product.h"

#include <vector>

class Board {
private:
    unsigned int rows;
    unsigned int columns;
    std::vector<Tile> tiles;

public:
    Board(unsigned int n_rows, unsigned int n_columns);
    // products tiene Product* para los Tile que son celda, y NULL para los Tile que son agujeros
    void setUp(std::list<Product*> products);
    // Product* getProduct(unsigned int x, unsigned int y);
    unsigned int getHeight();
    unsigned int getLength();
    int getProductColor(unsigned int x, unsigned int y);
    int getProductColor(Position& pos);
    int getProductType(unsigned int x, unsigned int y);
    int getProductType(Position& pos);
    Product* takeOutProduct(unsigned int x, unsigned int y);
    Product* takeOutProduct(Position& pos);
    bool setProduct(Product* product, unsigned int x, unsigned int y);
    bool setProduct(Product* product, Position& pos);
    void rearrage(std::vector<int> collumns);
    ~Board();

private:
    unsigned int getIndexFromPos(unsigned int x, unsigned int y);
    void initTiles();
};


#endif /* BOARD_H_ */
