#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "basecharacter.h"

class Character : public BaseCharacter
{
private:
	int windowWidth{};
	int windowHeight{};
	Rectangle weaponCollisionRec{};
	Texture2D weapon{LoadTexture("assets/characters/weapon_sword.png")};
	float health{100.f};

public:
	Character(int winWidth, int winHeight);
	// CPP function prototype
	virtual void tick(float deltaTime) override;
	virtual Vector2 getScreenPos() override;
	Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
	// constant means we are not changing the value
	float getHealth() const { return health; }
	void takeDamage(float damage);
};

#endif