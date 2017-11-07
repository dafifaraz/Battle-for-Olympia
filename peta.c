#include <stdio.h>
#include "pcolor.h"
#include "peta.h"
#include <stdlib.h>

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
	//Mencetak 'label' kolom petak
	printf("   ");
	for (int j = 0; j <= NKolEff(M) -1; ++j){
		if (j < 10)
			printf("%d   ", j);
		else
			printf("%d  ", j);
	}
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
			if (Milik(M,i,j) == 1){
				printf(" ");//Kemungkinan akan diedit lagi untuk unit yang sedang dipilih
				print_red(Jenis(M,i,j));
				printf(" *");
			}
			else if (Milik(M,i,j) == 2){
				printf(" ");//Kemungkinan akan diedit lagi untuk unit yang sedang dipilih
				print_blue(Jenis(M,i,j));
				printf(" *");
			}
			else
				printf(" %c *", Jenis(M,i,j));
		}
		//Menuliskan petak bagian tengah
		printf("\n%d*",i);
		for (int j = 0; j < NKolEff(M); ++j){
			if (Milik(M,i,j) == 1){
				printf(" ");//Kemungkinan akan diedit lagi untuk unit yang sedang dipilih
				print_red(Unit(M,i,j));
				printf(" *");
			}
			else if (Milik(M,i,j) == 2){
				printf(" ");//Kemungkinan akan diedit lagi untuk unit yang sedang dipilih
				print_blue(Unit(M,i,j));
				printf(" *");
			}
			else
				printf(" %c *", Unit(M,i,j));
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

void initAwal(PETA *M) {
	//Menyetel posisi awal king, castle dan tower pemain 1 (merah) 
	for (int i = 0; i < NBrsEff(*M); ++i){
		for (int j = 0; j < NKolEff(*M); ++j){
			Milik(*M,i,j) = 0;
		}
	}
	//Setting unit
	Unit(*M, NBrsEff(*M)-2, 1) = 'K';
	//Setting Kepemilikan
	Milik(*M, NBrsEff(*M)-1, 1) = 1;
	Milik(*M, NBrsEff(*M)-2, 0) = 1;
	Milik(*M, NBrsEff(*M)-2, 1) = 1;
	Milik(*M, NBrsEff(*M)-2, 2) = 1;
	Milik(*M, NBrsEff(*M)-3, 1) = 1;
	//Setting jenis petak
	Jenis(*M, NBrsEff(*M)-1, 1) = 'C';
	Jenis(*M, NBrsEff(*M)-2, 0) = 'C';
	Jenis(*M, NBrsEff(*M)-2, 1) = 'T';
	Jenis(*M, NBrsEff(*M)-2, 2) = 'C';
	Jenis(*M, NBrsEff(*M)-3, 1) = 'C';


	//Menyetel posisi awal king, castle dan tower pemain 2 (biru)
	//Setting unit
	Unit(*M, 1, NKolEff(*M)-2) = 'K';
	//Setting Kepemilikan
	Milik(*M, 0, NKolEff(*M)-2) = 2;
	Milik(*M, 1, NKolEff(*M)-3) = 2;
	Milik(*M, 1, NKolEff(*M)-2) = 2;
	Milik(*M, 1, NKolEff(*M)-1) = 2;
	Milik(*M, 2, NKolEff(*M)-2) = 2;
	//Setting jenis petak
	Jenis(*M, 0, NKolEff(*M)-2) = 'C';
	Jenis(*M, 1, NKolEff(*M)-3) = 'C';
	Jenis(*M, 1, NKolEff(*M)-2) = 'T';
	Jenis(*M, 1, NKolEff(*M)-1) = 'C';
	Jenis(*M, 2, NKolEff(*M)-2) = 'C';

	//Generate village di posisi random
	int x;
	int y;
	int n = ((NBrsEff(*M) * NKolEff(*M)) % 6) + 3; //Jumlah village yang akan dimunculkan, jumlahnya mengikuti formula yang tertera pada deklarasi 
	for (int i = 0; i < n; ++i){
		do {
			x = rand() * rand();
			y = rand() * rand();
			x %= NBrsEff(*M) - 1;
			y %= NKolEff(*M) - 1;
		} while (Milik(*M,x,y) != 0);		
		Jenis(*M,x,y) = 'V';
	}
}