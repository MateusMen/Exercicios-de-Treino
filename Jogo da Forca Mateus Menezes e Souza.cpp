//Esse programa foi feito como exercicio final do primeiro semestre do meu curo de fundamentos em C
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<time.h>

using namespace std;

int main(){
	setlocale(LC_ALL,"portuguese");
    int wordLength = 7, mistakesAllowed = 10, random,
    win = 0, mistakes = 0, aux = 0;
    //Gerador de numeros aleatorios
    srand (time(NULL));
    random = rand() % 13;
    //a lista "wordbank" guarda todas as possiveis palavras alvo, 
    char wordbank[12][wordLength] = {{'e','x','e','m','p','l','o'},{'s','u','b','l','i','m','e'},{'e','m','p','a','t','i','a'},{'t','r','i','v','i','a','l'},{'s','e','n','t','i','d','o'},{'b','i','z','a','r','r','o'},{'i','n','t','e','n','s','o'},{'e','n','s','i','n','a','r'},{'e','s','p','e','r','t','o'},
	{'c','a','u','t','e','l','a'},{'s','a','u','d','a','d','e'},{'c','o','s','t','u','m','e'}},
	visor[wordLength] = {'-','-','-','-','-','-','-'},tgtword[wordLength] = {'-','-','-','-','-','-','-'},wrongletters[11], inpt;
	//Arte ascii do homen da forca
	string hangman[11] = {"  +---+\n  |   |\n      |\n      |\n      |\n      |\n      |\n      |\n=========","  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n      |\n      |\n=========",
	"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n      |\n      |\n=========","  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n      |\n      |\n=========",
	"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n      |\n      |\n=========","  +---+\n  |   |\n  O   |\n /|\\  |\n  |   |\n      |\n      |\n      |\n=========",
	"  +---+\n  |   |\n  O   |\n /|\\  |\n  |   |\n  |   |\n      |\n      |\n=========","  +---+\n  |   |\n  O   |\n /|\\  |\n  |   |\n  |   |\n /    |\n      |\n      |\n=========",
	"  +---+\n  |   |\n  O   |\n /|\\  |\n  |   |\n  |   |\n / \\  |\n      |\n      |\n=========","  +---+\n  |   |\n  O   |\n /|\\  |\n  |   |\n  |   |\n / \\  |\n/     |\n      |\n=========",
	"  +---+\n  |   |\n  O   |\n /|\\  |\n  |   |\n  |   |\n / \\  |\n/   \\ |\n      |\n========="};
	//esse for loop muda os conteudos da array tgtword para a palavra alvo selecionada pelo gerador de numeros aleatorios
    for(int i = 0; i < wordLength; i++){
    	tgtword[i] = wordbank[random][i];
	}
    
    
   while(win < wordLength && mistakes <= mistakesAllowed) {

        //Digitamento de outputs
        std::cout << hangman[mistakes];
        printf("\nErros: %d,", mistakes);
        for(int i = 0; i < mistakes; i++){
        	printf(" %c", wrongletters[i]);
		}
        printf("\nAcertos: %d", win);
        printf("\n%s", visor);
        printf("\nDigite um caractere: ");

        //Nao tocar no espaco, ou o while quebra por alguma razao
        scanf(" %c", &inpt);

        //check de falha
        aux = 0;
        for(int i = 0; i < wordLength; i++){
            if(inpt == tgtword[i]){
                visor[i] = inpt;
            } else {
                aux++;
            }
        }

        if (aux == wordLength) {
            mistakes++;
            wrongletters[mistakes - 1] = inpt;
        }

        //check de acerto
        win = 0;
        for(int i = 0; i < wordLength; i++){
            if(visor[i] == tgtword[i]){
                win++;
            }
        }

        system("cls");
    }

//check de vitoria/perda
    if (win == wordLength) {
    	std::cout << hangman[mistakes];
        printf("\nVOCÊ GANHOU!");
    }

    if (mistakes > mistakesAllowed) {
    	std::cout << hangman[10];
        printf("\nVOCÊ PERDEU!");
    }
}
