#pragma once
#include <vector>
#include "Conta.h"
#include "CadELog.h"

class CarregadorDeContas
{
public:
	CarregadorDeContas();
	~CarregadorDeContas();
	void carregadorDeContas();
	int getQtdContas() { return qtdContas; };

//private:
	CadELog cadElog;
	fstream arqUsuarios, arqQtdContas;
	int qtdContas;
	string arquivoSenha[5], arquivoUsuario[5];
};

