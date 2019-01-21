#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
	int D, P, R, B;
	cin>>D>>P>>R>>B;
	int CD[D], CP[P];
	for(int i = 0; i < D; i++){
		cin>>CD[i];
	}
	for(int i = 0; i < P; i++){
		cin>>CP[i];
	}
	stack <int> RD[D];
	stack <int> RP[P];
	int temp1, temp2;
	for(int i = 0; i < R; i++){
		cin>>temp1>>temp2;
		RD[temp1].push(temp2);
		RP[temp2].push(temp1);
	}
	
	
	
	
	
	
	
}
