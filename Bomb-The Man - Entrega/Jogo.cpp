#include "Jogo.h"
#include<ctime>


Jogo::Jogo()
{
	
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	/*srand(time(0));
	int random = rand() % 800;
	int random2 = rand() % 600;*/

	uniInicializar(800, 600, false);
	
	carregadorAssets.carregarAssets();

	bomba.setSpriteBomb("Bomb");
	bomba.setSpriteExplosion("Explosion");
	player.setSpriteSheet("BomberMan");
	power.setSpriteBombUp("BombaUp");
	power.setSpriteTenis("Tenis");
	enem.setEnemySprite("Enemy");

	blocos[1].setSprite("1");
	blocos[2].setSprite("2");

	fundoMenu.setSpriteSheet("fundoMenu");
	fundoGameOver.setSpriteSheet("fundoGameOver");
	fundoJogo.setSpriteSheet("fundoJogo2");
	fundoCadastrar.setSpriteSheet("fundoCadastrar");
	fundoCreditos.setSpriteSheet("fundoCreditos");
	fundoLoad.setSpriteSheet("fundoLoad");
	fundoLogin.setSpriteSheet("fundoLogin");
	fundoRanking.setSpriteSheet("fundoRanking");
	fundoVitoria.setSpriteSheet("fundoWin");
	
	bJogar.setSpriteSheet("botaoJogar");
	bJogar.setPos(gJanela.getLargura() / 2, 150);
	
	bSair.setSpriteSheet("botaoSair");
	bSair.setPos(gJanela.getLargura() / 2, 510);

	bCadastrar.setSpriteSheet("botaoCadastrar");
	bCadastrar.setPos(gJanela.getLargura() / 2, 210);
	
	bCreditos.setSpriteSheet("botaoCreditos");
	bCreditos.setPos(gJanela.getLargura() / 2, 450);

	bSim.setSpriteSheet("botaoSim");
	bSim.setPos(gJanela.getLargura() / 2, 440);

	bNao.setSpriteSheet("botaoNao");
	bNao.setPos(gJanela.getLargura() / 2, 440);

	bVoltar.setSpriteSheet("botaoVoltar");
	bVoltar.setPos(gJanela.getLargura() / 2, 510);

	bRanking.setSpriteSheet("botaoRanking");
	bRanking.setPos(gJanela.getLargura() / 2, 390);

	bLogin.setSpriteSheet("botaoLogin");
	bLogin.setPos(gJanela.getLargura() / 2, 270);

	bLoad.setSpriteSheet("botaoLoad");
	bLoad.setPos(gJanela.getLargura() / 2, 330);

	telas.push(fundoMenu);

	telaAtual = tMenu;

	input.inicializar();
	carr.carregadorDeContas();
	//carr.cadElog.setConta(0, carr.cadElog.getConta()->usuario, carr.cadElog.getConta()->senha);
	carr.cadElog.setID(carr.getQtdContas());
	carregarRanking();


	texto.setFonte("fonte1");
}

void Jogo::finalizar()
{
	//Finalizar o input de texto
	input.finalizar();
	
	//	Descarregar todos os recursos (fonte para o texto)
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaAtual != sair)
	{
		uniIniciarFrame();

		telas.top().desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		switch (telaAtual)
		{
		case tMenu: telaMenu();
			if (telaAtual == tJogo)
			{
				carregarFase(faseAtual);
			}
			break;
		case tGameOver: telaGameOver();
			break;
		case tJogo: telaJogo();
			break;
		case tCadastro: telaCadastro();
			break;
		case tLogin: telaLogin();
			break;
		case tCreditos: telaCreditos();
			break;
		case tRanking: telaRanking();
			break;
		case tLoad: telaLoad();
			break;
		case tVitoria: telaVitoria();
		}

		user = input.getTxt().getString();
		senh = input.getTxtSenha().getString();

		uniTerminarFrame();

		if (telaAtual == tMenu)
		{
			pontosJogadores = 0;
		}
	}
}

