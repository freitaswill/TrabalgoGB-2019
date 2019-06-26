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

private:
	Sprite bombaUp, tenis;
};

