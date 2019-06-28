#pragma once
#include "libUnicornio.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	int getXEnemy() { return x; };
	int getYEnemy() { return y; };
	void setEnemySprite(string sprite);
	Sprite getSpriteEnem() { return enemy; };
	bool getVivo() { return vivo; };
	void setVivo(bool vi) { vivo = vi; };

private:
	int x, y;
	Sprite enemy;
	bool vivo = true;
};

