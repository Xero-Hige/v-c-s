/**
 sprite.h

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
#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#include <string>

#include "../surface/surface.h"

/*
 *
 */
class Sprite : public Surface {

protected:
	int x_pos;
	int y_pos;

public:
	Sprite(){};
	Sprite(const std::string& file_path,int x_pos=0,int y_pos=0);
	void set_transparency(int red,int green,int blue);
	virtual bool draw_over(Surface& destination_surface);
	virtual bool draw_over(Surface& destination_surface,int x_pos,int y_pos);
	void move(int x_pos,int y_pos);
};

#endif /* SPRITE_H_ */
