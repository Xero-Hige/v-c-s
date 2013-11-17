/**
 text_drawer.h

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
#ifndef TEXTDRAWER_H_
#define TEXTDRAWER_H_

#include <SDL2/SDL_ttf.h>

#include <string>

#include "../window/window.h"
#include "../sprite/sprite.h"

class Text_Drawer {
private:
	SDL_Color color;
	TTF_Font* font;

public:
	Text_Drawer();
	~Text_Drawer(){};
	/**
	 * Setea la fuente a utilizar, abriendo la que recibe como
	 * parametro
	 */
	void set_font(const std::string& path,int font_size);
	/**
	 * Setea el color del texto
	 */
	void set_color(Uint8 r,Uint8 g,Uint8 b,Uint8 alpha_level);
	/**
	 * Obtiene un sprite con el texto pasado por parametro
	 */
	Sprite get_text_sprite(const std::string& text,Window& window);
	/**
	 * Libera los recursos pedidos por el Drawer para la fuente
	 */
	void close_font();
};

#endif /* TEXTDRAWER_H_ */
