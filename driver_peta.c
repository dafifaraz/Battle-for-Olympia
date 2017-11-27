#include <stdio.h>
#include "peta.h"

int main(){
	peta M;
	player P1, P2;
	NBrsEff(M) = 0;
	NKolEff(M) = 0;

	// Ngetes Empty Peta
	empty_peta(&M, 10, 15);
	printf("INI HARUSNYA SEPULUH : %d \n", NBrsEff(M));
	printf("INI HARUSNYA LIMABELAS : %d \n", NKolEff(M));
	// Ngetes display peta (sekalian ngetes empty peta)
	display_peta(M, P1);

	// Ngetes bangun kerajaan
	// bangun_kerajaan(&M);
	// display_peta(M, P1);

	// Ngetes taruh king
	// taruh_king(&M, &P1, &P2);
	// display_peta(M, P1);

	// Ngetes init peta
	init_peta(&M, 10, 15, &P1, &P2);

	
	return 0;
}