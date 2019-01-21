#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;

int main() {
	int m , n, res, v;
	res = 1;
	
	printf("Digite dois numeros entre 100 e 0 \n");
	scanf("%d",&m);
	if((m <0)||(m > 100)){
		printf("Dados invalidos, M nao pode ser menor que 0 ou maior que 100 \n");
		system("pause");
		return 0;
	}
	scanf("%d",&n);
	if((n <0)||(n > 100)){
		printf("Dados invalidos, N nao pode ser menor que 0 ou maior que 100 \n");
		system("pause");
		return 0;
	}
	if (m == n) {
		printf("Dados inválidos, M não pode ser igual a N \n");
		system("pause");
		return 0;
	}
if(m > n){
	res = m%n;
	v = n;
	
	while (res != 0){
	n = v;
	v = res;
	res = n%v;
	}}
else{
	res = n%m;
	v = m;
	
	while (res != 0){
	m = v;
	v = res;
	res = m%v;
	}}
	
	printf("Maximo divisor comum: %d \n",v);
	system("pause");
	return 0;
}
