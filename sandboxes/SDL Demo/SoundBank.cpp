/**
 SoundBank.cpp

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
#include "SoundBank.h"

SoundBank SoundBank::SoundControl;

//==============================================================================
SoundBank::SoundBank() {
}

//------------------------------------------------------------------------------
int SoundBank::OnLoad(char* File) {
    Mix_Chunk* TempSound = NULL;

    if((TempSound = Mix_LoadWAV(File)) == NULL) {
        return -1;
    }

    SoundList.push_back(TempSound);

    return (SoundList.size() - 1);
}

//------------------------------------------------------------------------------
void SoundBank::OnCleanup() {
    for(int i = 0;i < SoundList.size();i++) {
        Mix_FreeChunk(SoundList[i]);
    }

    SoundList.clear();
}

//==============================================================================
void SoundBank::Play(int ID) {
    if(ID < 0 || ID >= SoundList.size()) return;
    if(SoundList[ID] == NULL) return;

    Mix_PlayChannel(-1, SoundList[ID], 0);
}
