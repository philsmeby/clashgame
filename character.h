#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "basecharacter.h"

class Character : public BaseCharacter
{
private:

public:
	Character(int winWidth, int winHeight);
	// CPP function prototype
	virtual void tick(float deltaTime) override;
	Vector2 getScreenPos() { return screenPos; }
};

#endif