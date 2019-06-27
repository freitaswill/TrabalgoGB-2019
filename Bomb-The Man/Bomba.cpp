#include "Bomba.h"

Bomba::Bomba()
{
	contagemBom = 180;
	contagemEx = 120;
	colocou = false;
	eCima, eBaixo, eEsquerda, eDireita = 0;
	qtdBombas = 1;
	i = 0;
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

/*void Bomba::colocarBomba(int xPlayer, int yPlayer, int eCima, int eBaixo, int eEsquerda, int eDireita)
{	
	srand(time(0));

	if (eCima == NULL)
	{
		eCima = 2;
	}

	if (eBaixo == NULL)
	{
		eBaixo = 2;
	}

	if (eEsquerda == NULL)
	{
		eEsquerda = 2;
	}

	if (eDireita == NULL)
	{
		eDireita = 2;
	}

	
	xAux = xPlayer;
	yAux = yPlayer;
	colocou = true;
	

	if (colocou == true && contagemBom > 0)
	{
		gDebug.depurar("contagemBomba", contagemBom);
		bombSprite.desenhar(xAux, yAux);
		contagemBom -= 1;
	}

	if (contagemBom <= 1)
	{
		//gDebug.erro("Explodiu");
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
		}
	}
}*/

void Bomba::colocarBomba(int xPlayer, int yPlayer)
{
	if (gTeclado.pressionou[TECLA_ESPACO] && colocou == false)
	{
		xAux = xPlayer;
		yAux = yPlayer;
		qtdBombas -= 1;
		colocou = true;
	}

	if (colocou == true && contagemBom > 0)
	{
		bombSprite.desenhar(xAux, yAux);
		contagemBom -= 1;
	}

	/*if (gTeclado.pressionou[TECLA_ESPACO] && qtdBombas >= 1 && colocou == true)
	{
		qtdBombas -= 1;
		gDebug.erro("entrei");
		bombSprite.desenhar(200, 200);
	}*/

	if (contagemBom <= 1)
	{
		if (contagemEx > 0)
		{
			//gDebug.depurar("contagemExplos", contagemEx);
			explodir(2, 2, 2, 2, xAux, yAux);
			contagemEx -= 1;
		}
		else
		{
			colocou = false;
			contagemBom = 180;
			contagemEx = 120;
			if (qtdBombas <= 0)
			{
				qtdBombas = 1;
			}
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

