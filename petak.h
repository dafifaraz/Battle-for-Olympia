#ifndef PETAK_H
#define PETAK_H

#include "point.h"
#include "unit.h"

typedef struct{
	char jenis;
	int milik;
	unit u;
	int income; // ada untuk villages
} petak;

#define lokasi_petak(p) (p).u.lokasi
#define jenis_petak(p) (p).jenis
#define milik_petak(p) (p).milik
#define unit_petak(p) (p).u
#define income_petak(p) (p).income

// mengecek kesamaan petak
boolean isequal_petak(petak p1, petak p2);

// mengembalikan petak yang belum berisi bangunan, unit, dan pemilik
petak empty_petak(POINT lokasi_p);

// mengisi petak *p yang sudah memiliki lokasi dengan jenis, milik, dan unitnya
void assign_petak(petak *p, char jenis_p, int milik_p, unit unit_p);

/***********************	LIST OF VILLAGES 	**************************/
#define Nil NULL

typedef struct t_petaklist *add_petak;
typedef struct t_petaklist {
	petak info;
	add_petak next;
} petaklist;
typedef struct {
	add_petak First;
} listpetak;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

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
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast_listpetak (listpetak *L, petak *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
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
/* F.S. Jika ada elemen list beradd_petak P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* listpetak mungkin menjadi kosong karena penghapusan */
void DelLast_listpetak (listpetak *L, add_petak *P);
/* I.S. listpetak tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter_listpetak (listpetak *L, add_petak *Pdel, add_petak Prec);
/* I.S. listpetak tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

#endif
