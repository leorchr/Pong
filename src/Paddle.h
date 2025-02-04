#pragma once
#include "RectangleI.h"

class Paddle
{
private:

	int mX;
	int mY;
	int mSpeedY;
	int mSizeX;
	int mSizeY;

public:
	Paddle();
	Paddle(int x, int y, int speedY, int sizeX, int sizeY);
	~Paddle();
	RectangleI GetRect();
	void Update();
	void Draw();
	void MoveUp();
	void MoveDown();
	void UpdateAI(int ballY);
};