#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "Prop.h"
#include "enemy.h"
#include <string>

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

	Prop props[2]{
		Prop{Vector2{600.f, 750.f}, LoadTexture("assets/maps/tiles/Rock.png")},
		Prop{Vector2{400.f, 500.f}, LoadTexture("assets/maps/tiles/Log.png")}
	};

	Enemy goblin{
		Vector2{200.f, 400.f},
		LoadTexture("assets/characters/goblin_idle_spritesheet.png"),
		LoadTexture("assets/characters/goblin_run_spritesheet.png")
	};

	Enemy slime{
		Vector2{800.f, 500.f},
		LoadTexture("assets/characters/slime_idle_spritesheet.png"),
		LoadTexture("assets/characters/slime_run_spritesheet.png")
	};

	Enemy* enemies[]{
		&goblin,
		&slime
	};

	for (auto enemy : enemies)
	{
		enemy->setTarget(&knight);
	}

	// Game loops
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

		// Draw Game assets
		DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

		for (auto prop : props)
		{
			prop.Render(knight.getWorldPos());
		}

		if (!knight.getAlive())
		{
			DrawText("Game Over!", 55.f, 45.f, 40, RED);
			EndDrawing();
			continue;
		}
		else
		{
			std::string knightsHealth = "Health: ";
			knightsHealth.append(std::to_string(knight.getHealth()), 0, 5);
			DrawText(knightsHealth.c_str(), 55.f, 45.f, 40, RED);
		}

		// logic to check map boundaries
		knight.tick(GetFrameTime());
		if (knight.getWorldPos().x < 0.f ||
			knight.getWorldPos().y < 0.f ||
			knight.getWorldPos().x + windowWidth > map.width * mapScale ||
			knight.getWorldPos().y + windowHeight > map.height * mapScale)
		{
			knight.undoMovement();
		}

		// Check prop collisions
		for (auto prop : props)
		{
			if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
			{
				knight.undoMovement();
			}
		}

		for (auto enemy : enemies)
		{
			enemy->tick(GetFrameTime());
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			for (auto enemy : enemies)
			{
				if (CheckCollisionRecs(enemy->getCollisionRec(), knight.getWeaponCollisionRec()))
				{
					enemy->setAlive(false);
				}
			}
		};

		EndDrawing();
	}

	CloseWindow();
}