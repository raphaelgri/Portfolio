#include <cstdlib>
#include "Personagem.h"
#include "NPC.h"
#include "NPCDB.h"
#include "Personagem_P.h"
#include <time.h>




#ifndef BATALHA_H
#define BATALHA_H 



using namespace std;
 
class Batalha{
    private :
        Personagem_P* PP;
        NPC inim;
        bool turn; //0 personagem principal, 1 inimigo
        bool defFlag; // 0 default, 1 defesa
    public:
        Batalha(Personagem_P * PP, NPCDB N, int i , bool turn ){
            this->PP = PP;
            this->inim = N.N[i];
            this->turn = turn;
            cout<<"apareceu: "<<inim.getNome()<<"\n";
        }
        int Dano(Personagem * P, int dan){ ;// causa dano em um personagem
            P->setHP(P->getHP()-dan);
            return P->getHP()-dan;
        }
        bool morre(Personagem *P){ //retorna se o personagem morreu
            if(P->getHP() <= 0) return 1;
            else return 0;
        }
        
        int treta(){ //retorna experiência ganha, ou -1 se perdeu a vida;
            defFlag = false; //seta defesa como false
            srand(time(NULL));
            while(morre(PP) != true && morre(&inim) != true){ //enquanto ambos estiverem vivos
                if(this->turn == 1){ // acao do NPC
                	int R =  rand()%100 + PP->getAtr().getAgi();
                	if(inim.getMP() > 10 && inim.getMagic().getValor() > 0 && inim.getMagic().getTipo()){
                		cout<<inim.getNome()<<" usou "<<inim.getMagic().getNome();
                		if(R < inim.getLV()*10) cout<<" causando "<<Dano(PP, inim.getMagic().getValor())<<" de dano."<<endl;
                		cout<<" e errou."<<endl;
					}
					else if(inim.getMP() > 10 && inim.getMagic().getValor() > 0){
						cout<<inim.getNome()<<" usou "<<inim.getMagic().getNome();
                		cout<<" e curou "<< -Dano(&inim, -inim.getMagic().getValor()) <<" de sua vida"<<endl;
					}
                	else{
                    	if(defFlag) if(inim.getAtk() > PP->getDef()+PP->getRes()){
							cout<<inim.getNome()<<" atacou!"<<endl;
								if(R < inim.getLV()*10) cout<<"Causando "<<Dano(PP, inim.getAtk() - (PP->getDef()+PP->getRes()))<<" de dano a"<<PP->getNome()<<endl; //caso o personagem esteja se defendendo e o dano for maior que a resistência
								else cout<<"E errou!"<<endl;
						}
                    	if(inim.getAtk() > PP->getDef()){
                    		cout<<inim.getNome()<<" atacou!"<<endl;
							if(R < inim.getLV()*10) cout<<"Causando "<<Dano(PP, inim.getAtk() - PP->getDef())<<" de dano a"<<PP->getNome()<<endl; //caso o ataque seja maior que a defesa;
							else cout<<"E errou!"<<endl;
						}
                	}
                    turn = 0;
                }
                else{
                    defFlag = false; // reseta defesa;
                    while(true){
                    	system("Pause");
                    	system("cls");
                    	cout<<"Seu Turno de Ataque"<<endl;
                    	cout<<"Personagem: "<<PP->getNome()<<endl;
                    	cout<<"HP: "<<PP->getHP()<<"/"<<PP->getHPmax()<<" MP: "<<PP->getMP()<<"/"<<PP->getMPmax()<<endl<<endl<<endl;
                    	cout<<"HP do "<< inim.getNome() << " :"<<inim.getHP()<<endl<<endl<<endl;
                    	cout << "============= Menu de Batalha =================" << endl;
                    	cout<<"1 - Se defender!"<<endl;
                    	cout<<"2 - Ataque com corte (precisa de arma)"<<endl;
                    	cout<<"3 - Ataque com estocada (precisa de arma)"<<endl;
                    	cout<<"4 - Soco"<<endl;
	                    cout << "================================================" << endl;
						int opcao;
	                    cin>>opcao;
	                    if(opcao == 1) //defesa
	                    {
	                    	cout<<PP->getNome()<<" se defendeu!"<<endl;
	                        defFlag = true;
	                        break;
	                        }
	                    if(opcao == 2 && PP->getArma() > 0) //corte
	                    {
	                        int R =  rand()%100 + PP->getAtr().getAgi();
	                        cout<<PP->getNome()<<" atacou com um corte!"<<endl;
	                        if(R > 40) cout<<"Causando "<<Dano(&inim, PP->getAtk())<<" de dano."<<endl;
	                        else cout<<"E errou!"<<endl;
	                        break;
	                        }
	                    if(opcao == 3 && PP->getArma() > 0) //estocada
	                    {
	                        int R =  rand()%100 + PP->getAtr().getAgi();
	                        cout<<PP->getNome()<<" atacou com uma estocada!"<<endl;
	                        if(R > 70) cout<<"Causando "<<Dano(&inim, PP->getAtk()*1.5)<<" de dano."<<endl;
	                        else cout<<"E errou!"<<endl;
	                        break;
	                    }
	                    if(opcao == 4) //soco
	                    {
	                    	cout<<PP->getNome()<<" tentou socar ";
	                    	if(inim.getGenero())cout<<" o ";
	                    	else cout<<" a ";
	                    	cout<<inim.getNome()<<endl;
	                        int R =  rand()%100 + PP->getAtr().getAgi();
	                        if(R > 30) cout<<"Causou "<<Dano(&inim, PP->getAtk()*0.5)<<" de dano."<<endl;
	                        else cout<<"E errou!"<<endl;
	                        break;
	                    }
	                    if(opcao == 5) //magia
	                    {
	                        if(PP->getMP() > 10 && PP->getMagic().getValor() > 0){
	                        	PP->setMP(PP->getMP()-10);
	                        	cout<<PP->getNome()<<" usou "<<PP->getMagic().getNome()<<"!"<<endl;
	                        	if(PP->getMagic().getTipo()) Dano(&inim, PP->getMagic().getValor());
	                        	else  Dano(PP, -PP->getMagic().getValor());
	                        	break;
							}
							else cout<<"Não tem magia ou MP!"<<endl;
	                    }
                	}
                    turn = 1;
                }
            }
        }
    };
    
#endif
