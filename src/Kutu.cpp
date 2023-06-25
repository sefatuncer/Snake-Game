#include "Kutu.h"
#include <iostream>
#include <GL/freeglut.h>

Kutu::Kutu()
{
	cizimSekli = GL_TRIANGLES;
	noktaSayisi = 6;
	boyut = 20;
	pNoktalar = new Nokta[noktaSayisi];
	yon = YON_SAG;
	pozisyonAta(200,200);
	rasgeleRenk();
}

Nokta Kutu::baslangicNoktasiniGetir() //Bulunduðu koordinat (x,y)
{
	return pNoktalar[1]; // Çarpýþma kontrolü için
}

void Kutu::ilerle()
{
	switch(yon)
	{
	case YON_SOL:
		for(int i=0;i<noktaSayisi;i++)
			pNoktalar[i].X -= boyut;
		break;
	case YON_SAG:
		for(int i=0;i<noktaSayisi;i++)
			pNoktalar[i].X += boyut;
		break;
	case YON_YUKARI:
		for(int i=0;i<noktaSayisi;i++)
			pNoktalar[i].Y += boyut;
		break;
	case YON_ASAGI:
		for(int i=0;i<noktaSayisi;i++)
			pNoktalar[i].Y -= boyut;
		break;
	}
}

void Kutu::yonDegistir(int yeniYon)
{
	if(yon == YON_SAG && yeniYon == YON_SOL)
		return;
	if(yon == YON_SOL && yeniYon == YON_SAG)
		return;
	if(yon == YON_YUKARI && yeniYon == YON_ASAGI)
		return;
	if(yon == YON_ASAGI && yeniYon == YON_YUKARI)
		return;
	yon = yeniYon;
}

void Kutu::pozisyonAta(float x,float y)
{
	pNoktalar[0] = Nokta(x,y+boyut);	     // V0
	pNoktalar[1] = Nokta(x,y);			    // V1
	pNoktalar[2] = Nokta(x+boyut,y);	   // V2

	pNoktalar[3] = Nokta(x+boyut,y+boyut);  // V3
	pNoktalar[4] = Nokta(x,y+boyut);	   // V0
	pNoktalar[5] = Nokta(x+boyut,y);	  // V2
}



void Kutu::rasgeleRenk()
{
	float r = (rand()%255)/255.0f;
	float g = (rand()%255)/255.0f;
	float b = (rand()%255)/255.0f;

	renk = Renk(r,g,b);
}
