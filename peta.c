#include <stdio.h>
#include "pcolor.h"
#include "peta.h"

POINT pojokBawah(PETA M){
	POINT P;

	Absis(P) = NBrsEff(M) - 1;
	Ordinat(P) = 0;

	return P;
}

POINT pojokAtas(PETA M){
	POINT P;

	Absis(P) = 0;
	Ordinat(P) = NKolEff(M) - 1;

	return P;
}

void MAP(PETA M){
	//KAMUS LOKAL
	int kol = 0;

	//Mencetak 'label' kolom petak
	printf(" ");
	for (int j = 1; j <= 4 * NKolEff(M) + 1; ++j){
		if (j % 4  == 0){
			printf("%d", kol);
			kol += 1;
		}
		else
			printf(" ");
	}
	kol = 0;
	//Mencetak batas peta
	printf("\n *");
	for (int j = 0; j < 4 * NKolEff(M); ++j){
		printf("*");
	}
	//Mwncetak petak-petak pada peta
	for (int i = 0; i < NBrsEff(M); ++i){
		//Menuliskan petak bagian atas 
		printf("\n *");
		for (int j = 0; j < NKolEff(M); ++j){
			printf(" %c *", Jenis(M,i,j)); //Nanti diedit lagi (buat nunjukkin kepemilikannya)
		}
		//Menuliskan petak bagian tengah
		printf("\n%d*",i);
		for (int j = 0; j < NKolEff(M); ++j){
			printf(" %c *", Unit(M,i,j)); //Nanti diedit lagi 
		}
		//Menuliskan petak bagian bawah
		printf("\n *");
		for (int j = 0; j < NKolEff(M); ++j){
			printf("   *"); //Nanti diedit lagi 
		}
		//Mencetak batas peta
		printf("\n *");
		for (int j = 0; j < 4 * NKolEff(M); ++j){
			printf("*");
		}
	}
}
