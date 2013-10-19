/**
 SoundBank.h

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
#ifndef SOUNDBANK_H_
#define SOUNDBANK_H_

#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>

/*
 *
 */
class SoundBank {
public:
	static SoundBank SoundControl;

	std::vector<Mix_Chunk*> SoundList;

public:
	SoundBank();

	int OnLoad(char* File);

	void OnCleanup();

public:
	void Play(int ID);
};

#endif /* SOUNDBANK_H_ */
