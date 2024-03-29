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

#include <string>

#include "app.h"
#include "backend/backend.h"
#include "../libs/window/window.h"
#include "../libs/animated_sprite/animated_sprite.h"
#include "../libs/surface/surface.h"
#include "../libs/text_box/text_box.h"
#include "../libs/secret_text_box/secret_text_box.h"
#include "../libs/music/music.h"
#include "../libs/button/button.h"

class LoginScreen: public App {

private:

	static const double LOADING_ICON_CORRECTION_FACTOR;
	static const int SCREEN_HEIGHT = 300;
	static const int SCREEN_WIDTH = 600;
	static const int WINDOW_FLAGS = 0;
	static const size_t TEXTBOX_LENGHT = 14;
	static const std::string TITLE;

private:

	bool registrer_action;

	Backend& backend;

	Window window;
	Sprite background;

	TextBox user_nick;
	TextBox user_pass;
	SecretTextBox secret_user_pass;

	Sprite mugshot_left;
	Sprite mugshot_right;

	//Loading_screen
	Sprite loading_mask;
	Animated_Sprite loading_icon;

	Music background_music;

	Button _register;

private:
	/**
	 * Dibuja la pantalla de carga
	 */
	void renderLoadscreen();

	/**
	 * Maneja los eventos de teclas
	 */
	void keyPressEvent(SDL_Event& event);
	/**
	 * Maneja los eventos de texto (teclas de caracteres)
	 */
	void textInputEvent(SDL_Event& event);
	/**
	 * Maneja los eventos de los botones del mouse
	 */
	void mouseButtonEvent(SDL_Event& event);

	/**
	 * Inicializa el fondo
	 */
	void setupBackground();
	/**
	 * Inicializa los textboxes
	 */
	void setupTextboxes();
	/**
	 * Inicializa la pantalla de carga
	 */
	void setupLoadingScreen();
	/**
	 * Inicializa los mugshots
	 */
	void setupMugshots();
	/**
	 * Inicializa el audio de la ventana
	 */
	void setupAudio();
	void setupButtons();

public:

	/**
	 * Constructor que recibe un Backend
	 */
	LoginScreen(Backend& back);

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

#endif /* LOGINSCREEN_H_ */
