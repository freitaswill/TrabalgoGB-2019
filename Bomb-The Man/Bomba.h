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
	void setSpriteBomb(string sprite);
	void setSpriteExplosion(string sprite);
	//Mudar a sprite da bomba antes de explodir

	//Quando explodir para desenhar a explosao vao ser quatro variáveis -> terá um for para cada
	//Ex: for(int i =0; i < variavel A; i++)
	//desenhar(posição player(posicao da bomba talvez?) + 50 x i);

private:
	int contagemBom, contagemEx, xAux, yAux;
	bool colocou;
	int eCima = 0, eBaixo = 0, eEsquerda = 0, eDireita = 0;
	Sprite bombSprite, explosao;
};

