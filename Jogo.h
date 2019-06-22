#pragma once
#include "libUnicornio.h"
#include <stack>
#include "Bloco.h"
#include "Bomba.h"

enum Tela { tJogo, tMenu, sair, tGameOver };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	stack <Sprite> telas;
	Sprite fundoJogo, fundoJogo1, fundoJogo2, fundoMenu, fundoPersonagem, fundoGameOver, character;
	Tela telaAtual;
	BotaoSprite bJogar, bSair;
	int faseAtual = 1;
	int x = 150, y = 50, vel = 1, indiceRotacao, xAux, yAux;
	int direcao = 0;
	int tileX = 1, tileY = 1;

	void executar();
	void telaJogo();
	void telaMenu();
	void telaSair();
	void telaGameOver();
	void carregarFase(string nomearq);
	void desenharFase();
	void mover();
	int mapa[13][13];
	Bloco blocos[3];
	Bomba bomba;
};

