/**
 login_screen_events.cpp

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
#include "../login_screen.h"

#define ACTIVE_NICK 1
#define ACTIVE_PASS 2

void Login_Screen::handle_event(SDL_Event& event) {
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		mouse_button_event(event);
		break;

	case SDL_KEYDOWN:
		key_press_event(event);
		break;

	case SDL_TEXTINPUT:
		text_input_event(event);
		break;
	}
}

void Login_Screen::key_press_event(SDL_Event& event) {
	if (SDL_SCANCODE_BACKSPACE == event.key.keysym.scancode) {
		if (active_textbox == ACTIVE_NICK) {
			user_nick.pop_char();
		} else {
			user_pass.pop_char();
		}
		return;
	}

	if (SDL_SCANCODE_RETURN == event.key.keysym.scancode) {
		for(int t=0;t<200;t++){
		 render_loadscreen();
		 SDL_Delay(10);
		 }
	}

	if (SDL_SCANCODE_TAB == event.key.keysym.scancode) {
		change_active_textbox();
	}
}

void Login_Screen::text_input_event(SDL_Event& event) {
	if (active_textbox == ACTIVE_NICK) {
		user_nick.add_char(event.text.text[0]);
	} else {
		user_pass.add_char(event.text.text[0]);
	}
}

void Login_Screen::mouse_button_event(SDL_Event& event) {

}

void Login_Screen::change_active_textbox() {
	if (active_textbox == ACTIVE_NICK) {
		active_textbox = ACTIVE_PASS;
	} else {
		active_textbox = ACTIVE_NICK;
	}
}
