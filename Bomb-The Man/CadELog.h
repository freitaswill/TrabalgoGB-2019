#pragma once
#include "libUnicornio.h"
#include "InputTexto.h"
#include "Conta.h"

class CadELog
{
public:
	CadELog();
	~CadELog();

	void cadastrar(string usuario, string senha);
	void logar(string usuario, string senha);
	Conta *getConta();
	void setConta(int id, string usu, string sen);
	void setID(int qtdContas) { contas->ID = qtdContas; }
	bool getApertou() { return apertouEnter; };
	void setApertou(bool apertou) { apertouEnter = apertou; };
	bool getLogou() { return logou; };

private:
	Conta contas[5];
	ofstream arq, arqQtdContas;
	bool apertouEnter = true;
	bool logou = false;
};

