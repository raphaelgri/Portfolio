#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i = 0; i < N; i++){
		map <string, int> users;	
		int M;
		cin>>M;
		for(int j = 0; j < M; j++){
			string Nome;
			int A;
			cin>>Nome>>A;
			users[Nome] = A;
			//cout<<users[Nome];
		}
		int total = 0;
		cin>>M;
		for(int j = 0; j < M; j++){
			string Nome;
			cin>>Nome;
			//cout<<users[Nome];
			total += users[Nome];
			total++;
		}
		cout<<total<<endl;
	}
}
