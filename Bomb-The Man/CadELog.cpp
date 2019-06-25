#include "CadELog.h"



CadELog::CadELog()
{
}


CadELog::~CadELog()
{
}

void CadELog::cadastrar(string usuario, string senha)
{
	if (gTeclado.pressionou[TECLA_TAB])
	{
		if (contas->ID < 5)
		{
			contas[contas->ID].usuario = usuario;
		}
	}

	if (gTeclado.pressionou[TECLA_ENTER] && apertouEnter == true)
	{
		if (contas->ID < 5)
		{
			//while(existe)
			//if(Txt == contas[ID].usuario -> Não cadastra) -> vai ter que percorrer o arquivo de contas;
			//existe = true;
			contas[contas->ID].senha = senha;

			//Arquivo ID
			arqQtdContas.open("../arqQtdContas.txt");
			if (arqQtdContas.is_open())
			{
				gDebug.erro("Abriu para IDs");
				contas->ID++;
				arqQtdContas << contas->ID << endl;
				contas->ID--;

				arqQtdContas.close();
			}
			else
			{
				gDebug.erro("Erro ao abrir arquivo");
			}

			//Arquivo usuario e senha
			arq.open("../arq.txt", ios::app);
			if (arq.is_open())
			{
				gDebug.erro("Abriu");
				arq << contas[contas->ID].usuario << " " << contas[contas->ID].senha << endl;

				arq.close();
			}
			else
			{
				gDebug.erro("Erro ao abrir arquivo");
			}

			gDebug.depurar("User", contas[contas->ID].usuario);
			gDebug.depurar("Senha", contas[contas->ID].senha);

			contas->ID++;
			gDebug.depurar("Qtd contas", contas->ID);
		}
		else
		{
			gDebug.erro("Limite de contas excedido");
		}
	}
}

void CadELog::logar(string usuario, string senha)
{
	for (int i = 0; i < contas->ID; i++) 
	{
		if(this->contas[i].usuario == usuario && this->contas[i].senha == senha)
		{
			gDebug.erro("Loguei");
			logou = true;
			//Fazer uma bool e testar na tela Login para mudar a tela;
		}
		else
		{
			gDebug.erro("Nao Logou, usuario ou senha errados");
		}
	}
}

Conta * CadELog::getConta()
{
	return contas;
}

void CadELog::setConta(int id, string usu, string sen)
{
	this->contas[id].usuario = usu;
	this->contas[id].senha = sen;
}


