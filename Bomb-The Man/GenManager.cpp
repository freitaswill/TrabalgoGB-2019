#include "GenManager.h"



GenManager::GenManager()
{
}


GenManager::~GenManager()
{
}

/*void GenManager::escolhePersonagem(int escolha)
{
	if (escolha == 1)
	{
		definePersonagem(new Mago);
		getPersonagem()->setSpritesheet("Mage");
		atual = 1;
	}
	
	if (escolha == 2)
	{
		definePersonagem(new Guerreiro);
		getPersonagem()->setSpritesheet("Knight");
		atual = 2;
	}

	if (escolha == 3)
	{
		definePersonagem(new Thief);
		getPersonagem()->setSpritesheet("Thief");
		atual = 3; 
	}
}

void GenManager::trocaPersonagem()
{
	if (atual != 1 && gTeclado.pressionou[TECLA_1])
	{
		definePersonagem(new Mago);
		getPersonagem()->setSpritesheet("Mage");
		getPersonagem()->setSpritesheet("Knight");
		getPersonagem()->inicializar(300, 300);
		atual = 1;
	}

	if (atual != 2 && gTeclado.pressionou[TECLA_2])
	{
		definePersonagem(new Guerreiro);
		getPersonagem()->setSpritesheet("Knight");
		getPersonagem()->inicializar(300, 300);
		atual = 2;
	}

	if (atual != 3 && gTeclado.pressionou[TECLA_3])
	{
		definePersonagem(new Thief);
		getPersonagem()->setSpritesheet("Thief");
		getPersonagem()->inicializar(300, 300);
		atual = 3;
	}
}
*/
void GenManager::checaColisao(Sprite sprite1, int x, int y, int rotacao, Sprite sprite2, int x2, int y2, int rotacao2)
{
	bool colidiu = uniTestarColisao(sprite1 , x, y, rotacao, sprite2, x2, y2, rotacao2);	
	
	if (colidiu)
	{
		gDebug.erro("Colidiu CARALHO");
	}
}

int GenManager::getAtual()
{
	return this->atual;
}

Personagem * GenManager::getPersonagem()
{
	return this->personagem;
}

void GenManager::testeSpriteColisao()
{
	sprite.setSpriteSheet("Knight");
	sprite.desenhar(700, 300);
}

Sprite GenManager::getSprite()
{
	return sprite;
}

void GenManager::definePersonagem(Personagem * p)
{
	this->personagem = p;
}
