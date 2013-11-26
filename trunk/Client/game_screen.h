/**
 games_creen.h

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

#include "../libs/animated_sprite/animated_sprite.h"
#include "../libs/button/button.h"
#include "../libs/music/music.h"
#include "../libs/screen_grid/screen_grid.h"
#include "../libs/surface/surface.h"
#include "../libs/window/window.h"
#include "app.h"
#include "backend/backend.h"
#include "screen_sprite_animator/screen_sprite_animator.h"

class Backend;

class Game_Screen: public App {

	static const std::string TITLE;
	static const int SCREEN_WIDTH = 1600;
	static const int SCREEN_HEIGHT = 900;
	static const int WINDOW_FLAGS = SDL_WINDOW_RESIZABLE;
	static const double LOADING_ICON_CORRECTION_FACTOR;

private:

	Backend& backend;

	Window window;
	Sprite background;
	Sprite over_mask;

	//Loading_screen
	Sprite loading_mask;
	Animated_Sprite loading_icon;

	Music background_music;

	std::vector<Animated_Sprite> sprites;
	std::vector<Screen_Sprite_Animator> animations;
	std::vector<std::vector<int> > board;

	Position actual_cell;

	Screen_Grid grid;

private:
	/**
	 * Dibuja la pantalla de carga
	 */
	void render_loadscreen();

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
	void mouse_button_event(SDL_Event& event);

	/**
	 * Inicializa el fondo
	 */
	void setup_background();
	/**
	 * Inicializa la pantalla de carga
	 */
	void setup_loadingscreen();
	/**
	 * Inicializa los mugshots
	 */
	void setup_sprites();
	/**
	 * Inicializa el audio de la ventana
	 */
	void setup_audio();
	void render_board();
	void setup_board();
	void animate_swap();

public:

	/**
	 * Constructor que recibe un Backend
	 */
	Game_Screen(Backend& back);

	/**
	 * Metodo para inicializar la app
	 */
	virtual bool initialize();
	/**
	 * Metodo para manejar los eventos de sdl
	 */
	virtual void handle_event(SDL_Event& event);
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