void Jogo::telaJogo()
{

	if (gTeclado.pressionou[TECLA_9]) 
	{
		faseAtual++;
		carregarFase(faseAtual);
	}

	if (colidiuBomb == false)
	{
		power.getSpriteBombaUp().desenhar(power.getX1(), power.getY1());
		if (uniTestarColisao(player, x, y, 0, power.getSpriteBombaUp(), power.getX1(), power.getY1(), 0))
		{
			colidiuBomb = true;
			bomba.setQtdBombas(2);
		}
	}
	if (colidiuTenis == false)
	{
		power.getSpriteTenis().desenhar(power.getX(), power.getY());
		if (uniTestarColisao(player, x, y, 0, power.getSpriteTenis(), power.getX(), power.getY(), 0))
		{
			colidiuTenis = true;
		}
	}
	
	if (gTeclado.pressionou[TECLA_M])
	{
		qtdVidas--;
	}

	pontosJogadores += 1;
	desenharFase();
	mover();
	player.desenhar(x, y);
	//if(uniTestarColisao(bomba.getSpriteExplos()))
	enem.getSpriteEnem().desenhar(enem.getXEnemy(), enem.getYEnemy());
	gDebug.depurar("bombas", bomba.getQtdBombas());

	if (gTeclado.pressionou[TECLA_ESPACO] && bomba.getColocou() == true && bomba.getColocouSeg() == false && bomba.getQtdBombas() > 0)
	{
		for (int i = 0; i < 4; i++)
		{

			if (mapa[tileX][tileY + i] == 0)
			{
				baixo2 = i;
			}
			else if (mapa[tileX][tileY + i] == 2)
			{
				mapa[tileX][tileY + i] = 0;
				baixo2 = i;
				i = 50;
			}
			else
				i = 50;
		}

		for (int i = 0; i < 4; i++)
		{

			if (mapa[tileX][tileY - i] == 0)
			{
				cima2 = i;

			}
			else if (mapa[tileX][tileY - i] == 2)
			{
				mapa[tileX][tileY - i] = 0;
				cima2 = i;
				i = 50;
			}
			else
			{
				i = 50;
			}

		}

		for (int i = 0; i < 4; i++)
		{
			if (mapa[tileX - i][tileY] == 0)
			{
				esquerda2 = i;
			}
			else if (mapa[tileX - i][tileY] == 2)
			{
				mapa[tileX - i][tileY] = 0;
				esquerda2 = i;
				i = 50;
			}
			else
			{
				i = 50;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (mapa[tileX + i][tileY] == 0)
			{
				direita2 = i;
			}
			else if (mapa[tileX + i][tileY] == 2)
			{
				mapa[tileX + i][tileY] = 0;
				direita2 = i;
				i = 50;
			}
			else
			{
				i = 50;
			}
		}

		gDebug.erro("Entrei");
		bomba.setColocouSeg(true);
		xAuxBomba2 = x;
		yAuxBomba2 = y;
		bomba.tiraBombas();
	}
	if (bomba.getColocouSeg() == true)
	{
		bomba.colocarSegundaBomba(xAuxBomba2, yAuxBomba2, cima2, baixo2, esquerda2 + 1, direita2);
	}
	else
	{
		direita2 = 0;
		cima2 = 0;
		esquerda2 = 0;
		baixo2 = 0;
	}

	if (gTeclado.pressionou[TECLA_ESPACO] && bomba.getQtdBombas() >= 0 && bomba.getColocou() == false)
	{
		for (int i = 0; i < 4; i++)
		{
		
			if (mapa[tileX][tileY + i] == 0)
			{
				baixo = i;
			}
			else if (mapa[tileX][tileY + i] == 2)
			{
				mapa[tileX][tileY + i] = 0;
				baixo = i;
				i = 50;
			}
			else
				i = 50;
			
		}

		for (int i = 0; i < 4; i++)
		{
			
			if (mapa[tileX][tileY - i ] == 0)
			{
				cima = i;

			}
			else if (mapa[tileX][tileY - i] == 2)
			{
				mapa[tileX][tileY - i] = 0;
				cima = i;
				i = 50;
			}
			else
			{
				i = 50;
			}
			
		}

		for (int i = 0; i < 4; i++)
		{
			if (mapa[tileX - i][tileY] == 0)
			{
				esquerda = i;
			}
			else if (mapa[tileX - i][tileY] == 2)
			{
				mapa[tileX - i][tileY] = 0;
				esquerda = i;
				i = 50;
			}
			else
			{
				i = 50;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (mapa[tileX + i][tileY] == 0)
			{
				direita = i;
			}
			else if (mapa[tileX + i][tileY] == 2)
			{
				mapa[tileX + i][tileY] = 0;
				direita = i;
				i = 50;
			}
			else
			{
				i = 50;
			}
		}

		bomba.setColocou(true);
		xAuxBomba = x;
		yAuxBomba = y;
		bomba.tiraBombas();
	}

	if(bomba.getColocou() == true)
	{
		bomba.colocarBomba(xAuxBomba, yAuxBomba, cima, baixo, esquerda+1, direita);
	}
	else
	{
		cima = 0;
		baixo = 0;
		direita = 0;
		esquerda = 0;
	}


	
	/*if (pontosJogadores > 1000)
	{
		faseAtual++;
		carregarFase(faseAtual);
	}*/
	if (faseAtual > 2) {

		telaAtual = tVitoria;
		telas.push(fundoVitoria);
	}

	//Jogador perdeu
	if (qtdVidas <= 0) {

		telaAtual = tGameOver;
		input.inicializar();
		telas.push(fundoGameOver);
	}
}

void Jogo::telaMenu()
{
	gMouse.mostrarCursor();

	bJogar.atualizar();
	bJogar.desenhar();
	if (bJogar.estaClicado())
	{
		telas.push(fundoJogo);
		telaAtual = tJogo;
	}

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		telaAtual = sair;
	}

	bLogin.atualizar();
	bLogin.desenhar();
	if (bLogin.estaClicado())
	{
		telaAtual = tLogin;
		telas.push(fundoLogin);
	}

	bCadastrar.atualizar();
	bCadastrar.desenhar();
	if (bCadastrar.estaClicado())
	{
		telaAtual = tCadastro;
		telas.push(fundoCadastrar);
	}

	bCreditos.atualizar();
	bCreditos.desenhar();
	if (bCreditos.estaClicado())
	{
		telaAtual = tCreditos;
		telas.push(fundoCreditos);
	}

	bRanking.atualizar();
	bRanking.desenhar();
	if (bRanking.estaClicado())
	{
		telaAtual = tRanking;
		telas.push(fundoRanking);
	}

	bLoad.atualizar();
	bLoad.desenhar();
	if (bLoad.estaClicado())
	{
		telaAtual = tLoad;
		telas.push(fundoLoad);
	}
}

void Jogo::telaCadastro()
{
	if (input.getTrocaString() == true)
	{
		input.atualizar();
		input.desenharSenha();
	}
	else
	{
		input.atualizar();
		input.desenhar();
	}
	
	carr.cadElog.cadastrar(user, senh);

	if (gTeclado.pressionou[TECLA_ENTER] && carr.cadElog.getApertou() == true)
	{
		telaAtual = tLogin;
		input.finalizar();
		input.inicializar();
		input.setTrocaString(false);
		telas.push(fundoLogin);
	}

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		telaAtual = tMenu;
		telas.pop();
	}
}

