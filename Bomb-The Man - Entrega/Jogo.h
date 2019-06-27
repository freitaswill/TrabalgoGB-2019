#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "GenManager.h"
#include "CarregadorAssets.h"
#include "InputTexto.h"
#include "CadELog.h"
#include "CarregadorDeContas.h"
#include <stack>
#include "Bloco.h"
#include "Bomba.h"
#include "PowerUp.h"
#include "Enemy.h"

using namespace std;

enum Tela { tJogo, tMenu, tCreditos, sair, tCadastro, tLogin, tGameOver, tRanking, tLoad, tVitoria };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

protected:
	GenManager *manager = new GenManager();
	Tela telaAtual;
	Sprite fundoJogo, fundoCreditos, fundoMenu, fundoCadastrar, fundoLogin, fundoGameOver, fundoRanking, fundoVitoria, fundoLoad, player;
	BotaoSprite bJogar, bSair, bVoltar, bCreditos, bRanking, bLogin, bCadastrar, bSim, bNao, bLoad;
	CarregadorAssets carregadorAssets;
	InputTexto input;
	Bloco blocos[3];
	Bomba bomba;
	stack <Sprite> telas; 
	int faseAtual = 1, pontosJogadores = 0, qtdVidas = 3, ranking[5], colocacao, nFases = 2;
	CarregadorDeContas carr;

	string user, senh, userTeste;

	Texto texto;
	string textoVidas, textoPontos, nomeRanking[5];
	Vetor2D posVidas, posPontos;
	Cor corVidas, corPontos, corNomeRanking;
	PowerUp power;
	Enemy enem;

	void telaJogo();
	void telaMenu();
	void telaCadastro();
	void telaLogin();
	void telaGameOver();
	void telaVitoria();
	void telaCreditos();
	void telaRanking();
	void telaLoad();
	bool verificarVitoria();
	void resetar();
	void inicializarFase(string nomearq, int ptsJogadores, int vidas);
	void carregarFase(int f);
	void desenharFase();
	void AtualizarFase();
	void carregarRanking();

	int x = 150, y = 50, vel = 1, indiceRotacao, xAux, yAux;
	int xAuxBomba, yAuxBomba, xAuxBomba2, yAuxBomba2;
	int direcao = 0;
	int tileX = 1, tileY = 1;
	void mover();
	int mapa[13][13];
	int cima, baixo, esquerda, direita;
	int cima2, baixo2, esquerda2, direita2;
	bool colidiuBomb = false, colidiuTenis = false, segBomba = false;
};

