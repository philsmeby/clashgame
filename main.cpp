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
	const float mapScale{4.0f};

	SetTargetFPS(60);

	Character knight{windowWidth, windowHeight};

	// Game loops
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

		// Draw Game assets
		DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

		// logic to check map boundaries
		knight.tick(GetFrameTime());
		if (knight.getWorldPos().x < 0.f ||
			knight.getWorldPos().y < 0.f ||
			knight.getWorldPos().x + windowWidth > map.width * mapScale ||
			knight.getWorldPos().y + windowHeight > map.height * mapScale)
		{
			knight.undoMovement();
		}

		EndDrawing();
	}

	CloseWindow();
}