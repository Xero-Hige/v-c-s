/**
 Surface.h

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

#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL.h>

#include <string>

class Surface {

protected:
	SDL_Surface* _surface;

public:
	Surface(){};
	Surface(const std::string& File);
	bool draw_on(Surface& source_surface, int source_x_pos, int source_y_pos , SDL_Rect* source_rect = NULL);
	void free();
};

#endif
