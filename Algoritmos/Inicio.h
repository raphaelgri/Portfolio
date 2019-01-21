#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "NPC.h"
#include "MagicDB.h"
#include "Magic.h"
#include "Batalha.h"

void InicializaPersonagem(){
	cout<<"Criando Personagem..."<<endl;
	MagicDB MDB;
	NPCDB NDB;
	string nome;
	int S = 3, A = 3, I = 3, R = 3;
	char g = '0';
	char opt = '0';
	while(true){
		cout<<"Escolha um nome para seu personagem: "<<endl;
		fflush(stdin);
		getline(cin, nome);
		system("cls");
		cout<<nome<<endl;
		cout<<"Este e o nome que voce escolheu? S/N"<<endl;
		cin>>opt;
		if(opt == 'S') break;
		else system("cls");
	}
	system("cls");
	while(true){
		cout<<"Digite agora o genero do personagem, f para feminino e m para masculino."<<endl;
		while(g != 'f' && g != 'm'){
			cin>>g;
			system("cls");
		}
		if(g == 'm') cout<<nome<<" eh um homem? S/N"<<endl;
		if(g == 'f') cout<<nome<<" eh um mulher? S/N"<<endl;
		cin>>opt;
		if(opt == 'S') break;
		else system("cls");
	}
	while(true){
		cout<<"Escolha agora o atributo principal de seu personagem."<<endl;
		cout<<"A - Agilidade, aumenta a chance de acerto durante o combate"<<endl;
		cout<<"F - Força, aumenta o dano causado por um ataque e a vida"<<endl;
		cout<<"I - Aumenta o dano de magia, e quantidade de MP"<<endl;
		cout<<"R - Aumenta o HP(vida)"<<endl;
		while(opt != 'R' && opt != 'I' && opt != 'F' && opt != 'A'){
			cin>>opt;
			system("cls");
		}
		if(opt == 'R') R++;
		if(opt == 'F') S++;
		if(opt == 'A') A++;
		if(opt == 'I') I++;
		break;
	}
	Personagem_P Player(nome, true, R*10 + S/2, I*10, 300, 0, S, A, I, R);
	Player();
	int i=0;
	while(true){
		cout<<"Antes de iniciar sua jornada, deve ser feita uma escolha:"<<endl;
		cout<<"1 - Seu personagem era um aprendiz de mago, e aprendeu a conjurar chamas para se defender"<<endl;
		cout<<"2 - "<<Player.getNome()<<" era ";
		if(Player.getGenero())cout<<" um ";
		else cout<<" uma ";
		cout<<"aprendiz de espadachim, e trouxe consigo uma espada."<<endl;
		cout<<"3 - "<<Player.getNome()<<" era ";
		if(Player.getGenero())cout<<" um ";
		else cout<<" uma ";
		cout<<"aprendiz de cavaleiro, e trouxe consigo uma armadura."<<endl;
		cout<<"4 - "<<Player.getNome()<<" era ";
		if(Player.getGenero())cout<<" um ";
		else cout<<" uma ";
		cout<<"aprendiz de curandeiro, e aprendeu magias de cura."<<endl;
		while(opt != '1' && opt != '2' && opt != '3' && opt!= '4'){
			cin>>opt;
			system("cls");
		}
		if(opt == '1') Player.aprendeMagic(MDB.M[1]);
		if(opt == '2') Player.setArma(5);
		if(opt == '3') Player.setDef(5);
		if(opt == '4') Player.aprendeMagic(MDB.M[5]);
		break;
	}
	do 
	{
		Batalha first(&Player, NDB,i, 0);
		Player.levelup();
		i++;
		if(first.treta() > 0) {
			cout<<"Ganhou!"<<endl;
			system("cls");
		}
		
		if(first.morre(&Player)==true){
			cout<<"morreuuuuu \n";
			system("pause");
			return;
			
			
		}
	}while(i<10);
		
	
	
	
}

int inicio(){
	int o;
	while(o != 0){
		cout<<"Digite 1 para iniciar o jogo, e 0 caso queira sair."<<endl;
		cin>>o;
		if(o == 1){
			system("cls");
			InicializaPersonagem();
			break;
		}
	}
}

