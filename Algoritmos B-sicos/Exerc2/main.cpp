#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;

int val, n10, n20, n50, n100;


int main() {

	printf("Digite o valor para ser retirado:");
	scanf("%d",&val);	
	n100 = val/100;
	n50 = (val%100)/50;
	n20 = ((val%100)%50)/20;
	n10 = (((val%100)%50)%20)/10;
	printf("Valor para ser retirado: R$%d,00 \n Nota(s) de R$100,00 : (%d) \n Nota(s) de R$50,00  : (%d) \n Nota(s) de R$20,00  : (%d) \n Nota(s) de R$10,00  : (%d) \n",val,n100, n50, n20, n10);
																																		

system("pause");

	return 0;
}
