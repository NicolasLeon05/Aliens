#include "Button.h"


namespace Button
{
	void DrawButton(Button button, Color color);

	void Draw(Button button)
	{
		if (button.isSelected)
			DrawButton(button, RED);
		else
			DrawButton(button, ORANGE);

		DrawText("GAMEPLAY", GetScreenHeight() / 2, 40, 40, WHITE);
	}

	Button Create(const char* text, float recX, float recY, float recWidth, float recHeight)
	{
		Button newButton;
		newButton.text = text;
		newButton.rec.x = recX;
		newButton.rec.y = recY;
		newButton.rec.width = recWidth;
		newButton.rec.height = recHeight;
		newButton.isSelected = false;

		return newButton;
	}

	bool IsButtonSelected(Button& button)
	{
		Vector2 mousePosition = GetMousePosition();
		//Mouse hover
		if (mousePosition.x > button.rec.x - (button.rec.width / 2) &&
			mousePosition.x < button.rec.x + (button.rec.width / 2) &&
			mousePosition.y  < button.rec.y + (button.rec.height / 2) &&
			mousePosition.y  > button.rec.y - (button.rec.height / 2))
		{
			button.isSelected = true;
			return true;
		}
		else
		{
			button.isSelected = false;
			return false;
		}
	}

	bool IsButtonPressed(Button& button)
	{
		bool pressed = false;

		if (IsMouseButtonReleased(1))
			pressed = true;

		if (IsButtonSelected(button) && pressed)
			return true;
		else
			return false;
	}

	void DrawButton(Button button, Color color)
	{
		int x = static_cast <int> (button.rec.x);
		int y = static_cast <int> (button.rec.y);
		int width = static_cast <int> (button.rec.width);
		int height = static_cast <int> (button.rec.height);

		DrawRectangle(x, y, width, height, color);
	}
}
