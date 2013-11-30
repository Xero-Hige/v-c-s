/*
 * refiller.cpp
 *
 * Created on: Nov 29, 2013
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

#include "refiller.h"

#include "board.h"
#include "product.h"

#include <list>

#include <iostream> //FIXME borrar

using std::list;

void Refiller::realocateBoard() {
    board->rearrangeBoard();
    for (int x = 0; x < board->getWidth(); x++) {
        int emptyCells = board->getEmptyCellsInColumn(x);
        list<Product*> products = replacement_board->popFromColumn(emptyCells, x);
        for (list<Product*>::iterator it = products.begin(); it != products.end(); ++it) {
            std::cout << "Producto a insertar en la columna " << x << ": Color " << (*it)->getColor() << " - Tipo " << (*it)->getType() << std::endl;
        }
        board->pushInColumn(products, x);
    }
    replacement_board->rearrangeBoard();
}

void Refiller::refillReplacementBoard(int column, list<Product*> products) {

}
