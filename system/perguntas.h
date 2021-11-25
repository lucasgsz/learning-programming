#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

typedef struct perguntas{ // definicao da struct

	char questao[500];
	char a[100];
	char b[100];
	char c[100];
	char d[100];
	char correta;

}Perguntas;

void inicio();// nao recebe parametros


/*
*Funcao que mostra a pergunta e suas alternativas ao usuario
*parametro: struct de pergunta
*retorno 1 para resposta certa ou 0 para resposta errada
*/
int mostraPerguntaPedeResposta(Perguntas perguntas);

//////////////////////////////////////


/*
*Funcao cujo o unico objetivo e mostrar os pontos
*parametro: inteiro de pontos
*nao possui retorno
*/
void verPontuacao(int pontos);
int main();
