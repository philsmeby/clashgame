#ifndef BASE_CHARACTER_H

#define BASE_CHARACTER_H
#include "raylib.h"

class BaseCharacter
{
private:

public:
	BaseCharacter();
	Vector2 getWorldPos() { return worldPos; }
	void undoMovement();
	Rectangle getCollisionRec();

protected:
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

#endif