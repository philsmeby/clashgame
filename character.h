#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character
{
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

public:
	Character(int winWidth, int winHeight);
	Vector2 getWorldPos(){return worldPos;}
	// CPP function prototype
	void tick(float deltaTime);
	void undoMovement();
	Rectangle getCollisionRec();
};

#endif