void Jogo::telaLogin()
{
	carr.cadElog.setApertou(false);

	if (gTeclado.pressionou[TECLA_TAB])
	{
		userTeste = user;
	}

	if (input.getTrocaString() == true)
	{
		input.atualizar();
		input.desenharSenha();
	}
	else
	{
		input.atualizar();
		input.desenhar();
	}

	if (gTeclado.pressionou[TECLA_ENTER] && carr.cadElog.getApertou() == false)
	{
		carr.cadElog.logar(userTeste, senh);

		if (carr.cadElog.getLogou() == true)
		{
			input.finalizar();
			telaAtual = tJogo;
			telas.push(fundoJogo);
		}
	}

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		telaAtual = tMenu;
		telas.pop();
	}
}

void Jogo::telaGameOver()
{
	texto.setString("Digite seu nome para colocar no ranking: ");
	texto.desenhar(100, 200);
	texto.setCor(corNomeRanking, true);

	input.atualizarTexRanking();
	input.desenharNomeRanking();

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		resetar();
		telaAtual = tMenu;

		telas.push(fundoMenu);
		
		pontosJogadores = pontosJogadores; 
		ofstream arqRank("../ranking.txt");
		for (int i = 0; i < 5; i++) {
			if (pontosJogadores > ranking[i]) {
				gDebug.depurar("nomeRanking", nomeRanking[i]);
				for (int j = 4; j > i; j--) {
					ranking[j] = ranking[j - 1];
					nomeRanking[j] = nomeRanking[j - 1];
				}
				nomeRanking[i] = input.getTxtRanking().getString();
				colocacao = i;
				ranking[i] = pontosJogadores;
				i = 20;
			}
		}
		for (int i = 0; i < 5; i++)
			if (arqRank.is_open()) {
				arqRank << nomeRanking[i] << " " << ranking[i] << endl;
			}
	}
}

