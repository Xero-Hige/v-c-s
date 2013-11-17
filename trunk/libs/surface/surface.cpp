/**
 Surface.cpp

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

#include "surface.h"
#include <SDL2/SDL_image.h>

using std::string;

Surface::Surface(const string& file_path) {
	_surface = NULL;
	SDL_Surface* temporal = NULL;

	if ((temporal = IMG_Load(file_path.c_str())) == NULL) {
		throw Surface_Construction_Error();
	}

	_surface = temporal;
}

bool Surface::draw_on(Surface& source_surface, int source_x_pos,
		int source_y_pos, SDL_Rect* source_rect) {

	if (_surface == NULL || source_surface._surface == NULL) {
		return false;
	}

	SDL_Rect destination_rectangle;

	destination_rectangle.x = source_x_pos;
	destination_rectangle.y = source_y_pos;

	SDL_BlitSurface(source_surface._surface, source_rect, _surface,
			&destination_rectangle);

	return true;
}

void Surface::set_transparency(int red, int green, int blue) {
	SDL_SetColorKey(_surface, SDL_TRUE | SDL_RLEACCEL,
			SDL_MapRGB(this->_surface->format, red, green, blue));
}

Sprite Surface::convert_to_sprite(Window& window, int image_width,
		int image_height) {
	return Sprite(*this->_surface, window, image_width, image_height);
}

Animated_Sprite Surface::convert_to_animated_sprite(Window& window,
		int image_width, int image_height, int frames) {
	return Animated_Sprite(*this->_surface, window, image_width, image_height,
			frames);
}

void Surface::free() {
	SDL_FreeSurface(_surface);
}

int Surface::get_width()
{
	return _surface->w;
}

int Surface::get_height()
{
	return _surface->h;
}
