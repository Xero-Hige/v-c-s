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

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_messagebox.h>
#include <cstdlib>
#include <exception>
#include <vector>

using std::string;
using std::exception;

const string levelConfigScreen::TITLE = "Level Config";

levelConfigScreen::levelConfigScreen(LevelBuilder& level) :
		level(level), window(Window()), background(Sprite()), text_box(
				Sprite()), level_name_marker(TextBox()), background_file_marker(
				TextBox()), cell_file_marker(TextBox()), win_points_needed_marker(
				TextBox()), max_players_marker(TextBox()), level_name(
				TextBox()), background_file(TextBox()), cell_file(TextBox()), win_points_needed(
				TextBox()), max_players(TextBox()), add_cell(Button()), next_step(
				Button()) {
}

void levelConfigScreen::setup_markers() {
	int start_position = 10;
	level_name_marker = TextBox(120, "resources/game_editor/font.ttf", 45,
			window);
	level_name_marker.setAlternativeText("Level Name", window);
	level_name_marker.move(10, start_position);

	start_position += text_box.get_scaled_height();
	background_file_marker = TextBox(12, "resources/game_editor/font.ttf", 45,
			window);
	background_file_marker.setAlternativeText("Background", window);
	background_file_marker.move(10, start_position);

	start_position += text_box.get_scaled_height();
	cell_file_marker = TextBox(12, "resources/game_editor/font.ttf", 45,
			window);
	cell_file_marker.setAlternativeText("Cell file", window);
	cell_file_marker.move(10, start_position);

	start_position += text_box.get_scaled_height();
	win_points_needed_marker = TextBox(12, "resources/game_editor/font.ttf", 45,
			window);
	win_points_needed_marker.setAlternativeText("Win points", window);
	win_points_needed_marker.move(10, start_position);

	start_position += text_box.get_scaled_height();
	max_players_marker = TextBox(12, "resources/game_editor/font.ttf", 45,
			window);
	max_players_marker.setAlternativeText("Max Players", window);
	max_players_marker.move(10, start_position);

	start_position += text_box.get_scaled_height();
	columns_marker = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	columns_marker.setAlternativeText("Columns", window);
	columns_marker.move(10, start_position);

	start_position += text_box.get_scaled_height();
	rows_marker = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	rows_marker.setAlternativeText("Rows", window);
	rows_marker.move(10, start_position);
}

void levelConfigScreen::setup_textboxes() {
	int start_position = 10;
	level_name = TextBox(120, "resources/game_editor/font.ttf", 45, window);
	level_name.setAlternativeText(" ", window);
	level_name.move(text_box.get_scaled_width() + 10, start_position);

	start_position += text_box.get_scaled_height();
	background_file = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	background_file.setAlternativeText(" ", window);
	background_file.move(text_box.get_scaled_width() + 10, start_position);

	start_position += text_box.get_scaled_height();
	cell_file = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	cell_file.setAlternativeText(" ", window);
	cell_file.move(text_box.get_scaled_width() + 10, start_position);

	start_position += text_box.get_scaled_height();
	win_points_needed = TextBox(12, "resources/game_editor/font.ttf", 45,
			window);
	win_points_needed.setAlternativeText(" ", window);
	win_points_needed.move(text_box.get_scaled_width() + 10, start_position);

	start_position += text_box.get_scaled_height();
	max_players = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	max_players.setAlternativeText(" ", window);
	max_players.move(text_box.get_scaled_width() + 10, start_position);

	start_position += text_box.get_scaled_height();
	columns = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	columns.setAlternativeText(" ", window);
	columns.move(text_box.get_scaled_width() + 10, start_position);

	start_position += text_box.get_scaled_height();
	rows = TextBox(12, "resources/game_editor/font.ttf", 45, window);
	rows.setAlternativeText(" ", window);
	rows.move(text_box.get_scaled_width() + 10, start_position);
}

bool levelConfigScreen::initialize() {
	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);

	background = Sprite("resources/game_editor/background.jpg", window);
	background.scale_with_widht(SCREEN_WIDTH);

	text_box = Sprite("resources/game_editor/textbox.png", window);

	setup_markers();
	setup_textboxes();
	setupButtons();

	return true;
}

void levelConfigScreen::handleEvent(SDL_Event& event) {
	switch (event.type) {
	case SDL_QUIT:
		status = STATUS_ENDED_ERROR;
		return;
	case SDL_MOUSEBUTTONDOWN:
		mouseButtonEvent(event);
		return;
	case SDL_TEXTINPUT:
		textInputEvent(event);
		break;
	case SDL_KEYDOWN:
		keyPressEvent(event);
		break;
	}
}

