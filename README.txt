README:


Göksen Arda Pakkan 6953


The collision detection works as such: update game is wrapped over a (!gameOver) 
check which is false by default. The player(dino) and all the obstacles have a 
square that is not drawn and has the same position and size respectively. 
When the player and any obstacle's square collide the hit sound effect plays and 
the gameOver is set to true which stops the game. That instant all drawings are 
stopped and the text "Press enter to play again" is drwan. Enter key resets everything 
except the high score and sets the gameOver false.

Score simply increases every frame, in the game.cpp update function. 
Highscore is set to the score if its smaller than the score.
Highscore doesnt reset unless the window is closed.

Audio files are simply PlaySoundMulti(sound) calls on conditions, sound files were 
loaded in the game.cpp init function. They play once when called. Raylib's method 
InitAudioDevice() method is called in the game.cpp init function and it's 
deinitalized when window is closed in the deconsturctor of game.cpp using CloseAudioDevice() function.. 
The sound files are also unloaded when the window is closed also in the deconsturctor of game.cpp;