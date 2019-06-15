#include "Guerreiro.h"



Guerreiro::Guerreiro()
{
	som.setAudio("Scream");
}


Guerreiro::~Guerreiro()
{
}

void Guerreiro::ataqueEspecial()
{
	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		som.tocar();
	}
}
