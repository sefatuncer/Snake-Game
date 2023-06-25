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
protected: // Sadece kal�t�m alan s�n�flar eri�ebilir
	int		noktaSayisi;
	int		maksimumNoktaSayisi;
	int		cizimSekli;
	Nokta*	pNoktalar;
	Renk	renk;
};

#endif