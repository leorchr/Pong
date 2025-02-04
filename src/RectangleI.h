#ifndef INC_01_PONG_RECTANGLEI_H
#define INC_01_PONG_RECTANGLEI_H

struct RectangleI {
	int x;
	int y;
	int width;
	int height;
};

#endif

#ifndef INC_01_PONG_COLLISIONS_H
#define INC_01_PONG_COLLISIONS_H

#include <raylib.h>

class Collisions {
public:
	static bool AABBCollision(const RectangleI& rectA, const RectangleI& rectB) {
		int xMinA = rectA.x;
		int xMaxA = rectA.x + rectA.width;
		int yMinA = rectA.y;
		int yMaxA = rectA.y + rectA.height;
		int xMinB = rectB.x;
		int xMaxB = rectB.x + rectB.width;
		int yMinB = rectB.y;
		int yMaxB = rectB.y + rectB.height;
		return!(xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB);
	}
};

#endif