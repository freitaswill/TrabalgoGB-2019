#include "CarregadorDeContas.h"



CarregadorDeContas::CarregadorDeContas()
{
}


CarregadorDeContas::~CarregadorDeContas()
{
}

void CarregadorDeContas::carregadorDeContas()
{
	arqQtdContas.open("../arqQtdContas.txt", ios::in);
	if (arqQtdContas.is_open())
	{
		while (!arqQtdContas.eof())
		{
			arqQtdContas >> qtdContas;
		}

		//gDebug.depurar("QtdContas", qtdContas);

		arqQtdContas.close();
	}
	else
	{
		gDebug.erro("Erro ao abrir arquivo de leitura");
	}

	if (qtdContas > 0)
	{
		arqUsuarios.open("../arq.txt", ios::in);
		if (arqUsuarios.is_open())
		{
			while (!arqUsuarios.eof())
			{
				for (int i = 0; i < qtdContas; i++)
				{
					arqUsuarios >> arquivoUsuario[i] >> arquivoSenha[i];

					cadElog.setConta(i, arquivoUsuario[i], arquivoSenha[i]);
				}
			}

			gDebug.depurar("Users0", cadElog.getConta()[0].usuario);
			gDebug.depurar("Users0Senha", cadElog.getConta()[0].senha);

			arqUsuarios.close();
		}
		else
		{
			gDebug.erro("Erro ao abrir arquivo de leitura");
		}
	}
}
