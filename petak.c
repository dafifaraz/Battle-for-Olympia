#include "petak.h"
#include "unit.h"
#include "point.h"

#define income_p 10;

boolean isequal_petak(petak p1, petak p2){
	boolean b1 = isequal_unit(unit_petak(p1), unit_petak(p2));
	boolean b2 = jenis_petak(p1) == jenis_petak(p2);
	boolean b3 = milik_petak(p1) == milik_petak(p2);
	boolean b4 = income_petak(p1) == income_petak(p2);
	return (b1 && b2 && b3 && b4);
}

petak empty_petak(POINT lokasi_p){
	petak p;
	lokasi_petak(p) = lokasi_p;
	jenis_petak(p) = ' ';
	milik_petak(p) = 0;
	unit_petak(p) = empty_unit(lokasi_p);
	income_petak(p) = 0;
	return p;
}

void assign_petak(petak *p, char jenis_p, int milik_p, unit unit_p){
	jenis_petak(*p) = jenis_p;
	milik_petak(*p) = milik_p;
	unit_petak(*p) = unit_p;
	
	if (jenis_p == 'V'){
		income_petak(*p) = income_p;
	} else {
		income_petak(*p) = 0;
	}
}


boolean IsEmpty_listpetak(listpetak L){
	return First(L) == Nil;
}

void CreateEmpty_listpetak(listpetak *L){
	First(*L) = Nil;
}

add_petak Alokasi_listpetak(petak X){
	add_petak P = (add_petak) malloc(sizeof(petaklist));
	if (P!=Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi_listpetak(add_petak *P){
	free (*P);
}

add_petak Search_listpetak(listpetak L, petak X){
	add_petak P = First(L);
	boolean bFound = false;
	while (P!=Nil && !bFound){
		if (isequal_petak(X,Info(P))){
			bFound = true; 
		} else {
			P = Next(P);
		}
	}
	return P;
}

void InsVFirst_listpetak (listpetak *L, petak X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	add_petak P = Alokasi_listpetak(X);
	if (P!=Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}
void InsVLast_listpetak (listpetak *L, petak X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	add_petak P = Alokasi_listpetak(X);
	if (P!=Nil) {
		InsertLast_listpetak(L,P);
	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_listpetak (listpetak *L, petak *X)
/* I.S. listpetak L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
{
	add_petak P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	*X = Info(P);
	Dealokasi_listpetak(&P);
}
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast_listpetak (listpetak *L, petak *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	add_petak Last = First(*L);
	add_petak PrecLast = Nil;
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

void InsertFirst_listpetak (listpetak *L, add_petak P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-add_petak P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;	
}

void InsertAfter_listpetak (listpetak *L, add_petak P, add_petak Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast_listpetak (listpetak *L, add_petak P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmpty_listpetak(*L)){
		InsertFirst_listpetak(L,P); 
	} else {
		add_petak Last = First(*L);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		InsertAfter_listpetak(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_listpetak (listpetak *L, add_petak *P)
/* I.S. listpetak tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP_listpetak (listpetak *L, petak X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beradd_petak P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* listpetak mungkin menjadi kosong karena penghapusan */
{
	if (!IsEmpty_listpetak(*L)){
		add_petak P = Search_listpetak(*L,X);
		if (P!=Nil){
			if (P==First(*L)){
				DelFirst_listpetak(L,&P);
			} else {
				add_petak Prec = First(*L);
				while (Next(Prec) != P) {
					Prec = Next(Prec);
				}
				DelAfter_listpetak(L,&P,Prec);
			}
		}
	}
}

void DelLast_listpetak (listpetak *L, add_petak *P)
/* I.S. listpetak tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	add_petak Last = First(*L);
	add_petak PrecLast = Nil;
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

void DelAfter_listpetak (listpetak *L, add_petak *Pdel, add_petak Prec)
/* I.S. listpetak tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}
