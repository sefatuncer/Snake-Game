#include "Izgara.h"
#include <GL/freeglut.h>

Izgara::Izgara()
{
	maksimumNoktaSayisi = 300;
	pNoktalar = new Nokta[maksimumNoktaSayisi];
	cizimSekli = GL_LINES;
	noktaSayisi = 200;
	cizgiSayisi = 100;
	cizgilerArasiMesafe = 10;
	renk = Renk(0.0f,1.0f,0.0f); // Green

	for(int i=0;i<cizgiSayisi;i+=2)
	{
		pNoktalar[i].X = i*cizgilerArasiMesafe;
		pNoktalar[i].Y = 0;
		pNoktalar[i+1].X = i*cizgilerArasiMesafe;
		pNoktalar[i+1].Y = 800;
	}
	for(int i=0;i<cizgiSayisi;i+=2)
	{
		pNoktalar[i+cizgiSayisi].X = 0;
		pNoktalar[i+cizgiSayisi].Y = i*cizgilerArasiMesafe;
		pNoktalar[i+1+cizgiSayisi].X = 800;
		pNoktalar[i+1+cizgiSayisi].Y = i*cizgilerArasiMesafe;
	}
}

Izgara::Izgara(int cizgiSayisi,int cizgilerArasiMesafe)
{
	this->cizgiSayisi			= cizgiSayisi;
	this->cizgilerArasiMesafe	= cizgilerArasiMesafe;
}