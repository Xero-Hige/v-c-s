/**
 level_config_screen.h

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
#ifndef LEVEL_CONFIG_SCREEN_H_
#define LEVEL_CONFIG_SCREEN_H_

#include <SDL2/SDL_video.h>
#include <string>

#include "../libs/button/button.h"
#include "../libs/position/position.h"
#include "../libs/screen_grid/screen_grid.h"
#include "../libs/sprite/sprite.h"
#include "../libs/text_box/text_box.h"
#include "../libs/window/window.h"
#include "app.h"
#include "level_builder/LevelBuilder.h"

class LevelBuilder;

class levelConfigScreen : public App {
private:

	static const std::string TITLE;
	static const int SCREEN_WIDTH = 1600;
	static const int SCREEN_HEIGHT = 900;
	static const int WINDOW_FLAGS = SDL_WINDOW_RESIZABLE;

	static const int max_board_columns = 30;
	static const int max_board_rows = 20;

	static const int min_board_columns = 3;
	static const int min_board_rows = 3;

private:

	LevelBuilder& level;

	Window window;
	Sprite background;
	Sprite text_box;

	TextBox level_name_marker;
	TextBox background_file_marker;
	TextBox cell_file_marker;
	TextBox win_points_needed_marker;
	TextBox max_players_marker;

	TextBox level_name;
	TextBox background_file;
	TextBox cell_file;
	TextBox win_points_needed;
	TextBox max_players;

	Button add_cell;
	Button next_step;


public:
	levelConfigScreen(LevelBuilder& level);

	/**
	 * Metodo para inicializar la app
	 */
	virtual bool initialize();
	/**
	 * Metodo para manejar los eventos de sdl
	 */
	virtual void handleEvent(SDL_Event& event);
	/**
	 * Metodo para ejecutar durante el loop
	 * (actualizacion de estados de la aplicacion)
	 */
	virtual void loop();
	/**
	 * Metodo para ejecutar durante la etapa de
	 * dibujado en pantalla
	 */
	virtual void render();
	/**
	 * Metodo para limpiar el contenido de la app
	 */
	virtual void cleanup();
};

#endif /* LEVEL_CONFIG_SCREEN_H_ */
