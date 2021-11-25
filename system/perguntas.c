#include "perguntas.h"


FILE *criaArquivo(){
	int op;
	FILE *arq;
	
	printf("\n\t----------------------------------------------------------");
	printf("\n\t\t1 - Lógica Matemática");
	printf("\n\t\t2 - Introdução a Ciência da Computação");
	printf("\n\t\t3 - Programação");
	printf("\n\t\t4 - Aleatório");
	printf("\n\t----------------------------------------------------------\n");
	scanf("%d",&op);
	//system("clear");
	system("cls");
	switch(op){
		case 1:
			arq=fopen("logica","r"); // salva o arquivo
			if(arq!=NULL){ // se ocorreu tudo bem, retorna o que foi salvo
				return arq;
			}
			else{
				printf("\nErro ao abrir arquivo\n");
			}
			break;
		case 2:
			arq=fopen("introducaoComputacao","r"); // salva o arquivo
			if(arq!=NULL){ // se ocorreu tudo bem, retorna o que foi salvo
				return arq;
			}
			else{
				printf("\nErro ao abrir arquivo\n");
			}
			break;
		case 3:
			arq=fopen("programacao","r"); // salva o arquivo
			if(arq!=NULL){ // se ocorreu tudo bem, retorna o que foi salvo
				return arq;
			}
			else{
				printf("\nErro ao abrir arquivo\n");
			}
			break;
		case 4:
			arq = fopen("aleatorio", "r"); // salva o arquivo
			
			if(arq != NULL){ // se ocorreu tudo bem, retorna o que foi salvo
				return arq;
			}else{
				printf("\nErro ao abrir arquivo\n");
			}
		break;
		
		default:
			printf("\nOpção inválida!\n");
			break;
	}
}

Perguntas *criaStructPerguntas(){ //o nome ja diz o que faz

	Perguntas *p = NULL; //inicia como NULO

	p = malloc(sizeof(Perguntas)*3);

	if(p == NULL){//se ocorreu algum erro ao alocar, informa
		printf("Erro ao alocar struct!");
		return 0;
	}else{
		return p;
	}

}

Perguntas *salvaQuestoes(FILE *arq){
	char Linha[500];
	int cont =1 , qst = 0, i;
	Perguntas *p = NULL;

	//qst determina a posiÃ§Ã£o do array que vai guardar a pergunta/resposta
	//cont determina se estamos salvando questao, alternativa ou resposta certa!

	p = malloc(sizeof(Perguntas)*20);

	//for pra ler o arquivo 
	for(i=0; ;i++){

		//se chegar no fim, para o for, senao, segue a vida
		if(feof(arq)){
			break;

		}else{

			//faz a leitura da linha
			fgets(Linha, sizeof(Linha), arq);

			//nao le # e nem E
			if(Linha[0] == '#'){ //pula uma linha para ler a proxima questao
				qst++;
			}else if(Linha[0] != 'E'){ // E = END (fim) -> por algum motivo esta merda esta lendo esse E 2x entÃ£o eu nao deixo ler

				switch(cont){
					case 1:
						//cont = 1 salva pergunta
						strcpy(p[qst].questao, Linha);
						cont++; 
					break;
				
					case 2:
						//cont = 2 salva alternativa A
						
						strcpy(p[qst].a,  Linha);
						cont++;
						
					break;
					
					case 3:
						//cont = 3 salva alternativa B
						strcpy(p[qst].b,  Linha);
						cont++;
						
					break;
					
					case 4:
						//cont = 4 salva alternativa C
						strcpy(p[qst].c,  Linha);
						cont++;
						
					break;

					case 5:
						//cont = 5 salva alternativa D
						strcpy(p[qst].d,  Linha);
						cont++;
						
					break;

					case 6:
						//cont = 6 salva alternativa correta
						p[qst].correta =  Linha[0];
						cont = 1;
					break;															

				}

			}
		}
	}

	//apos a leitura retorna a estrutura preenchida
	return p;
}


int mostraPerguntaPedeResposta(Perguntas pergunta){
	char resp;

	printf("%s\n", pergunta.questao);
	printf("Alternativas:\n\n");
	printf("%s\n", pergunta.a);
	printf("%s\n", pergunta.b);
	printf("%s\n", pergunta.c);
	printf("%s\n", pergunta.d);
	printf("Escolha uma alternativa: ");
	fflush(stdin);
	scanf("%c", &resp);

	if(tolower(resp) == pergunta.correta){
		printf("\nVocê acertou!\n\n");
		Sleep(700);
		system("cls");
		return 1;
	}
	printf("\nVocê errou!\n\n");
	Sleep(700);
	system("cls");
	return 0;
}

void verPontuacao(int pontos){
	
	int sair;
	printf("\nVocê acertou %d de 20 questões!\n", pontos);
	
	do{
		printf("\n\nPressione 1 para voltar ao menu | Pressione 0 para jogar novamente\n");
		scanf("%d", &sair);
		switch(sair){
			case 1:
			system("cls");
			main();
			break;

			case 2:
				system("cls");
				inicio();
			break;


			default:
				printf("Opção inválida!\n");

			break;
		}

	}while(sair != 1 || sair != 0);
}

void inicio(){

	FILE *arq; //cria a variavel que salvara o arquivo
	arq = criaArquivo(); //preenche essa variavel
	Perguntas *perguntas; //cria struct pergunta

	perguntas = criaStructPerguntas(); // aloca dinamicamente o numero de perguntas
	perguntas = salvaQuestoes(arq); // salva todas as questoes dentro da estrutura

	int i=0;
	int fim = 0;
	int pontos = 0;
	int verificaAcerto;
	int op;
	do{

		for(i=0; i<10; i++){
			verificaAcerto =  mostraPerguntaPedeResposta(perguntas[i]);

			if(verificaAcerto == 1){
				pontos++;
			}
		}

		printf("\n\n\t1 - Menu\n\t2 - Jogar Novamente\n\t3 - Ver  Pontuação\n\t0 - Sair\n");
		scanf("%d", &op);
		switch(op){

			case 1:
				main();
			break;

			case 2:
				inicio();
			break;

			case 3: 
				verPontuacao(pontos);
			break;

			case 0:
				system("cls");
				fim = 1;
			break;

			default:
				printf("Opção inválida!\n");
			break;
		}
	}while(fim!=1);

	printf("\nObrigado por jogar!\n");
	system("exit");
}

