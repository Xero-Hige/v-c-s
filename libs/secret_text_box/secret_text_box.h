/**
 secret_text_box.h

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
#ifndef SECRETTEXTBOX_H_
#define SECRETTEXTBOX_H_

#include "../text_box/text_box.h"

/*
 *
 */
class Secret_Text_Box: public Text_Box {
private:
	std::string replace_string;

public:
	Secret_Text_Box(){}

	Secret_Text_Box(int max_len, const std::string& font_path, int font_size,
			Window& window);

	/**
	 * Agrega un caracter al final del texto
	 */
	virtual void add_char(char character);
	/**
	 * Remueve el ultimo caracter del texto
	 */
	virtual void pop_char();
};

#endif /* SECRETTEXTBOX_H_ */
