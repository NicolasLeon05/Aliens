#pragma once
#include "raylib.h"

namespace Button
{
	struct Button
	{
		Rectangle rec;
		const char* text;
		bool isSelected;
	};

	void Draw(Button button, int fontSize);

	Button Create(const char* text, float recX, float recY, float recWidth, float recHeight);

	bool IsButtonSelected(Button& button);

	bool IsButtonPressed(Button& button);
}