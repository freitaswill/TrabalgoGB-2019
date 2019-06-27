#include "Bomba.h"

Bomba::Bomba()
{
	contagemBom = 180;
	contagemEx = 120;
	contagemBom2 = 180;
	contagemEx2 = 120;
	colocou = false, colocouSeg = false;
	eCima, eBaixo, eEsquerda, eDireita = 0;
	qtdBombas = 1;
}


Bomba::~Bomba()
{
}

void Bomba::explodir(int eCima, int eBaixo, int eEsquerda, int eDireita, int x, int y)
{
	for (int i = 0; i < eCima; i++)
	{
		explosao.desenhar(x, y - 50 * i);
	}

	for (int j = 0; j < eBaixo; j++)
	{
		explosao.desenhar(x, y + 50 * j);
	}

	for (int k = 0; k < eEsquerda; k++)
	{
		explosao.desenhar(x - 50 * k, y);
	}

	for (int l = 0; l < eDireita; l++)
	{
		explosao.desenhar(x + 50 * l, y);
	}
}

void Bomba::colocarBomba(int xPlayer, int yPlayer, int eCima, int eBaixo, int eEsquerda, int eDireita)
{	
	xAux = xPlayer;
	yAux = yPlayer;

	if (colocou == true && contagemBom > 0)
	{
		gDebug.depurar("contagemBomba", contagemBom);
		bombSprite.desenhar(xAux, yAux);
		contagemBom -= 1;
	}

	if (contagemBom <= 1)
	{
		if (contagemEx > 0)
		{
			gDebug.depurar("contagemExplos", contagemEx);
			explodir(eCima, eBaixo, eEsquerda, eDireita, xAux, yAux);
			contagemEx -= 1;
		}
		else
		{
			colocou = false;
			contagemBom = 180;
			contagemEx = 120;
			qtdBombas = 1;
		}
	}
}

void Bomba::colocarSegundaBomba(int x, int y, int eCima, int eBaixo, int eEsquerda, int eDireita)
{
	xAux2 = x;
	yAux2 = y;

	if (colocouSeg == true && contagemBom2 > 0)
	{
		gDebug.depurar("contagemBomba", contagemBom2);
		bombSprite.desenhar(xAux2, yAux2);
		contagemBom2 -= 1;
	}

	if (contagemBom2 <= 1)
	{
		if (contagemEx2 > 0)
		{
			gDebug.depurar("contagemExplos", contagemEx);
			explodir(eCima, eBaixo, eEsquerda, eDireita, xAux2, yAux2);
			contagemEx2 -= 1;
		}
		else
		{
			colocouSeg = false;
			contagemBom2 = 180;
			contagemEx2 = 120;
			qtdBombas = 1;
		}
	}
}

void Bomba::setSpriteBomb(string sprite)
{
	this->bombSprite.setSpriteSheet(sprite);
}

void Bomba::setSpriteExplosion(string sprite)
{
	this->explosao.setSpriteSheet(sprite);
}

