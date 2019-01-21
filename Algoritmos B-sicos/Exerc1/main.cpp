#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;

int main() {
int par, caxg, caxp, sobr;

printf("Digite a quantidade de parafusos:");
scanf("%d",&par);
caxg = par/40;
caxp = (par%40)/10;
sobr = (par%40)%10;
printf("Resultado: \n Total de parafusos:%d \n Total de caixas grandes %d \n Total de caixas pequenas:%d \n Total de parafusos sobrando: %d \n",par,caxg,caxp,sobr);


system("pause");

	return 0;
}
