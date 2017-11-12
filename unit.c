#include "unit.h"
#include "boolean.h"
#include "point.h"

#define MH_KING 100
#define ATK_KING 10
#define MM_KING 1
#define TS_KING 'M'
#define H_KING -1

#define MH_ARCHER 50
#define ATK_ARCHER 15
#define MM_ARCHER 2
#define TS_ARCHER 'R'
#define H_ARCHER 10

#define MH_SWORDSMAN 75
#define ATK_SWORDSMAN 10
#define MM_SWORDSMAN 3
#define TS_SWORDSMAN 'M'
#define H_SWORDSMAN 15

#define MH_WHITEMAGE 50
#define ATK_WHITEMAGE 5
#define MM_WHITEMAGE 2
#define TS_WHITEMAGE 'M'
#define H_WHITEMAGE 20

unit empty_unit(POINT lokasi_u){
	unit u;
	
	max_health(u) = 0;
	health(u) = 0;
	attack(u) = 0;
	max_move_point(u) = 0;
	tipe_serang(u) = ' ';
	harga(u) = 0;	
	move_point(u) = 0;
	kesempatan_serang(u) = false;
	lokasi_unit(u) = lokasi_u;
	simbol(u) = ' ';

	return u;
}

void assign_unit(unit *u, char tipe_unit){
	move_point(*u) = 0;
	kesempatan_serang(*u) = true;
	simbol(*u) = tipe_unit;

	if (tipe_unit == 'K'){
		max_health(*u) = MH_KING;
		health(*u) = MH_KING;
		attack(*u) = ATK_KING;
		max_move_point(*u) = MM_KING;
		tipe_serang(*u) = TS_KING;
		harga(*u) = H_KING;	
	} else if (tipe_unit == 'A'){
		max_health(*u) = MH_ARCHER;
		health(*u) = MH_ARCHER;
		attack(*u) = ATK_ARCHER;
		max_move_point(*u) = MM_ARCHER;
		tipe_serang(*u) = TS_ARCHER;
		harga(*u) = H_ARCHER;
	} else if (tipe_unit == 'S'){
		max_health(*u) = MH_SWORDSMAN;
		health(*u) = MH_SWORDSMAN;
		attack(*u) = ATK_SWORDSMAN;
		max_move_point(*u) = MM_SWORDSMAN;
		tipe_serang(*u) = TS_SWORDSMAN;
		harga(*u) = H_SWORDSMAN;
	} else {
		max_health(*u) = MH_WHITEMAGE;
		health(*u) = MH_WHITEMAGE;
		attack(*u) = ATK_WHITEMAGE;
		max_move_point(*u) = MM_WHITEMAGE;
		tipe_serang(*u) = TS_WHITEMAGE;
		harga(*u) = H_WHITEMAGE;
	}
}

boolean isequal_unit(unit u1, unit u2){
	boolean b1 = health(u1) == health(u2);
	boolean b2 = move_point(u1) == move_point(u2);
	boolean b3 = kesempatan_serang(u1) == kesempatan_serang(u2);
	boolean b4 = isequal_point(lokasi_unit(u1),lokasi_unit(u2));
	boolean b5 = simbol(u1) == simbol(u2);
	return (b1 && b2 && b3 && b4 && b5);
}

boolean IsEmpty_listunit(listunit L){
	return First(L) == Nil;
}

void CreateEmpty_listunit(listunit *L){
	First(*L) = Nil;
}

add_unit Alokasi_listunit(unit X){
	add_unit P = (add_unit) malloc(sizeof(unitlist));
	if (P!=Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi_listunit(add_unit *P){
	free (*P);
}

add_unit Search_listunit(listunit L, unit X){
	add_unit P = First(L);
	boolean bFound = false;
	while (P!=Nil && !bFound){
		if (isequal_unit(X,Info(P))){
			bFound = true; 
		} else {
			P = Next(P);
		}
	}
	return P;
}

void InsVFirst_listunit (listunit *L, unit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan Alokasi_listunit sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika Alokasi_listunit berhasil */
{
	add_unit P = Alokasi_listunit(X);
	if (P!=Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}
void InsVLast_listunit (listunit *L, unit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan Alokasi_listunit sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika Alokasi_listunit berhasil. Jika Alokasi_listunit gagal: I.S.= F.S. */
{
	add_unit P = Alokasi_listunit(X);
	if (P!=Nil) {
		InsertLast_listunit(L,P);
	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_listunit (listunit *L, unit *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
{
	add_unit P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	*X = Info(P);
	Dealokasi_listunit(&P);
}
/*      dan alamat elemen pertama di-Dealokasi_listunit */
void DelVLast_listunit (listunit *L, unit *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-Dealokasi_listunit */
{
	add_unit Last = First(*L);
	add_unit PrecLast = Nil;
	while (Next(Last) != Nil){
		PrecLast = Last;
		Last = Next(Last);
	}
	*X = Info(Last);
	if (PrecLast == Nil){
		First(*L) = Nil;
	} else {
		Next(PrecLast) = Nil;
	}
}

void InsertFirst_listunit (listunit *L, add_unit P)
/* I.S. Sembarang, P sudah diAlokasi_listunit  */
/* F.S. Menambahkan elemen ber-add_unit P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;	
}

void InsertAfter_listunit (listunit *L, add_unit P, add_unit Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah diAlokasi_listunit  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast_listunit (listunit *L, add_unit P)
/* I.S. Sembarang, P sudah diAlokasi_listunit  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmpty_listunit(*L)){
		InsertFirst_listunit(L,P); 
	} else {
		add_unit Last = First(*L);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		InsertAfter_listunit(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_listunit (listunit *L, add_unit *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP_listunit (listunit *L, unit X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradd_unit P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-Dealokasi_listunit */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if (!IsEmpty_listunit(*L)){
		add_unit P = Search_listunit(*L,X);
		if (P!=Nil){
			if (P==First(*L)){
				DelFirst_listunit(L,&P);
			} else {
				add_unit Prec = First(*L);
				while (Next(Prec) != P) {
					Prec = Next(Prec);
				}
				DelAfter_listunit(L,&P,Prec);
			}
		}
	}
}

void DelLast_listunit (listunit *L, add_unit *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	add_unit Last = First(*L);
	add_unit PrecLast = Nil;
	while (Next(Last) != Nil){
		PrecLast = Last;
		Last = Next(Last);
	}	
	*P = Last;
	if (PrecLast == Nil) {
		First(*L) = Nil;
	} else {
		Next(PrecLast) = Nil;
	}
}

void DelAfter_listunit (listunit *L, add_unit *Pdel, add_unit Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}
