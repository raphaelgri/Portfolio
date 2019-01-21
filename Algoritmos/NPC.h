#include <iostream>
#include "Personagem.h"
#include "Atributos.h"
#include "Invent.h"
#include "magic.h"

#ifndef NPC_H
#define NPC_H

using namespace std;

class NPC:public Personagem{
	private:
		string nome;
		bool g;
		int HP, MP, gold, atk, def, exp, lv;
		int arma;
		magic m;
		
	public:
	NPC(string n = "", bool g = 0, int HP = 0, int MP = 0, int gold = 0, int exp = 0, int Lv = 0, string nm = "", int vm = 0, bool tm = 0, int atk = 0, int def = 0):Personagem(n, g){
	    setHP(HP);
		setMP(MP);
		setGold(gold);
		setExp(exp);
		setLv(Lv);	
		setAtk(atk);
		setDef(def);
        arma = 20;
        def = 0;
        m.setValor(-1);
        string NomeNpc();
	}

	void setHP(int HP)
	{
		this->HP=HP;
	}
	
	void setMP(int MP)
	{
		this->MP=MP;
	}
	
	void setGold(int gold)
	{
		this->gold=gold;
	}
	
	void setExp(int exp)
	{
		this->exp=exp;
	}
	void setLv(int L){
		lv = L;
	}
	void setAtk(int atk){
		this->atk = atk;
	}
	void setDef(int def){
		this->def = def;
	}
	int getHP()
	{
		return HP;
	}
	
	int getMP()
	{
		return MP;
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
	
	magic getMagic(){
		return m;
	}
	
	
};
#endif
