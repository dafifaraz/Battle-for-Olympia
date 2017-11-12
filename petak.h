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

#define lokasi_petak(p) p.unit.lokasi
#define jenis_petak(p) p.jenis
#define milik_petak(p) p.milik
#define unit_petak(p) p.u
#define income_petak(p) p.income

// mengecek kesamaan petak
boolean isequal_petak(petak p1, petak p2);

// mengembalikan petak yang belum berisi bangunan, unit, dan pemilik
petak empty_petak(POINT lokasi_p);

// mengisi petak *p yang sudah memiliki lokasi dengan jenis, milik, dan unitnya
void assign_petak(petak *p, char jenis_p, int milik_p, unit unit_p);

/***********************	LIST OF VILLAGES 	**************************/
#define Nil NULL

typedef petak infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} listvillages;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

boolean IsEmpty_listvillages(listvillages L);

void CreateEmpty_listvillages(listvillages *L);

address Alokasi_listvillages(infotype X);

void Dealokasi_listvillages(adress *P);

address Search_listvillages(listvillages l, infotype X);

void InsVFirst_listvillages (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast_listvillages (listvillages *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_listvillages (listvillages *L, infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast_listvillages (listvillages *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst_listvillages (listvillages *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter_listvillages (listvillages *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast_listvillages (listvillages *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_listvillages (listvillages *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP_listvillages (listvillages *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast_listvillages (listvillages *L, address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter_listvillages (listvillages *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

#endif
