#include "Sekil.h"
#include <GL/freeglut.h>
Sekil::Sekil()
{
	noktaSayisi	= 0;
	maksimumNoktaSayisi = 0;
	pNoktalar = 0;
	renk = Renk(1.0f , 0.0f, 0.0f);
}

void Sekil::renkAta(Renk r)
{
	renk = r;
}

void Sekil::ciz()
{
	glBegin(cizimSekli);
	renk.kullan();
	for(int i=0;i<noktaSayisi;i++)
	{
		pNoktalar[i].kullan();
	}
	glEnd();
}

void Sekil::noktaEkle(float x,float y)
{
	if(noktaSayisi == maksimumNoktaSayisi)
		return;

	pNoktalar[noktaSayisi].X = x;
	pNoktalar[noktaSayisi].Y = y;
	
	noktaSayisi++;
}