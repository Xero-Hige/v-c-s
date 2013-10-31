/**
 login_screen.cpp

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
#include "login_screen.h"

using std::string;

bool Login_Screen::initialize() {

	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	Surface background_temp = Surface("resources/login/background.png");
	Surface textbox_temp = Surface("resources/login/textbox.png");

	int text_box_pos_x = background_temp.get_width()/2 - textbox_temp.get_width()/2;

	background_temp.draw_on(textbox_temp, text_box_pos_x, 200);
	background_temp.draw_on(textbox_temp, text_box_pos_x, 194+textbox_temp.get_height());

	background = background_temp.convert_to_sprite(window, 790, 315);

	background_temp.free();
	textbox_temp.free();

	background.set_scaled_height(SCREEN_HEIGHT);
	background.set_scaled_width(SCREEN_WIDTH);

	user_nick = Text_Box(14,"resources/login/logfont.ttf",20,window);
	user_nick.move(214,202);

	return true;
}

void Login_Screen::handle_event(SDL_Event& event) {
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Click",
				"Oh, un click (?)", window.window);
		break;

	case SDL_KEYDOWN:
		if (SDL_SCANCODE_BACKSPACE == event.key.keysym.scancode)
		user_nick.pop_char();
		break;

	case SDL_TEXTINPUT:
		user_nick.add_char(event.text.text[0]);
		break;

	case SDL_TEXTEDITING:
		break;
	}
}

void Login_Screen::loop() {
	user_nick.refresh(window);
}

void Login_Screen::render() {
	window.clear();

	background.draw(window);
	user_nick.draw(window);

	window.render();

}

void Login_Screen::cleanup() {
	background.free();
	user_nick.free();
	window.free();
}
