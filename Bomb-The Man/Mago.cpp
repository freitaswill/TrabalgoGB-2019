#include "Mago.h"



Mago::Mago()
{
	
}


Mago::~Mago()
{
}

void Mago::setSprite()
{
	poderMagico.setSpriteSheet("FireBall");
}

void Mago::ataqueEspecial()
{
	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		especial = true;
	}
	
	if(especial == true && bomb_Time >= 50)
	{	
		poderMagico.setSpriteSheet("FireBall");
		poderMagico.desenhar(xAux, yAux, 0);
		bomb_Time -= 1;
		gDebug.depurar("bomtime", bomb_Time);
	
	}
	if (especial == true && bomb_Time >= 0) //bomb_Time < 50 && 
	{
		poderMagico.setSpriteSheet("Thief");
		if (bomb_Time < 50)
		{
			poderMagico.desenhar(xAux, yAux, 0);
		}
		//poderMagico.desenhar(xAux, yAux, 0);
		bomb_Time -= 1;
		gDebug.depurar("bomtime menor100", bomb_Time);
	}
	else
	{
		especial = false;
		xAux = x;
		yAux = y;
		bomb_Time = 480;
		explosion_Time = 180;
	}

}

Sprite Mago::getSpriteBomb()
{
	return poderMagico;
}

int Mago::getXAux()
{
	return xAux;
}

int Mago::getYAux()
{
	return yAux;
}

