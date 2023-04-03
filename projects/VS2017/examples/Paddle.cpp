#include "Paddle.h"
#include "raylib.h"

Paddle::Paddle() {
	mX = 0;
	mY = 200;
	mSizeX = 128;
	mSizeY = 20;
	mSpeedY = 10;
}

Paddle::Paddle(int x, int y, int speedY, int sizeX, int sizeY) {
	mX = x;
	mY = y;
	mSizeX = sizeX;
	mSizeY = sizeY;
	mSpeedY = speedY;
}

Paddle::~Paddle() {}

void Paddle::Update() {

	if (IsKeyDown(KEY_W)) {
		MoveUp();
	}
	if (IsKeyDown(KEY_S)) {
		MoveDown();
	}
}

void Paddle::Draw() {
	DrawRectangle(mX, mY, mSizeX, mSizeY, PINK);
}

RectangleI Paddle::GetRect() {
	return RectangleI{ mX,mY,mSizeX,mSizeY };
}

void Paddle::MoveUp() {
	mY -= mSpeedY;
	if (mY < 0) {
		mY = 0;
	}
}

void Paddle::MoveDown() {
	int screenHeight = GetScreenHeight();
	mY += mSpeedY;
	if (mY > screenHeight - mSizeY) {
		mY = screenHeight - mSizeY;
	}
}

void Paddle::UpdateAI(int ballY) {
	if (ballY < mY + mSizeY / 4) {
		MoveUp();
	}
	if (ballY > mY + 3 * mSizeY / 4) {
		MoveDown();
	}
}