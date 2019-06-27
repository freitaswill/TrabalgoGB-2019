#pragma once
#include "libUnicornio.h"
#include <ctime>

class Bomba
{
public:
	Bomba();
	~Bomba();
	void explodir(int eCima, int eBaixo, int eEsquerda, int eDireita, int x, int y);
	void colocarBomba(int xPlayer, int yPlayer, int eCima, int eBaixo, int eEsquerda, int eDireita);
	void colocarSegundaBomba(int x, int y, int eCima, int eBaixo, int eEsquerda, int eDireita);
	//void colocarBomba(int xPlayer, int yPlayer);
	Sprite getSpriteExplos() { return explosao; };
	void setSpriteBomb(string sprite);
	void setSpriteExplosion(string sprite);
	int getQtdBombas() { return qtdBombas; };
	void setQtdBombas(int qtd) { qtdBombas = qtd; };
	void tiraBombas() { qtdBombas -= 1; };
	bool getColocou() { return colocou; };
	void setColocou(bool col) { colocou = col; };
	bool getColocouSeg() { return colocouSeg; };
	void setColocouSeg(bool col) { colocouSeg = col; };

	/*int getXexp() { return xExplosao; };
	int getYexp() { return yExplosao; };
	void setXexp(int soma) { xExplosao = soma; };
	void setYexp(int soma) { yExplosao = soma; };*/

private:
	int contagemBom, contagemBom2, contagemEx, contagemEx2, xAux, xAux2, yAux, yAux2, qtdBombas;
	bool colocou, colocouSeg;
	int eCima = 0, eBaixo = 0, eEsquerda = 0, eDireita = 0;
	Sprite bombSprite, explosao;
	//int xExplosao, yExplosao;
};

