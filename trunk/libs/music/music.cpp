/**
 Music.cpp

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
#include "music.h"

bool Music::open_audio(int audio_rate, Uint16 audio_format, int audio_channels,
		int audio_buffers) {
	int result = Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers);
	if (result != 0)
	{
		//TODO: exception
	}
}

void Music::close_audio() {
	Mix_CloseAudio();
}

void Music::halt_audio() {
	Mix_HaltMusic();
}

Music::Music() {
	music = NULL;
}

void Music::open_music(const std::string& path) {
	music = Mix_LoadMUS(path.c_str());
	if (!music)
	{
		//TODO: exception
	}
}

void Music::play(int loops) {
	if (!music) return;
	Mix_PlayMusic(music, loops);
}

void Music::free() {
	Mix_FreeMusic(music);
}
