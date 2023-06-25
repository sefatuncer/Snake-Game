#include "Yilan.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Yilan::Yilan()
{
	srand(time(NULL));
	Kutular[0] = new Kutu;
	kutuSayisi = 1;
	for(int i=1;i<6;i++) // yýlanýn ilk uzunluðu
	{
		kutuEkle();
	}

	yem.renkAta(Renk(0.0f,0.0f,1.0f)); // blue
}

void Yilan::ilerle() // kutular ilerledikten sonra ekstra kutu olusmasý lazým
{
	yemiYenile();
	for(int i=0;i<kutuSayisi;i++)
	{
		Kutular[i]->ilerle();
	}

	/* KUYRUK YÖNÜ BELÝRLEME */
	for(int i=0;i<kutuSayisi;i++)
	{
		Kutular[i]->oncekiYon = Kutular[i]->yon;
	}
	for(int i=1;i<kutuSayisi;i++)
	{
		Kutular[i]->yon = Kutular[i-1]->oncekiYon;
	}
	/* -------------------- */
	kutuEkle();
}

void Yilan::ciz()
{
	for(int i=0;i<kutuSayisi;i++)
	{
		Kutular[i]->ciz();
	}
}

bool Yilan::carpismaVarmi()
{
	if(Kutular[0]->baslangicNoktasiniGetir().X < 0)
		return true;
	if(Kutular[0]->baslangicNoktasiniGetir().Y < 0)
		return true;
	if(Kutular[0]->baslangicNoktasiniGetir().X > 780)
		return true;
	if(Kutular[0]->baslangicNoktasiniGetir().Y > 580)
		return true;
	for(int i=1;i<kutuSayisi;i++)
		if(Kutular[0]->baslangicNoktasiniGetir() == Kutular[i]->baslangicNoktasiniGetir())
			return true;
	return false;
}

void Yilan::yemiYenile()
{
	if(Kutular[0]->baslangicNoktasiniGetir() == yem.baslangicNoktasiniGetir())
	{
		float x_rand = (rand()%40)*20; // 800 width
		float y_rand = (rand()%30)*20; // 600 height
		for(int i=0;i<kutuSayisi;i++)
			if(x_rand == Kutular[i]->baslangicNoktasiniGetir().X && y_rand == Kutular[i]->baslangicNoktasiniGetir().Y)
			{
				x_rand = (rand()%40)*20;
				y_rand = (rand()%30)*20;
				i = 0;
			}
			yem.pozisyonAta(x_rand,y_rand);
	}
	yem.ciz();
}

void Yilan::kutuEkle() // Kuyruða eleman ekleme
{
	if(Kutular[0]->baslangicNoktasiniGetir() == yem.baslangicNoktasiniGetir())
	{
		Kutular[kutuSayisi] = new Kutu;
		Kutular[kutuSayisi]->rasgeleRenk();
		/* Eklenen kutunun pozisyonu */
		if(Kutular[kutuSayisi]->yon == YON_SAG)
			Kutular[kutuSayisi]->pozisyonAta(Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().X-20,Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().Y);
		else if(Kutular[kutuSayisi]->yon == YON_SOL)
			Kutular[kutuSayisi]->pozisyonAta(Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().X+20,Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().Y);
		else if(Kutular[kutuSayisi]->yon == YON_YUKARI)
			Kutular[kutuSayisi]->pozisyonAta(Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().X,Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().Y-20);
		else if(Kutular[kutuSayisi]->yon == YON_ASAGI)
			Kutular[kutuSayisi]->pozisyonAta(Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().X,Kutular[kutuSayisi-1]->baslangicNoktasiniGetir().Y+20);
		kutuSayisi++;
		//for(int i=1;i<kutuSayisi;i++) // boyut = 20
		//{
		//	if(Kutular[i]->yon == YON_SAG)
		//		Kutular[i]->pozisyonAta(Kutular[i-1]->baslangicNoktasiniGetir().X-20,Kutular[i-1]->baslangicNoktasiniGetir().Y);
		//	else if(Kutular[i]->yon == YON_SOL)
		//		Kutular[i]->pozisyonAta(Kutular[i-1]->baslangicNoktasiniGetir().X+20,Kutular[i-1]->baslangicNoktasiniGetir().Y);
		//	else if(Kutular[i]->yon == YON_YUKARI)
		//		Kutular[i]->pozisyonAta(Kutular[i-1]->baslangicNoktasiniGetir().X,Kutular[i-1]->baslangicNoktasiniGetir().Y-20);
		//	else if(Kutular[i]->yon == YON_ASAGI)
		//		Kutular[i]->pozisyonAta(Kutular[i-1]->baslangicNoktasiniGetir().X,Kutular[i-1]->baslangicNoktasiniGetir().Y+20);
		//}
	}
}

void Yilan::klavyeOku(unsigned char key)
{
	switch (key)
	{
	case 'd':
	case 'D':
		Kutular[0]->yonDegistir(YON_SOL);
		break;
	case 'g':
	case 'G':
		Kutular[0]->yonDegistir(YON_SAG);
		break;
	case 'r':
	case 'R':
		Kutular[0]->yonDegistir(YON_YUKARI);
		break;
	case 'f':
	case 'F':
		Kutular[0]->yonDegistir(YON_ASAGI);
		break;
	}
}


