/**
 sprite.cpp

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
#include "sprite.h"
#include <SDL_image.h>

using std::string;

Sprite::Sprite(const string& file_path, int x_pos, int y_pos){

	_surface = NULL;
	SDL_Surface* temporal = NULL;

	if ((temporal = IMG_Load(file_path.c_str())) == NULL) {
		return;
	}

	_surface = SDL_DisplayFormat(temporal);
	SDL_FreeSurface(temporal);

	this->x_pos = x_pos;
	this->y_pos = y_pos;
}

void Sprite::set_transparency(int red, int green, int blue) {
	SDL_SetColorKey(this->_surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(this->_surface->format, red, green , blue));
}

bool Sprite::draw_over(Surface& destination_surface) {

	destination_surface.draw_on(*this,x_pos,y_pos);

}

bool Sprite::draw_over(Surface& destination_surface, int x_pos, int y_pos) {

	destination_surface.draw_on(*this,x_pos,y_pos);

}

void Sprite::move(int x_pos, int y_pos) {
	this->x_pos = x_pos;
	this->y_pos = y_pos;
}
