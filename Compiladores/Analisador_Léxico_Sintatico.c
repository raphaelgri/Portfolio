#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


typedef struct{
	int pos;
	char * cont[200];
	char under;
}s_stack;

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
	char TempC;
	int  TempN;
	char MAT[200][200];
	char * PRE[9];
	char SINT[200];
	int pex = 0;
	s_stack SP;
	SP.pos = 0;
	SP.under = 'f';
	PRE[0] = "IF";		PRE[5] = "READ";
	PRE[1] = "THEN";	PRE[6] = "PRINT";
	PRE[2] = "ELSE";	PRE[7] = "END";
	PRE[3] = "GOTO";	PRE[8] = "LET";
	PRE[4] = "OF";
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
					if(a[p] == 0){
						goto END;
					}
					else{
						if(a[p] == '+' || a[p] == '-' || a[p] == '/' || a[p] == '*'){
							SINT[pex] = 'E';
							pex++;
						}
						if(a[p] == '('){
							SP.pos++;
							SP.cont[SP.pos] = '(';
						}
						if(a[p] == ')'){
							if(SP.pos > 0) SP.pos--;
							else(SP.under = 't');
						}
						if(a[p] == ':'){
							goto E3;
						}
						else{
							if(a[p] == '%'){
								pt = 0;
								TempS[pt] = '%';
								goto E5;
							}
							else{
								goto E6;
							}
						}
					}
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
					flag = 0;
					for(i = 0; i < 9 && !flag; i++){ //varre o array de palavras reservadas
						flag = iguais(TempS, PRE[i]);
						if(flag) printf("P(%d)", i);
					}
					for(i = 0; i < maxtab && !flag; i++){ //varre a tabela de variaveis
						flag = iguais(TempS, MAT[i]);
						if(flag) printf("V(%d)", i);
						SINT[pex] = 'N';
						pex++;
					}
					if(!flag){
						maxtab++; //aumenta tabela
						scpy(TempS, MAT[i]); //copia nova variavel para a tabela
						printf("V(%d)", i);
						SINT[pex] = 'N';
						pex++;
					}
					goto E0;
			}
		}
	E2:
		p++;
		if(a[p] >= '0' && a[p] <= '9'){
			TempN = TempN*10 + a[p] - '0';
			goto E2; 
		}
		else{
			printf("N(%d)", TempN);
			SINT[pex] = 'N';
			pex++;
			goto E0;
		}
	E3:
		p++;
		if(a[p] == '='){
			SINT[pex] = 'E';
			pex++;
			goto E4;
		}
		else{
			printf(":");
			goto E0;
		}
	E4:
		p++;
		printf(":=");
		goto E0;
	E5:
		p++;
		pt++;
		TempS[pt] = a[p];
		if(a[p] == '\n' || a[p] == 0){
			printf("%s", TempS);
			goto E0;
		}
		else{
			goto E5;
		}		
	E6:
		TempC = a[p];
		printf("%c", TempC);
		p++;
		goto E0;
	
	END:
		printf("\n%s\n", SINT);
		printf("%d", SP.pos);
		SINT[pex] = 0;
		pex = 0;
		goto SE0;
		SE0:
			if(SINT[pex] == 'N'){
				pex++;
				goto SE1;
			}
			else{
				if(SINT[pex] == 0){
					if(SP.under == 'f'){
						if(SP.pos == 0){
							goto SACEITA;
						}
						else{
							goto SREJEITA;
						}
					}
					else{
						goto SREJEITA;
					}
				}
				else{
					goto SREJEITA;
				}
			}
		SE1:
			if(SINT[pex] == 'E'){
				pex++;
				goto SE2;
			}
			else{
				if(SINT[pex] == 0){
					if(SP.under == 'f'){
						if(SP.pos == 0){
							goto SACEITA;
						}
						else{
							goto SREJEITA;
						}
					}
					else{
						goto SREJEITA;
					}
				}
				else{
					goto SREJEITA;
				}
			}
		SE2:
			if(SINT[pex] == 'N'){
				pex++;
				goto SE1;
			}
			else{
				goto SREJEITA;
			}
		SACEITA:
			printf("\nACEITA\n");
			goto FIM;
		SREJEITA:
			printf("\nREJEITA\n");
			goto FIM;
	FIM:
		SP.pos = 0;
		pex = 0;
		gets(a);
		p = 0;
		pt = 0;
		flag = 0;
		i = 0;
		maxtab = 0;
		goto E0;
		return 0;
}
