#include <iostream>
#include "Personagem.h"
#include "Atributos.h"
#include "Invent.h"
#include "magic.h"

#ifndef PERSONAGEM_P_H
#define PERSONAGEM_P_H

using namespace std;

class Personagem_P:public Personagem{
	private:
		string nome;
		bool g;
		int HP, MP, gold, HPmax, MPmax, atk, def, exp, lv, expUp;
		int arma;
		Atributos atr;
		magic m;
		Invent inv;
		
	public:
	Personagem_P(string n, bool g, int HP, int MP, int gold, int exp, int S, int A, int I, int R):Personagem(n, g){
	    setHP(HP);
		setMP(MP);
		setGold(gold);
		setExp(exp);
        lv=1;
		expUp=20;	
        arma = 20;
        def = 0;
        m.setValor(-1);
        atr.setAgi(A);
        atr.setRes(R);
        atr.setStr(S);
        atr.setInt(I);
	}

	void setHP(int HP)
	{
		this->HP=HP;
	}
	
	void setMP(int MP)
	{
		this->MP=MP;
	}
	void setDef(int d){
		def = d;
	}
	void setGold(int gold)
	{
		this->gold=gold;
	}
	
	void setExp(int exp)
	{
		this->exp=exp;
	}
	
	int getHP()
	{
		return HP;
	}
	
	int getMP()
	{
		return MP;
	}
	
	int getHPmax()
	{
		return HPmax;
	}
	
	int getMPmax()
	{
		return MPmax;
	}
	
	int getAtk()
	{
		return atk;
		
	}
	
	int getGold()
	{
		return gold;
	}
	
	int getDef()
	{
		return def;
	}
	
	int getEXP()
	{
		return exp;
	}
	
	int getLV()
	{
		return lv;
	}
	int getRes(){
		return atr.getRes();
	}
	int getArma(){
		return arma;
	}
	int setArma(int dano){
		arma = dano;
	}
	void Regen(){
		HP = HPmax;
		MP = MPmax;
	}
	magic getMagic(){
		return m;
	}
	Atributos getAtr(){
		return atr;
	}
	void aprendeMagic(magic m){
		this->m = m;
	}
int operator()()
{
	this->HPmax=(atr.getStr())*2+(atr.getRes()*10);
	this->MPmax=(atr.getInt())*10;
	this->atk=(atr.getStr())+(atr.getAgi() + arma);//+arma;
	//this->def=armadura;
	return 1; 
}

int levelup()
{
	if(getEXP()==expUp)
	{
		lv++;
		expUp*=2;
		char opt;
		int S = atr.getStr();
		int I = atr.getInt();
		int R = atr.getRes();
		int A = atr.getAgi();
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
		if(opt == 'R') atr.setRes(R+1);
		if(opt == 'F') atr.setStr(S+1);
		if(opt == 'A') atr.setAgi(A+1);
		if(opt == 'I') atr.setInt(I+1);
		break;
	}	
		return 1;
	}
	else return 0;
}
};
#endif
