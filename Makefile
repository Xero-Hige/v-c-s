#Project Builder
#General
CC = gcc
CPPFLAGS = -Wall -Wextra -g -pedantic 
CPPLDFLAGS = -lm -lstdc++

all: run-client

#Graphic libs builder

SDL_CPPFLAGS = $(CPPFLAGS) `sdl2-config --cflags`

SDL_LDFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf $(CPPLDFLAGS)

GRAPHIC_LIBS = surface.o sprite.o animated_sprite.o button.o window.o text_drawer.o text_box.o secret_text_box.o

surface.o: libs/surface/surface.h libs/surface/surface.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/surface/surface.cpp
	
sprite.o: libs/sprite/sprite.h libs/sprite/sprite.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/sprite/sprite.cpp

animated_sprite.o: libs/animated_sprite/animated_sprite.h libs/animated_sprite/animated_sprite.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/animated_sprite/animated_sprite.cpp

button.o: libs/button/button.h libs/button/button.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/button/button.cpp

window.o: libs/window/window.h libs/window/window.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/window/window.cpp
	
text_drawer.o: libs/text_drawer/text_drawer.h libs/text_drawer/text_drawer.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/text_drawer/text_drawer.cpp
	
text_box.o: libs/text_box/text_box.h libs/text_box/text_box.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/text_box/text_box.cpp
	
secret_text_box.o: libs/secret_text_box/secret_text_box.h libs/secret_text_box/secret_text_box.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/secret_text_box/secret_text_box.cpp
	
#Sound libs builder

SOUND_LIBS = music.o

music.o: libs/music/music.h libs/music/music.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/music/music.cpp

#Thread libs builder

THREAD_LDFLAGS = 

THREAD_LIBS = Thread.o Mutex.o

Thread.o:

Mutex.o:

#Sockets libs builder 

SOCKET_LIBS = Socket.o

#Messages libs builder

MESSAGES_LIBS = MsgInterpreter.o

#Protocol libs builder

COMUMINICATION_PROTOCOL_LIBS = HMAC.o BigEndianProtocol.o

HMAC.o:

BigEndianProtocol.o:

#Client

CLIENT_OBJ = $(GRAPHIC_LIBS) $(SOUND_LIBS) login_screen.o client_app.o rooms_screen.o game_screen.o backend.o #server_connector.o

CLIENT_NAME = game-client

login_screen.o: Client/login_screen/login_screen.cpp Client/login_screen/login_screen_events.cpp Client/login_screen/login_screen_loading.cpp Client/login_screen.h Client/app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/login_screen/login_screen_events.cpp Client/login_screen/login_screen_loading.cpp Client/login_screen/login_screen.cpp

rooms_screen.o: Client/rooms_screen/rooms_screen.cpp Client/rooms_screen.h Client/app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/rooms_screen/rooms_screen.cpp
	
game_screen.o: Client/game_screen/game_screen.cpp Client/game_screen.h Client/app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/game_screen/game_screen.cpp

backend.o: Client/backend/backend.cpp Client/backend/backend.h
	$(CC) $(SDL_CPPFLAGS) -c Client/backend/backend.cpp
	
server_connector.o: Client/server_connector/server_connector.cpp Client/server_connector/server_connector.h
	$(CC) $(SDL_CPPFLAGS) -c Client/server_connector/server_connector.cpp

client_app.o: Client/client_app.cpp Client/client_app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/client_app.cpp

client: Client/client.cpp $(CLIENT_OBJ)
	$(CC) $(SDL_CPPFLAGS) $(CLIENT_OBJ) Client/client.cpp -o $(CLIENT_NAME) $(SDL_LDFLAGS)
		
#Cleanup
clean:
	rm *.o *.save $(CLIENT_NAME)
	
#Run
run-client: client
	./$(CLIENT_NAME)
