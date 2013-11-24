/**
 screen_sprite_animator.cpp

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

#include "screen_sprite_animator.h"

Screen_Sprite_Animator::Screen_Sprite_Animator(int reference,
		const Position& position, const Position& direction, size_t cell_height,
		size_t cell_width) :
		position(position), reference(reference), direction(direction), cell_height(
				cell_height), cell_width(cell_width), speed(1), step_cells(0), moved_x(
						0), moved_y(0) {
}

void Screen_Sprite_Animator::animate() {
	if (direction[0] == 0) //movimiento en y
	{
		moved_y = direction[1] * (++speed);
		if (moved_y >= (step_cells * cell_height)) {
			moved_y = (step_cells * cell_height);
			return;
		}
	} else //movimiento en x
	{
	}
}

const Position Screen_Sprite_Animator::get_position() {
	return Position(position[0] + moved_x, position[1] + moved_y);
}

int Screen_Sprite_Animator::get_reference() {
	return reference;
}

void Screen_Sprite_Animator::set_step_cells(size_t cells) {
	step_cells = cells;
}

bool Screen_Sprite_Animator::animation_ended() {
	return ((moved_x >= step_cells * cell_width)
			|| (moved_y >= step_cells * cell_height));
}

Screen_Sprite_Animator::~Screen_Sprite_Animator() {
	// TODO Auto-generated destructor stub
}

