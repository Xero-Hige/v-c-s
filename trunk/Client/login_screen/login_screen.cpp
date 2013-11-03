/**
 login_screen.cpp

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
#include "../login_screen.h"
#include "login_screen_events.cpp"
#include "login_screen_loading.cpp"

#define CORRECTION_Y_TEXTBOX 19
#define CORRECTION_Y_SECOND_TEXTBOX -5

#define X_USER_NICK 214
#define Y_USER_NICK 202

#define X_USER_PASS 214
#define Y_USER_PASS 242

#define LOADING_ICON_WIDHT 140

using std::string;

void Login_Screen::setup_background() {
	//TODO: excepciones
	Surface background_temp = Surface("resources/login/background.png");
	Surface textbox_temp = Surface("resources/login/textbox.png");

	int text_box_pos_x = background_temp.get_width() / 2
			- textbox_temp.get_width() / 2;

	int text_box_pos_y = background_temp.get_height()
					/ 2 + textbox_temp.get_height() / 2 + CORRECTION_Y_TEXTBOX;

	background_temp.draw_on(textbox_temp, text_box_pos_x, text_box_pos_y);
	background_temp.draw_on(textbox_temp, text_box_pos_x,
			text_box_pos_y
			+ textbox_temp.get_height() + CORRECTION_Y_SECOND_TEXTBOX);

	background = background_temp.convert_to_sprite(window,
			background_temp.get_width(), background_temp.get_width());

	background_temp.free();
	textbox_temp.free();

	background.set_scaled_height(SCREEN_HEIGHT);
	background.set_scaled_width(SCREEN_WIDTH);
}

void Login_Screen::setup_textboxes() {
	user_nick = Text_Box(14, "resources/login/logfont.ttf", 20, window);
	user_nick.move(X_USER_NICK, Y_USER_NICK);
	user_nick.set_alternative_text("USUARIO", window);

	user_pass = Text_Box(14, "resources/login/logfont.ttf", 20, window);
	user_pass.move(X_USER_PASS, Y_USER_PASS);
	user_pass.set_alternative_text("PASSWORD", window);

	active_textbox = ACTIVE_NICK;
}

void Login_Screen::setup_loadingscreen() {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
			32, 0, 0, 0, 255);

	loading_mask = Sprite(*surface, window, SCREEN_WIDTH, SCREEN_HEIGHT);
	loading_mask.set_transparency_level(128);

	loading_icon = Animated_Sprite("resources/general/pika_loading.png", window, 4);

	double loading_height = LOADING_ICON_WIDHT
			* loading_icon.get_scaled_height()
			/ loading_icon.get_scaled_width();

	loading_icon.set_scaled_height(loading_height);
	loading_icon.set_scaled_width(LOADING_ICON_WIDHT);
	loading_icon.set_oscillation(false);
	loading_icon.set_fps(10);
	loading_icon.move(SCREEN_WIDTH - LOADING_ICON_WIDHT,
			SCREEN_HEIGHT - loading_height);
}

bool Login_Screen::initialize() {

	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setup_background();
	setup_textboxes();
	setup_loadingscreen();
	mugshot_left = Sprite("resources/login/left_mug.png",window);
	mugshot_right = Sprite("resources/login/right_mug.png",window);

	double scale_left = double(SCREEN_HEIGHT)/mugshot_left.get_scaled_height();
	double scale_right = double(SCREEN_HEIGHT)/mugshot_right.get_scaled_height();

	mugshot_left.scale(scale_left);
	mugshot_right.scale(scale_right);

	mugshot_left.scale(1.2d);
	mugshot_right.scale(1.2d);

	mugshot_left.move(-(mugshot_left.get_scaled_width()/2),0);
	mugshot_right.move(SCREEN_WIDTH -(mugshot_right.get_scaled_width()/2),0);
	return true;
}

void Login_Screen::loop() {
	user_nick.refresh(window);
	user_pass.refresh(window);
}

void Login_Screen::render() {
	window.clear();

	background.draw(window);
	mugshot_left.draw(window);
	mugshot_right.draw(window);
	user_nick.draw(window);
	user_pass.draw(window);

	window.render();

}

void Login_Screen::cleanup() {
	window.free();
	background.free();

	user_nick.free();
	user_pass.free();
	hover_text.free();

	mugshot_left.free();
	mugshot_right.free();

	loading_mask.free();
	loading_icon.free();

}

