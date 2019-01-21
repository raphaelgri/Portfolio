#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//int iguais(char* a, char* b){
//	int i = 0;
//	int R = -1;
//	while(R == -1){
//		if(a[i] == b[i]){
//			if(a[i] == 0){
//				 R = 1;
//			}
//		}
//		else{
//			R = 0;
//		}
//		i++;
//	}
//	return R;
//}
int vflush(char a[], int N){ //zera um vetor char
	int i;
	for(i = 0; i < N; i++){
		a[i] = 0;
	}
}

int scpy(char a[], char b[]){ //recebe duas strings, a primeira é copiada na segunda.
	int c;
	for(c=0; a[c] != 0; c++){
		b[c] = a[c];
	}
	return 1;
}

int iguais (char a[], char b[]) //recebe duas strings, retorna 1 se iguais, 0 se diferentes.
{
	//printf("\n%s %s\n", a,b);
	int c;
	for(c=0; a[c]==b[c] && a[c]; c++);
	return(a[c]==b[c]);
}

int main(){
	char a[200];
	char TempS[200];
	int  TempN;
	char MAT[200][200];
	int  p = 0;
	int  pt = 0;
	int  i = 0;
	int  flag = 0;
	int  maxtab = 0;
	gets(a);
	goto E0;
	
	E0:
		if((a[p] >= 'a' && a[p] <= 'z') || (a[p] >= 'A' && a[p] <= 'Z')){
			vflush(TempS, 200);
			pt = 0;
			TempS[pt] = a[p];	
			goto E1;
		}
		else{
			if(a[p] >= '0' && a[p] <= '9'){
				TempN = a[p] - '0';
				goto E2; 
			}
			else{
				if(a[p] == ' '){
					p++;
					goto E0;
				}
				else{
					goto END;
				}
			}
		}
	E1:
		p++;
		pt++;
		if((a[p] >= 'a' && a[p] <= 'z') || (a[p] >= 'A' && a[p] <= 'Z')){
			TempS[pt] = a[p];	
			goto E1;
		}
		else{
			if(a[p] >= '0' && a[p] <= '9'){
				TempS[pt] = a[p];	
			goto E1;
			}
			else{
				if(a[p] == ' ' || a[p] == 0){
					flag = 0;
					for(i = 0; i < maxtab && !flag; i++){
						flag = iguais(TempS, MAT[i]);
						i-=flag;
					}
					if(!flag){
						maxtab++;
						scpy(TempS, MAT[i]);
					}
					printf("V(%d) ", i);
					p++;
					goto E0;
				}
				goto END;
			}
		}
	E2:
		p++;
		if(a[p] >= '0' && a[p] <= '9'){
			TempN = TempN*10 + a[p] - '0';
			goto E2; 
		}
		else{
			printf("N(%d) ", TempN);
			goto E0;
		}
		
	
	END:
		getch();
		return 0;
}
