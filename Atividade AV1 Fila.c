#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
//Feito por Mateus Menezes e Souza

//definindo os elementos da fila
typedef struct aviao{
	int id;
	char nome[20];
	struct aviao *prox;
}aviao;
//definindo a fila e a funcao que a inicializa
typedef struct fila{
	aviao *ini;
	aviao *fim;
}fila;

void inicializaFila(fila *f){
	f->ini = NULL;
	f->fim = NULL;
}
//essa funcao adiciona um novo elemento a fila, alocando a memoria dinamicamente
void enfileira(int id,char *nome,fila *f){
	//alocamos a memoria...
	aviao *ptr = (aviao*) malloc(sizeof(aviao));
	if(ptr == NULL){
		system("cls");
		printf("Erro de alocação\n");
		return;
	}else{
		//...e adicionamos os dados
		ptr->id = id;
		strcpy(ptr->nome,nome);
		ptr->prox = NULL;
		if(f->ini == NULL){
			f->ini = ptr;
		}else{
			f->fim->prox = ptr;
		}
		f->fim = ptr;
	}
}

//esta aqui remove o primeiro elemento da fila, o primeiro a entrar e o primeiro a ser removido
int desenfileira(fila *f){
	aviao *ptr = f->ini;
	int id;
	char nome;
	if(ptr != NULL){
		f->ini = ptr->prox;
		ptr->prox = NULL;
		id = ptr->id;
		nome = ptr->nome;
		free(ptr);
		if(f->ini == NULL){
			f->fim = NULL;
		}
		printf("Feito.\n\n");
		return id;
	}else{
		system("cls");
		printf("Fila vazia. \n\n");
		return;
	}
}
//essa funcao mostra os objetos na fila
void mostraFila(fila *f){
	aviao *ptr = f->ini;
	if(ptr != NULL){
		while(ptr != NULL){
			printf(":Avião %d ", ptr->id);
			printf("Nome %s :", ptr->nome);
			ptr = ptr->prox;
		}
		printf("\n");
	}else{
		system("cls");
		printf("Fila vazia. \n");
		return;
	}
}
//essa funcao diz quantos objetos tem na fila
void numeroElementos(fila *f){
	aviao *ptr = f->ini;
	int numero=0;
	if(ptr != NULL){
		while(ptr != NULL){
			numero++;
			ptr = ptr->prox;
		}
		if(numero == 1){
			printf("Existe 1 avião na fila\n");
		}else{
		printf("Existem %d aviôes na fila\n",numero);
		}
		printf("\n");
	}else{
		printf("Fila vazia. \n");
		return;
	}
}
//essa funcao mostra o primeiro objeto na fila
void mostraPrimeiro(fila *f){
	aviao *ptr = f->ini;
	if(ptr != NULL){
		printf(":Avião %d ", ptr->id);
		printf("Nome %s :", ptr->nome);
		printf("\n");
	}else{
		printf("Fila vazia. \n");
		return;
	}
}


int main(){
	setlocale(LC_ALL,"portuguese");
	fila *f1 = (fila*) malloc(sizeof(fila));

	if(f1 == NULL){
		printf("Erro de alocação. \n");
		exit(-1);
	}else{
		printf("Bem vindo ao programa de controle da aerovia\n");
		
		//essa variavel controla o loop principal
		bool quit=false;
		
		//input para o usuario selecionar a operacao desejada
		char input = ' ';
		
		
		char NomeInput[20];
		int IdInput;
		
		while(!quit){
			printf("Digite 1 para listar o numero de aviões a espera\n");
			printf("Digite 2 para autorizar a decolagem do primeiro avão da fila\n");
			printf("Digite 3 para adicionar um aviâo a fila\n");
			printf("Digite 4 para listar as caracteristicas de todos os aviôes na fila\n");
			printf("Digite 5 para listar as caracteristicas do primeiro aviâo da fila\n");
			printf("Digite 6 para sair do programa\n");
			
			scanf(" %c", &input);
			
			switch(input){
				case '1':
					system("cls");
					numeroElementos(f1);
					break;
				case '2':
					system("cls");
					printf("Autorizando o voo do primeiro avião da fila...\n");
					desenfileira(f1);
					break;
				case '3':
					printf("Digite o id do avião: ");
					scanf(" %d",&IdInput);
					printf("Digite o nome do avião: ");
					scanf(" %s",&NomeInput);
					enfileira(IdInput,NomeInput,f1);
					system("cls");
					printf("Avião adicionado\n");
					break;
				case '4':
					system("cls");
					mostraFila(f1);
					break;
				case '5':
					system("cls");
					mostraPrimeiro(f1);
					break;
				case '6':
					quit = true;
					break;
				default:
					system("cls");
					printf("Input Invalido\n\n");
					break;
			}
		}
		return 0;
	}
}
