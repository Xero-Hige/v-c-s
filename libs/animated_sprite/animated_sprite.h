/**
 animatedsprite.h

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
#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include "../sprite/sprite.h"
#include <string>

class Animated_Sprite: public Sprite {

private:
	int actual_frame;
	int max_frames;
	int framerate;

	long time;

	int frame_increment;
	int frame_height;
	int frame_width;

	bool oscillate;

public:
	/**
	 * Dummy
	 */
	Animated_Sprite() {}
	/**
	 * TODO
	 */
	Animated_Sprite(const std::string& file_path, Window& window,
			int image_width, int image_height, int frames);
	/**
	 * TODO
	 */
	Animated_Sprite(SDL_Surface& file_path, Window& window, int image_width,
			int image_height, int frames);
	/**
	 * Dibuja el sprite animado en la ventana correspondiente
	 */
	virtual bool draw(Window& destination_window);
	/**
	 * Dibuja el sprite en la ventana correspondiente
	 * en la posicion indicada por el rectangulo
	 */
	virtual bool draw(Window& destination_window, SDL_Rect& destination_rect);
	/**
	 * Dibuja el sprite en la ventana correspondiente
	 * en la posicion indicada por los puntos
	 */
	virtual bool draw(Window& destination_window, int x_pos, int y_pos);
	/**
	 * Ejecuta el cambio de frame del sprite si corresponde
	 * segun el tiempo transcurrido desde la ultima llamada a
	 * este metodo
	 */
	void animate();
	/**
	 * Setea la cantidad de frames por segundo
	 */
	void set_fps(int fps);
	/**
	 * Activa o desactiva la oscilacion
	 */
	void set_oscillation(bool status);
	/**
	 * Libera la textura asociada al sprite
	 */
	void free();

};

#endif /* ANIMATEDSPRITE_H_ */
