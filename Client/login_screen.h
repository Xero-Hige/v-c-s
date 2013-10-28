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

#define SCREEN_WIDTH	300
#define SCREEN_HEIGHT   100
#define TITLE 		"Login"
#define WINDOW_FLAGS SDL_WINDOW_RESIZABLE

#include "app.h"
#include "../libs/window/window.h"

/*
 *
 */
class Login_Screen: public App {

private:

	Window window;

public:

	/**
	 * Metodo para inicializar la app
	 */
	bool initialize();
	/**
	 * Metodo para manejar los eventos de sdl
	 */
	void handle_event(SDL_Event& event);
	/**
	 * Metodo para ejecutar durante el loop
	 * (actualizacion de estados de la aplicacion)
	 */
	void loop();
	/**
	 * Metodo para ejecutar durante la etapa de
	 * dibujado en pantalla
	 */
	void render();
	/**
	 * Metodo para limpiar el contenido de la app
	 */
	void cleanup();

};

#endif /* LOGINSCREEN_H_ */
