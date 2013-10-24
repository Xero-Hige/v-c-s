/**
 window.h

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
#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL.h>
#include <string>

#include <iostream>
/*
 *
 */
class Window {
public: //TODO: Fixear
	SDL_Window* window;
	SDL_Renderer* window_render;

public:
	Window(): window(NULL), window_render(NULL){}
	Window(const std::string& title,int widht,int height,int flags);

	virtual ~Window(){}

	SDL_Renderer* get_renderer();

	void render();
	void clear();
	bool draw_on(SDL_Texture* source_sprite, SDL_Rect& source_rect, SDL_Rect& dest_rect);
};

#endif /* WINDOW_H_ */
