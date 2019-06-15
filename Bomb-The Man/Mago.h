#pragma once
#include "Personagem.h"
class Mago :
	public Personagem 
{
public:
	Mago();
	~Mago();
	void ataqueEspecial() override;
	Sprite getSpriteBomb();
	int getXAux();
	int getYAux();
	void setSprite();

private:
	Sprite poderMagico;
	
};

