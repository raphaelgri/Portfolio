#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (){
	int N, T, temp, i, j, k; //numero de titas, tamanho da muralha
	char S[200];
	scanf("%d %d", &N, &T);
	for(i = 0; i < 100; i++){
		S[i] = 0;	
	} 
	for(i = 0; i < N; i++){
		fflush(stdin);
		fgets(S, 100, stdin);
		j = 99;
		k = 0;
		temp = 0;
		while(S[j] == 0 || S[j] == 10){
			S[j] = 0;
			j--;
		}
		while(S[j] != ' '){
			temp += (S[j]-48)*pow(10, k);
			S[j] = 0;
			k++;
			j--;
			
		}
		S[j] = '\n';
		if(temp > T) printf("%s", S);
	}
	
}


