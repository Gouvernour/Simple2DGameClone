#pragma once

#include "Dino.h"
#include "Obstacle.h"
#include <raylib.h>

class game {
private:
	//Private variables
	Dino* player;
	int ScreenWidth;
	int ScreenHeight;
	Obstacle* obs;
public:
	//Public variables

private:
	//Private functions

public:
	//Public functions
	game(int screenwidth, int screenheight);
	~game();

	void Update();
	void Draw();
	void Score();

};