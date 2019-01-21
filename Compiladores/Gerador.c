#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(){
	char S[1000];
	int Ns = 0, i;
	printf("Quantos simbolos tem o alfabeto? \n");
	scanf("%d", &Ns);
	
	
	for(i = 0; i < Ns; i++ ){
		printf("Qual o símbolo %d? \n", i+1);
		fflush(stdin);
		scanf("%c", &S[i]);
	}
	
	
}
