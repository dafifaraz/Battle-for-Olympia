#ifndef PETA_H
#define PETA_H

#include "petak.h"

#define NBrsMax 100
#define NKolMax 100

typedef struct {
	petak matriks_peta[NBrsMax+1][NKolMax+1];
	int NBrsEff;
	int NKolEff;
} peta;

#define petak(M,i,j) (M).matriks_peta[i][j]
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff

// mengisi setiap elemen peta dengan empty petak
void empty_peta(peta *M, int NBrsEff, int NKolEff);

void bangun_kerajaan(peta *M);

void init_peta(peta *M, int NBrsEff, int NKolEff);

void display_peta(peta M);

#endif