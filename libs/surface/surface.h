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

#include <SDL2/SDL.h>

#include <string>
#include <exception>

#include "../sprite/sprite.h"
#include "../animated_sprite/animated_sprite.h"

class Surface_Construction_Error: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Ocurrio un error al crear la surface";
  }
};

class Surface {

protected:
	SDL_Surface* _surface;

public:
	/**
	 * Dummy
	 */
	Surface() {}
	/**
	 * Construye un SDL_Surface en base al path pasado como parametro
	 */
	Surface(const std::string& file_path);
	/**
	 * Dibuja sobre si la source_surface
	 */
	bool draw_on(Surface& source_surface, int source_x_pos, int source_y_pos,
			SDL_Rect* source_rect = NULL);
	/**
	 * Establece el valor RGB para la transparencia de la surface
	 */
	void set_transparency(int red, int green, int blue);
	/**
	 * Devuelve un sprite asociado a la ventana pasada como parametro con este
	 * surface como textura
	 */
	Sprite convert_to_sprite(Window& window, int image_width, int image_height);
	/**
	 * Devuelve un animated sprite asociado a la ventana pasada como parametro con este
	 * surface como textura
	 */
	Animated_Sprite convert_to_animated_sprite(Window& window, int image_width,
			int image_height, int frames);
	/**
	 * Libera la surface interna del objeto
	 */
	void free();
	/**
	* Obtiene el ancho de la surface
	*/
	int get_width();
	/**
	* Obtiene el alto de la surface
	*/
	int get_height();
};

#endif
