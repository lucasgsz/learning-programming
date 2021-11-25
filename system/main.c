#include "perguntas.h"

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int op;

	do{
		printf("\n\t==========================\n");
		printf("\t\t1 - Inicio\n\t\t0 - Sair");
		printf("\n\t==========================\n");
		scanf("%d", &op);
		//system("clear");
		system("cls");

		switch(op){
			case 1:
				inicio();
				break;
			case 0:
				return 0;
				break;

		}
	}while(op!=0);
}
