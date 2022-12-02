#include "game.h"

game::game(int screenwidth, int screenheight)
{
	ScreenWidth = screenwidth;
	ScreenHeight = screenheight;
	player = new Dino(screenwidth, screenheight);
}

game::~game()
{
    delete player;
    player = nullptr;
}

void game::Update()
{
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP))
        player->Jump();
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        player->Duck();
    else
        player->StopDucking();
    player->Update();
}

void game::Draw()
{
    player->Draw();
}

void game::Score()
{
}
