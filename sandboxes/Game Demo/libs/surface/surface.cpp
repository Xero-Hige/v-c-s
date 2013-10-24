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
#include <SDL_image.h>

using std::string;

/**
 * Construye un SDL_Surface en base al path pasado como parametro
 */
Surface::Surface(const string& file_path) {
	_surface = NULL;
	SDL_Surface* temporal = NULL;

	if ((temporal = IMG_Load(file_path.c_str())) == NULL) {
		return;
	}

	_surface = temporal;//SDL_ConvertSurfaceFormat(temporal);
	//SDL_FreeSurface(temporal);
}

/**
 * Dibuja en sobre si la source_surface
 */
bool Surface::draw_on(Surface& source_surface, int source_x_pos, int source_y_pos, SDL_Rect* source_rect){

	if (_surface == NULL || source_surface._surface == NULL) {
		return false;
	}

	SDL_Rect destination_rectangle;

	destination_rectangle.x = source_x_pos;
	destination_rectangle.y = source_y_pos;

	SDL_BlitSurface(source_surface._surface, source_rect, _surface, &destination_rectangle);

	return true;
}

void Surface::free()
{
	SDL_FreeSurface(_surface);
}
