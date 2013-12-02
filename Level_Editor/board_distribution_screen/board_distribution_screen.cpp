/**
 gamescreen.cpp

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

#include "../board_distribution_screen.h"

#include <stddef.h>
#include <SDL2/SDL_events.h>
#include <iostream>
//#include <string>
//#include <vector>

//#include "../../libs/position/position.h"
//#include "../../libs/screen_grid/screen_grid.h"
//#include "../../libs/sprite/sprite.h"
#include "../../libs/surface/surface.h"
//#include "../../libs/window/window.h"
//#include "../app.h"
//#include "../level_builder/LevelBuilder.h"

//FIXME
#define DIMENSION_X 36
#define DIMENSION_Y 37
#define INICIO_X 300
#define INICIO_Y 100

using std::string;
using std::vector;

const string BoardDistributionScreen::TITLE = "Level ";

void BoardDistributionScreen::mouseButtonEvent(SDL_Event& event) {
	Position pos = grid.getGridPosition(event.button.x, event.button.y);
	if (pos.is_valid()) {
		if (board_schema[pos[0]][pos[1]] == 0)
			return; //no hay nada
		board_schema[pos[0]][pos[1]] = (board_schema[pos[0]][pos[1]] + 1) % cells.size();
		if (board_schema[pos[0]][pos[1]] == 0)
			board_schema[pos[0]][pos[1]] = 1;
	}
}

void BoardDistributionScreen::setupBackground() {

	Surface temporal_background = Surface(
			"resources/game_board/backgrounds/"+level.getBackgroundFile()+".jpg");
	temporal_background.set_scaled_dimensions(SCREEN_WIDTH, SCREEN_HEIGHT);
	background = temporal_background.convert_to_sprite(window);

	temporal_background.free();
}

BoardDistributionScreen::BoardDistributionScreen(LevelBuilder& level) :
		App(), level(level), window(Window()), background(Sprite()),grid(ScreenGrid()) { //FIXME

}

void BoardDistributionScreen::setupBoard() {
	grid = ScreenGrid(INICIO_X, INICIO_Y, DIMENSION_Y, DIMENSION_X, level.getColumns(), level.getRows());

	vector<string> cell_files = level.getCellFiles();
	for (size_t i = 0; i < cell_files.size(); i++) {
		cells.push_back(
				Sprite("resources/game_board/cell/" + cell_files[i] + ".png",
						window));
	}
	board_schema = level.getBoardSchema();
}

bool BoardDistributionScreen::initialize() {
	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setupBackground();
	setupBoard();
	return true;
}

void BoardDistributionScreen::handleEvent(SDL_Event& event) {
	switch (event.type) {
	case SDL_QUIT:
		status = STATUS_ENDED_ERROR;
		return;
	case SDL_MOUSEBUTTONDOWN:
		mouseButtonEvent(event);
		return;
	}
}

void BoardDistributionScreen::loop() {
}

void BoardDistributionScreen::renderBoard() {
	background.draw(window);

	for (int i = 0; i < level.getColumns(); i++) {
		for (int j = 0; j < level.getRows(); j++) {
			int cell = board_schema[i][j];
			if (cell > 0) {
				cell--; //Corregido para que vaya de 0 a longitud-1

				int x = INICIO_X + (DIMENSION_X * i);
				int y = INICIO_Y + (DIMENSION_Y * j);
				std::cout << cell << std::endl;
				cells[cell].move(x, y);
				cells[cell].draw(window);
			}
		}
	}
}

void BoardDistributionScreen::render() {
	window.clear();

	renderBoard();

	window.render();
}

void BoardDistributionScreen::cleanup() {
}
