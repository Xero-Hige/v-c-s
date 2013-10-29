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

#include <SDL_ttf.h>

#include <string>

#include "../libs/window/window.h"

class Text_Drawer {
private:
	SDL_Color color;
	TTF_Font* font;

public:
	Text_Drawer();

	void set_font(TTF_Font* font);
	void set_color(SDL_Color& color);

	Sprite get_text_sprite(std::string text,Window& window);

	virtual ~Text_Drawer();
};

#endif /* TEXTDRAWER_H_ */
