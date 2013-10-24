/**
 sprite.h

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
#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#include <string>

#include "../surface/surface.h"
#include "../window/window.h"

/*
 *
 */
class Sprite {

private:
	SDL_Texture* _texture;
	int x_pos;
	int y_pos;

	int image_width;
	int image_height;

	int scaled_width;
	int scaled_height;

public:
	Sprite() {}
	virtual ~Sprite() {	}
	Sprite(const std::string& file_path, SDL_Renderer* window_render,
			int image_width, int image_height);
	void set_transparency(int red, int green, int blue);
	void move(int x_pos, int y_pos);
	virtual bool draw(Window& destination_window);
	virtual bool draw(Window& destination_window, SDL_Rect& DesR);
	void free();
};

#endif /* SPRITE_H_ */
