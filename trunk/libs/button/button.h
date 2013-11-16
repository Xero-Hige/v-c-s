/**
 button.h

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
#ifndef BUTTON_H_
#define BUTTON_H_

#include "../sprite/sprite.h"

/**
 * Button (Aka clickeable Sprite)
 */
class Button: public Sprite {

private:
	bool clicked;
	bool active;

	void setup_button();

public:
	Button(){};
	/**
	 * TODO:
	 */
	Button(const std::string& file_path, Window& window);

	/**
	 * TODO:
	 */
	Button(SDL_Surface& surface, Window& window);

	/**
	 * TODO:
	 */
	Button(SDL_Surface& surface, Window& window, int image_width,
			int image_height);

	/**
	 *
	 */
	void handle_event(SDL_Event& event);

	void draw(Window& destination_window);

	void draw(Window& destination_window, SDL_Rect& destination_rect);

	void draw(Window& destination_window, int x_pos, int y_pos);

	/**
	 * Activa o desactiva el boton
	 */
	void set_active(bool active){this->active = active;}
	/**
	 * Setea al boton como clickeado o no
	 */
	void set_clicked(bool active){this->clicked = active;}

	/**
	 * Devuelve si el control esta clickeado
	 */
	bool is_clicked(){return this->clicked;}
};

#endif /* BUTTON_H_ */
