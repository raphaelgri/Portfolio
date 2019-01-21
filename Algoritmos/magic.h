#ifndef MAGIC_H
#define MAGIC_H

class magic{
	private:
		string nome;
		int valor;
		bool tipo; //cura = 0, dano = 1;
	public:
		magic(string n = "", int v = -1, bool t = false){
			nome = n;
			valor = v;
			t = tipo;
		}
		void setNome(string N){
			nome = N;
		}
		void setValor(int v){
			valor = v;
		}
		int getValor(){
			return valor;
		}
		bool getTipo(){
			return tipo;
		}
		string getNome(){
			return nome;
		}
};

#endif
