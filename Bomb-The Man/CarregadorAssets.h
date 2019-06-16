#pragma once
#include "libUnicornio.h"

class CarregadorAssets
{
public:
	CarregadorAssets();
	~CarregadorAssets();

	void carregarAssets();

private:
	int qtdAssets, animacoes, frames, tamanhoFonte;
	string token, nome, path;
	Sprite sprite;

};

