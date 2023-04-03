#ifndef INC_01_PONG_TEXT_H
#define INC_01_PONG_TEXT_H

#include <raylib.h>
#include <string>

using std::string;

class TextRaylib
{
public:
	TextRaylib() = delete;
	TextRaylib(int xP, int yP, string text, int fontSizeP, Color colorP);
	~TextRaylib();

	void Draw();
	void SetText(string textP);

private:
	int x;
	int y;
	string text;
	int fontSize;
	Color color;
};

#endif