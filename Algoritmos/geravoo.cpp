#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	srand(time(NULL));
	freopen("vooin.txt", "w", stdout);
	for(int i = 0; i < 10; i++){
			int N, N2;
			N = rand()%5;
			for(int j = 0; j < N; j++){
				N2 = rand()%16;
				printf("%d\n", N2);
				for(int k = 0; k < N2;k++){
					for(int k = 0; k < N2;k++){
						if(k!=0){
							printf(" ");
						}	
						printf("%d", rand()%2);	
					}	
					printf("\n");	
				}
			}
			
	}
}
