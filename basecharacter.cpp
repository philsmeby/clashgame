#include "basecharacter.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
{
	worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
	return Rectangle{
		screenPos.x, screenPos.y,
		width * scale, height * scale
	};
}

void BaseCharacter::tick(float deltaTime)
{
	// Save current position, so we can know where we are moving from.
	// Used to undo movement that is not allowed.
	worldPosLastFrame = worldPos;

		// Update Animation frame
	runningTime += deltaTime;
	if (runningTime >= updateTime)
	{
		frame++;
		runningTime = 0.f;
		if (frame > maxFrames) frame = 0;
	}
	Rectangle source{frame * width, 0.f, rightLeft * width, height};
	Rectangle dest{screenPos.x, screenPos.y, scale * width,  scale * height};
	DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}
