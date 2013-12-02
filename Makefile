#Project Builder
#General
CC = gcc
CPPFLAGS = -Wall -Wextra -g -pedantic
CPPLDFLAGS = -lm -lstdc++ -lcrypto -lssl -lpthread

all: client editor

#Graphic libs builder

SDL_CPPFLAGS = $(CPPFLAGS) `sdl2-config --cflags`

SDL_LDFLAGS = `sdl2-config --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf $(CPPLDFLAGS)

GRAPHIC_LIBS = $(POSITION) surface.o sprite.o animated_sprite.o button.o window.o text_drawer.o text_box.o secret_text_box.o screen_grid.o

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
	
screen_grid.o: libs/screen_grid/screen_grid.h libs/screen_grid/screen_grid.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/screen_grid/screen_grid.cpp
	
#Sound libs builder

SOUND_LIBS = music.o

music.o: libs/music/music.h libs/music/music.cpp
	$(CC) $(SDL_CPPFLAGS) -c libs/music/music.cpp

#Thread libs builder

THREAD_LDFLAGS = 

THREAD_LIBS = Thread.o Mutex.o

Thread.o: libs/wrappers/Thread.h libs/wrappers/Thread.cpp
		$(CC) $(SDL_CPPFLAGS) -c libs/wrappers/Thread.cpp

Mutex.o: libs/wrappers/Mutex.h libs/wrappers/Mutex.cpp
		$(CC) $(SDL_CPPFLAGS) -c libs/wrappers/Mutex.cpp

#Sockets libs builder 

SOCKET_LIBS = Socket.o

Socket.o: libs/wrappers/Socket.h libs/wrappers/Socket.cpp
	$(CC) $(CPPFLAGS) -c libs/wrappers/Socket.cpp

#Messages libs builder

MESSAGES_LIBS = MsgInterpreter.o

MsgInterpreter.o: libs/messages/MsgInterpreter.h libs/messages/MsgInterpreter.cpp
				$(CC) $(CPPFLAGS) -c libs/messages/MsgInterpreter.cpp

#Protocol libs builder

COMMUNICATION_PROTOCOL_LIBS = HMAC.o BigEndianProtocol.o FormattedSocket.o 

FormattedSocket.o: Socket.o libs/communication_protocol/FormattedSocket.h libs/communication_protocol/FormattedSocket.cpp
		$(CC) $(CPPFLAGS) -c libs/communication_protocol/FormattedSocket.cpp

HMAC.o: libs/communication_protocol/HMAC.h libs/communication_protocol/HMAC.cpp
		$(CC) $(CPPFLAGS) -c libs/communication_protocol/HMAC.cpp

BigEndianProtocol.o: libs/communication_protocol/BigEndianProtocol.h libs/communication_protocol/BigEndianProtocol.cpp
		$(CC) $(CPPFLAGS) -c libs/communication_protocol/BigEndianProtocol.cpp

#Game Messages

GAME_MESSAGES_LIBS = json_serializer.o message_builder.o game_message_builder.o combination_effects_factory.o json_deserializer.o message_reader.o game_message_reader.o    

json_serializer.o: libs/game_messages/json_serializer.h libs/game_messages/json_serializer.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/json_serializer.cpp

message_builder.o: libs/game_messages/message_builder.h libs/game_messages/message_builder.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/message_builder.cpp

game_message_builder.o: libs/game_messages/game_message_builder.h libs/game_messages/game_message_builder.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/game_message_builder.cpp

combination_effects_factory.o: libs/game_messages/combination_effects_factory.h libs/game_messages/combination_effects_factory.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/combination_effects_factory.cpp

json_deserializer.o: libs/game_messages/json_deserializer.h libs/game_messages/json_deserializer.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/json_deserializer.cpp

message_reader.o: libs/game_messages/message_reader.h libs/game_messages/message_reader.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/message_reader.cpp

game_message_reader.o: libs/game_messages/game_message_reader.h libs/game_messages/game_message_reader.cpp
		$(CC) $(CPPFLAGS) -c libs/game_messages/game_message_reader.cpp

#Position

POSITION = position.o

position.o: libs/position/position.h libs/position/position.cpp
	$(CC) $(CPPFLAGS) -c libs/position/position.cpp
	
#Logic boards builder

BOARDS_LIBS = product.o tile.o board.o product_generator.o refiller.o replacements_generator.o

product.o: libs/boards/product.h libs/boards/product.cpp
	$(CC) $(CPPFLAGS) -c libs/boards/product.cpp
	
tile.o: libs/boards/tile.h libs/boards/tile.cpp
	$(CC) $(CPPFLAGS) -c libs/boards/tile.cpp
	
board.o: libs/boards/board.h libs/boards/board.cpp
	$(CC) $(CPPFLAGS) -c libs/boards/board.cpp

product_generator.o: libs/boards/product_generator.h libs/boards/product_generator.cpp
	$(CC) $(CPPFLAGS) -c libs/boards/product_generator.cpp	

refiller.o: libs/boards/refiller.h libs/boards/refiller.cpp
	$(CC) $(CPPFLAGS) -c libs/boards/refiller.cpp
	
replacements_generator.o: libs/boards/replacements_generator.h libs/boards/replacements_generator.cpp
	$(CC) $(CPPFLAGS) -c libs/boards/replacements_generator.cpp

#Checkers builder

CHECKERS_LIBS = physical_checker.o combination_checker.o

physical_checker.o: libs/checkers/physical_checker.h libs/checkers/physical_checker.cpp
	$(CC) $(CPPFLAGS) -c libs/checkers/physical_checker.cpp

combination_checker.o: libs/checkers/combination_checker.h libs/checkers/combination_checker.cpp
	$(CC) $(CPPFLAGS) -c libs/checkers/combination_checker.cpp

#Level reader builder

level_reader.o: libs/level_reader/level_reader.h libs/level_reader/level_reader.cpp libs/boards/tile.h
	$(CC) $(CPPFLAGS) -c libs/level_reader/level_reader.cpp
	
#Combiner 

combiner.o: libs/combiner/combiner.h libs/combiner/combiner.cpp
	$(CC) $(CPPFLAGS) -c libs/combiner/combiner.cpp

#Combination effects

COMBINATION_EFFECTS_LIBS = combination_effect.o change_product_effect.o take_out_product_effect.o take_out_column_effect.o take_out_row_effect.o clean_board_effect.o

combination_effect.o: libs/combination_effects/combination_effect.h libs/combination_effects/combination_effect.cpp
	$(CC) $(CPPFLAGS) -c libs/combination_effects/combination_effect.cpp
	
change_product_effect.o: libs/combination_effects/change_product_effect.h libs/combination_effects/change_product_effect.cpp
	$(CC) $(CPPFLAGS) -c libs/combination_effects/change_product_effect.cpp
	
clean_board_effect.o: libs/combination_effects/clean_board_effect.h libs/combination_effects/clean_board_effect.cpp
	$(CC) $(CPPFLAGS) -c libs/combination_effects/clean_board_effect.cpp
	
take_out_product_effect.o: libs/combination_effects/take_out_product_effect.h libs/combination_effects/take_out_product_effect.cpp
	$(CC) $(CPPFLAGS) -c libs/combination_effects/take_out_product_effect.cpp
	
take_out_row_effect.o: libs/combination_effects/take_out_row_effect.h libs/combination_effects/take_out_row_effect.cpp
	$(CC) $(CPPFLAGS) -c libs/combination_effects/take_out_row_effect.cpp
	
take_out_column_effect.o: libs/combination_effects/take_out_column_effect.h libs/combination_effects/take_out_column_effect.cpp
	$(CC) $(CPPFLAGS) -c libs/combination_effects/take_out_column_effect.cpp

#Score Tracker

score_tracker.o: libs/score_tracker/score_tracker.h libs/score_tracker/score_tracker.cpp
	$(CC) $(CPPFLAGS) -c libs/score_tracker/score_tracker.cpp

#Client

CLIENT_EXTERN = $(GRAPHIC_LIBS) $(SOUND_LIBS) $(BOARDS_LIBS) $(CHECKERS_LIBS) $(SOCKET_LIBS) $(THREAD_LIBS) $(COMMUNICATION_PROTOCOL_LIBS) $(MESSAGES_LIBS) $(COMBINATION_EFFECTS_LIBS) $(GAME_MESSAGES_LIBS) score_tracker.o combiner.o
#hay que sacar el combiner.o, lo agregué para probar

CLIENT_OBJ = $(CLIENT_EXTERN) level_reader.o login_screen.o client_app.o rooms_screen.o game_screen.o server_connector.o ClientMsgInterpreter.o Authenticator.o backend.o screen_sprite_animator.o ServerListener.o

CLIENT_NAME = game-client

login_screen.o: Client/login_screen/login_screen.cpp Client/login_screen/login_screen_events.cpp Client/login_screen/login_screen_loading.cpp Client/login_screen.h Client/app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/login_screen/login_screen_events.cpp Client/login_screen/login_screen_loading.cpp Client/login_screen/login_screen.cpp

rooms_screen.o: Client/rooms_screen/rooms_screen.cpp Client/rooms_screen.h Client/app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/rooms_screen/rooms_screen.cpp
	
screen_sprite_animator.o: Client/screen_sprite_animator/screen_sprite_animator.cpp Client/screen_sprite_animator/screen_sprite_animator.h
	$(CC) $(SDL_CPPFLAGS) -c Client/screen_sprite_animator/screen_sprite_animator.cpp
	
game_screen.o: Client/game_screen/game_screen.cpp Client/game_screen.h Client/app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/game_screen/game_screen.cpp

backend.o: Client/backend/backend.cpp Client/backend/backend.h
	$(CC) $(SDL_CPPFLAGS) -c Client/backend/backend.cpp
	
ClientMsgInterpreter.o: Client/server_communication/ClientMsgInterpreter.h Client/server_communication/ClientMsgInterpreter.cpp
	$(CC) $(CPPFLAGS) -c Client/server_communication/ClientMsgInterpreter.cpp

Authenticator.o: Client/server_communication/Authenticator.h Client/server_communication/Authenticator.cpp
		$(CC) $(SDL_CPPFLAGS) -c Client/server_communication/Authenticator.cpp
	

server_connector.o: Client/server_connector/server_connector.cpp Client/server_connector/server_connector.h
	$(CC) $(SDL_CPPFLAGS) -c Client/server_connector/server_connector.cpp
	
ServerListener.o: Client/server_communication/ServerListener.h Client/server_communication/ServerListener.cpp
	$(CC) $(SDL_CPPFLAGS) -c Client/server_communication/ServerListener.cpp

client_app.o: Client/client_app.cpp Client/client_app.h
	$(CC) $(SDL_CPPFLAGS) -c Client/client_app.cpp

client: Client/client.cpp $(CLIENT_OBJ)
	$(CC) $(SDL_CPPFLAGS) $(CLIENT_OBJ) Client/client.cpp -o $(CLIENT_NAME) $(SDL_LDFLAGS) -ljsoncpp
		
#Editor

EDITOR_EXTERN = $(GRAPHIC_LIBS)

EDITOR_OBJ = $(EDITOR_EXTERN) editor_app.o board_screen.o board_distribution_screen.o level_config_screen.o LevelBuilder.o

EDITOR_NAME = game-editor

board_screen.o: Level_Editor/board_screen/board_screen.cpp Level_Editor/board_screen.h
	$(CC) $(SDL_CPPFLAGS) -c Level_Editor/board_screen/board_screen.cpp

board_distribution_screen.o: Level_Editor/board_distribution_screen/board_distribution_screen.cpp Level_Editor/board_distribution_screen.h
	$(CC) $(SDL_CPPFLAGS) -c Level_Editor/board_distribution_screen/board_distribution_screen.cpp
	
LevelBuilder.o: Level_Editor/level_builder/LevelBuilder.cpp Level_Editor/level_builder/LevelBuilder.h
	$(CC) $(SDL_CPPFLAGS) -c Level_Editor/level_builder/LevelBuilder.cpp
	
level_config_screen.o: Level_Editor/level_config_screen/level_config_screen.cpp Level_Editor/level_config_screen.h
	$(CC) $(SDL_CPPFLAGS) -c Level_Editor/level_config_screen/level_config_screen.cpp

editor_app.o: Level_Editor/editor_app.cpp Level_Editor/editor_app.h
	$(CC) $(SDL_CPPFLAGS) -c Level_Editor/editor_app.cpp

editor: Level_Editor/editor.cpp $(EDITOR_OBJ)
	$(CC) $(SDL_CPPFLAGS) $(EDITOR_OBJ) Level_Editor/editor.cpp -o $(EDITOR_NAME) $(SDL_LDFLAGS) -ljsoncpp


#Cleanup
clean:
	rm *.o $(CLIENT_NAME) $(EDITOR_NAME)
	
#Run
run-client: client
	./$(CLIENT_NAME)
	
#Run
run-editor: editor
	./$(EDITOR_NAME)
