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
    if(time + framerate > SDL_GetTicks()) {
        return;
    }

    time = SDL_GetTicks();

    if(oscillate) {
        if(frame_increment > 0) {
            if(actual_frame >= max_frames - 1) {
                frame_increment = -frame_increment;
            }
        }else{
            if(actual_frame <= 0) {
            	frame_increment = -frame_increment;
            }
        }
    }else{
        if(actual_frame >= max_frames - 1) {
        	actual_frame = 0;
        }
    }

    actual_frame += frame_increment;

}

Animated_Sprite::Animated_Sprite(const string& file_path, SDL_Renderer& window_render,
		int image_width, int image_height, int frames) : Sprite(file_path,window_render,image_width,image_height){

	framerate = 1000/frames;
	max_frames = frames;
	this->frame_height = image_height;
	this->frame_width = image_width;
	frame_increment = 1;
	actual_frame = 0;
	oscillate = true;
	time = 0;
}

Animated_Sprite::Animated_Sprite(SDL_Surface& surface, SDL_Renderer& window_render,
		int image_width, int image_height, int frames) : Sprite(surface,window_render,image_width,image_height){

	framerate = 1000/frames;
	max_frames = frames;
	this->frame_height = image_height;
	this->frame_width = image_width;
	frame_increment = 1;
	actual_frame = 0;
	oscillate = true;
	time = 0;
}

bool Animated_Sprite::draw(Window& destination_window){
	SDL_Rect SrcR;
	SDL_Rect DesR;

	SrcR.x = frame_width * actual_frame + 1;
	SrcR.y = 0;
	SrcR.w = frame_width;
	SrcR.h = frame_height;

	DesR.x = x_pos;
	DesR.y = y_pos;
	DesR.w = scaled_width;
	DesR.h = scaled_height;

	destination_window.draw_on(*_texture, SrcR, DesR);

}

bool Animated_Sprite::draw(Window& destination_window, SDL_Rect& DesR) {

	SDL_Rect SrcR;

	SrcR.x = frame_width * actual_frame + 1;
	SrcR.y = 0;
	SrcR.w = frame_width;
	SrcR.h = frame_height;

	destination_window.draw_on(*_texture, SrcR, DesR);
}
