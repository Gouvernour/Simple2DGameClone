#include "game.h"

static bool gameOver = false;

game::game(int screenwidth, int screenheight)
{
	ScreenWidth = screenwidth;
	ScreenHeight = screenheight;
	player = new Dino(screenwidth, screenheight);
    obs = new Obstacle(screenwidth, screenheight);
    obs->Spawn();
}

game::~game()
{
    delete player;
    player = nullptr;
}

void game::Update()
{
    if (!gameOver) {
        //-----------------------------------------------------------------------
        // Movement
         //-----------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP))
            player->Jump();
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            player->Duck();
        else
            player->StopDucking();
        player->Update();

        //-----------------------------------------------------------------------
        //Implement obstacles
        //-----------------------------------------------------------------------

        //update obstacle
        obs->Update();
        //when obstacle goes off screen and is deleted, spawn a new one

        //-----------------------------------------------------------------------
        //Collision
        //-----------------------------------------------------------------------

    //    for (int i = 0; i < tube_amount; i++)
    //    {
   //         if (CheckCollisionRecs(dino.rec, obs[i].rec))
   //         {
    //            gameOver = true;
     //       } 
    //        else if ((obs[i].rec.x < dino.position.x) && obs[i].active && !gameOver) {
    //       obs[i].active = false;
    //    }
    }
    else {
        if (IsKeyPressed(KEY_ENTER)) {
            gameOver = false;
        }
    }
}

void game::Draw()
{
    player->Draw();
    obs->Draw();
}

void game::Score()
{
}
