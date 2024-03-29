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
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	running = false;
	apps = vector<App*>();

	apps.push_back(new LoginScreen(backend));
	apps.push_back(new Rooms_Screen(backend));
	apps.push_back(new GameScreen(backend));

	actual_app = 0;
}

Client_App::~Client_App() {
    apps.clear();  //TODO Modifiqué esto para que sea menos negro =P pero me agarró la duda (Bruno)
//	delete apps[0];
//	delete apps[1];
//	delete apps[2];

	SDL_Quit();
}

void Client_App::change_app() {
	if (apps[actual_app]->get_app_status() != STATUS_RUNNING) {
		if (apps[actual_app]->get_app_status() != STATUS_ENDED_OK) {
			running = false;
			return;
		}
		switch (actual_app) {

		case 2: //Tablero
			apps[actual_app]->cleanup();
			actual_app--;
			apps[actual_app]->initialize();
			return;

		default:
			apps[actual_app]->cleanup();
			actual_app++;
			apps[actual_app]->initialize();
			return;
		}
	}
}

int Client_App::run() {
	if (initialize() == false) {
		return 1;
	}
	SDL_Event Event;

	while (running) {
		change_app();
		while (SDL_PollEvent(&Event)) {
			handleEvent(Event);
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

void Client_App::handleEvent(SDL_Event& event) {
	apps[actual_app]->handleEvent(event);
	if (event.type == SDL_QUIT) {
		running = false;
	}
	return;
}

void Client_App::loop() {
	apps[actual_app]->loop();
	return;
}

void Client_App::render() {
	apps[actual_app]->render();
	return;
}

void Client_App::cleanup() {
	apps[actual_app]->cleanup();
}
