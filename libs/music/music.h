/**
 music.h

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
#ifndef MUSIC_H_
#define MUSIC_H_

#include <SDL.h>
#include <SDL_mixer.h>

#include <string>

class Music {
public:
	/**
	 * Abre el dispositivo de salida de audio
	 */
	static void open_audio(int audio_rate=22050,Uint16 audio_format=AUDIO_S16,int audio_channels=2,int audio_buffers=4096);
	/**
	 * Cierra el dispositivo de salida de audio
	 */
	static void close_audio();
	/**
	 * Detiene todas las reproducciones en curso
	 */
	static void halt_audio();

private:
	Mix_Music* music;

public:
	Music();
	/**
	 * Abre el archivo de audio indicado en el path
	 */
	void open_music(const std::string& path);
	/**
	 * Reproduce el audio abierto. "loops" indica el numero
	 * de reproducciones continuas, por defecto es 0 (una sola)
	 * y para infinitas es -1
	 */
	void play(int loops=0);
	/**
	 * Libera los recursos pedidos
	 */
	void free();
};

#endif /* MUSIC_H_ */
