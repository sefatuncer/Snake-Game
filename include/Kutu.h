#ifndef Kutu_h
#define Kutu_h
#include "Sekil.h"

const int YON_SAG		= 1;
const int YON_SOL		= 2;
const int YON_YUKARI	= 3;
const int YON_ASAGI		= 4;

	class Kutu:public Sekil
	{
	public:
		int boyut;
		int yon;
		int oncekiYon;
		Kutu();
		Nokta baslangicNoktasiniGetir();
		void ilerle();
		void pozisyonAta(float x,float y);
		void yonDegistir(int yeniYon);
		void rasgeleRenk();
	};

#endif