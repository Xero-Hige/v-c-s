/**
 App.cpp

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

#include "App.h"
#include "Surface.h"
#include "SoundBank.h"

App::App()
{
    Surf_Test = NULL;
    Surf_Back = NULL;
    Surf_Display = NULL;

    Running = true;
}

int App::OnExecute()
{
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

bool App::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(800, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Back = Surface::OnLoad("bg.bmp")) == NULL) {
        return false;
    }

    if((Surf_Test = Surface::OnLoad("octocat.png")) == NULL) {
        return false;
    }

    if((sound = SoundBank::SoundControl.OnLoad("sonido.wav")) == -1) {
        return false;
    }

    return true;
}

void App::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT) {
        Running = false;
    }

    if(Event->type == SDL_MOUSEBUTTONDOWN){
        posx = Event->button.x - 128;
        posy = Event->button.y - 128;

        SoundBank::SoundControl.Play(sound);
    }
}

void App::OnLoop()
{
}

void App::OnRender()
{
    Surface::OnDraw(Surf_Display, Surf_Back, 0, 0);
    Surface::OnDraw(Surf_Display, Surf_Test, posx, posy);

    SDL_Flip(Surf_Display);
}

void App::OnCleanup()
{
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
int main(int argc, char* argv[])
{
    App theApp;

    return theApp.OnExecute();
}

