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

using std::string;

const string LoginScreen::TITLE = "Login";
const double LoginScreen::LOADING_ICON_CORRECTION_FACTOR = 2.3;

LoginScreen::LoginScreen(Backend& back) :
		App(), backend(back) {
}

void LoginScreen::setupBackground() {
	//TODO: excepciones
	Surface background_temp = Surface("resources/login/background.png");
	Surface textbox_temp = Surface("resources/login/textbox.png");

	int text_box_pos_x = background_temp.get_width() / 2
			- textbox_temp.get_width() / 2;

	int text_box_pos_y = background_temp.get_height()
			/ 2+ textbox_temp.get_height() / 2 + CORRECTION_Y_TEXTBOX;

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

void LoginScreen::setupTextboxes() {
	user_nick = TextBox(14, "resources/login/logfont.ttf", 20, window);
	user_nick.move(X_USER_NICK, Y_USER_NICK);
	user_nick.setAlternativeText("USUARIO", window);

	user_pass = TextBox(14, "resources/login/logfont.ttf", 20, window);
	user_pass.move(X_USER_PASS, Y_USER_PASS);
	user_pass.setAlternativeText("PASSWORD", window);

	secret_user_pass = SecretTextBox(14, "resources/login/logfont.ttf", 20,
			window);
	secret_user_pass.move(X_USER_PASS, Y_USER_PASS);
	secret_user_pass.setAlternativeText("PASSWORD", window);

}

void LoginScreen::setupLoadingScreen() {
	SDL_Surface* surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,
			32, 0, 0, 0, 255);

	loading_mask = Sprite(*surface, window, SCREEN_WIDTH, SCREEN_HEIGHT);
	loading_mask.set_transparency_level(128);

	SDL_FreeSurface(surface);

	loading_icon = Animated_Sprite("resources/general/pika_loading.png", window,
			4);

	loading_icon.scale_with_widht(SCREEN_WIDTH / 4);
	loading_icon.scale_height(LOADING_ICON_CORRECTION_FACTOR);

	loading_icon.set_oscillation(false);
	loading_icon.set_fps(10);
	loading_icon.move(SCREEN_WIDTH - loading_icon.get_scaled_width(),
			SCREEN_HEIGHT - loading_icon.get_scaled_height());
}

void LoginScreen::setupMugshots() {
	mugshot_left = Sprite("resources/login/left_mug.png", window);
	mugshot_right = Sprite("resources/login/right_mug.png", window);
	double scale_left = double(SCREEN_HEIGHT)
			/ mugshot_left.get_scaled_height();
	double scale_right = double(SCREEN_HEIGHT)
			/ mugshot_right.get_scaled_height();
	mugshot_left.scale(scale_left);
	mugshot_right.scale(scale_right);
	mugshot_left.scale(1.2);
	mugshot_right.scale(1.2);
	mugshot_left.move(-(mugshot_left.get_scaled_width() / 2), 0);
	mugshot_right.move(SCREEN_WIDTH - (mugshot_right.get_scaled_width() / 2),
			0);
}

void LoginScreen::setupAudio() {
	background_music.open_audio();
	background_music.open_music("resources/login/title_music.mp3");
	background_music.play(-1);
}

void LoginScreen::setupButtons() {
	_register = Button("resources/login/login-register.png", window);
	_register.move(SCREEN_WIDTH - _register.get_scaled_width(),
			SCREEN_HEIGHT - _register.get_scaled_height());
	registrer_action = false;
}

bool LoginScreen::initialize() {

	window = Window(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_FLAGS);
	//TODO: excepciones

	setupBackground();
	setupTextboxes();
	setupLoadingScreen();
	setupMugshots();
	setupAudio();
	setupButtons();
	return true;
}

void LoginScreen::loop() {
	user_nick.refresh(window);
	user_pass.refresh(window);
}

void LoginScreen::render() {
	window.clear();

	background.draw(window);
	mugshot_left.draw(window);
	mugshot_right.draw(window);
	user_nick.draw(window);
	if (registrer_action) {
		user_pass.draw(window);
	} else {
		secret_user_pass.draw(window);
	}
	_register.set_clicked(registrer_action);
	_register.draw(window);

	window.render();

}

void LoginScreen::cleanup() {
	background.free();

	user_nick.free();
	user_pass.free();
	secret_user_pass.free();

	mugshot_left.free();
	mugshot_right.free();

	loading_mask.free();
	loading_icon.free();

	background_music.halt_audio();
	background_music.free();
	background_music.close_audio();

	window.free();
}
