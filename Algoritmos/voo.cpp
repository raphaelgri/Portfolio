
/* 
 * File:   main.cpp
 * Author: Paulo
 *
 * Created on 12 de Fevereiro de 2014, 10:44
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <time.h> 

using namespace std;


// qual o voo
int main()
{
    
    int N, B, E;
    cin>>N;
    //freopen("file.txt","w",stdout);    
    for(int i=0; i < N; i++)
    {
      int S = 0;
      for(int j=N-1; j >= 0; j--)
      {
         cin>>B;
         E = (int)pow(2,j);
         S = S + B*E; 
      }
      cout<<"SC"<<i+1<<" "<<S<<endl;
    }
       
    return 0;
}
