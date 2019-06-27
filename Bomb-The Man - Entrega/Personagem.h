#pragma once
#include"libUnicornio.h"

class Personagem 
{
public:
	Personagem();
	~Personagem();
	void mover();
	void anima();
	void setSpritesheet(string nome);
	void desenhar();
	void inicializar(int xInicial, int yInicial);
	virtual void ataqueEspecial();
	Sprite getSprite();
	int getX();
	int getY();

protected:
	int x = 150, y = 50;
	int bomb_Time, explosion_Time;
	int xAux, yAux;
	bool especial = false;
	int vel = 1;
	int indiceRotacao = 1, indiceRotacaoAux = 1, rotacao = 0;
	Sprite spriteSheet;
	int direcao = 0;
	int tileX = 1, tileY = 1;
	int mapa[13][13];
};

