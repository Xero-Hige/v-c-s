/**
 board_creen.h

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
#ifndef GAMES_CREEN_H_
#define GAMES_CREEN_H_

#include <SDL2/SDL_video.h>
#include <string>
#include <vector>

#include "level_builder/LevelBuilder.h"
#include "../libs/position/position.h"
#include "../libs/screen_grid/screen_grid.h"
#include "../libs/sprite/sprite.h"
#include "../libs/window/window.h"

#include "app.h"

class BoardScreen: public App {

	static const std::string TITLE;
	static const int SCREEN_WIDTH = 1600;
	static const int SCREEN_HEIGHT = 900;
	static const int WINDOW_FLAGS = SDL_WINDOW_RESIZABLE;

	static const int board_columns = 30;
	static const int board_rows = 20;

private:

	LevelBuilder& level;

	Window window;
	Sprite background;

	Sprite cell;

	std::vector<std::vector<int> > board_schema;

	Screen_Grid grid;

private:
	/**
	 * Dibuja la pantalla de carga
	 */
	void renderLoadscreen();

	/**
	 * Maneja los eventos de teclas
	 */
	void key_press_event(SDL_Event& event);
	/**
	 * Maneja los eventos de texto (teclas de caracteres)
	 */
	void text_input_event(SDL_Event& event);
	/**
	 * Maneja los eventos de los botones del mouse
	 */
	void mouseButtonEvent(SDL_Event& event);

	/**
	 * Inicializa el fondo
	 */
	void setupBackground();
	/**
	 * Inicializa la pantalla de carga
	 */
	void setup_loadingscreen();
	/**
	 * Inicializa los mugshots
	 */
	void setup_sprites();
	void setup_audio();
	void renderBoard();
	void setupBoard();

public:

	/**
	 * Constructor que recibe un Backend
	 */
	BoardScreen(LevelBuilder& level);

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

#endif /* GAMES_CREEN_H_ */
