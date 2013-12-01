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

void LoginScreen::handleEvent(SDL_Event& event) {
	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		mouseButtonEvent(event);
		break;

	case SDL_KEYDOWN:
		keyPressEvent(event);
		break;

	case SDL_TEXTINPUT:
		textInputEvent(event);
		break;
	}
}

void LoginScreen::keyPressEvent(SDL_Event& event) {
	user_nick.handleEvent(event);
	user_pass.handleEvent(event);

	if (SDL_SCANCODE_RETURN == event.key.keysym.scancode) {
		if (user_nick.getText() == "" || user_pass.getText() == "") {
			window.show_message_box(SDL_MESSAGEBOX_ERROR, "Datos Invalidos",
					"Debe especificar un nombre y usuario");
			return;
		}
		if (!backend.connected()) {
			backend.async_connect("192.168.1.1", 8080); //FIXME
			while (!backend.operation_ended()) {
				renderLoadscreen(); //FIXME
				SDL_Delay(10);
			}
			if (backend.operation_error() != "") {
				window.show_message_box(SDL_MESSAGEBOX_INFORMATION, "Error",
						backend.operation_error().c_str());
				return;
			}
		}

		backend.async_log_in(user_nick.getText(), user_pass.getText());
		while (!backend.operation_ended()) {
			renderLoadscreen(); //FIXME
			SDL_Delay(10);
		}
		if (backend.operation_error() != "") {
			window.show_message_box(SDL_MESSAGEBOX_INFORMATION, "Error",
					backend.operation_error().c_str());
			return;
		}
		status = STATUS_ENDED_OK;
	}
}

void LoginScreen::textInputEvent(SDL_Event& event) {
	user_nick.handleEvent(event);
	user_pass.handleEvent(event);
}

void LoginScreen::mouseButtonEvent(SDL_Event& event) {
	user_nick.handleEvent(event);
	user_pass.handleEvent(event);
	//_register.handle_event(event);
}
