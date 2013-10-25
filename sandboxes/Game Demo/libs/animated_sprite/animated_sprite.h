/**
 animatedsprite.h

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
#ifndef ANIMATEDSPRITE_H_
#define ANIMATEDSPRITE_H_

#include "../sprite/sprite.h"
#include <string>

/*
 *
 */
class Animated_Sprite : public Sprite {

private:
	int actual_frame;
	int max_frames;
	int framerate;
    long time;
    int frame_increment;
    int frame_height;
    int frame_width;
    bool oscillate;


public:
    Animated_Sprite(){}
    Animated_Sprite(const std::string& file_path, SDL_Renderer& window_render,
			int image_width, int image_height, int frames);
    Animated_Sprite(SDL_Surface& file_path, SDL_Renderer& window_render,
				int image_width, int image_height, int frames);
	virtual bool draw(Window& destination_window);
	virtual bool draw(Window& destination_window, SDL_Rect& DesR);
	virtual bool draw(Window& destination_window,int x_pos,int y_pos);
    void animate();
    void set_fps(int fps);

};

#endif /* ANIMATEDSPRITE_H_ */
