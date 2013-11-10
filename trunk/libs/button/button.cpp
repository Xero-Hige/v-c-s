/**
 Button.cpp

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
#include "button.h"

void Button::setup_button() {
	image_width = image_width / 2;
	scaled_width = scaled_width / 2;
	active = true;
	clicked = false;
}

Button::Button(const std::string& file_path, Window& window) :
		Sprite(file_path, window) {
	setup_button();
}

Button::Button(SDL_Surface& surface, Window& window) :
		Sprite(surface, window) {
	setup_button();

}

Button::Button(SDL_Surface& surface, Window& window, int image_width,
		int image_height) :
		Sprite(surface, window, image_width, image_height) {
	setup_button();
}

//FIXME: Ya no me gusta esta solucion para nada
void Button::draw(Window& destination_window) {
	SDL_Rect source_rect;
	SDL_Rect destination_rect;

	source_rect.x = clicked ? image_width : 0;
	source_rect.y = 0;
	source_rect.w = image_width;
	source_rect.h = image_height;

	destination_rect.x = x_pos;
	destination_rect.y = y_pos;
	destination_rect.w = scaled_width;
	destination_rect.h = scaled_height;

	destination_window.draw_on(*_texture, source_rect, destination_rect);

}

void Button::draw(Window& destination_window, SDL_Rect& destination_rect) {

	SDL_Rect source_rect;

	source_rect.x = clicked ? image_width : 0;
	source_rect.y = 0;
	source_rect.w = image_width;
	source_rect.h = image_height;

	destination_window.draw_on(*_texture, source_rect, destination_rect);
}

void Button::handle_event(SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		int x = event.button.x;
		int y = event.button.y;
		if (x >= x_pos && y >= y_pos && x <= x_pos + scaled_width
				&& y <= y_pos + scaled_height) {
			clicked = true;
		} else {
			clicked = false;
		}
	}
}

void Button::draw(Window& destination_window, int x_pos, int y_pos) {
	SDL_Rect source_rect;
	SDL_Rect destination_rect;

	source_rect.x = clicked ? image_width : 0;
	source_rect.y = 0;
	source_rect.w = image_width;
	source_rect.h = image_height;

	destination_rect.x = x_pos;
	destination_rect.y = y_pos;
	destination_rect.w = scaled_width;
	destination_rect.h = scaled_height;

	destination_window.draw_on(*_texture, source_rect, destination_rect);
}
