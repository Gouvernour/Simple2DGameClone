#pragma once

#include "Dino.h"
#include "Obstacle.h"
#include <raylib.h>
#include "BackgroundArt.h"

class game {
private:
	//Private variables
	Dino* player;
	int ScreenWidth;
	int ScreenHeight;
	Obstacle* obs;
	BackgroundArt* backgrounds;
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