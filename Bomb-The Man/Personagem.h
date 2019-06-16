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
	int x, y;
	int bomb_Time, explosion_Time;
	int xAux, yAux;
	bool especial = false;
	int vel = 2;
	int indiceRotacao = 1, indiceRotacaoAux = 1, rotacao = 0;
	Sprite spriteSheet;
};

