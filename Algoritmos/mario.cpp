#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <climits>
 
using namespace std;
 
 

 
 
int CS(int *A, int N, int L){
    int q = INT_MAX; 
   
    for(int i = 0; i <= L-N; i++){
    	//printf("ok!\n");
    	int f = 0;
        q = min(q,CS_AUX(A, i, N+i-1, &f));
        //printf("%d\n", q);
    }
    return q;
}
 
int main(){
    int N, L;
    scanf("%d %d", &N, &L);
    while(N != 0 && L != 0){
        int A[L];
        for(int i = 0; i < L; i++){
            scanf("%d", &A[i]);
        }   
		printf("%d\n", CS(A, N, L));  
        scanf("%d %d", &N, &L); 
    }
    return 0;
}
