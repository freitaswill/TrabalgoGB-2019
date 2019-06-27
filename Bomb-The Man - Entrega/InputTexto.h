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
	void atualizarTexRanking();
	void desenharSenha();
	void desenhar();
	void desenharNomeRanking();

	Texto getTxt();
	Texto getTxtSenha();
	Texto getTxtRanking();
	bool getTrocaString() { return trocaString; };
	void setTrocaString(bool trocou) { trocaString = trocou; };

private:
	Texto txt, txtSenha, txtNomeRanking;
	bool trocaString = false;
};

