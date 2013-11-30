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

#include "../board_screen.h"

#include <stddef.h>
#include <SDL2/SDL_events.h>

#include "../../libs/surface/surface.h"
#include "../level_builder/LevelBuilder.h"

//FIXME
#define DIMENSION_X 36
#define DIMENSION_Y 37
#define INICIO_X 300
#define INICIO_Y 100

using std::string;
using std::vector;

const string BoardScreen::TITLE = "Level ";

void BoardScreen::mouse_button_event(SDL_Event& event) {
	Position pos = grid.get_grid_position(event.button.x, event.button.y);
	if (pos.is_valid()) {
		board_schema[pos[0]][pos[1]] = (board_schema[pos[0]][pos[1]] + 1) % 2;
	}
}

void BoardScreen::setup_background() {

	Surface temporal_background = Surface(
			"resources/game_board/backgrounds/Zangoose.jpg");
	temporal_background.set_scaled_dimensions(SCREEN_WIDTH, SCREEN_HEIGHT);
	background = temporal_background.convert_to_sprite(window);

	temporal_background.free();

	//TODO: agregar soporte para multiples celdas
	cell = Sprite("resources/game_board/cell/cell_A.png", window);

	board_schema = vector<vector<int> >();
	for (size_t i = 0; i < board_columns; i++) {
		board_schema.push_back(vector<int>());
		for (size_t j = 0; j < board_rows; j++) {
			board_schema[i].push_back(EMPTY);
		}
	}
}

BoardScreen::BoardScreen(LevelBuilder& level) :
		App(), level(level) { //FIXME

}

void BoardScreen::setup_board() {
	grid = Screen_Grid(INICIO_X, INICIO_Y, DIMENSION_Y, DIMENSION_X, 30, 20);
}

bool BoardScreen::initialize() {
	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setup_background();
	setup_board();
	return true;
}

void BoardScreen::handle_event(SDL_Event& event) {
	switch (event.type) {
	case SDL_QUIT:
		status = STATUS_ENDED_ERROR;
		return;
	case SDL_MOUSEBUTTONDOWN:
		mouse_button_event(event);
		return;
	}
}

void BoardScreen::loop() {
}

void BoardScreen::render_board() {
	background.draw(window);

	for (int i = 0; i < board_columns; i++) {
		for (int j = board_rows; j < board_rows * 2; j++) {
			if (board_schema[i][j] != 0) {

				int x = INICIO_X + (DIMENSION_X * i);
				int y = INICIO_Y + (DIMENSION_Y * (j - board_rows));

				cell.move(x, y);
				cell.draw(window);
			}
		}
	}
}

void BoardScreen::render() {
	window.clear();

	render_board();

	window.render();
}

void BoardScreen::cleanup() {
}
