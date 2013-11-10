/**
 rooms_screen.cpp

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
#include "../rooms_screen.h"

#define TITLE "Lobby"
#define SCREEN_WIDTH 1360
#define SCREEN_HEIGHT 768
#define WINDOW_FLAGS SDL_WINDOW_RESIZABLE

Rooms_Screen::Rooms_Screen(Backend& back): backend(back), status(STATUS_RUNNING){}

void Rooms_Screen::render_loadscreen() {
}

void Rooms_Screen::key_press_event(SDL_Event& event) {
}

void Rooms_Screen::text_input_event(SDL_Event& event) {
}

void Rooms_Screen::mouse_button_event(SDL_Event& event) {
}

void Rooms_Screen::setup_background() {
	background = Sprite("resources/rooms/background.jpg",window);

	background.set_scaled_height(SCREEN_HEIGHT);
	background.set_scaled_width(SCREEN_WIDTH);
}

void Rooms_Screen::setup_textboxes() {
}

void Rooms_Screen::setup_loadingscreen() {
}

bool Rooms_Screen::initialize() {

	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setup_background();
	setup_textboxes();
	setup_loadingscreen();
	return true;
}

void Rooms_Screen::handle_event(SDL_Event& event) {
}

void Rooms_Screen::loop() {
}

void Rooms_Screen::render() {
	window.clear();

	background.draw(window);

	window.render();
}

void Rooms_Screen::cleanup() {
}

int Rooms_Screen::get_app_status() {
	return status;
}
