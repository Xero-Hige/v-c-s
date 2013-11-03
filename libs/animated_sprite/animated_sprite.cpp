/**
 animatedsprite.cpp

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
#include "animated_sprite.h"

using std::string;

void Animated_Sprite::animate() {
	if (time + framerate > SDL_GetTicks()) {
		return;
	}

	time = SDL_GetTicks();

	if (oscillate) {
		if (frame_increment > 0) {
			if (actual_frame >= max_frames - 1) {
				frame_increment = -frame_increment;
			}
		} else {
			if (actual_frame <= 0) {
				frame_increment = -frame_increment;
			}
		}
	} else {
		if (actual_frame >= max_frames - 1) {
			actual_frame = 0;
		}
	}

	actual_frame += frame_increment;

}

Animated_Sprite::Animated_Sprite(const string& file_path, Window& window,int frames) :
				Sprite(file_path, window) {

	// cada frame esta 1/frames Seg
	framerate = 1000 / frames;
	max_frames = frames;
	frame_height = image_height/frames;
	frame_width = image_width/frames;
	frame_increment = 1;
	actual_frame = 0;
	oscillate = true;
	time = 0;
}

Animated_Sprite::Animated_Sprite(SDL_Surface& surface, Window& window,
		int image_width, int image_height, int frames) :
				Sprite(surface, window, image_width, image_height) {

	// cada frame esta 1/frames Seg
	framerate = 1000 / frames;
	max_frames = frames;
	frame_height = image_height;
	frame_width = image_width;
	frame_increment = 1;
	actual_frame = 0;
	oscillate = true;
	time = 0;
}

void Animated_Sprite::draw(Window& destination_window) {
	SDL_Rect source_rect;
	SDL_Rect destination_rect;

	source_rect.x = frame_width * actual_frame;
	source_rect.y = 0;
	source_rect.w = frame_width;
	source_rect.h = frame_height;

	destination_rect.x = x_pos;
	destination_rect.y = y_pos;
	destination_rect.w = scaled_width;
	destination_rect.h = scaled_height;

	destination_window.draw_on(*_texture, source_rect, destination_rect);

}

void Animated_Sprite::draw(Window& destination_window,
		SDL_Rect& destination_rect) {

	SDL_Rect source_rect;

	source_rect.x = frame_width * actual_frame;
	source_rect.y = 0;
	source_rect.w = frame_width;
	source_rect.h = frame_height;

	destination_window.draw_on(*_texture, source_rect, destination_rect);
}

void Animated_Sprite::draw(Window& destination_window, int x_pos, int y_pos) {
	SDL_Rect source_rect;
	SDL_Rect destination_rect;

	source_rect.x = frame_width * actual_frame;
	source_rect.y = 0;
	source_rect.w = frame_width;
	source_rect.h = frame_height;

	destination_rect.x = x_pos;
	destination_rect.y = y_pos;
	destination_rect.w = scaled_width;
	destination_rect.h = scaled_height;

	destination_window.draw_on(*_texture, source_rect, destination_rect);
}

void Animated_Sprite::set_fps(int fps) {
	framerate = 1000 / fps;
}

void Animated_Sprite::set_oscillation(bool status) {
	oscillate = status;
}
