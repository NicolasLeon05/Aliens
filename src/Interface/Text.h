#pragma once

#include "raylib.h"

namespace Text
{
	struct Text
	{
		const char* content;
		int fontSize;
		int length;
		Vector2 pos;
		Color color;
	};

	Text CreateText(const char* content, int fontSize, Vector2 pos, Color color);

	void SetTextLength(Text& text);

	void Draw(Text text, int posX);

	void DrawCentered(Text text);

	void DrawCentered(Text text1, Text text2);
}