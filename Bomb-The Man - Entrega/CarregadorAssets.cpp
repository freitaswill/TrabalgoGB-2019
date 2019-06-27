#include "CarregadorAssets.h"



CarregadorAssets::CarregadorAssets()
{
}


CarregadorAssets::~CarregadorAssets()
{
}

void CarregadorAssets::carregarAssets()
{
	ifstream arqMapa_assets("../mapaAssets.txt", ios::in);

	if (arqMapa_assets.is_open())
	{
		gDebug.depurar("abriu", 1);

		while (!arqMapa_assets.eof())
		{
			arqMapa_assets >> token;
			gDebug.depurar("token", token);

			if (token == "SPRITE")
			{
				arqMapa_assets >> qtdAssets;

				for (int i = 0; i < qtdAssets; i++)
				{
					gDebug.depurar("token", qtdAssets);
					arqMapa_assets >> nome >> path >> animacoes >> frames;
					gRecursos.carregarSpriteSheet(nome, path, animacoes, frames);
				}
			}
			else if (token == "FUNDO")
			{
				arqMapa_assets >> qtdAssets;

				for (int i = 0; i < qtdAssets; i++)
				{
					gDebug.depurar("token", qtdAssets);
					arqMapa_assets >> nome >> path;
					gRecursos.carregarSpriteSheet(nome, path);
				}
			}
			else if (token == "BOTAO")
			{
				arqMapa_assets >> qtdAssets;

				for (int i = 0; i < qtdAssets; i++)
				{
					gDebug.depurar("token", qtdAssets);
					arqMapa_assets >> nome >> path >> animacoes;
					gRecursos.carregarSpriteSheet(nome, path, animacoes);
				}
			}
			else if (token == "MUSICA")
			{
				arqMapa_assets >> qtdAssets;

				for (int i = 0; i < qtdAssets; i++)
				{
					arqMapa_assets >> nome >> path;
					gRecursos.carregarMusica(nome, path);
				}
			}
			else if (token == "AUDIO")
			{
				arqMapa_assets >> qtdAssets;
				for (int i = 0; i < qtdAssets; i++)
				{
					arqMapa_assets >> nome >> path;
					gRecursos.carregarAudio(nome, path);
				}
			}
			else if (token == "FONTE")
			{
				arqMapa_assets >> qtdAssets;
				for (int i = 0; i < qtdAssets; i++)
				{
					arqMapa_assets >> nome >> path >> tamanhoFonte;
					gRecursos.carregarFonte(nome, path, tamanhoFonte);
				}
			}
		}

		arqMapa_assets.close();
	}
	else
	{
		gDebug.depurar("Erro ao abrir arquivo", 0);
	}
}
