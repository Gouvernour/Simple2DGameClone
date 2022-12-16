#include "game.h"


static bool gameOver = false;
static int score = 0;
static int hiScore = 0;
Sound hitSound; 
Sound jumpSound; 
Sound scoreSound;


game::game(int screenwidth, int screenheight)
{
    InitAudioDevice();
	ScreenWidth = screenwidth;
	ScreenHeight = screenheight;
	player = new Dino(screenwidth, screenheight);
    obs = new Obstacle(screenwidth, screenheight);
    obs->Spawn();
    hitSound= LoadSound("./Sounds/hit.wav");
    jumpSound = LoadSound("./Sounds/jump.wav");
    scoreSound = LoadSound("./Sounds/score.wav");
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
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) {
            SetSoundVolume(jumpSound, 1.f);
            player->Jump();
            if (player->GetHeight() = ) {
            PlaySoundMulti(jumpSound);
            }
        }
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
        if (CheckCollisionRecs(player->rec, obs->rec))
        {
            SetSoundVolume(hitSound, 1.f);
            PlaySoundMulti(hitSound);
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
