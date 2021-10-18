# include "raylib.h"

class Enemy
{
public:
	Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
	Vector2 getWorldPos() { return worldPos; }
	void tick(float deltaTime);
	void undoMovement();
	Rectangle getCollisionRec();

private:
	Texture2D texture{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
	Texture2D idle{LoadTexture("assets/characters/knight_idle_spritesheet.png")};
	Texture2D run{LoadTexture("assets/characters/knight_run_spritesheet.png")};
	Vector2 screenPos{};
	Vector2 worldPos{};
	Vector2 worldPosLastFrame{};
	float rightLeft{1.0f}; // rightleft handles flipping sprint left and right
	float runningTime{};
	int frame{};
	int maxFrames{6};
	float updateTime{1.f/12.f};
	float speed{4.f};
	float width{};
	float height{};
	float health{100.f};
	float scale{4.0f};
};