/**
 window_surface.h

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
#ifndef WINDOW_SURFACE_H_
#define WINDOW_SURFACE_H_

#include "../surface/surface.h"

/*
 *
 */
class Window_Surface : public Surface {

public:
	Window_Surface(){};
	Window_Surface(size_t height,size_t width, size_t deep, int flags);
	void flip();

};

#endif /* WINDOW_SURFACE_H_ */
