#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>

int main()
{
	//Mateus Menezes e Souza
	setlocale(LC_ALL,"portuguese");
  char *str, c;
  int i = 0, j = 1;

  str = (char*)malloc(sizeof(char));

  printf("Enter String : ");

  while (c != '\n') {
    // lemos inputs do teclado
    c = getc(stdin);

    // re-alocamos a memoria para guardar o proximo caractere
    str = (char*)realloc(str, j * sizeof(char));

    // guardamos o caracter fazendo o ponteiro apontar para c
    str[i] = c;

    i++;
    j++;
  }
  
  //apendemos o caractere especial de fim da string
  str[i] = '\0';


  bool e_palindromo = true;
  int f,size = (i-2);
  
  
  for(f = 0;f <= size;f++){
  	printf("%c",str[size - f]);
  }
  
  for(f = 0;f <= size;f++){
  	if(str[f] != str[size - f]){
  		e_palindromo = false;
	  }
  }
  
  if(e_palindromo == false){
  	printf("\nEssa frase não e palindromo");
  }else{
  	printf("\nEsse frase e palindromo");
  }
  
  free(str); // sempre se lembre de liberar memoria quando terminou de usa-la!
  return 0;
}
