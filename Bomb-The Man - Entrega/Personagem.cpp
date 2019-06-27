#include "Personagem.h"



Personagem::Personagem()
{
}


Personagem::~Personagem()
{
}

void Personagem::mover()
{
	
}

void Personagem::anima()
{
	enum PersonagemAnim {

		BAIXO,
		ESQUERDA,
		DIREITA,
		CIMA
	};

	if (gTeclado.segurando[TECLA_W]) 
	{
		/*spriteSheet.setAnimacao(CIMA);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 3;*/
		spriteSheet.setAnimacao(0);
		spriteSheet.avancarAnimacao();
	}

	if (gTeclado.segurando[TECLA_S])
	{
		/*spriteSheet.setAnimacao(BAIXO);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 1;*/
		spriteSheet.setAnimacao(2);
		spriteSheet.avancarAnimacao();
	}

	if (gTeclado.segurando[TECLA_D])
	{
		/*spriteSheet.setAnimacao(DIREITA);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 0;*/
		spriteSheet.setAnimacao(3);
		spriteSheet.avancarAnimacao();
	}

	if (gTeclado.segurando[TECLA_A])
	{
		/*spriteSheet.setAnimacao(ESQUERDA);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 2;*/
		spriteSheet.setAnimacao(1);
		spriteSheet.avancarAnimacao();
	}
}

void Personagem::setSpritesheet(string nome)
{
	spriteSheet.setSpriteSheet(nome);
}

void Personagem::desenhar()
{
	spriteSheet.desenhar(x,y);
}

void Personagem::inicializar(int xInicial, int yInicial)
{
	x = xInicial;
	y = yInicial;
}

void Personagem::ataqueEspecial()
{
}

Sprite Personagem::getSprite()
{
	return spriteSheet;
}

int Personagem::getX()
{
	return x;
}

int Personagem::getY()
{
	return y;
}







