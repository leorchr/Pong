#pragma once
#include "RectangleI.h"
#include "raylib.h"


class Ball
{
private:
	int mX;
	int mY;
	int mSpeedX;
	int mSpeedY;
	int mSize;
	Sound wallSound;

public:
	Ball();
	Ball(int x, int y, int speedX, int speedY, int size, Sound& wallSoundP);
	~Ball();
	RectangleI GetRect();
	void Update();
	void Draw();
	void HorizontalBounce(int xReplace);
	void VerticalBounce(int yReplace);
	int GetX() const;
	void SetX(int xPos);
	int GetWidth() const;
	void Ball::SetStartDirection(bool left);
};