/**
 text_drawer.cpp

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
#include "text_drawer.h"

using std::string;

Text_Drawer::Text_Drawer(): font(NULL){
	color = {0,0,0,255};//NEGRO
}

void Text_Drawer::set_font(const string& path,int font_size) {
	font = TTF_OpenFont( path.c_str() , font_size );
	if(!font)printf("Well darn, \n%s",TTF_GetError());
	if (font==NULL) throw Sprite_Construction_Error();
}

void Text_Drawer::set_color(int r,int g,int b,int alpha_level) {
	color = {r,g,b,alpha_level};
}

Sprite Text_Drawer::get_text_sprite(const string& text, Window& window) {
	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (text_surface == NULL) {
		throw Sprite_Construction_Error();
	} //TODO: exception;

	try {
		return Sprite(*text_surface, window, text_surface->w, text_surface->h);
	} catch (Sprite_Construction_Error& err) {
		SDL_FreeSurface(text_surface);
		throw err;
	}

}

Text_Drawer::~Text_Drawer() {
	TTF_CloseFont(font);
}
