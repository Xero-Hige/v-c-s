/**
 window.cpp

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
#include "window.h"
#include <string>

using std::string;

Window::Window(const string& title,int widht,int height,int flags) {
	SDL_CreateWindowAndRenderer(widht, height, flags, &window, &window_render);

	SDL_SetRenderDrawColor(window_render, 0, 0, 0, 255);
	SDL_RenderClear(window_render);
	SDL_RenderPresent(window_render);

	SDL_SetWindowTitle(window,title.c_str());
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	SDL_RenderSetLogicalSize(window_render, widht, height);
}

void Window::clear()
{
	SDL_RenderClear(window_render);
}

void Window::render()
{
	//SDL_RenderClear(window_render);
	SDL_RenderPresent(window_render);
}

SDL_Renderer* Window::get_renderer()
{
	return window_render;
}

bool Window::draw_on(SDL_Texture* source_sprite, SDL_Rect& source_rect, SDL_Rect& dest_rect) {
    SDL_RenderCopy(window_render, source_sprite, &source_rect, &dest_rect);
    //SDL_RenderPresent(window_render);
}
