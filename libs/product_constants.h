/*
 * product_constants.h
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

#ifndef PRODUCT_CONSTANTS_H_
#define PRODUCT_CONSTANTS_H_

/* Constantes del color y tipo de los productos */

// Constantes de color
#define NO_COLOR -1
#define UNCOLORED 0
#define RED      1
#define YELLOW   2
#define GREEN    3
#define BLUE     4
#define VIOLET   5

#define N_COLORS 6  // Cantidad de colores, sin contar el inválido (NO_COLOR)

// Constantes de tipo
#define NO_TYPE -1
#define BUTTON 0
#define V_BAR 1
#define H_BAR 2
#define STAR 3

#define N_TYPES 4   // Cantidad de tipos, sin contar el inválido (NO_TYPE)

#endif /* PRODUCT_CONSTANTS_H_ */
