#include <iostream>
#include <cstdlib>
#include "Magic.h"

#ifndef MAGICDB_H
#define MAGICDB_H

class MagicDB{
	public:
		magic M[10];
	MagicDB(){
	magic c1("Chamas I", 12, 1);
	magic c2("Chamas II", 24, 1);
	magic c3("Chamas III", 48, 1);
	magic b1("Bola de Fogo I", 50, 1);
	magic b2("Bola de Fogo II", 100, 1);
	magic cc1("Cura I", 15, 0);
	magic cc2("Cura II", 30, 0);
	magic cc3("Cura III", 60, 0);
	M[0] = c1;
	M[1] = c2;
	M[2] = c3;
	M[3] = b1;
	M[4] = b2;
	M[5] = cc1;
	M[8] = cc2;
	M[9] = cc3;
	}
};

#endif
