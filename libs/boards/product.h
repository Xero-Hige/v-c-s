/*
 * product.h
 *
 * Created on: Nov 17, 2013
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

#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product {
public:
    // Constantes de color
    static const int NO_COLOR = -1;
    static const int RED = 0;
    static const int YELLOW = 1;
    static const int GREEN = 2;
    static const int BLUE = 3;
    static const int VIOLET = 4;

    static const int N_COLORS = 6; // Cantidad de colores, sin contar el inválido (NO_COLOR)

    // Constantes de tipo
    static const int NO_TYPE = -1;
    static const int BUTTON = 0;
    static const int V_BAR = 1;
    static const int H_BAR = 2;
    static const int STAR = 3;

    static const int N_TYPES = 4;   // Cantidad de tipos, sin contar el inválido (NO_TYPE)

private:
    int color;
    int type;

public:
    Product(int color, int type)
        : color(color), type(type) {}
    int getColor();
    int getType();
};

#endif /* PRODUCT_H_ */
