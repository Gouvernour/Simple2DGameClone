#include "game.h"

static bool gameOver = false;
static int score = 0;
static int hiScore = 0;

game::game(int screenwidth, int screenheight)
{
	ScreenWidth = screenwidth;
	ScreenHeight = screenheight;
	player = new Dino(screenwidth, screenheight);
    obs = new Obstacle(screenwidth, screenheight);
    obs->Spawn();
    score = 0;  
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
        // Score
        //-----------------------------------------------------------------------
        score++;
        if (score > hiScore) {
            hiScore = score;
        }

        //-----------------------------------------------------------------------
        // Movement
        //-----------------------------------------------------------------------
<<<<<<< Updated upstream
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP))
            player->Jump();
=======
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) {
            SetSoundVolume(jumpSound, 1.f);
            player->Jump();
            PlaySoundMulti(jumpSound);
        }
>>>>>>> Stashed changes
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            player->Duck();
        else
            player->StopDucking();
        player->Update();

        //-----------------------------------------------------------------------
        //Implement obstacles
        //-----------------------------------------------------------------------

        //update obstacle
        obs->obsSpeed = 10 + (score / 125);
        obs->Update();
        //when obstacle goes off screen and is deleted, spawn a new one

        //-----------------------------------------------------------------------
        //Collision
        //-----------------------------------------------------------------------

 
        if (CheckCollisionRecs(player->rec, obs->rec))
        {
<<<<<<< Updated upstream
=======
            SetSoundVolume(hitSound, 1.f);
            PlaySoundMulti(hitSound);
>>>>>>> Stashed changes
            gameOver = true;
            obs->Spawn();
            score = 0;
        } 
    }
    else {
        if (IsKeyPressed(KEY_ENTER)) {
            gameOver = false;
        }
    }
}

void game::Draw()
{
    if (!gameOver) {
    player->Draw();
    obs->Draw();
    DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);
    DrawText(TextFormat("HI-SCORE: %04i", hiScore), 20, 70, 20, DARKGRAY);
    }
    else {
        DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);
    }
}

void game::Score()
{
}
