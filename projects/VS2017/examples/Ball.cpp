#include "Ball.h"

Ball::Ball() {
	mX = GetScreenWidth()/2;
	mY = GetScreenHeight() / 2;
	mSpeedX = 10;
	mSpeedY = 10;
	mSize = 20;
	wallSound;
}

Ball::Ball(int x, int y, int speedX, int speedY, int size,Sound& wallSoundP) {
	mX = x;
	mY = y;
	mSpeedX = speedX;
	mSpeedY = speedY;
	mSize = size;
	wallSound = wallSoundP;
}

Ball::~Ball() {}

void Ball::Update() {
	mX += mSpeedX;
	mY += mSpeedY;

	if (mX > GetScreenWidth() - mSize) {
		mSpeedX = -mSpeedX;
	}
	if (mX < 0) {
		mSpeedX = -mSpeedX;
	}
	if (mY > GetScreenHeight() - mSize) {
		mSpeedY = -mSpeedY;
		PlaySoundMulti(wallSound);
	}
	if (mY < 0) {
		mSpeedY = -mSpeedY;
		PlaySoundMulti(wallSound);
	}
}

void Ball::Draw() {
	DrawRectangle(mX, mY, mSize, mSize, PINK);
}

RectangleI Ball::GetRect() {
	return RectangleI{ mX,mY,mSize,mSize };
}

void Ball::HorizontalBounce(int xReplace) {
	mSpeedX = -mSpeedX;
	mX = xReplace;
}

void Ball::VerticalBounce(int yReplace) {
	mSpeedY = -mSpeedY;
	mY = yReplace;
}

int Ball::GetX() const {
	return mX;
}

void Ball::SetX(int xPos) {
	mX = xPos;
}

int Ball::GetWidth() const {
	return mSize;
}

void Ball::SetStartDirection(bool left){
	if (left) {
		if (mSpeedX >= 0) {
			mSpeedX = -mSpeedX;
		}
	}
	else {
		if (mSpeedX <= 0) {
			mSpeedX = -mSpeedX;
		}
	}
}
