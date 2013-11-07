/**
 clientApp.cpp

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
#include "client_app.h"

using std::vector;

Client_App::Client_App() {
	SDL_Init (SDL_INIT_EVERYTHING);
	TTF_Init();
	running = false;
	apps = vector<App*>();

	apps.push_back(new Login_Screen(backend));
}

Client_App::~Client_App() {
	delete apps[0];
	SDL_Quit();
}

int Client_App::run() {
	if (initialize() == false) {
		return 1;
	}

	SDL_Event Event;

	while (running) {
		while (SDL_PollEvent(&Event)) {
			handle_event(Event);
		}
		loop();
		render();
		SDL_Delay(17); //60fps aprox;
	}

	cleanup();
	return 0;
}

bool Client_App::initialize() {
	running = true;
	apps[0]->initialize();
	return true;
}

void Client_App::handle_event(SDL_Event& event) {
	if (event.type == SDL_QUIT) {
		running = false;

	}
	apps[0]->handle_event(event);
	return;
}

void Client_App::loop() {
	apps[0]->loop();
	return;
}

void Client_App::render() {
	apps[0]->render();
	return;
}

void Client_App::cleanup() {
	apps[0]->cleanup();
}
