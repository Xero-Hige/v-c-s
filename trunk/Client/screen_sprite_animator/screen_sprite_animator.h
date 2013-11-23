/**
 screen_sprite_animator.h

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

#ifndef SCREEN_SPRITE_ANIMATOR_H_
#define SCREEN_SPRITE_ANIMATOR_H_

#include "../../libs/position/position.h"

class Screen_Sprite_Animator {

	Position position;
	Position direction;

	int reference;
	int speed;

	size_t cell_height;
	size_t cell_width;

public:
	/**
	 *
	 */
	Screen_Sprite_Animator(int reference, const Position& position,
			const Position& direction, size_t cell_height, size_t cell_whidth);
	/**
	 *
	 */
	void animate();
	/**
	 *
	 */
	const Position get_position();
	/**
	 * Devuelve la referencia asociada al animator
	 */
	int get_reference();
	/**
	 *
	 */
	virtual ~Screen_Sprite_Animator();
};

#endif /* SCREEN_SPRITE_ANIMATOR_H_ */
