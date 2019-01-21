#include <iostream>
#ifndef ATRIBUTOS_H
#define ATRIBUTOS_H

using namespace std;


class Atributos{
    private:
	   int Str, Agi, Int, Res;
	public:
	   Atributos(int=0, int=0, int=0, int=0);
	   void setStr(int);
	   void setAgi(int);
	   void setInt(int);
	   void setRes(int);
	   int  getStr();
	   int  getAgi();
	   int  getInt();
	   int  getRes();	
};
#endif
