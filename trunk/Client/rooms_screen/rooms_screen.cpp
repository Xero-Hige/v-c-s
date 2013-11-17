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
#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 384
#define WINDOW_FLAGS SDL_WINDOW_RESIZABLE
#define LOADING_ICON_CORRECTION_FACTOR 2.5

Rooms_Screen::Rooms_Screen(Backend& back) :
backend(back), status(STATUS_RUNNING) {
}

void Rooms_Screen::key_press_event(SDL_Event& event) {
}

void Rooms_Screen::text_input_event(SDL_Event& event) {
}

void Rooms_Screen::mouse_button_event(SDL_Event& event) {
}

void Rooms_Screen::setup_background() {
	background = Sprite("resources/rooms/background.jpg", window);

	background.set_scaled_height(SCREEN_HEIGHT);
	background.set_scaled_width(SCREEN_WIDTH);
}

void Rooms_Screen::setup_textboxes() {
}

void Rooms_Screen::setup_loadingscreen() {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
			32, 0, 0, 0, 255);

	loading_mask = Sprite(*surface, window, SCREEN_WIDTH, SCREEN_HEIGHT);
	loading_mask.set_transparency_level(128);

	loading_icon = Animated_Sprite("resources/general/pika_loading.png", window,
			4);

	loading_icon.scale_with_widht(SCREEN_WIDTH / 4);
	loading_icon.scale_height(LOADING_ICON_CORRECTION_FACTOR);

	loading_icon.set_oscillation(false);
	loading_icon.set_fps(10);
	loading_icon.move(SCREEN_WIDTH - loading_icon.get_scaled_width(),
			SCREEN_HEIGHT - loading_icon.get_scaled_height());
}

void Rooms_Screen::setup_buttons() {
	int x = 0;
	int y = 0;

	next_level_button = Button("resources/rooms/button1.png", window);
	next_level_button.scale_with_height((SCREEN_HEIGHT / 3) - 1);
	next_level_button.move(x, y);

	y += next_level_button.get_scaled_height();
	y += 1; //Solo para que no colicionen entre ellos

	make_room_button = Button("resources/rooms/button2.png", window);
	make_room_button.scale_with_height((SCREEN_HEIGHT / 3) - 1);
	make_room_button.move(x, y);

	y += make_room_button.get_scaled_height();
	y += 1;

	make_custom_room_button = Button("resources/rooms/button3.png", window);
	make_custom_room_button.scale_with_height((SCREEN_HEIGHT / 3) - 1);
	make_custom_room_button.move(x, y);
}

bool Rooms_Screen::initialize() {

	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setup_background();
	setup_textboxes();
	setup_loadingscreen();
	setup_buttons();

	return true;
}

void Rooms_Screen::handle_event(SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) { //FIXME
		next_level_button.handle_event(event);
		make_room_button.handle_event(event);
		make_custom_room_button.handle_event(event);
	}
}

void Rooms_Screen::loop() {
	if (next_level_button.is_clicked()) {
		backend.async_get_room();
		while (!backend.operation_ended() && status == STATUS_RUNNING) {
			render_loadscreen(100);
		}
		status = STATUS_ENDED_OK;
	}
}

void Rooms_Screen::render() {
	window.clear();

	background.draw(window);

	next_level_button.draw(window);
	make_room_button.draw(window);
	make_custom_room_button.draw(window);

	window.render();
}

void Rooms_Screen::cleanup() {
	background.free();

	loading_mask.free();
	loading_icon.free();

	next_level_button.free();
	make_room_button.free();
	make_custom_room_button.free();

	window.free();
}

int Rooms_Screen::get_app_status() {
	return status;
}

void Rooms_Screen::render_loadscreen(int times) {
	for (int i = 0; i < times; i++) {
		SDL_Event event;
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT) {
			status = STATUS_ENDED_ERROR;
			return;
		}

		loading_icon.animate();

		window.clear();

		background.draw(window);

		loading_mask.draw(window);
		loading_icon.draw(window);

		window.render();
		SDL_Delay(10);
	}
}
