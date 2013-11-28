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
    //TODO esto hacerlo int, está trayendo más problemas que otra cosa
    int rows;
    int columns;
    std::vector<Tile> tiles;
    std::vector<int> cellsInColumn;
    std::vector<int> productsInColumn;

public:
    /* Solo se usa como dummy, el tablero no queda de forma válida ni usable */
    Board()
        : rows(-1), columns(-1) {};
    Board(int n_rows, int n_columns);
    /* Setea los casilleros (Tile) a celdas o a agujeros                   *
     * schema es un vector que tiene las constantes HOLE o EMPTY_CELL de   *
     * Tile. Es de largo n_filas*n_columnas, y está ordenado como una fila *
     * a continuación de la otra                                           */
    void setSchema(std::vector<std::vector<int> >& schema);
    /* Setea los productos contenidos en products en las celdas tablero  *
     * La cantidad de productos debe coincidir con la cantidad de celdas */
    void setUp(std::list<Product*> products);
    /* Devuelve la altura del tablero */
    int getHeight();
    /* Devuelve el ancho del tablero */
    int getWidth();
    /* Devuelve si un casillero es celda o agujero, según las contantes de *
     * la clase Tile                                                       */
    int getTileType(int x, int y);
    int getTileType(Position& pos);
    /* Devuelve un int que representa el color del producto, según las *
     * constantes de product_constants.h                               */
    int getProductColor(int x, int y);
    int getProductColor(Position& pos);
    /* Devuelve un int que representa el tipo del producto, según las *
     * constantes de product_constants.h                              */
    int getProductType(int x, int y);
    int getProductType(Position& pos);
    /* Saca el producto del tablero y lo devuelve, dejando la celda vacía. *
     * Si la celda estaba vacía, o es un agujero, devuelve NULL            */
    Product* takeOutProduct(int x, int y);
    Product* takeOutProduct(Position& pos);
    /* Agrega un producto al tablero.                                        *
     * Devuelve true si el producto se insertó correctamente. Si la celda ya *
     * tiene un producto o es un agujero, devuelve false.                    */
    bool setProduct(Product* product, int x, int y);
    bool setProduct(Product* product, Position& pos);
    /* Intercambia dos productos del tablero */
    void swapProducts(Position& pos1, Position& pos2);
    /* Acomoda la columna. Hace que los productos bajen si tienen celdas *
     * vacías debajo, dejando las celdas superiores libres.              *
     * Si el número de columna es inválido, lo ignora                    */
    void rearrangeColumn(int column_number);
    //FIXME este no está actualizado, creo que no se va a usar en ningún lugar
//    /* Acomoda todas las columnas pasadas por parámetro */
//    void rearrangeColumn(std::vector<int> column_numbers);
    //////////////////////////////////////////////////////////////////////////
    /* Acomoda todas las columnas del tablero */
    void rearrangeBoard();
    /* Saca todos los productos de una fila y los devuelve en una lista */
    std::list<Product*> takeOutRow(int row);
    /* Saca todos los productos de una columna y los devuelve en una lista */
    std::list<Product*> takeOutColumn(int column);
    /* Inserta los productos de la lista en la columna especificada   *
     * Se insertan en el orden que vienen en la lista, de abajo hacia *
     * arriba. Devuelve la cantidad de productos insertados           */
    int pushInColumn(std::list<Product*> products, int column);
    /* Extrae n productos de la columna especificada, y los devuelve     *
     * Los productos se sacan de abajo hacia arriba, y se insertan en la *
     * lista en el orden que se sacaron                                  */
    std::list<Product*> popFromColumn(int n, int column);
    /* Devuelve la cantidad de celdas vacias en la columna dada *
     * Si el número de columna es inválido devuelve -1          */
    int getEmptyCellsInColumn(int column_number);
    ~Board();

private:
    int getIndexFromPos(int x, int y);
    void initTiles();
    int countEmpty(Position pos);
};


#endif /* BOARD_H_ */
