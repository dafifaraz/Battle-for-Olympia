
#ifndef PETA_H
#define PETA_H

#include "petak.h"
#include "player.h"

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

void empty_peta(peta *M, int NBrsEff, int NKolEff, player *p1, player *p2);
//Mengisi setiap petak pada peta dengan petak kosong.
//Petak kosong : petak yang belum berisi bangunan, unit, dan pemilik

void bangun_kerajaan(peta *M, player *p1, player *p2);
//Menginisiasi bangunan kerajaan dan King kedua pemain pada awal permainan.

void init_peta(peta *M, int NBrsEff, int NKolEff, player *p1, player *p2);
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

boolean isAdaMusuh(POINT P1, POINT P2, peta M);
//Memeriksa apakah terdapat musuh di antara kedua titik tersebut 

void MOVE(player P, peta *M);
//Menggerakkan unit yang sedang dipilih oleh player P ke petak yang dituju (sesuai input user)
//Proses : Memanfaatkan swap_unit

void do_recruit(player *P, POINT loc_new, peta *M);
// sub task dari recruit

void recruit(player *P, peta *M);
// melakukan recruit unit baru

#endif