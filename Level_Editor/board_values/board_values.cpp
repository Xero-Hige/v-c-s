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

#include "../board_values.h"

#include <stddef.h>
#include <SDL2/SDL_events.h>
#include <iostream>

#include "../../libs/surface/surface.h"

//#include "../../libs/window/window.h"
//#include "../level_builder/LevelBuilder.h"

//FIXME
#define DIMENSION_X 36
#define DIMENSION_Y 37
#define INICIO_X 300
#define INICIO_Y 100

using std::string;
using std::vector;

const string BoardValues::TITLE = "Level ";

void BoardValues::mouseButtonEvent(SDL_Event& event) {
	Position pos = grid.getGridPosition(event.button.x, event.button.y);
	if (pos.is_valid()) {
		if (board_schema[pos[0]][pos[1]] == 0)
			return; //no hay nada
		selected_board[pos[0]][pos[1]] = (selected_board[pos[0]][pos[1]] + 1) % 2;
	}

	next_step.handle_event(event);
	if (next_step.is_clicked()) {
		render();
		level.setBoardSchema(board_schema);
		status = STATUS_ENDED_OK;
	}

	apply.handle_event(event);
	if (next_step.is_clicked()) {
		render();
		//APPLY val
	}
}

void BoardValues::setupBackground() {

	Surface temporal_background = Surface(
			"resources/game_board/backgrounds/"+level.getBackgroundFile()+".jpg");
	temporal_background.set_scaled_dimensions(SCREEN_WIDTH, SCREEN_HEIGHT);
	background = temporal_background.convert_to_sprite(window);

	temporal_background.free();
}

BoardValues::BoardValues(LevelBuilder& level) :
		App(), level(level), window(Window()), background(Sprite()),grid(ScreenGrid()) { //FIXME

}

void BoardValues::setupBoard() {
	grid = ScreenGrid(INICIO_X, INICIO_Y, DIMENSION_Y, DIMENSION_X, level.getColumns(), level.getRows());

	vector<string> cell_files = level.getCellFiles();
	for (size_t i = 0; i < cell_files.size(); i++) {
		cells.push_back(
				Sprite("resources/game_board/cell/" + cell_files[i] + ".png",
						window));
	}
	board_schema = level.getBoardSchema();

	for (size_t i = 0;i<board_schema.size();i++)
	{
		selected_board.push_back(vector<int>());
		for(size_t j=0;j<board_schema[i].size();j++)
		{
			selected_board[i].push_back(0);
		}
	}
}

bool BoardValues::initialize() {
	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setupBackground();
	setupBoard();
	setupButtons();

	return true;
}

void BoardValues::handleEvent(SDL_Event& event) {
	switch (event.type) {
	case SDL_QUIT:
		status = STATUS_ENDED_ERROR;
		return;
	case SDL_MOUSEBUTTONDOWN:
		mouseButtonEvent(event);
		return;
	}
}

void BoardValues::loop() {
}

void BoardValues::renderBoard() {
	background.draw(window);

	for (int i = 0; i < level.getColumns(); i++) {
		for (int j = 0; j < level.getRows(); j++) {
			int x = INICIO_X + (DIMENSION_X * i);
			int y = INICIO_Y + (DIMENSION_Y * j);

			int cell = board_schema[i][j];
			if (cell > 0) {
				cell--; //Corregido para que vaya de 0 a longitud-1

				cells[cell].move(x, y);
				cells[cell].draw(window);
			}
			if (selected_board[i][j] == 1)
			{
				hover_cell.move(x, y);
				hover_cell.draw(window);
			}
		}
	}
}

void BoardValues::setupButtons() {
	next_step = Button("resources/game_editor/next_button.png", window);
	next_step.scale_with_widht(INICIO_X);
	next_step.move(0, SCREEN_HEIGHT / 2);

	apply = Button("resources/game_editor/add_button.png", window);
	apply.scale_with_widht(INICIO_X);
	apply.move(0, SCREEN_HEIGHT - apply.get_scaled_height());

}

void BoardValues::render() {
	window.clear();

	renderBoard();

	next_step.draw(window);
	apply.draw(window);

	window.render();
}

void BoardValues::setup_sprites() {
	SDL_Surface* temp_surface = SDL_CreateRGBSurface(0,DIMENSION_X, DIMENSION_Y,
	32, 0, 0, 0, 255);
	hover_cell = Sprite(*temp_surface,window);
	hover_cell.set_transparency_level(64);
	SDL_FreeSurface(temp_surface);
}

void BoardValues::cleanup() {
}
