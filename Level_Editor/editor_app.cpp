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

#include "editor_app.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

#include "board_distribution_screen.h"
#include "level_builder/LevelBuilder.h"

using std::vector;

Editor_App::Editor_App() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	running = false;
	apps = vector<App*>();

	apps.push_back(new BoardScreen(level));
	apps.push_back(new BoardDistributionScreen(level));


	actual_app = 0;
}

Editor_App::~Editor_App() {
    apps.clear();
	SDL_Quit();
}

void Editor_App::change_app() {
	if (apps[actual_app]->get_app_status() != App::STATUS_RUNNING) {
		if (apps[actual_app]->get_app_status() != App::STATUS_ENDED_OK) {
			running = false;
			return;
		}
		switch (actual_app) {
		default:
			apps[actual_app]->cleanup();
			actual_app++;
			apps[actual_app]->initialize();
			return;
		}
	}
}

int Editor_App::run() {
	if (initialize() == false) {
		return 1;
	}
	SDL_Event Event;

	while (running) {
		change_app();
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

bool Editor_App::initialize() {
	running = true;
	apps[0]->initialize();
	return true;
}

void Editor_App::handle_event(SDL_Event& event) {
	apps[actual_app]->handleEvent(event);
	if (event.type == SDL_QUIT) {
		running = false;
	}
	return;
}

void Editor_App::loop() {
	apps[actual_app]->loop();
	return;
}

void Editor_App::render() {
	apps[actual_app]->render();
	return;
}

void Editor_App::cleanup() {
	apps[actual_app]->cleanup();
}
