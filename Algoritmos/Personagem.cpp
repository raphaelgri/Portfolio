#include <iostream>
#include "Personagem.h"

using namespace std;

Personagem::Personagem(string nome, bool genero)
{
	setNome(nome);
	setGenero(genero);
}

void Personagem::setNome(string nome)
{
	this->nome=nome;
}

void Personagem::setGenero(bool genero)
{
	this->genero=genero;
}
string Personagem::getNome()
{
	return nome;
}

bool Personagem::getGenero(){
	return genero;
}

void Personagem::setHP(int h){
    	
}

void Personagem::setMP(int M){
	
}

int Personagem::getHP(){
	
}

int Personagem::getMP(){
	
	
}

