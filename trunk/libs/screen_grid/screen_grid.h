/**
 screen_grid.h

 Copyright 2013 Gaston Martinez Gaston.martinez.90@gmail.com

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses
 */
#ifndef SCREEN_ZONE_H_
#define SCREEN_ZONE_H_

#include <stddef.h>

#include "../position/position.h"

class Screen_Grid {
private:
	size_t columns;
	size_t rows;

	size_t grid_height;
	size_t grid_widht;

	size_t x_pos;
	size_t y_pos;

public:

	Screen_Grid() :
			columns(0), rows(0), grid_height(0), grid_widht(0), x_pos(0), y_pos(
					0) {
	}
	/**
	 *
	 */
	Screen_Grid(size_t x_pos, size_t y_pos, size_t grid_height,
			size_t grid_widht, size_t columns = 1, size_t rows = 1);

	/**
	 *	Devuelve una posicion que indica a que casillero
	 *	dentro de la grilla corresponde esa posicion. Si no corresponde
	 *	a ninguna la posicion es (-1,-1) (invalida)
	 */
	Position get_grid_position(size_t x, size_t y);

	/**
	 * 	Devuelve una posicion que indica las coordenadas
	 * 	x e y de la posicion de la grilla pasada. Devuelve
	 * 	una posicion invalida si se le paso una posicion invalida
	 */
	Position get_screen_position(Position position);
};

#endif /* SCREEN_ZONE_H_ */
