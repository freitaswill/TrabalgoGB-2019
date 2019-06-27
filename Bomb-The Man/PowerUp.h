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
	Sprite getSpriteBombaUp() { return bombaUp; };
	Sprite getSpriteTenis() { return tenis; };
	int getX() { return x; };
	int getY() { return y; };
	int getX1() { return x1; };
	int getY1() { return y1; };

private:
	Sprite bombaUp, tenis;
	int x, y, x1, y1;
};

