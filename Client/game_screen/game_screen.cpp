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
#include "../game_screen.h"

//FIXME
#define DIMENSION_X 36
#define DIMENSION_Y 37
#define INICIO_X 300
#define INICIO_Y 100

using std::string;
using std::vector;

const string Game_Screen::TITLE = "Level ";
const double Game_Screen::LOADING_ICON_CORRECTION_FACTOR = 2.3;

void Game_Screen::render_loadscreen() {
}

void Game_Screen::key_press_event(SDL_Event& event) {
}

void Game_Screen::text_input_event(SDL_Event& event) {
}

void Game_Screen::mouse_button_event(SDL_Event& event) {
}

void Game_Screen::setup_background() {

	Surface temporal_background = Surface(
			"resources/game_board/backgrounds/Zangoose.jpg");
	temporal_background.set_scaled_dimensions(SCREEN_WIDTH, SCREEN_HEIGHT);

	//TODO: agregar soporte para multiples celdas
	Surface temporal_cell = Surface("resources/game_board/cell/cell_A.png");
	//FIXME
	//temporal_cell.set_scaled_dimensions(DIMENSION_X, DIMENSION_Y);

	vector<vector<int> > schema = backend.get_board_schema();

	for (size_t i = 0; i < schema.size(); i++) {
		for (size_t j = 0; j < schema[i].size(); j++) {
			if (schema[i][j] != 0) {
				int x = INICIO_X + (DIMENSION_X * i);
				int y = INICIO_Y + (DIMENSION_Y * j);
				temporal_background.draw_on(temporal_cell, x, y);
			}
		}
	}

	background = temporal_background.convert_to_sprite(window);

	temporal_background.free();
	temporal_cell.free();
}

void Game_Screen::setup_loadingscreen() {
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

void Game_Screen::setup_sprites() {
	vector<string> pokemon_codes = backend.get_board_pokemon_codes();

	for (int i = 0; i < 5; i++) {
		sprites.push_back(
				Animated_Sprite(
						"resources/game_board/pokemons/" + pokemon_codes[i]
								+ "_button.png", window, 3));
		sprites.back().set_scaled_height(DIMENSION_Y);
		sprites.back().set_scaled_width(DIMENSION_X);
		sprites.back().set_fps(6);

		sprites.push_back(
				Animated_Sprite(
						"resources/game_board/pokemons/" + pokemon_codes[i]
								+ "_minA.png", window, 4));
		sprites.back().set_scaled_height(DIMENSION_Y);
		sprites.back().set_scaled_width(DIMENSION_X);
		sprites.back().set_fps(3);

		sprites.push_back(
				Animated_Sprite(
						"resources/game_board/pokemons/" + pokemon_codes[i]
								+ "_minB.png", window, 4));
		sprites.back().set_scaled_height(DIMENSION_Y);
		sprites.back().set_scaled_width(DIMENSION_X);
		sprites.back().set_fps(3);
	}
}

void Game_Screen::setup_audio() {
	background_music.open_audio();
	background_music.open_music("resources/game_board/background_music/000-Trainer.mp3");
	background_music.play(-1);
}

Game_Screen::Game_Screen(Backend& back) :
		App(), backend(back) {

}

bool Game_Screen::initialize() {
	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setup_background();
	setup_loadingscreen();
	setup_sprites();
	board = backend.get_full_board();
	setup_audio();
	return true;
}

void Game_Screen::handle_event(SDL_Event& event) {
	if (event.type == SDL_QUIT) {
		status = STATUS_ENDED_ERROR;
		return;
	}
}

void Game_Screen::loop() {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].animate();
	}
}

void Game_Screen::render() {
	window.clear();

	background.draw(window);

	for (int i = 0; i < board.size(); i++) {
		int board_size = board[0].size() / 2;
		for (int j = board_size; j < board[0].size(); j++) {
			if (board[i][j] == 0) continue;
			int x = INICIO_X + (DIMENSION_X * i);
			int y = INICIO_Y + (DIMENSION_Y * (j-board_size));

			sprites[board[i][j]-1].draw(window,x,y);
		}
	}

	window.render();
}

void Game_Screen::cleanup() {
}
