#include "Jogo.h"
#include<ctime>


Jogo::Jogo()
{
	
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	/*srand(time(0));
	int random = rand() % 800;
	int random2 = rand() % 600;*/

	uniInicializar(800, 600, false);
	
	carregadorAssets.carregarAssets();

	fundoMenu.setSpriteSheet("fundoMenu");
	fundoPersonagem.setSpriteSheet("fundoPersonagens");
	fundoJogo.setSpriteSheet("fundoJogo");
	fundoJogo1.setSpriteSheet("fundoJogo1");
	fundoJogo2.setSpriteSheet("fundoJogo2");
	
	bJogar.setSpriteSheet("botaoJogar");
	bJogar.setPos(gJanela.getLargura() / 2, 360);
	
	bSair.setSpriteSheet("botaoSair");
	bSair.setPos(gJanela.getLargura() / 2, 440);

	bGuerreiro.setSpriteSheet("botaoGuerreiro");
	bGuerreiro.setPos(150, 360);

	bMago.setSpriteSheet("botaoMago");
	bMago.setPos(gJanela.getLargura() / 2, 360);

	bLadrao.setSpriteSheet("botaoLadrao");
	bLadrao.setPos(650, 360);

	telaAtual = tMenu;

	input.inicializar();
	carr.carregadorDeContas();
	//carr.cadElog.setConta(0, carr.cadElog.getConta()->usuario, carr.cadElog.getConta()->senha);
	carr.cadElog.setID(carr.getQtdContas());
}

void Jogo::finalizar()
{
	//Finalizar o input de texto
	input.finalizar();
	
	//	Descarregar todos os recursos (fonte para o texto)
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaAtual != sair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
		case tMenu: telaMenu();
			break;
		case tPersonagem: telaPersonagem();
			break;
		case tJogo: telaJogo();
			break;
		case tCadastro: telaCadastro();
			break;
		case tLogin: telaLogin();
		}

		if (gTeclado.pressionou[TECLA_I])
		{
			telaAtual = tCadastro;
		}

		if (gTeclado.pressionou[TECLA_M])
		{
			telaAtual = tLogin;
		}

		user = input.getTxt().getString();
		senh = input.getTxtSenha().getString();

		uniTerminarFrame();
	}
}

void Jogo::telaJogo()
{
	if (manager->getAtual() == 1)
	{
		fundoJogo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
	
	if (manager->getAtual() == 2)
	{
		fundoJogo1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}

	if (manager->getAtual() == 3)
	{
		fundoJogo2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		
	}

	manager->getMago()->setSprite();
	manager->getPersonagem()->ataqueEspecial();
	manager->getPersonagem()->desenhar();
	manager->testeSpriteColisao();
	manager->trocaPersonagem();
	manager->getPersonagem()->mover();
	manager->getPersonagem()->anima();
	manager->checaColisao(manager->getMago()->getSpriteBomb(), manager->getMago()->getXAux(), manager->getMago()->getYAux(), 0, manager->getSprite(), 700, 300, 0);
	//manager->checaColisao(manager->getPersonagem()->getSprite(), manager->getPersonagem()->getX(), manager->getPersonagem()->getY(), 0, manager->getSprite(), 700, 300, 0);
}

void Jogo::telaMenu()
{
	gMouse.mostrarCursor();
	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bJogar.atualizar();
	bJogar.desenhar();
	if (bJogar.estaClicado())
	{
		telaAtual = tPersonagem;
	}

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		telaAtual = sair;
	}
}

void Jogo::telaPersonagem()
{
	gMouse.mostrarCursor();
	fundoPersonagem.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bMago.atualizar();
	bMago.desenhar();
	if (bMago.estaClicado())
	{
		telaAtual = tJogo;
		manager->escolhePersonagem(1);
		manager->getPersonagem()->inicializar(200, 200);
	}

	bGuerreiro.atualizar();
	bGuerreiro.desenhar();
	if (bGuerreiro.estaClicado())
	{
		telaAtual = tJogo;
		manager->escolhePersonagem(2);
		manager->getPersonagem()->inicializar(200, 200);
	}

	bLadrao.atualizar();
	bLadrao.desenhar();
	if (bLadrao.estaClicado())
	{
		telaAtual = tJogo;
		manager->escolhePersonagem(3);
		manager->getPersonagem()->inicializar(200, 200);
	}
}

void Jogo::telaCadastro()
{
	//Atualizar e desenhar o input de texto
	if (input.getTrocaString() == true)
	{
		input.atualizar();
		input.desenharSenha();
	}
	else
	{
		input.atualizar();
		input.desenhar();
	}
	
	carr.cadElog.cadastrar(user, senh);

	if (gTeclado.pressionou[TECLA_ENTER] && carr.cadElog.getApertou() == true)
	{
		telaAtual = tLogin;
		input.finalizar();
		input.inicializar();
		input.setTrocaString(false);
	}
}

void Jogo::telaLogin()
{
	//gDebug.erro("TelaLogin");
	
	
	carr.cadElog.setApertou(false);

	if (gTeclado.pressionou[TECLA_TAB])
	{
		userTeste = user;
	}

	if (input.getTrocaString() == true)
	{
		input.atualizar();
		input.desenharSenha();
	}
	else
	{
		input.atualizar();
		input.desenhar();
	}

	if (gTeclado.pressionou[TECLA_ENTER] && carr.cadElog.getApertou() == false)
	{
		carr.cadElog.logar(userTeste, senh);
		
		if (carr.cadElog.getLogou() == true)
		{
			input.finalizar();
			telaAtual = tPersonagem;
		}
	}
}
