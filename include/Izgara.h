#ifndef Izgara_h
#define Izgara_h
#include "Sekil.h"

class Izgara:public Sekil
{
public:
	Izgara();
	Izgara(int cizgiSayisi,int cizgilerArasiMesafe);
	int cizgilerArasiMesafe;
	int cizgiSayisi;
};

#endif