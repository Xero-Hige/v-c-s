/*
 * test.cpp
 *
 * Created on: Nov 5, 2013
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

#include "position.h"
#include "simple_product.h"
#include "simple_board.h"
#include "simple_combination_checker.h"
#include "simple_refiller.h"

#include <list>
#include <iostream>
#include <map>
#include <vector>

using std::list;
using std::cout;
using std::endl;
using std::map;
using std::vector;

void printBoard(Board& board, int lenght, int width) {
    int color;
    int type;
    for (int y = 0; y < lenght; y++) {
        for (int x = 0; x < width; x++) {
            color = board.getProductColor(x, y);
            type = board.getProductType(x, y);
            cout << color << type << " ";
        }
        cout << endl;
    }
}

void printCheck(CombinationChecker& checker, int lenght, int width) {
    for (int y = 0; y < lenght; y++) {
        for (int x = 0; x < width; x++) {
            Position pos = Position(x,y);
            cout << "En la posición (" << x << "," << y << ") ";
            if (! checker.check(pos)) {
                cout << "NO ";
            }
            cout << "hay combinación" << endl;
        }
    }
}

void setUpRefiller() {
    vector<string> colors = vector<string>();
    vector.push_back("uncolored");
    vector.push_back("red");
    vector.push_back("yellow");
    vector.push_back("green");
    vector.push_back("blue");
    vector.push_back("violet");
    Refiller::setConvertionTable(colors);
}

int main() {
    list<Product*> products;
    products.push_back(new Product(RED, BUTTON));
    products.push_back(new Product(RED, BUTTON));
    products.push_back(new Product(BLUE, BUTTON));
    products.push_back(new Product(BLUE, BUTTON));
    products.push_back(new Product(YELLOW, BUTTON));
    products.push_back(new Product(RED, BUTTON));
    products.push_back(new Product(GREEN, BUTTON));
    products.push_back(new Product(GREEN, BUTTON));
    products.push_back(new Product(YELLOW, BUTTON));
    products.push_back(new Product(RED, BUTTON));
    products.push_back(new Product(BLUE, BUTTON));
    products.push_back(new Product(RED, BUTTON));
    Board board = Board(3, 4, products);
    printBoard(board, 3, 4);
    CombinationChecker checker = CombinationChecker(board);
    printCheck(checker, 3, 4);
    setUpRefiller();
    Refiller refiller = Refiller();
    return 0;
}
