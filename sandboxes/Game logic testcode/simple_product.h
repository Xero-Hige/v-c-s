/*
 * simple_product.h
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

#ifndef SIMPLE_PRODUCT_H_
#define SIMPLE_PRODUCT_H_

#include "simple_effect.h"
#include "test_effect.h"

// Color constants
#define NO_COLOR -1
#define UNCOLORED 0
#define RED      1
#define YELLOW   2
#define GREEN    3
#define BLUE     4
#define VIOLET   5

// Type constants
#define NO_TYPE -1
#define BUTTON 1
#define V_BAR 2
#define H_BAR 3
#define STAR 4

class Product {
private:
    int color;
    int type;
    Effect effect;

public:
    Product(int color, int type)
        : color(color), type(type), effect(TestEffect()) {}
    int getColor();
    int getType();
    Effect& getEffect();
    void applyEffect();
};

#endif /* SIMPLE_PRODUCT_H_ */
