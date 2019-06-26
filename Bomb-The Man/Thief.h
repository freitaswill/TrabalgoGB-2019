#pragma once
#include "Personagem.h"
#include "GenManager.h"
class Thief :
	public Personagem
{
public:
	Thief();
	~Thief();
	void ataqueEspecial() override;
private: 
	bool _isVisible;
};

