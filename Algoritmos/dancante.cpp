#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int IsUpper(char l){
	if(l >= 65 && l <= 90){
		return 1;
	}
	return 0;
}

int IsLower(char l){
	if(l >= 97 && l <= 122){
		return 1;
	}
	return 0;
}

int main(){
	string c;
	while(getline(cin, c)){
		int i = 0;
		int odd = 0; //se 1 letra minuscula, se 0 letra maiuscula
		while(i < c.size()){
			if(IsLower(c[i])){
				if(!(odd%2)) c[i]-=32;
				odd++;
			}
			else if(IsUpper(c[i])){
				if(odd%2) c[i]+=32;
				odd++;
			}
			i++;
		}
		cout<<c<<endl;
	}
}
