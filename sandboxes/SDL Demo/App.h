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

class App
{

private:
    bool    Running;
    SDL_Surface* Surf_Display;
    SDL_Surface*    Surf_Back;
    SDL_Surface*    Surf_Test;

    int posx = 0;
    int posy = 0;

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
