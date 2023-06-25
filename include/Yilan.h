#ifndef Yilan_h
#define Yilan_h
#include "Kutu.h"

const int MAX_KUTU = 255;

class Yilan
{
public:
	Yilan();

	void	ciz();
	void	klavyeOku(unsigned char key);
	void	ilerle();

	void	kutuEkle();
	void	yemiYenile();
	bool	carpismaVarmi();

	int		kutuSayisi;
	Kutu*	Kutular[MAX_KUTU]; //Kutu adreslerini tutacak dizi.

	Kutu	yem;
};

#endif