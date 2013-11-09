/**
 text_box.h

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
#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include <string>

#include "../text_drawer/text_drawer.h"

class Text_Box {

private:
	int x_pos;
	int y_pos;

	int height;
	int length;

	Sprite text_sprite;
	Text_Drawer drawer;

	bool active;

protected:
	std::string text;
	std::string shown_text;

	size_t max_len;

	bool need_refresh;

private:
	/**
	 * Agrega un caracter al final del texto
	 */
	virtual void add_char(char character);
	/**
	 * Remueve el ultimo caracter del texto
	 */
	virtual void pop_char();

	/**
	 * Maneja los eventos de teclado no alfanumerico
	 */
	void keydown_event(SDL_Event& event);

	/**
	 * Maneja los eventos de teclado alfanumerico
	 */
	void text_input_event(SDL_Event& event);

	/**
	 * Maneja los eventos del click de mouse
	 */
	void mouse_click_event(SDL_Event& event);

public:
	Text_Box();
	/**
	 * //TODO:
	 */
	Text_Box(int max_len, const std::string& font_path, int font_size,
			Window& window);
	virtual ~Text_Box();
	/**
	 * Mueve el textbox hacia las coordenadas x,y pasadas
	 */
	void move(int x_pos, int y_pos);
	/**
	 * Dibuja el textbox sobre la ventana
	 */
	void draw(Window& window);
	/**
	 * Obtiene el texto del cuadro de texto
	 */
	std::string get_text();
	/**
	 * Refresca los datos si se modifico alguno de los atributos,
	 * sino se hace solo durante el draw
	 */
	void refresh(Window& window);

	/**
	 * Setea un texto alternativo que se muestra hasta que se
	 * modifique el texto
	 */
	void set_alternative_text(const std::string& text, Window& window);
	/**
	 * Libera los recursos pedidos por el textbox
	 */
	void free();

	/**
	 * Metodo para manejar los eventos de sdl
	 */
	void handle_event(SDL_Event& event);
};

#endif /* TEXTBOX_H_ */
