/**
 App.h

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

#ifndef APP_H_
#define APP_H_

#include <SDL.h>
#include "libs/surface/surface.h"
#include "libs/window/window.h"
#include "libs/sprite/sprite.h"
#include "libs/animated_sprite/animated_sprite.h"


class App
{

private:
    bool    Running;
    Window          window;
    Sprite   		background;
    Sprite    		cell;
    Sprite    		hover_cell;


    Animated_Sprite a;
    Animated_Sprite b;
    Animated_Sprite c;
    Animated_Sprite d;
    Animated_Sprite e;

    Animated_Sprite A;
    Animated_Sprite B;
    Animated_Sprite C;

    int** table;

    int button_1x = -100;
    int button_1y = -100;

    int button_2x;
    int button_2y;

    int sound;

public:
    App();

    int OnExecute();

public:

    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();

    void OnCleanup();

};

#endif /* APP_H_ */
