#include "peta.h"
#include "point.h"
#include "petak.h"
#include "player.h"
#include "unit.h"

void empty_peta(peta *M, int NB, int NK){
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	for (int i=0; i<NB; i++){
		for (int j=0; j<NK; j++){
			petak(*M,i,j) = empty_petak(MakePOINT(i,j));
		}
	}
}

void bangun_kerajaan(peta *M){
	POINT lokasi_p1 = MakePOINT(NBrsEff(*M) - 2, 1);
	POINT lokasi_p2 = MakePOINT(1, NKolEff(*M) - 2);

	unit king_p1 = unit_petak(petak(*M,Absis(lokasi_p1),Ordinat(lokasi_p1)));
	unit king_p2 = unit_petak(petak(*M,Absis(lokasi_p2),Ordinat(lokasi_p2)));
	
	assign_unit(&king_p1, 'K');
	assign_unit(&king_p2, 'K');

	assign_petak(&(petak(*M,Absis(lokasi_p1),Ordinat(lokasi_p1))), 'T', 1, king_p1);
	assign_petak(&(petak(*M,Absis(lokasi_p2),Ordinat(lokasi_p2))), 'T', 2, king_p2);

	POINT lokasi_CL_P1 = MakePOINT(Absis(lokasi_p1),Ordinat(lokasi_p1) - 1);
	POINT lokasi_CU_P1 = MakePOINT(Absis(lokasi_p1) - 1,Ordinat(lokasi_p1));
	POINT lokasi_CR_P1 = MakePOINT(Absis(lokasi_p1),Ordinat(lokasi_p1) + 1);
	POINT lokasi_CD_P1 = MakePOINT(Absis(lokasi_p1) + 1,Ordinat(lokasi_p1));

	POINT lokasi_CL_P2 = MakePOINT(Absis(lokasi_p2),Ordinat(lokasi_p2) - 1);
	POINT lokasi_CU_P2 = MakePOINT(Absis(lokasi_p2) - 1,Ordinat(lokasi_p2));
	POINT lokasi_CR_P2 = MakePOINT(Absis(lokasi_p2),Ordinat(lokasi_p2) + 1);
	POINT lokasi_CD_P2 = MakePOINT(Absis(lokasi_p2) + 1,Ordinat(lokasi_p2));

	assign_petak(&(petak(*M,Absis(lokasi_CL_P1),Ordinat(lokasi_CL_P1))), 'C', 1, empty_unit(lokasi_CL_P1));		
	assign_petak(&(petak(*M,Absis(lokasi_CU_P1),Ordinat(lokasi_CU_P1))), 'C', 1, empty_unit(lokasi_CU_P1));
	assign_petak(&(petak(*M,Absis(lokasi_CR_P1),Ordinat(lokasi_CR_P1))), 'C', 1, empty_unit(lokasi_CR_P1));
	assign_petak(&(petak(*M,Absis(lokasi_CD_P1),Ordinat(lokasi_CD_P1))), 'C', 1, empty_unit(lokasi_CD_P1));

	assign_petak(&(petak(*M,Absis(lokasi_CL_P2),Ordinat(lokasi_CL_P2))), 'C', 1, empty_unit(lokasi_CL_P2));
	assign_petak(&(petak(*M,Absis(lokasi_CU_P2),Ordinat(lokasi_CU_P2))), 'C', 1, empty_unit(lokasi_CU_P2));
	assign_petak(&(petak(*M,Absis(lokasi_CR_P2),Ordinat(lokasi_CR_P2))), 'C', 1, empty_unit(lokasi_CR_P2));
	assign_petak(&(petak(*M,Absis(lokasi_CD_P2),Ordinat(lokasi_CD_P2))), 'C', 1, empty_unit(lokasi_CD_P2));
}

void init_peta(peta *M, int NBrsEff, int NKolEff){
	empty_peta(M, NBrsEff, NKolEff);
	bangun_kerajaan(M);
}

void display_peta(peta M){
	printf("\n");
	for (int i=0; i<NBrsEff(M); i++){
		for (int j=0; j<4*NKolEff(M)+1; j++){
			printf("*");
		}
		for (int j=0; j<4; j++){
			for (int k=0; k<NKolEff(M); k++){
				for (int l=0; l<4; l++){
					if (j!=0){
						if (l == 0){
							printf("*");
						} else if (l == 2){
							if (j == 0){
								printf("");
							} else if (j==1){
								if (isequal_petak(petak(M,i,k),empty_petak(MakePOINT(i,k)))){
									printf(" ");
								} else {
									printf("%c",jenis_petak(petak(M,i,k)));
								}
							} else if (j==2){
								if (isequal_unit(unit_petak(petak(M,i,k)),empty_unit(MakePOINT(i,k)))){
									printf(" ");
								} else {
									printf("%c",simbol(unit_petak(petak(M,i,k))));
								}
							} else {
								printf(" ");
							}
						} else {
							printf(" ");
						}
					}
				}	
				if (k == NKolEff(M) - 1 && j!=0){
					printf("*");
				}
			}
			printf("\n");
		}
	}
	for (int i=0; i<4*NKolEff(M)+1; i++) printf("*");
	printf("\n");
}



