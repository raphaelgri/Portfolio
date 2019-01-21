#include <cstdio>
#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int FACE(int l1, int p, int x5,int x15,int x30,int &xs5,int &xs15,int &xs30){
        int s5, s15, s30; //azulejos usados em cada linha da face;
        for(int i = 0; i < p/30; i++){   
            s30 = l1/30;
            if(xs30 + s30 > x30){
                s15 = ((xs30+s30) - x30)*4;
                xs30 = x30;
                if(xs15 + s15 > x15){
                    s5 = ((xs15 + s15) - x15)*9;
                    xs15 = x15;
                    if((xs5 + s5) > x5){
//                      cout<<"!!!!!"<<endl;
                        return 0;
                        break;
                    }
                    else xs5 += s5;
                }
                else xs15 += s15;
            }
            else xs30 += s30;
            //sobras 30cm
              
            if(l1%30 >= 15){
                s15 = ((l1%30)/15)*2;
                if(xs15 + s15 > x15){
                    s5 = ((xs15 + s15) - x15)*9;
                    xs15 = x15;
                    if((xs5 + s5) > x5){
//                      cout<<"!!!!!"<<endl;
                        return 0;
                        break;
                    }
                    else xs5 += s5;
                }
                else xs15 += s15;   
            }
            //sobras 15cm
              
            if(l1%15 >= 5){
                s5 = ((l1%15)/5)*6;
                if((xs5 + s5) > x5){
//                  cout<<"!!!!!"<<endl;
                        return 0;
                        break;
                }
                else xs5 += s5;
            }
        }
        //linha sobra 30cm
        for(int i = 0; i < (p%30)/15; i++){
//          cout<<"ok15"<<endl;
            s15 = l1/15;
                if(xs15 + s15 > x15){
                    s5 = ((xs15 + s15) - x15)*9;
                    xs15 = x15;
                    if((xs5 + s5) > x5){
//                      cout<<"!!!!!"<<endl;
                        return 0;
                        break;
                    }
                    else xs5 += s5;
                }
                else xs15 += s15;
            if(l1%15 >= 5){
                s5 = ((l1%15)/5)*3;
                if((xs5 + s5) > x5){
//                      cout<<"!!!!!"<<endl;
                        return 0;
                        break;
                }
                else xs5 += s5;
            }   
        }
        //linha sobra 15cm
        for(int i = 0; i < (p%15)/5; i++){
//          cout<<"ok5"<<endl;
            s5 = l1/5;
                if((xs5 + s5) > x5){
                       return 0;
                        break;
                }
                else xs5 += s5; 
        }
        return 1;
}
 
 
 
int main(){
    int Xa = 0, Xb = 0, Ya = 0, Yb = 0, Za = 0, Zb = 0;
    scanf ("%d.%d %d.%d %d.%d", &Xa, &Xb, &Ya, &Yb, &Za, &Zb);
    int l1 =    (10*Xa+Xb)*10;
    int l2 =    (10*Ya+Yb)*10;
    int p  =    (10*Za+Zb)*10;
	//freopen("pis.out", "w", stdout);
    while(l1 != 0 && l2 != 0 && p != 0){
        int Eflag = 1; 
        int x5, x15, x30; //azulejos disponiveis
        cin>>x5>>x15>>x30;
        int xs5 = 0, xs15 = 0, xs30 = 0; //azulejos usados
        Eflag = FACE(l1, p, x5, x15, x30, xs5, xs15, xs30);
        if(Eflag) Eflag = FACE(l1, p, x5, x15, x30, xs5, xs15, xs30);
        if(Eflag) Eflag = FACE(l2, p, x5, x15, x30, xs5, xs15, xs30);
        if(Eflag) Eflag = FACE(l2, p, x5, x15, x30, xs5, xs15, xs30);
        if(Eflag) Eflag = FACE(l2, l1, x5, x15, x30, xs5, xs15, xs30);
         
         
        if(Eflag) printf("%d %d %d\n", xs5, xs15, xs30);
        else printf("impossivel\n");
        scanf ("%d.%d %d.%d %d.%d", &Xa, &Xb, &Ya, &Yb, &Za, &Zb);
        l1 =    (10*Xa+Xb)*10;
        l2 =    (10*Ya+Yb)*10;
        p  =    (10*Za+Zb)*10;
    }
}
 

