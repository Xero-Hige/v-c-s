/**
 app.h

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
#ifndef APP_H_
#define APP_H_

#include <SDL2/SDL.h>

class App {

public:

	static const int STATUS_RUNNING = 0;
	static const int STATUS_ENDED_OK = 1;
	static const int STATUS_ENDED_ERROR = 2;

protected:
	int status;

public:
	App() :
			status(STATUS_RUNNING) {
	}
	;

	virtual ~App() {
	}
	;

	/**
	 * Metodo para inicializar la app
	 */
	virtual bool initialize()=0;
	/**
	 * Metodo para manejar los eventos de sdl
	 */
	virtual void handleEvent(SDL_Event& event)=0;
	/**
	 * Metodo para ejecutar durante el loop
	 * (actualizacion de estados de la aplicacion)
	 */
	virtual void loop()=0;
	/**
	 * Metodo para ejecutar durante la etapa de
	 * dibujado en pantalla
	 */
	virtual void render()=0;
	/**
	 * Metodo para limpiar el contenido de la app
	 */
	virtual void cleanup()=0;
	/**
	 * Obtiene el estado actual:
	 * -STATUS_RUNNING
	 * -STATUS_ENDED_OK
	 * -STATUS_ENDED_ERROR
	 */
	int get_app_status() {
		return status;
	}
};

#endif /* APP_H_ */
