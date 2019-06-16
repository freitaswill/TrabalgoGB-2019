#include "Personagem.h"



Personagem::Personagem()
{
}


Personagem::~Personagem()
{
}

void Personagem::mover()
{
	if (gTeclado.segurando[TECLA_W]) 
	{
		y -= 1 * vel;
	}

	if (gTeclado.segurando[TECLA_S]) 
	{
		y += 1 * vel;
	}

	if (gTeclado.segurando[TECLA_D])
	{
		x += 1 * vel;
	}

	if (gTeclado.segurando[TECLA_A])
	{
		x -= 1 * vel;
	}
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
		spriteSheet.setAnimacao(CIMA);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 3;
	}

	if (gTeclado.segurando[TECLA_S])
	{
		spriteSheet.setAnimacao(BAIXO);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 1;
	}

	if (gTeclado.segurando[TECLA_D])
	{
		spriteSheet.setAnimacao(DIREITA);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 0;
	}

	if (gTeclado.segurando[TECLA_A])
	{
		spriteSheet.setAnimacao(ESQUERDA);
		spriteSheet.avancarAnimacao();
		indiceRotacao = 2;
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






