#pragma once
#include "libUnicornio.h"

class Bloco
{
public:
	Bloco();
	~Bloco();

	void setSprite(string nome) { sprite.setSpriteSheet(nome); }
	Sprite getSprite() { return sprite; }

	void desenhar(int x, int y) { sprite.desenhar(x, y); }

protected:
	Sprite sprite;
};