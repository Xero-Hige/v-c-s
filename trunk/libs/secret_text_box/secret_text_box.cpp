/**
 secrettextbox.cpp

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
#include "secret_text_box.h"

#include <algorithm>

using std::string;
using std::min;

SecretTextBox::SecretTextBox(int max_len, const string& font_path,
		int font_size, Window& window) :
				TextBox(max_len, font_path, font_size, window) {
	replace_string = "";
	for (size_t i = 0; i < max_len; i++) {
		replace_string += '*';
	}
}

void SecretTextBox::addChar(char character) {
	text += character;

	need_refresh = (shown_text.size() < max_len);

	if (need_refresh)
		shown_text = replace_string.substr(0, text.size());
}

void SecretTextBox::popChar() {
	if (text == "")
		return;
	text = text.substr(0, text.size() - 1);

	need_refresh = (shown_text.size() > text.size());

	if (need_refresh){
		shown_text = replace_string.substr(0, text.size());
		if (shown_text == "") shown_text = " ";
	}
}
