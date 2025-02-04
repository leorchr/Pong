#include "TextRaylib.h"

TextRaylib::TextRaylib(int xP, int yP, string textP, int fontSizeP, Color colorP)
	: x(xP), y(yP), text(textP), fontSize(fontSizeP), color(colorP) {

}

TextRaylib::~TextRaylib() {}

void TextRaylib::SetText(string textP) {
	text = textP;
}

void TextRaylib::Draw() {
	DrawText(text.c_str(), x, y, fontSize, color);
}