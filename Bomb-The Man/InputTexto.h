#pragma once

#include "libUnicornio.h"

class InputTexto
{
public:
	InputTexto();
	~InputTexto();

	void inicializar();
	void finalizar();

	void atualizar();
	void desenharSenha();
	void desenhar();

	Texto getTxt();
	Texto getTxtSenha();
	bool getTrocaString() { return trocaString; };
	void setTrocaString(bool trocou) { trocaString = trocou; };

private:
	Texto txt;
	Texto txtSenha;
	bool trocaString = false;
};

