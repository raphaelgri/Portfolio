#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	unsigned long long int N, SUM_CAR,SUM_SIT; //numero de sitios, numero de carneiros restantes e numero de sitios atacados.
	scanf("%lu", &N);
	vector<unsigned long long int> X; //vetor que armazena a quantidade de carneiros no sitio i
	vector<unsigned long long int> X2;
	X.resize(N);
	X2.resize(N);
	 //vetor que armazena se o sitio foi ou não atacado.
	for(long long int i = 0; i < N; i++){
		scanf("%llu", &X[i]); //le quantidade de carneiros no sitio i
		X2[i] = 0;
	}
	int i = 0; //posição do louco
	int prox = 0; //posição pro proximo sitio
	while(true){
		X2[i] = 1;
		prox = i;
		if(X[i]%2 == 0){ //numero de carneiros restante par
			prox--;
		}
		else{
			prox++;
		}
		if(X[i] != 0) X[i]--;
		i = prox;
		if(i < 0 || i >= N) break;
	}
	SUM_CAR = 0;
	SUM_SIT = 0;
	for(i = 0; i < N; i++){
		SUM_CAR += X[i];
		SUM_SIT += X2[i];
	}
	printf("%llu %llu\n", SUM_SIT, SUM_CAR);
}

