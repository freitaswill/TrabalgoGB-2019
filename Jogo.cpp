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

	//	O resto da inicializa��o vem aqui!
	//	...

	gRecursos.carregarSpriteSheet("fundoMenu", "assets/fundos/fundoMenu.png");
	fundoMenu.setSpriteSheet("fundoMenu");
	gRecursos.carregarSpriteSheet("fundoPersonagens", "assets/fundos/fundoPersonagem.png");
	fundoPersonagem.setSpriteSheet("fundoPersonagens");
	gRecursos.carregarSpriteSheet("fundoGameOver", "assets/fundos/GameOver.png");
	fundoGameOver.setSpriteSheet("fundoGameOver");

	telas.push(fundoMenu);
}

void Jogo::finalizar()
{
	//	O resto da finaliza��o vem aqui (provavelmente, em ordem inversa a inicializa��o)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu c�digo vem aqui!
		//	...
		telas.top().desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		uniTerminarFrame();
	}
}