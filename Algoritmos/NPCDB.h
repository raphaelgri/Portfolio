#include <iostream>
#include <cstdlib>
#include "NPC.h"

#ifndef NPCDB_H
#define NPCDB_H

class NPCDB{
	public:
		NPC N[10];
	NPCDB(){
		NPC cao("Cao Raivoso", 1, 15, 0, 5, 5, 1, "", -1, 0, 12, 0);
		NPC Andarilho("Andarilho", 1, 35, 0, 10, 25, 1, "", -1, 0, 18, 5);
		NPC elfo("Elfo desmembrador", 1, 30, 0, 15, 35, 2, "", -1, 0, 28, 18);
		NPC Yeti("Yeti Sanguinario", 1, 50, 10, 20, 45, 3, "", -1, 0, 35, 5);
		NPC Tigre("Tigre Dentes De Sabre", 1, 45, 0, 20, 55, 4, "", -1, 0, 35, 5);
		NPC Cavaleiro("Cavaleiro de Metal", 1, 30, 15, 10, 50, 4, "", -1, 0, 45, 35);
		NPC Cerberus("Cerberus de Onigrux", 1, 55, 0, 50, 60, 5, "", -1, 0, 55, 15);
		NPC Ilusionista("O Ilusionista", 1, 20, 100, 20, 65, 6, "", -1, 0, 60, 15);
		NPC Guardiao("Guardião de Onigrux", 1, 70, 0, 20, 50, 6, "", -1, 0, 50, 25);
		NPC Mago("Mago Supremo", 1, 70, 15, 10, 80, 8, "", -1, 0, 80, 45);
		
		
		//NPC(string n = "", bool g = 0, int HP = 0, int MP = 0, int gold = 0, int exp = 0, int Lv = 0, string nm = "", int vm = 0, bool tm = 0, int atk = 0, int def = 0)
		N[0] = cao;
		N[1] = Andarilho;
		N[2] = elfo;
		N[3] = Yeti;
		N[4] = Tigre;
		N[5] = Cavaleiro;
		N[6] = Cerberus;
		N[7] = Ilusionista;
		N[8] = Guardiao;
		N[9] = Mago;
		
		
	}
};

#endif
