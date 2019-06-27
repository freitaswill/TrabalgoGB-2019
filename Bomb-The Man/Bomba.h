#pragma once
#include "libUnicornio.h"
#include <ctime>

class Bomba
{
public:
	Bomba();
	~Bomba();
	void explodir(int eCima, int eBaixo, int eEsquerda, int eDireita, int x, int y);
	//void colocarBomba(int xPlayer, int yPlayer, int eCima, int eBaixo, int eEsquerda, int eDireita);
	void colocarBomba(int xPlayer, int yPlayer);
	void setSpriteBomb(string sprite);
	void setSpriteExplosion(string sprite);
	int getQtdBombas() { return qtdBombas; };
	void setQtdBombas(int qtd) { qtdBombas = qtd; };

private:
	int contagemBom, contagemEx, xAux, yAux, qtdBombas, i;
	bool colocou;
	int eCima = 0, eBaixo = 0, eEsquerda = 0, eDireita = 0;
	Sprite bombSprite, explosao;
};

