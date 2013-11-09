/**
 login_screen.h

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
#ifndef LOGINSCREEN_H_
#define LOGINSCREEN_H_

#define SCREEN_WIDTH	600
#define SCREEN_HEIGHT   300
#define TITLE 		"Login"
#define WINDOW_FLAGS 0//SDL_WINDOW_RESIZABLE

#include <string>

#include "app.h"
#include "backend/backend.h"
#include "../libs/window/window.h"
#include "../libs/animated_sprite/animated_sprite.h"
#include "../libs/surface/surface.h"
#include "../libs/text_box/text_box.h"
#include "../libs/secret_text_box/secret_text_box.h"
#include "../libs/music/music.h"


class Login_Screen: public App {

private:

	Backend& backend;

	Window window;
	Sprite background;

	Text_Box user_nick;
	Secret_Text_Box user_pass;

	Sprite mugshot_left;
	Sprite mugshot_right;

	//Loading_screen
	Sprite loading_mask;
	Animated_Sprite loading_icon;

	Music background_music;

	int status;

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
	 * Inicializa los textboxes
	 */
	void setup_textboxes();
	/**
	 * Inicializa la pantalla de carga
	 */
	void setup_loadingscreen();
	/**
	 * Inicializa los mugshots
	 */
	void setup_mugshots();
	/**
	 * Inicializa el audio de la ventana
	 */
	void setup_audio();


public:

	/**
	 * Constructor que recibe un Backend
	 */
	Login_Screen(Backend& back);

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
	/**
	 *
	 */
	virtual int get_app_status();

};

#endif /* LOGINSCREEN_H_ */
