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

Animated_Sprite::Animated_Sprite(const std::string& file_path, int fps,
		int frames, int frame_height, int frame_width) : Sprite(file_path){
	framerate = 1000/fps;
	max_frames = frames;
	this->frame_height = frame_height;
	this->frame_width = frame_width;
	frame_increment = 1;
	actual_frame = 0;
	oscillate = true;
	time = 0;
}

bool Animated_Sprite::draw_over(Surface& destination_surface) {

	SDL_Rect SrcR;

	SrcR.x = frame_width * actual_frame + 1;
	SrcR.y = 0;
	SrcR.w = frame_width;
	SrcR.h = frame_height;

	destination_surface.draw_on(*this,x_pos,y_pos,&SrcR);

}

bool Animated_Sprite::draw_over(Surface& destination_surface, int x_pos,
		int y_pos) {

	SDL_Rect SrcR;

	SrcR.x = frame_height * actual_frame;
	SrcR.y = 0;
	SrcR.w = frame_width;
	SrcR.h = frame_height;

	destination_surface.draw_on(*this,x_pos,y_pos,&SrcR);
}
