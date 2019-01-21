#include <iostream>
#ifndef PERSONAGEM_H
#define PERSONAGEM_H

using namespace std;

class Personagem{
	private:
		string nome; //
		bool genero; //bool (0 – mulher, 1 – homem)
	public:
		Personagem(string=0, bool=true);
		void setNome(string);
		void setGenero(bool);
		string getNome();
		bool getGenero();
		virtual void setHP(int)=0; //não há sentido fazer isso
		virtual void setMP(int)=0;
		virtual int  getHP();
		virtual int  getMP();
		
};
#endif
