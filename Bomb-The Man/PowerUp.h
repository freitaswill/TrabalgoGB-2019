#pragma once
#include "libUnicornio.h"


class PowerUp
{
public:
	PowerUp();
	~PowerUp();
	/*void ganhaVida();
	void ganhaBomba();
	void aumentaFogo();*/
	void setSpriteBombUp(string sprite);
	void setSpriteTenis(string sprite);
	Sprite getSpriteBomba() { return bombaUp; };
	Sprite getSpriteTenis() { return tenis; };
	int getX() { return x; };
	int getY() { return y; };

private:
	Sprite bombaUp, tenis;
	int x = 150, y = 50;
};

