#ifndef PETA_H
#define PETA_H

#include "petak.h"
#include "player.h"

/* UKURAN MAKSIMUM PETA*/
#define NBrsMax 100
#define NKolMax 100

/*TIPE DATA PETA*/
typedef struct {
	petak matriks_peta[NBrsMax+1][NKolMax+1];
	int NBrsEff;
	int NKolEff;
} peta;

/*SELEKTOR PETA*/
#define petak(M,i,j) (M).matriks_peta[i][j]
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff

void empty_peta(peta *M, int NB, int NK);
/*I.S. : Sembarang
  F.S. : terbentuk peta M dengan ukuran NB x NK */

void bangun_kerajaan(peta *M);
/*I.S. : peta M
  F.S. : terbentuk kerajaan untuk player p1 dan player p2 di pojok kiri bawah (p1) dan pojok kanan atas (p2) */

void taruh_king(peta *M, player *p1, player *p2);
/*I.S. : player *p terdefinisi
  F.S. : king player ditaruh di tower player yang bersesuaian dan diinsert ke list unitnya*/

void init_peta(peta *M, int NBrsEff, int NKolEff, player *p1, player *p2);
//Menginisiasi state awal peta pada awal permainan.
//Proses : Membuat peta kosong sebesar NBRsEff * NKolEff, 

void display_peta(peta M, player P);
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