#include "raylib.h"

int main()
{
	const int windowWidth{384};
	const int windowHeight{384};
	InitWindow(windowWidth, windowHeight, "First RPG Game!");

	Texture2D map = LoadTexture("assets/maps/WorldMap.png");

	SetTargetFPS(60);

	// Game loops
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		Vector2 mapPos{0.0, 0.0};
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

		EndDrawing();
	}

	CloseWindow();
}