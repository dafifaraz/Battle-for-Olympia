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

void empty_peta(peta *M, int NBrsEff, int NKolEff);
//Mengisi setiap petak pada peta dengan petak kosong.
//Petak kosong : petak yang belum berisi bangunan, unit, dan pemilik

void bangun_kerajaan(peta *M);
//Menginisiasi bangunan kerajaan dan King kedua pemain pada awal permainan.

void init_peta(peta *M, int NBrsEff, int NKolEff);
//Menginisiasi state awal peta pada awal permainan.
//Proses : Membuat peta kosong sebesar NBRsEff * NKolEff, 

void display_peta(peta M);
//Menampilkan peta

int RNGbatas(int min, int maks);
//Random Number Generator dengan batas min sampai maks
//Memanfaatkan fungsi rand() dari stdlib C

void PasangDesa(int jumlah_village, peta *M);
//Memasang Village di Peta yang telah terdefinisi ukurannya
//Village dipasang secara random, setengah jumlahnya dipasang di bagian kiri peta, dan sisanya di bagian kanan peta.

#endif