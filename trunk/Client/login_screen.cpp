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

bool Login_Screen::initialize() {
	window = Window(TITLE,SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_FLAGS);
	//TODO: excepciones
}

void Login_Screen::handle_event(SDL_Event& event) {
}

void Login_Screen::loop() {
}

void Login_Screen::render() {
	window.clear();
	window.render();
}

void Login_Screen::cleanup() {
}
