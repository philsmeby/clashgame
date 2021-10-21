#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "basecharacter.h"

class Character : public BaseCharacter
{
private:
	int windowWidth{};
	int windowHeight{};
public:
	Character(int winWidth, int winHeight);
	// CPP function prototype
	virtual void tick(float deltaTime) override;
	virtual Vector2 getScreenPos() override;
	Texture2D weapon{LoadTexture("assets/characters/weapon_sword.png")};
	Rectangle weaponCollisionRec{};
};

#endif