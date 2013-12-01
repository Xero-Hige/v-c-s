/**
 level_config_screen.cpp

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
#include "../level_config_screen.h"

using std::string;

const string levelConfigScreen::TITLE = "Level Config";


levelConfigScreen::levelConfigScreen(LevelBuilder& level) :
		level(level), window(Window()), background(Sprite()), text_box(
		Sprite()), level_name_marker(TextBox()), background_file_marker(
		TextBox()), cell_file_marker(TextBox()), win_points_needed_marker(
		TextBox()), max_players_marker(TextBox()), level_name(
		TextBox()), background_file(TextBox()), cell_file(TextBox()),
		win_points_needed(TextBox()), max_players(TextBox()),
		add_cell(Button()), next_step(
				Button()) {
}

bool levelConfigScreen::initialize() {
	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);

	background = Sprite("resources/game_editor/background.jpg",window);
	background.scale_with_widht(SCREEN_WIDTH);

	text_box = Sprite("resources/game_editor/textbox.png",window);

	int start_position = 10;

	level_name_marker = TextBox(120,"resources/game_editor/font.ttf",45,window);
	level_name_marker.setAlternativeText("Level Name",window);
	level_name_marker.move(10,start_position);

	start_position += text_box.get_scaled_height();

	background_file_marker = TextBox(120,"resources/game_editor/font.ttf",45,window);
	background_file_marker.setAlternativeText("Background file",window);
	background_file_marker.move(10,start_position);
/*
	TextBox background_file_marker;
	TextBox cell_file_marker;
	TextBox win_points_needed_marker;
	TextBox max_players_marker;

/*
	TextBox level_name;
	TextBox background_file;
	TextBox cell_file;
	TextBox win_points_needed;
	TextBox max_players;

	Button add_cell;
	Button next_step;*/
	return true;
}

void levelConfigScreen::handleEvent(SDL_Event& event) {
}

void levelConfigScreen::loop() {
}

void levelConfigScreen::render() {
	window.clear();

	background.draw(window);
	text_box.move(0,0);
	text_box.draw(window);
	text_box.move(0,text_box.get_scaled_height());
	text_box.draw(window);
	level_name_marker.draw(window);
	background_file_marker.draw(window);

	window.render();
}

void levelConfigScreen::cleanup() {
}
