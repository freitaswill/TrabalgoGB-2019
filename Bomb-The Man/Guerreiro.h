#pragma once
#include "Personagem.h"
class Guerreiro :
	public Personagem
{
public:
	Guerreiro();
	~Guerreiro();
	void ataqueEspecial() override;

private:
	Som som;
};

