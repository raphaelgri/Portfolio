#include <iostream>
#include "Atributos.h"

using namespace std;

 Atributos::Atributos(int Str, int Agi, int Int, int Res)
 {
 	     setStr(Str);
         setAgi(Agi);
         setInt(Int);
         setRes(Res);
 }
 
 void Atributos::setStr(int Str)
 {
 	this->Str=Str;
 }
 
 void Atributos::setAgi(int Agi)
 {
 	this->Agi=Agi;
 }
 
 void Atributos::setInt(int Int)
 {
 	this->Int=Int;
 }
 
 void Atributos::setRes(int Res)
 {
 	this->Res=Res;
 }
 
  int  Atributos::getStr()
 {
 	return Str;
 }
 
 int Atributos::getAgi()
 {
 	return Agi;
 }
 
 int Atributos::getInt()
 {
 	return Int;
 }
 
 int Atributos::getRes()
 {
 	return Res;
 }
 
