#pragma once
#include "Personagem.h"
#include "Mago.h"
#include "Guerreiro.h"
#include "Thief.h"

class GenManager 
{
public:
	GenManager();
	~GenManager();

	void escolhePersonagem(int escolha);
	void trocaPersonagem();
	void checaColisao(Sprite sprite1, int x, int y, int rotacao, Sprite sprite2, int x2, int y2, int rotacao2);
	int getAtual();
	Personagem *getPersonagem();
	Mago *getMago();
	void testeSpriteColisao();
	Sprite getSprite();

private:

	void definePersonagem(Personagem *p);
	Personagem *personagem = new Personagem; //new personagem
	Mago *mago = new Mago;
	int atual;
	Sprite sprite;
	//bool tem_Bomba;
};

