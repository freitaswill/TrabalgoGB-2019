#pragma once
#include "Personagem.h"

class GenManager 
{
public:
	GenManager();
	~GenManager();

	void checaColisao(Sprite sprite1, int x, int y, int rotacao, Sprite sprite2, int x2, int y2, int rotacao2);
	int getAtual();
	Personagem *getPersonagem();
	void testeSpriteColisao();
	Sprite getSprite();

private:

	void definePersonagem(Personagem *p);
	Personagem *personagem = new Personagem; //new personagem
	int atual;
	Sprite sprite;
	//bool tem_Bomba;
};

