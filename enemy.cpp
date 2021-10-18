#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
	worldPos = pos;
	texture = idle_texture;
	idle = idle_texture;
	run = run_texture;
	width = texture.width / maxFrames;
	height = texture.height;
	speed = 3.0f;
}

void Enemy::tick(float deltaTime)
{
	// Get toTarget
	Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
	// normalize toTarget so it has a length of 1
	toTarget = Vector2Normalize(toTarget);
	// multiply toTarget by speed
	toTarget = Vector2Scale(toTarget, speed);
	// move the enemy
	worldPos = Vector2Add(worldPos, toTarget);
	screenPos = Vector2Subtract(worldPos, target->getWorldPos());
	BaseCharacter::tick(deltaTime);
}