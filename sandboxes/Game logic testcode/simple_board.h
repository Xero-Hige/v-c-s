/*
 * simple_board.h
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

#ifndef SIMPLE_BOARD_H_
#define SIMPLE_BOARD_H_

#include "simple_tile.h"
#include "simple_product.h"

#include <vector>
#include <list>

class Board {
private:
    unsigned int rows;
    unsigned int columns;
    std::vector<Tile> tiles;

public:
    Board(unsigned int n_rows, unsigned int n_columns);
    // products tiene Product* para los Tile que son celda, y NULL para los Tile que son agujeros
    Board(unsigned int n_rows, unsigned int n_columns, std::list<Product*> products);
    // Lo mismo que para el constructor
    void setUp(std::list<Product*> products);
    // Product* getProduct(unsigned int x, unsigned int y);
    unsigned int getHeight();
    unsigned int getWidth();
    int getProductColor(unsigned int x, unsigned int y);
    int getProductType(unsigned int x, unsigned int y);
    Effect& getProductEffect(unsigned int x, unsigned int y);
    Product* takeOutProduct(unsigned int x, unsigned int y);
    bool setProduct(Product* product, unsigned int x, unsigned int y);
    int getProductColor(Position& pos);
    int getProductType(Position& pos);
    Effect& getProductEffect(Position& pos);
    Product* takeOutProduct(Position& pos);
    bool setProduct(Product* product, Position& pos);
    ~Board();

private:
    unsigned int getIndexFromPos(unsigned int x, unsigned int y);
    void initTiles();
};

#endif /* SIMPLE_BOARD_H_ */
