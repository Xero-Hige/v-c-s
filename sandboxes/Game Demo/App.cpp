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

App::App() {
	Running = true;
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
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		return false;
	}

	Surf_Display = Window_Surface(592, 359, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	cell = Sprite("res/images/cell.png", 60, 60);
	cell.set_transparency(255, 255, 255);

	background = Surface("res/images/forrest.jpg");

	int x = 100;
	int y = 20;
	int rows = 9;
	int colums = 10;

	for (int i = 0; i < colums; i++) {
		for (int j = 0; j < rows; j++) {

			cell.draw_over(background, x + (36 * i), y + (37 * j));

		}
	}

	a = Animated_Sprite("res/images/001_button.png", 6, 3, 35, 35);
	a.set_transparency(0, 128, 128);

	b = Animated_Sprite("res/images/025_button.png", 6, 3, 35, 35);
	b.set_transparency(0, 128, 128);

	c = Animated_Sprite("res/images/124_button.png", 6, 3, 35, 35);
	c.set_transparency(0, 128, 128);

	d = Animated_Sprite("res/images/228_button.png", 6, 3, 35, 35);
	d.set_transparency(0, 128, 128);

	e = Animated_Sprite("res/images/319_button.png", 6, 3, 35, 35);
	e.set_transparency(0, 128, 128);

	if ((sound = SoundBank::SoundControl.OnLoad("res/sounds/sonido.wav"))
			== -1) {
		return false;
	}

	return true;
}

void App::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	if (Event->type == SDL_MOUSEBUTTONDOWN) {
		SoundBank::SoundControl.Play(sound);
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
	Surf_Display.draw_on(background, 0, 0);

	int x = 100;
	int y = 20;
	int colums = 9;
	int rows = 10;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colums; j++) {
			if (((i * j) + j + i) % 5 == 0) {
				a.draw_over(Surf_Display, x + (36 * i) + 1,
						y + (37 * j) + 1);
			}
			if (((i * j) + j + i) % 5 == 1) {
				b.draw_over(Surf_Display, x + (36 * i) + 1, y + (37 * j) + 1);
			}
			if (((i * j) + j + i) % 5 == 2) {
				c.draw_over(Surf_Display, x + (36 * i) + 1, y + (37 * j) + 1);
			}
			if (((i * j) + j + i) % 5 == 3) {
				d.draw_over(Surf_Display, x + (36 * i) + 1, y + (37 * j) + 1);
			}
			if (((i * j) + j + i) % 5 == 4) {
				e.draw_over(Surf_Display, x + (36 * i) + 1, y + (37 * j) + 1);
			}
		}
	}

	Surf_Display.flip();
}

void App::OnCleanup() {
	background.free();
	cell.free();
	Surf_Display.free();
	a.free();
	b.free();
	c.free();
	d.free();
	e.free();
	SDL_Quit();
}

int main(int argc, char* argv[]) {
	App theApp;

	return theApp.OnExecute();
}

