#include <stdlib.h>
#include <stdio.h>

int main(){
	int S, T, F, A; //Saída, Tempo de viagem, Fuso, e hora de aterrissagem
	scanf("%d %d %d", &S, &T, &F);
	A = (S+T+F)%24;
	printf("%d", A);
		
}

