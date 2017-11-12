#ifndef PETA_H
#define PETA_H

#include "petak.h"

const int NBrsMax = 100;
const int NKolMax = 100;

typedef struct {
	PETAK[NBrsMax+1][NKolMax+1];
	int NBrsEff;
	int NKolEff;
} peta;

#define petak(M,i,j) M.Petak[i][j]
#define NBrsEff(M) M.NBrsEff
#define NKolEff(M) M.NKolEff

// mengisi setiap elemen peta dengan empty petak
void empty_peta(peta *M, int NBrsEff, int NKolEff);

void bangun_kerajaan(peta *M);

void init_peta(peta *M, int NBrsEff, int NKolEff);

void display_peta(peta *M);


#endif