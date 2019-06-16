#include "Thief.h"

Thief::Thief()
{
	_isVisible = true;
}


Thief::~Thief()
{
}

void Thief::ataqueEspecial()
{
	if (gTeclado.pressionou[TECLA_ESPACO] && _isVisible)
	{
		spriteSheet.setCorAlpha(50);
		_isVisible = false;
	}

	else if (gTeclado.pressionou[TECLA_ESPACO] && !_isVisible)
	{
		spriteSheet.setCorAlpha(255);
		_isVisible = true;
	}
}
