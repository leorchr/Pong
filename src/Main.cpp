#include "raylib.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "TextRaylib.h"

using namespace std;

void Update();
void Draw();

const int screenWidth = 800;
const int screenHeight = 450;
const int paddleSizeX = 20;
const int paddleSizeY = 128;
const int paddleOffset = 20;

Paddle leftPaddle;
Paddle rightPaddle;

int playerPoints = 0;
int opponentPoints = 0;
int finalResults = 0;
TextRaylib playerScoreText = TextRaylib(350, 20, to_string(playerPoints), 40, PINK);
TextRaylib opponentScoreText = TextRaylib(screenWidth - 350, 20, to_string(opponentPoints), 40, PINK);
TextRaylib results = TextRaylib(screenWidth / 2 - 60, 100, "", 40, PINK);
TextRaylib retry = TextRaylib(screenWidth / 2 - 170, 200, "", 40, PINK);

Sound pingSound;
Sound wallSound;
Sound outSound;
Sound victorySound;
Sound defeatSound;
Sound restartSound;
Ball ball;

int main(int argc, char* argv[])
{
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);
    InitAudioDevice();

    leftPaddle = Paddle(0 + paddleOffset, screenHeight / 2 - paddleSizeY / 2, 10, 20, 128);
    rightPaddle = Paddle(screenWidth - paddleSizeX - paddleOffset, screenHeight / 2 - paddleSizeY / 2, 3, 20, 128);
    

    pingSound = LoadSound("assets/ping.wav");
    wallSound = LoadSound("assets/wall.wav");
    outSound = LoadSound("assets/out.wav");
    victorySound = LoadSound("assets/victory.wav");
    defeatSound = LoadSound("assets/defeat.wav");
    restartSound = LoadSound("assets/restart.wav");
    ball = Ball(screenWidth / 2 - 10, screenHeight / 2 - 10, 10, 10, 20, wallSound);

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    UnloadSound(pingSound);
    UnloadSound(wallSound);
    UnloadSound(outSound);
    UnloadSound(victorySound);
    UnloadSound(defeatSound);
    UnloadSound(restartSound);
    CloseAudioDevice();

    CloseWindow();
    return 0;
}

void Update() {
    if (finalResults == 0) {
        ball.Update();
        leftPaddle.Update();
        RectangleI ballRect = ball.GetRect();
        rightPaddle.UpdateAI(ballRect.y);

        RectangleI leftPaddleRect = leftPaddle.GetRect();
        bool colliding = Collisions::AABBCollision(ballRect, leftPaddleRect);
        if (colliding) {
            ball.HorizontalBounce(leftPaddleRect.x + leftPaddleRect.width);
            PlaySoundMulti(pingSound);
        }

        RectangleI rightPaddleRect = rightPaddle.GetRect();
        colliding = Collisions::AABBCollision(ballRect, rightPaddleRect);
        if (colliding) {
            ball.HorizontalBounce(rightPaddleRect.x - ballRect.width);
            PlaySoundMulti(pingSound);
        }

        if (ball.GetX() < 0) {
            ++opponentPoints;
            if (opponentPoints >= 5) {
                results.SetText("Defeat");
                PlaySoundMulti(defeatSound);
                finalResults = 2;
                retry.SetText("Press R to Retry");
            }
            else {
                PlaySoundMulti(outSound);
            }
            ball.SetX(screenWidth / 2);
            ball.SetStartDirection(false);
            opponentScoreText.SetText(to_string(opponentPoints));
        }
        if (ball.GetX() > screenWidth - ball.GetWidth()) {
            ++playerPoints;
            if (playerPoints >= 5) {
                results.SetText("Victory");
                PlaySoundMulti(victorySound);
                finalResults = 1;
                retry.SetText("Press R to Retry");
            }
            else {
                PlaySoundMulti(outSound);
            }
            ball.SetX(screenWidth / 2);
            ball.SetStartDirection(true);
            playerScoreText.SetText(to_string(playerPoints));
        }
    }
    if (finalResults == 1 || finalResults == 2) {
        if (IsKeyDown(KEY_R)) {
            finalResults = 0;
            ball.SetX(screenWidth / 2);
            ball.SetStartDirection(true);
            playerPoints = 0;
            opponentPoints = 0;
            playerScoreText.SetText(to_string(playerPoints));
            opponentScoreText.SetText(to_string(opponentPoints));
            results.SetText("");
            retry.SetText("");
        }
    }
}

void Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    results.Draw();
    retry.Draw();
    playerScoreText.Draw();
    opponentScoreText.Draw();
    if(finalResults == 0) ball.Draw();
    leftPaddle.Draw();
    rightPaddle.Draw();
    EndDrawing();
}