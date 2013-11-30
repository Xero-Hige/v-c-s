/**
 screen_grid.cpp

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

#include "screen_grid.h"

ScreenGrid::ScreenGrid(size_t x_pos, size_t y_pos, size_t grid_height,
		size_t grid_widht, size_t columns, size_t rows) {
	this->columns = columns;
	this->rows = rows;

	this->grid_height = grid_height;
	this->grid_widht = grid_widht;

	this->x_pos = x_pos;
	this->y_pos = y_pos;
}

Position ScreenGrid::getGridPosition(size_t x, size_t y) {
	if (x >= x_pos and y >= y_pos) {
		int x_reference = (x - x_pos) / grid_widht;
		int y_reference = (y - y_pos) / grid_height;

		if (x_reference >= columns or y_reference >= rows) {
			return Position();
		}

		return Position(x_reference, y_reference);

	}
	return Position(); //invalida
}

Position ScreenGrid::getScreenPosition(Position position) {
	if (!position.is_valid())
		return Position();

	if (position[0] >= columns or position[1] >= rows) {
		return Position();
	}

	return Position(position[0] * grid_widht, position[1] * grid_height);
}