void Jogo::telaVitoria()
{
	texto.setString("Digite seu nome para colocar no ranking: ");
	texto.desenhar(100, 200);
	texto.setCor(corNomeRanking, true);

	input.atualizarTexRanking();
	input.desenharNomeRanking();

	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		resetar();
		telaAtual = tMenu;

		telas.push(fundoMenu);

		pontosJogadores = pontosJogadores;
		ofstream arqRank("../ranking.txt");
		for (int i = 0; i < 5; i++) {
			if (pontosJogadores > ranking[i]) {
				gDebug.depurar("nomeRanking", nomeRanking[i]);
				for (int j = 4; j > i; j--) {
					ranking[j] = ranking[j - 1];
					nomeRanking[j] = nomeRanking[j - 1];
				}
				nomeRanking[i] = input.getTxtRanking().getString();
				colocacao = i;
				ranking[i] = pontosJogadores;
				i = 20;
			}
		}
		for (int i = 0; i < 5; i++)
			if (arqRank.is_open()) {
				arqRank << nomeRanking[i] << " " << ranking[i] << endl;
			}
	}
}

void Jogo::telaCreditos()
{
	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		telaAtual = tMenu;
		telas.pop();
	}
}

void Jogo::telaRanking()
{
	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		telaAtual = tMenu;
		telas.pop();
	}
	/*else if (colocacao < 10 && colocacao > -1) {
		texto.setString("Você está em " + to_string(colocacao + 1) + "º Lugar");
		texto.setCor(255, 255, 255);
		texto.desenhar(250, 430);
	}*/
	for (int i = 0; i < 5; i++) {

		texto.setString(nomeRanking[i] + ": " + to_string(ranking[i]));
		texto.setCor(0, 0, 0);
		texto.desenhar(gJanela.getLargura() / 2 - 150, (gJanela.getAltura() / 2 + 50 * i - 150));
	}
}

void Jogo::telaLoad()
{
	bVoltar.atualizar();
	bVoltar.desenhar();
	if (bVoltar.estaClicado())
	{
		telaAtual = tMenu;
		telas.pop();
		//telas.push(fundoMenu);
	}
}

bool Jogo::verificarVitoria()
{
	return false;
}

void Jogo::resetar()
{
	faseAtual = 1;
	qtdVidas = 3;
	player.desenhar(x, y);
}

void Jogo::inicializarFase(string nomeArq, int ptsJogadores, int vidas)
{
	ifstream arq(nomeArq + to_string(faseAtual) + ".txt");

	pontosJogadores = ptsJogadores;
	qtdVidas = vidas;

	string sToken;
	int iToken, r, g, b;
	float fToken;
	Cor cor;

	//fonte
	arq >> sToken;
	gDebug.depurar("stringTOKEN", sToken);
	texto.setFonte(sToken);
	texto.setAncora(0, 0.5);

	arq >> textoPontos >> r >> g >> b >> posPontos.x >> posPontos.y;
	corPontos.set(r, g, b, 255);
	arq >> textoVidas >> r >> g >> b >> posVidas.x >> posVidas.y;
	corVidas.set(r, g, b, 255);
	texto.setString(textoPontos + to_string(pontosJogadores));
	texto.desenhar(posPontos.x, posPontos.y);
	texto.setString(textoVidas + to_string(qtdVidas));
	texto.desenhar(posVidas.x, posVidas.y);
	corNomeRanking.set(165, 42, 42, 255);

	for (int y = 0; y < 13; y++)
		for (int x = 0; x < 13; x++)
		{
			arq >> iToken;
			mapa[x][y] = iToken;
		}
}

