#include "raylib.h"
#include "raymath.h"

class Character
{
private:
	Texture2D texture{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
	Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
	Texture2D run{"assets/characters/knight_run_spritesheet.png"};
	Vector2 screenPos{};
	Vector2 worldPos{};
		// 1 is facing right, -1 is facing left
	float rightLeft{1.0f};
	float runningTime{};
	int frame{};
	const int maxFrames{6};
	const float updateTime{1.f/12.f};
	const float speed{4.f};

public:
	Vector2 getWorldPos(){return worldPos;}
	// CPP function prototype
	void setScreenPos(int winWidth, int winHeight);
	void tick(float deltaTime);
};

// scope resolution operator c++ is the ::
void Character::setScreenPos(int winWidth, int winHeight)
{
	screenPos = {
			(float)winWidth/2.0f - 4.0f * (0.5f * (float)texture.width/6.0f),
			(float)winHeight/2.0f - 4.0f * (0.5f * (float)texture.height)
	};
}

void Character::tick(float deltaTime)
{
		Vector2 direction{};
		if (IsKeyDown(KEY_A)) direction.x -= 1.0;
		if (IsKeyDown(KEY_D)) direction.x += 1.0;
		if (IsKeyDown(KEY_W)) direction.y -= 1.0;
		if (IsKeyDown(KEY_S)) direction.y += 1.0;

		if (Vector2Length(direction) != 0.0)
		{

			// Set worldPos = worldPos + direction
			worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
			// ternary operator example in cpp
			direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
			texture = run;
		}
		else
		{
			texture = idle;
		}

		// Update Animation frame
		runningTime += deltaTime;
		if (runningTime >= updateTime)
		{
			frame++;
			runningTime = 0.f;
			if (frame > maxFrames) frame = 0;
		}

		float pawnXPos = frame * (float)texture.width/6.f;
		Rectangle source{pawnXPos, 0.f, rightLeft * (float)texture.width/6.0f, (float)texture.height};
		Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width/6.0f,  4.0f * (float)texture.height};

		DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

int main()
{
	const int windowWidth{384};
	const int windowHeight{384};
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