/**
 Surface.cpp

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

#include "Surface.h"
#include <SDL_image.h>

Surface::Surface() {
}

SDL_Surface* Surface::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL) {
        return NULL;
    }

    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

    return Surf_Return;
}

bool Surface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}