void Jogo::carregarFase(int f)
{
	faseAtual = f;
	if (faseAtual > 1) {

		pontosJogadores = pontosJogadores;//fase.getpontuacao();
	}
	else {

		pontosJogadores = 0;
	}

	if (faseAtual <= nFases)
	{	
		inicializarFase("config/fases/fase", pontosJogadores, qtdVidas);
	}
	/*else {

		ofstream arqRanking("../ranking.txt");
		for (int i = 0; i < 5; i++) {
			if (pontosJogadores > ranking[i]) {
				for (int j = 4; j > i; j--) {
					ranking[j] = ranking[j - 1];
				}
				colocacao = i;
				ranking[i] = pontosJogadores;
				i = 20;
			}
		}
		for (int i = 0; i < 5; i++) {
			if (arqRanking.is_open()) {

				arqRanking << nomeRanking[i] << " " << ranking[i] << endl;
			}
			arqRanking.close();
		}

	}*/
}

void Jogo::desenharFase()
{
	for (int y = 0; y < 13; y++)
		for (int x = 0; x < 13; x++)
		{
			if (mapa[x][y] != 0)
				blocos[mapa[x][y]].desenhar(blocos[mapa[x][y]].getSprite().getLargura()*x + 100, blocos[mapa[x][y]].getSprite().getAltura()*y);
		}

	texto.setString(textoPontos + "   " + to_string(pontosJogadores));
	texto.desenhar(posPontos.x, posPontos.y);
	texto.setString(textoVidas + "    " + to_string(qtdVidas));
	texto.desenhar(posVidas.x, posVidas.y);
}

void Jogo::AtualizarFase()
{
	//pontoJogadores = pontos;
}

void Jogo::carregarRanking()
{
	ifstream arqRanking("../ranking.txt", ios::in);

	resetar();
	if (arqRanking.is_open()) {
		for (int i = 0; i < 5; i++) {

			arqRanking >> nomeRanking[i] >> ranking[i];
		}
	}
}

void Jogo::mover()
{
	if (gTeclado.segurando[TECLA_W] && direcao == 0 && mapa[tileX][tileY - 1] == 0)
	{
		xAux = x;
		yAux = y;
		player.setAnimacao(0);
		player.avancarAnimacao();
		direcao = 1;
	}

	else if (gTeclado.segurando[TECLA_S] && direcao == 0 && mapa[tileX][tileY + 1] == 0)
	{
		xAux = x;
		yAux = y;
		player.setAnimacao(2);
		player.avancarAnimacao();
		direcao = 2;
	}

	else if (gTeclado.segurando[TECLA_D] && direcao == 0 && mapa[tileX + 1][tileY] == 0)
	{
		xAux = x;
		yAux = y;
		player.setAnimacao(3);
		player.avancarAnimacao();
		direcao = 3;
	}

	else if (gTeclado.segurando[TECLA_A] && direcao == 0 && mapa[tileX - 1][tileY] == 0)
	{
		xAux = x;
		yAux = y;
		player.setAnimacao(1);
		player.avancarAnimacao();
		direcao = 4;
	}
	if (direcao == 1) {
		y -= vel;
		if (y + 50 == yAux) {
			direcao = 0;
			tileY -= 1;
			if (colidiuTenis) {
				vel = 2;
			}
		}
	}
	else if (direcao == 2) {
		y += vel;
		if (y - 50 == yAux) {
			direcao = 0;
			tileY += 1;
			if (colidiuTenis) {
				vel = 2;
			}
		}
	}
	else if (direcao == 3) {
		x += vel;
		if (x - 50 == xAux) {
			direcao = 0;
			tileX += 1;
			if (colidiuTenis) {
				vel = 2;
			}
		}
	}
	else if (direcao == 4) {
		x -= vel;
		if (x + 50 == xAux) {
			direcao = 0;
			tileX -= 1;
			if (colidiuTenis) {
				vel = 2;
			}
		}
	}
}


