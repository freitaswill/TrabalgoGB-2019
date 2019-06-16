#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "GenManager.h"
#include "CarregadorAssets.h"
#include "InputTexto.h"
#include "CadELog.h"
#include "CarregadorDeContas.h"

using namespace std;

enum Tela { tJogo, tMenu, tPersonagem, sair, tCadastro, tLogin };

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
	Sprite fundoJogo, fundoJogo1, fundoJogo2, fundoMenu, fundoPersonagem;
	BotaoSprite bJogar, bSair, bMago, bGuerreiro, bLadrao;
	CarregadorAssets carregadorAssets;
	InputTexto input;

	//CadELog conta;
	CarregadorDeContas carr;

	string user, senh, userTeste;

	void telaJogo();
	void telaMenu();
	void telaPersonagem();
	void telaCadastro();
	void telaLogin();
};

