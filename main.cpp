#include "raylib.h"
#include "raymath.h"
#include "character.h"

int main()
{
	int windowWidth{384};
	int windowHeight{384};
	InitWindow(windowWidth, windowHeight, "First RPG Game!");

	Texture2D map = LoadTexture("assets/maps/WorldMap.png");
	Vector2 mapPos{0.0, 0.0};

	SetTargetFPS(60);

	Character knight;
	knight.setScreenPos(windowWidth, windowHeight);

	// Game loops
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

		// Draw Game assets
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
		knight.tick(GetFrameTime());
		EndDrawing();
	}

	CloseWindow();
}