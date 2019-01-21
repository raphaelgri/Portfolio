#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct tarefa{
	int pts, inicio, fim;
};

int main(){
	//freopen("sol.in", "r", stdin);
	//freopen("sol.out", "w", stdout);
	int N;
	cin>>N;
	while(N != 0){
	vector <tarefa> Seg;
	vector <tarefa> Ter;
	vector <tarefa> Qua;
	vector <tarefa> Qui;
	vector <tarefa> Sex;
	vector <tarefa>::iterator it;
	int cod, pts, ini1, ini2, fim1, fim2, ini, fim;
	string dia; 
	for(int i = 0; i < N; i++){
		cin>>cod>>pts>>dia;
		scanf("%d:%d %d:%d", &ini1, &ini2, &fim1, &fim2);
		ini = ini1*60 + ini2;
		fim = fim1*60 + fim2;
		tarefa t;
		t.pts = pts;
		t.inicio = ini;
		t.fim = fim;
		if(dia == "Seg") Seg.push_back(t);
		if(dia == "Ter") Ter.push_back(t);	
		if(dia == "Qua") Qua.push_back(t);
		if(dia == "Qui") Qui.push_back(t);
		if(dia == "Sex") Sex.push_back(t);
	}
	int tpts, seg, ter, qua, qui, sex;
	vector <int> dp(1440);
	dp[0] = 0;
	tpts = 0;
	for(int k = 1; k < 1440; k++){
		dp[k] = dp[k-1];
		int i = 0;
		for(it = Seg.begin(); it != Seg.end(); it++){
			if(Seg[i].fim == k){
				dp[k] = max(dp[k], Seg[i].pts + dp[Seg[i].inicio]);
			}
			i++;
		}
	}
	
	seg = dp[1439];
	tpts += seg;
	//dp.clear();
	
	for(int k = 1; k < 1440; k++){
		dp[k] = dp[k-1];
		int i = 0;
		for(it = Ter.begin(); it != Ter.end(); it++){
			if(Ter[i].fim == k){
				dp[k] = max(dp[k], Ter[i].pts + dp[Ter[i].inicio]);
			}
			i++;
		}
	}
	
	ter = dp[1439];
	tpts += ter;
	//dp.clear();
	
	for(int k = 1; k < 1440; k++){
		dp[k] = dp[k-1];
		int i = 0;
		for(it = Qua.begin(); it != Qua.end(); it++){
			if(Qua[i].fim == k){
				dp[k] = max(dp[k], Qua[i].pts + dp[Qua[i].inicio]);
			}
			i++;
		}
	}
	
	qua = dp[1439];
	tpts += qua;
	//dp.clear();
	
	for(int k = 1; k < 1440; k++){
		dp[k] = dp[k-1];
		int i = 0;
		for(it = Qui.begin(); it != Qui.end(); it++){
			if(Qui[i].fim == k){
				dp[k] = max(dp[k], Qui[i].pts + dp[Qui[i].inicio]);
			}
			i++;
		}
	}
	
	qui = dp[1439];
	tpts += qui;
	//dp.clear();
	
	for(int k = 1; k < 1440; k++){
		dp[k] = dp[k-1];
		int i = 0;
		for(it = Sex.begin(); it != Sex.end(); it++){
			if(Sex[i].fim == k){
				dp[k] = max(dp[k], Sex[i].pts + dp[Sex[i].inicio]);
			}
			i++;
		}
	}
	
	sex = dp[1439];
	tpts += sex;
	//dp.clear();
	cout<<"Total de pontos: "<<tpts<<endl;
	cout<<"Seg: "<<seg<<endl;
	cout<<"Ter: "<<ter<<endl;
	cout<<"Qua: "<<qua<<endl;
	cout<<"Qui: "<<qui<<endl;
	cout<<"Sex: "<<sex<<endl;
	
	
	
	cin>>N;
	}
}
