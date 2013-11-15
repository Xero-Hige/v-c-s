/**
 text_box.cpp

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
#include "text_box.h"

using std::string;

Text_Box::Text_Box() {
}

Text_Box::Text_Box(int max_len, const string& font_path, int font_size,
		Window& window) {
	this->max_len = max_len;
	text = "";
	shown_text = "";

	drawer = Text_Drawer();
	drawer.set_font(font_path, font_size);

	text_sprite = drawer.get_text_sprite(" ", window);

	height = text_sprite.get_scaled_height();
	length = text_sprite.get_scaled_width() * max_len;

	x_pos = y_pos = 0;

	active = false;
	need_refresh = false;

}

Text_Box::~Text_Box() {
}

void Text_Box::move(int x_pos, int y_pos) {
	this->x_pos = x_pos;
	this->y_pos = y_pos;
	text_sprite.move(x_pos, y_pos);
}

void Text_Box::draw(Window& window) {
	if (need_refresh)
		refresh(window);
	text_sprite.draw(window);
}

void Text_Box::add_char(char character) {
	text += character;
	if (shown_text == " ")
		shown_text = character;
	else
		shown_text += character;
	if (shown_text.size() > max_len) {
		shown_text = shown_text.substr(1, max_len);
	}
	need_refresh = true;
}

void Text_Box::pop_char() {
	if (text == "")
		return;
	text = text.substr(0, text.size() - 1);
	if (text.size() <= max_len) {
		shown_text = text;
	} else {
		shown_text = text.substr(text.size() - max_len - 1, max_len);
	}
	if (shown_text == "")
		shown_text = " ";
	need_refresh = true;
}

/**
 * Refresca el textbox regenerando el sprite a imprimir
 */
void Text_Box::refresh(Window& window) {
	if (!need_refresh)
		return;
	text_sprite.free();
	text_sprite = drawer.get_text_sprite(shown_text, window);
	text_sprite.move(x_pos, y_pos);
	need_refresh = false;
}

void Text_Box::free() {
	drawer.close_font();
}

void Text_Box::set_alternative_text(const std::string& text, Window& window) {
	//TODO exception
	text_sprite = drawer.get_text_sprite(text, window);
	text_sprite.move(x_pos, y_pos);
}

std::string Text_Box::get_text() {
	return text;
}

void Text_Box::keydown_event(SDL_Event& event) {
	if (!active)
		return;
	if (SDL_SCANCODE_BACKSPACE == event.key.keysym.scancode) {
		pop_char();
	}
}

void Text_Box::text_input_event(SDL_Event& event) {
	if (!active)
		return;
	add_char(event.text.text[0]);
}

void Text_Box::mouse_click_event(SDL_Event& event) {
	int x = event.button.x;
	int y = event.button.y;
	if (x >= x_pos && y >= y_pos && x <= x_pos + length
			&& y <= y_pos + height) {
		active = true;
	} else {
		active = false;
	}
}

void Text_Box::handle_event(SDL_Event& event) {
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		mouse_click_event(event);
		return;

	case SDL_KEYDOWN:
		keydown_event(event);
		return;

	case SDL_TEXTINPUT:
		text_input_event(event);
		return;
	}
}