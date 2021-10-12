#include "raylib.h"
#include "raymath.h"

class Character
{
private:
	Texture2D texture;
	Texture2D idle;
	Texture2D run;
	Vector2 screenPos;
	Vector2 worldPos;
		// 1 is facing right, -1 is facing left
	float rightLeft{1.0f};
	float runningTime{};
	int frame{};
	const int maxFrames{6};
	const float updateTime{1.f/12.f};

public:
	Vector2 getWorldPos(){return worldPos;}

};

int main()
{
	const int windowWidth{384};
	const int windowHeight{384};
	InitWindow(windowWidth, windowHeight, "First RPG Game!");

	Texture2D map = LoadTexture("assets/maps/WorldMap.png");
	Vector2 mapPos{0.0, 0.0};
	float speed{4.0f};

	Texture2D knight_idle = LoadTexture("assets/characters/knight_idle_spritesheet.png");
	Texture2D knight_run = LoadTexture("assets/characters/knight_run_spritesheet.png");

	Texture2D knight = knight_idle;
	Vector2 knightPos{
			(float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
			(float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
	};
	// 1 is facing right, -1 is facing left
	float rightLeft{1.0f};
	float runningTime{};
	int frame{};
	const int maxFrames{6};
	const float updateTime{1.f/12.f};

	SetTargetFPS(60);

	// Game loops
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		Vector2 direction{};
		if (IsKeyDown(KEY_A)) direction.x -= 1.0;
		if (IsKeyDown(KEY_D)) direction.x += 1.0;
		if (IsKeyDown(KEY_W)) direction.y -= 1.0;
		if (IsKeyDown(KEY_S)) direction.y += 1.0;

		if (Vector2Length(direction) != 0.0)
		{

			// Set mapPos = mapPos - direction
			mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
			// ternary operator example in cpp
			direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
			knight = knight_run;
		}
		else
		{
			knight = knight_idle;
		}

		// Draw Game assets
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

		// Update Animation frame
		runningTime += GetFrameTime();
		if (runningTime >= updateTime)
		{
			frame++;
			runningTime = 0.f;
			if (frame > maxFrames) frame = 0;
		}

		float pawnXPos = frame * (float)knight.width/6.f;

		Rectangle source{pawnXPos, 0.f, rightLeft * (float)knight.width/6.0f, (float)knight.height};
		Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f,  4.0f * (float)knight.height};

		DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

		EndDrawing();
	}

	CloseWindow();
}