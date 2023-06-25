#ifndef Sekil_h
#define Sekil_h
#include "Nokta.h"
#include "Renk.h"

class Sekil
{
public:
	Sekil(); //Constructor
	void ciz();
	void renkAta(Renk r);
	void noktaEkle(float x,float y);
protected: // Sadece kalýtým alan sýnýflar eriþebilir
	int		noktaSayisi;
	int		maksimumNoktaSayisi;
	int		cizimSekli;
	Nokta*	pNoktalar;
	Renk	renk;
};

#endif