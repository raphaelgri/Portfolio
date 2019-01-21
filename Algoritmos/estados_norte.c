#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	char S[200];
	scanf("%s", S);
	if(strcmp(S, "para") == 0 || strcmp(S, "roraima") == 0 || strcmp(S, "amazonas") == 0 || strcmp(S, "acre") == 0 || strcmp(S, "amapa") == 0 || strcmp(S, "rondonia") == 0 || strcmp(S, "tocantins") == 0 ){
		printf("Regiao Norte\n");
	}
	else{
		printf("Outra regiao\n");
	}
	
}
