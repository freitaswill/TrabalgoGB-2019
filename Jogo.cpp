#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	//	O resto da inicialização vem aqui!
	//	...

	gRecursos.carregarSpriteSheet("Thief", "assets/spritesheets/Thief.png", 4, 1);
	character.setSpriteSheet("Thief");

	gRecursos.carregarSpriteSheet("1", "assets/blocos/1.png");
	blocos[1].setSprite("1");
	gRecursos.carregarSpriteSheet("2", "assets/blocos/2.png");
	blocos[2].setSprite("2");

	gRecursos.carregarSpriteSheet("fundoMenu", "assets/fundos/fundoMenu.png");
	fundoMenu.setSpriteSheet("fundoMenu");
	gRecursos.carregarSpriteSheet("fundoPersonagens", "assets/fundos/fundoPersonagem.png");
	fundoPersonagem.setSpriteSheet("fundoPersonagens");
	gRecursos.carregarSpriteSheet("fundoGameOver", "assets/fundos/GameOver.png");
	fundoGameOver.setSpriteSheet("fundoGameOver");
	gRecursos.carregarSpriteSheet("fundoJogo", "assets/fundos/fundoJogo.png");
	fundoJogo.setSpriteSheet("fundoJogo");

	//botoes
	gRecursos.carregarSpriteSheet("botaoJogar", "assets/botoes/botaoJogar.png", 3);
	bJogar.setSpriteSheet("botaoJogar");
	bJogar.setPos(gJanela.getLargura() / 2, 360);

	gRecursos.carregarSpriteSheet("botaoSair", "assets/botoes/Sair.png", 3);
	bSair.setSpriteSheet("botaoSair");
	bSair.setPos(gJanela.getLargura() / 2, 440);

	telas.push(fundoMenu);

	carregarFase("config/fases/fase");

	telaAtual = tMenu;

	
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		

			telas.top().desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

			switch (telaAtual)
			{
			case tMenu: telaMenu();
				break;
			case tGameOver: telaGameOver();
				break;
			case tJogo: telaJogo();
			}
		

		

		uniTerminarFrame();
	}
}

void Jogo::telaJogo()
{
	desenharFase();
	mover();
	character.desenhar(x, y);
}

void Jogo::telaMenu()
{
	gMouse.mostrarCursor();


	bJogar.atualizar();
	bJogar.desenhar();
	if (bJogar.estaClicado())
	{
		telas.push(fundoJogo);
		telaAtual = tJogo;
	}

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		telaAtual = sair;
	}
}

void Jogo::telaSair()
{
}

void Jogo::telaGameOver()
{
}

void Jogo::carregarFase(string nomeArq)
{
	ifstream arq(nomeArq + to_string(faseAtual) + ".txt");

	int iToken;

	for (int y = 0; y < 13; y++)
		for (int x = 0; x < 13; x++)
		{
			arq >> iToken;
			mapa[x][y] = iToken;
		}
}

void Jogo::desenharFase()
{
	for (int y = 0; y < 13; y++)
		for (int x = 0; x < 13; x++)
		{
			if (mapa[x][y] != 0)
				blocos[mapa[x][y]].desenhar(blocos[mapa[x][y]].getSprite().getLargura()*x + 100,blocos[mapa[x][y]].getSprite().getAltura()*y);
		}
}

void Jogo::mover()
{
	if (gTeclado.segurando[TECLA_W] && direcao == 0 && mapa[tileX][tileY-1] == 0)
	{
		xAux = x;
		yAux = y;
		character.setAnimacao(3);
		character.avancarAnimacao();
		direcao = 1;
	}

	else if (gTeclado.segurando[TECLA_S] && direcao == 0 && mapa[tileX][tileY + 1] == 0)
	{
		xAux = x;
		yAux = y;
		character.setAnimacao(0);
		character.avancarAnimacao();
		direcao = 2;
	}

	else if (gTeclado.segurando[TECLA_D] && direcao == 0 && mapa[tileX + 1][tileY] == 0)
	{
		xAux = x;
		yAux = y;
		character.setAnimacao(2);
		character.avancarAnimacao();
		direcao = 3;
	}

	else if (gTeclado.segurando[TECLA_A] && direcao == 0 && mapa[tileX - 1][tileY] == 0)
	{
		xAux = x;
		yAux = y;
		character.setAnimacao(1);
		character.avancarAnimacao();
		direcao = 4;
	}
	if (direcao == 1) {
		y -= vel;
		if (y + 50 == yAux) {
			direcao = 0;
			tileY -= 1;
		}
	}
	else if (direcao == 2) {
		y += vel;
		if (y - 50 == yAux) {
			direcao = 0;
			tileY += 1;
		}
	}
	else if (direcao == 3) {
		x += vel;
		if (x - 50 == xAux) {
			direcao = 0;
			tileX += 1;
		}
	}
	else if (direcao == 4) {
		x -= vel;
		if (x + 50 == xAux) {
			direcao = 0;
			tileX -= 1;
		}
	}
}
