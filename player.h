#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "petak.h"
#include <stdlib.h>
#include <stdio.h>

/***********************	LIST OF UNIT 	**************************/

#define Nil NULL

typedef struct t_unitlist *add_unit;
typedef struct t_unitlist {
	unit info_unit;
	add_unit next_unit;
} unitlist;
typedef struct {
	add_unit First_unit;
} listunit;

#define Info_unit(P) (P)->info_unit
#define Next_unit(P) (P)->next_unit
#define First_unit(L) (L).First_unit

boolean IsEmpty_listunit(listunit L);

void CreateEmpty_listunit(listunit *L);

add_unit Alokasi_listunit(unit X);

void Dealokasi_listunit(add_unit *P);

add_unit Search_listunit(listunit l, unit X);

void InsVFirst_listunit (listunit *L, unit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast_listunit (listunit *L, unit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_listunit (listunit *L, unit *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info_unit disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast_listunit (listunit *L, unit *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info_unit disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst_listunit (listunit *L, add_unit P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-add_unit P sebagai elemen pertama */
void InsertAfter_listunit (listunit *L, add_unit P, add_unit Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast_listunit (listunit *L, add_unit P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_listunit (listunit *L, add_unit *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP_listunit (listunit *L, unit X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradd_unit P, dengan Info_unit(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info_unit(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast_listunit (listunit *L, add_unit *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter_listunit (listunit *L, add_unit *Pdel, add_unit Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next_unit(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/***********************	LIST OF PETAK 	**************************/

typedef struct t_petaklist *add_petak;
typedef struct t_petaklist {
	petak info_petak;
	add_petak next_petak;
} petaklist;
typedef struct {
	add_petak First_petak;
} listpetak;

#define Info_petak(P) (P)->info_petak
#define Next_petak(P) (P)->next_petak
#define First_petak(L) (L).First_petak

boolean IsEmpty_listpetak(listpetak L);

void CreateEmpty_listpetak(listpetak *L);

add_petak Alokasi_listpetak(petak X);

void Dealokasi_listpetak(add_petak *P);

add_petak Search_listpetak(listpetak l, petak X);

void InsVFirst_listpetak (listpetak *L, petak X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast_listpetak (listpetak *L, petak X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_listpetak (listpetak *L, petak *X);
/* I.S. listpetak L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info_petak disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast_listpetak (listpetak *L, petak *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info_petak disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst_listpetak (listpetak *L, add_petak P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-add_petak P sebagai elemen pertama */
void InsertAfter_listpetak (listpetak *L, add_petak P, add_petak Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast_listpetak (listpetak *L, add_petak P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_listpetak (listpetak *L, add_petak *P);
/* I.S. listpetak tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP_listpetak (listpetak *L, petak X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradd_petak P, dengan Info_petak(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info_petak(P)=X, maka list tetap */
/* listpetak mungkin menjadi kosong karena penghapusan */
void DelLast_listpetak (listpetak *L, add_petak *P);
/* I.S. listpetak tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter_listpetak (listpetak *L, add_petak *Pdel, add_petak Prec);
/* I.S. listpetak tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next_petak(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */


/***********************	PLAYER 	************************/
typedef struct {
	int gold;
	listunit list_unit;
	listpetak list_petak;
	int income;
	int upkeep;
	char warna;
	char simbol;
} player;

#define gold(p) p.gold;
#define list_unit(p) p.list_unit;
#define list_villages(p) p.list_villages;
#define income(p) p.income;
#define upkeep(p) p.upkeep;
#define warna(p) p.warna;
#define simbol_player(p) p.simbol;


#endif