void levelConfigScreen::setupButtons() {
	next_step = Button("resources/game_editor/next_button.png", window);
	next_step.scale_with_widht(text_box.get_scaled_width());
	next_step.move(0, SCREEN_HEIGHT - next_step.get_scaled_height());

	add_cell = Button("resources/game_editor/add_button.png", window);
	add_cell.scale_with_height(text_box.get_scaled_height());
	add_cell.move(2 * text_box.get_scaled_width(),
			2 * text_box.get_scaled_height());
}

void levelConfigScreen::textInputEvent(SDL_Event& event) {
	level_name.handleEvent(event);
	background_file.handleEvent(event);
	cell_file.handleEvent(event);
	win_points_needed.handleEvent(event);
	max_players.handleEvent(event);
	columns.handleEvent(event);
	rows.handleEvent(event);
}

void levelConfigScreen::addCell() {
	try {
		string path = "resources/game_board/cell/" + cell_file.getText()
				+ ".png";
		Sprite aux = Sprite(path, window);
		aux.free();

		window.show_message_box(SDL_MESSAGEBOX_INFORMATION, "Agregado",
				"Agregada la celda " + cell_file.getText() + "con exito.");
		cells.push_back(cell_file.getText());
	} catch (exception& e) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"El archivo de celda no es valido");
	}
	add_cell.set_clicked(false);
}

bool levelConfigScreen::check_values() {

	if (level_name.getText() == "") {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"Debe especificar un nombre para el nivel");
		return false;
	}

	level.setName(level_name.getText());

	try {
		string path = "resources/game_board/backgrounds/"
				+ background_file.getText() + ".jpg";
		Sprite aux = Sprite(path, window);
		aux.free();
	} catch (exception& e) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"El archivo de fondo no es valido");
		return false;
	}

	level.setBackgroundFile(background_file.getText());

	int value = atoi(win_points_needed.getText().c_str());
	if (value < 300) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"Debe especificar un puntaje valido (mayor a 300)");
		return false;
	}

	level.setWinPoints(value);

	value = atoi(max_players.getText().c_str());
	if (value > MAX_PLAYERS || value < 2) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"Debe especificar una cantidad de jugadores valida ( 2 a 8 )");
		return false;
	}

	level.setMaxPlayers(value);

	value = atoi(columns.getText().c_str());
	if (value > MAX_BOARD_COLUMNS || value < MIN_BOARD_COLUMNS) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"Debe especificar un numero valido de columnas ( 3 a 30 )");
		return false;
	}

	level.setColumns(value);

	value = atoi(rows.getText().c_str());
	if (value > MAX_BOARD_ROWS || value < MIN_BOARD_ROWS) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"Debe especificar un numero valido de filas ( 3 a 20 )");
		return false;
	}

	level.setRows(value);

	if (cells.size() < 1) {
		window.show_message_box(SDL_MESSAGEBOX_ERROR, "Error",
				"Debe agregar al menos una celda");
		return false;
	}

	level.setCellFiles(cells);

	return true;
}

void levelConfigScreen::mouseButtonEvent(SDL_Event& event) {
	level_name.handleEvent(event);
	background_file.handleEvent(event);
	cell_file.handleEvent(event);
	win_points_needed.handleEvent(event);
	max_players.handleEvent(event);
	columns.handleEvent(event);
	rows.handleEvent(event);

	next_step.handle_event(event);
	add_cell.handle_event(event);

	if (add_cell.is_clicked()) {
		addCell();
	}

	if (next_step.is_clicked()) {
		if (check_values()) {
			status = STATUS_ENDED_OK;
		}
	}
}

void levelConfigScreen::loop() {
}

void levelConfigScreen::render_markers() {
	level_name_marker.draw(window);
	background_file_marker.draw(window);
	cell_file_marker.draw(window);
	win_points_needed_marker.draw(window);
	max_players_marker.draw(window);
	columns_marker.draw(window);
	rows_marker.draw(window);
}

void levelConfigScreen::render_textboxes() {
	level_name.draw(window);
	background_file.draw(window);
	cell_file.draw(window);
	win_points_needed.draw(window);
	max_players.draw(window);
	columns.draw(window);
	rows.draw(window);
}

void levelConfigScreen::draw_buttons() {
	next_step.draw(window);
	add_cell.draw(window);
}

void levelConfigScreen::render() {
	window.clear();

	background.draw(window);
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 7; i++) {
			text_box.move(text_box.get_scaled_width() * j,
					text_box.get_scaled_height() * i);
			text_box.draw(window);
		}
	}

	render_markers();
	render_textboxes();
	draw_buttons();

	window.render();
}

void levelConfigScreen::keyPressEvent(SDL_Event& event) {
	level_name.handleEvent(event);
	background_file.handleEvent(event);
	cell_file.handleEvent(event);
	win_points_needed.handleEvent(event);
	max_players.handleEvent(event);
	columns.handleEvent(event);
	rows.handleEvent(event);
}

void levelConfigScreen::cleanup() {
	window.free();
}
