/**
 sprite.cpp

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
#include "sprite.h"
#include <SDL_image.h>

#include <iostream>

using std::string;

Sprite::Sprite(const string& file_path, SDL_Renderer* window_render,
		int image_width, int image_height) {

	_texture = NULL;
	SDL_Surface* temporal = NULL;
	if ((temporal = IMG_Load(file_path.c_str())) == NULL) {
		return;
	}

	_texture = SDL_CreateTextureFromSurface(window_render, temporal);

	SDL_FreeSurface(temporal);

	this->x_pos = 0;
	this->y_pos = 0;

	this->image_width = image_width;
	this->image_height = image_height;

	scaled_width = image_width;
	scaled_height = image_height;
}

/*
 void Sprite::set_transparency(int red, int green, int blue) {
 SDL_SetColorKey(_texture, SDL_TRUE | SDL_RLEACCEL,
 SDL_MapRGB(this->_texture->format, red, green, blue));
 }*/

bool Sprite::draw(Window& destination_window) {

	SDL_Rect SrcR;
	SDL_Rect DesR;

	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = image_width;
	SrcR.h = image_height;

	DesR.x = x_pos;
	DesR.y = y_pos;
	DesR.w = scaled_width;
	DesR.h = scaled_height;

	destination_window.draw_on(_texture, SrcR, DesR);

}

bool Sprite::draw(Window& destination_window, SDL_Rect& DesR) {

	SDL_Rect SrcR;

	SrcR.x = 100;
	SrcR.y = 100;
	SrcR.w = 100;
	SrcR.h = 100;

	destination_window.draw_on(_texture, SrcR, DesR);

}

void Sprite::move(int x_pos, int y_pos) {
	this->x_pos = x_pos;
	this->y_pos = y_pos;
}
