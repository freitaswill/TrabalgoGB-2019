#pragma once
#include "libUnicornio.h"
#include <stack>

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	stack <Sprite> telas;
	Sprite fundoJogo, fundoJogo1, fundoJogo2, fundoMenu, fundoPersonagem, fundoGameOver;

	void executar();
};

