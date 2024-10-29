#pragma once

#include <iostream>

#include "raylib.h"

using namespace std;

namespace Text
{
	struct Text
	{
		string content;
		int fontSize;
		int length;
		Vector2 pos;
		Color color;
	};

	Text CreateText(string content, int fontSize, Vector2 pos, Color color);

	void SetTextLength(Text& text);

	void Draw(Text text, int posX);

	void DrawCentered(Text text);

	void DrawCentered(Text text1, Text text2);
}