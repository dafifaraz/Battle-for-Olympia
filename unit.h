#ifndef UNIT_H
#define UNIT_H

#include "point.h"
#include "boolean.h"
#include <stdlib.h>
/***********************	UNIT 	**************************/

typedef struct{
	int max_health;
	int health;
	int attack;
	int max_move_point;
	int move_point;
	char tipe_serang;
	boolean kesempatan_serang;
	POINT lokasi;
	int harga;
	char simbol;
} unit;

#define max_health(U) (U).max_health
#define health(U) (U).health
#define attack(U) (U).attack
#define max_move_point(U) (U).max_move_point
#define move_point(U) (U).move_point
#define tipe_serang(U) (U).tipe_serang
#define kesempatan_serang(U) (U).kesempatan_serang
#define lokasi_unit(U) (U).lokasi
#define harga(U) (U).harga
#define simbol(U) (U).simbol

// unit di lokasi_u dengan jenis unit belum didefinisikan
unit empty_unit(POINT lokasi_u);

// ambil unit *u, lalu kasih propertinya
void assign_unit(unit *u, char tipe); 

boolean isequal_unit(unit u1, unit u2);

/***********************	LIST OF UNIT 	**************************/

#define Nil NULL

typedef struct t_unitlist *add_unit;
typedef struct t_unitlist {
	unit info;
	add_unit next;
} unitlist;
typedef struct {
	add_unit First;
} listunit;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

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
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast_listunit (listunit *L, unit *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
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
/* F.S. Jika ada elemen list beradd_unit P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast_listunit (listunit *L, add_unit *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter_listunit (listunit *L, add_unit *Pdel, add_unit Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

#endif