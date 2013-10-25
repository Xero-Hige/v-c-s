/**
 App.cpp

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

#include "App.h"
#include "SoundBank.h"

#include <stdlib.h>     /* srand, rand */

#define COLUMNS 24
#define ROWS 18

#define XINIT 100
#define YINIT 52

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

App::App() {
	Running = true;

	int button_1x = -1;
	int button_1y = -1;

	int button_2x = -1;
	int button_2y = -1;
	this->window = Window("Pokemon: Make It Real", WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_RESIZABLE);
}

int App::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	SDL_Event Event;

	while (Running) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

bool App::OnInit() {

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		return false;
	}

	Surface back_temp = Surface("res/images/lab_tutorial.jpg");
	Surface cell_temp = Surface("res/images/cell.png");
	cell_temp.set_transparency(255, 255, 255);

	//hover_cell = Sprite("res/images/hover_cell.png");
	//hover_cell.set_transparency(255, 255, 255);

	//background = Surface("res/images/forrest.jpg");

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {

			back_temp.draw_on(cell_temp, XINIT + (36 * i), YINIT + (37 * j));

		}
	}

	background = back_temp.convert_to_sprite(*window.window_render, 1280, 720);
	background.set_scaled_width(WINDOW_WIDTH);
	background.set_scaled_height(WINDOW_HEIGHT);

	Surface temp = Surface("res/images/001_button.png");
	temp.set_transparency(0, 128, 128);
	a = temp.convert_to_animated_sprite(*window.window_render, 35, 36, 3);
	temp.free();

	temp = Surface("res/images/025_button.png");
	temp.set_transparency(0, 128, 128);
	b = temp.convert_to_animated_sprite(*window.window_render, 35, 36, 3);
	temp.free();

	temp = Surface("res/images/124_button.png");
	temp.set_transparency(0, 128, 128);
	c = temp.convert_to_animated_sprite(*window.window_render, 35, 36, 3);
	temp.free();

	temp = Surface("res/images/228_button.png");
	temp.set_transparency(0, 128, 128);
	d = temp.convert_to_animated_sprite(*window.window_render, 35, 36, 3);
	temp.free();

	temp = Surface("res/images/319_button.png");
	temp.set_transparency(0, 128, 128);
	e = temp.convert_to_animated_sprite(*window.window_render, 35, 36, 3);
	temp.free();

	if ((sound = SoundBank::SoundControl.OnLoad("res/sounds/sonido.wav"))
			== -1) {
		return false;
	}

	table = new int*[COLUMNS]();

	for (int i = 0; i < COLUMNS; i++) {
		table[i] = new int[ROWS]();
		for (int j = 0; j < ROWS; j++) {
			table[i][j] = rand() % 5;
		}
	}

	a.set_fps(6);
	b.set_fps(6);
	c.set_fps(6);
	d.set_fps(6);
	e.set_fps(6);

	back_temp.free();
	cell_temp.free();
	return true;
}

void App::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	if (Event->type == SDL_MOUSEBUTTONDOWN) {
		SoundBank::SoundControl.Play(sound);

		int x = Event->button.x;
		int y = Event->button.y;

		int max_x = XINIT + 36 * COLUMNS;
		int max_y = YINIT + 37 * ROWS;

		if ((x > XINIT) && (x < max_x) && (y > YINIT) && (y < max_y)) {
			int columna = (x - XINIT) / 36;
			int fila = (y - YINIT) / 37;

			if (button_1x < 0) {
				button_1x = columna;
				button_1y = fila;
			} else {
				button_2x = columna;
				button_2y = fila;

				int aux = table[button_1x][button_1y];
				table[button_1x][button_1y] = table[button_2x][button_2y];
				table[button_2x][button_2y] = aux;

				button_1x = -100;
				button_1y = -100;
			}
		}
	}
}

void App::OnLoop() {
	a.animate();
	b.animate();
	c.animate();
	d.animate();
	e.animate();
}

void App::OnRender() {
	window.clear();
	background.draw(window);

	SDL_Rect dest;

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {

			if (i == button_1x && j == button_1y) {
				//				hover_cell.draw_over(Surf_Display, XINIT + (36 * i), YINIT + (37 * j));
			}

			if (table[i][j] == 0) {
				a.draw(window, XINIT + (36 * i) + 1, YINIT + (37 * j) + 1);
			}
			if (table[i][j] == 1) {
				b.draw(window, XINIT + (36 * i) + 1, YINIT + (37 * j) + 1);
			}
			if (table[i][j] == 2) {
				c.draw(window, XINIT + (36 * i) + 1, YINIT + (37 * j) + 1);
			}
			if (table[i][j] == 3) {
				d.draw(window, XINIT + (36 * i) + 1, YINIT + (37 * j) + 1);
			}
			if (table[i][j] == 4) {
				e.draw(window, XINIT + (36 * i) + 1, YINIT + (37 * j) + 1);
			}
		}
	}

	window.render();
}

void App::OnCleanup() {
	//background.free();
	//cell.free();
	//Surf_Display.free();
	//a.free();
	//b.free();
	//c.free();
	//d.free();
	//e.free();
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	App theApp;

	return theApp.OnExecute();
}

