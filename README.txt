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


Fabian Larsson

Made the Dino (Player) and Background code + art

The player is initialized in the Game class and is given a reference to the screenwidth and height which is used for determining ground and jumpheight
The Player Jumps when the game class registers space or uparrow if it is on the ground and not ducking.
The Player ducks or falls quicker if downarrow or the 'S' key is pressed which changes the sprite to half it's standing size.
The Game class also calls the Dino class if the duck button is released to trigger the switch to normal sprites.
The player keeps track of what state it is in for determining direction of y directional movement and what sprites it is switching between.
The player has GetHeight and GetPosition/Size functions for collisions data collection.
When the player is deleted it unloads the sprites used for animating

The BackgroundArt class draws and updates positions of both the road and clouds in the game.
The Road is instantiated with a buffer length exceeding the width of the screen and randomly decides between 3 sprites
Clouds are instantiated as 3 clouds that moves slower than obstacles and road to show some distance variation
When a cloud or roadpiece moves out of the screen on its left side a new piece is added and the old one is removed



Otto Roberts Olšteins

Made the obstacles (code and art)

The obstacle is one object, initialized in the game class, which moves across the screen and is then moved back. 

The obstacle's Spawn function randomly picks between the 6 possible obstacles
(birds flying at 3 different heights, and 3 different types of cacti), gives the obstacle's hitbox rectangle the corresponding size and Y position, and
moves the obstacle to the right side of the screen - this function is called once when the game begins, and then from the obstacle's Update method when
it reaches the left side of the screen.

The Update function moves the obstacle and its hitbox, and checks if it has reached the left side.

The Draw function, in addition to drawing the obstacle's sprite, also handles animating the bird's wings (if the obstacle is a bird) by changing the sprite
used every 10 frames (this value can be changed by changing the AnimationFrequency variable in obstacle.h)

The speed of the obstacles ramps up over time - their speed is based on the score (which itself is just counting how many frames the player has been alive for)
This is done directly in game.cpp, which is also where the score is managed.