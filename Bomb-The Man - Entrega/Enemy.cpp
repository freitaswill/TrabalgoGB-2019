#include "Enemy.h"



Enemy::Enemy()
{
	x = 650;
	y = 50;
}


Enemy::~Enemy()
{
}

void Enemy::setEnemySprite(string sprite)
{
	enemy.setSpriteSheet(sprite);
}
