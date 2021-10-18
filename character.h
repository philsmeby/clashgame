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
	void tick(float deltaTime);
};

#endif