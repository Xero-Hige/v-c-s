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
#include "../position/position.h"

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
    void setUp(std::list<Product*> products);
    // Product* getProduct(unsigned int x, unsigned int y);
    /* Devuelve la altura del tablero */
    unsigned int getHeight();
    /* Devuelve el ancho del tablero */
    unsigned int getLength();
    /* Devuelve un int que representa el color del producto, según las *
     * constantes de product_constants.h                               */
    int getProductColor(unsigned int x, unsigned int y);
    int getProductColor(Position& pos);
    /* Devuelve un int que representa el tipo del producto, según las *
     * constantes de product_constants.h                              */
    int getProductType(unsigned int x, unsigned int y);
    int getProductType(Position& pos);
    /* Saca el producto del tablero y lo devuelve, dejando la celda vacía. *
     * Si la celda estaba vacía, o es un agujero, devuelve NULL            */
    Product* takeOutProduct(unsigned int x, unsigned int y);
    Product* takeOutProduct(Position& pos);
    /* Agrega un producto al tablero.                                        *
     * Devuelve true si el producto se insertó correctamente. Si la celda ya *
     * tiene un producto o es un agujero, devuelve false.                    */
    bool setProduct(Product* product, unsigned int x, unsigned int y);
    bool setProduct(Product* product, Position& pos);
    /* Acomoda la columna. Hace que los productos bajen si tienen celdas *
     * vacías debajo, dejando las celdas superiores libres.              *
     * Si el número de columna es inválido, lo ignora                    */
    void rearrangeColumn(int column_number);
    /* Acomoda todas las columnas pasadas por parámetro */
    void rearrangeColumn(std::vector<int> column_numbers);
    ~Board();

private:
    unsigned int getIndexFromPos(unsigned int x, unsigned int y);
    void initTiles();
};


#endif /* BOARD_H_ */
