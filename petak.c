#include "petak.h"
#include "unit.h"
#include "point.h"

const int income_p 10;

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


boolean IsEmpty_listvillages(listvillages L){
	return First(L) == Nil;
}

void CreateEmpty_listvillages(listvillages *L){
	First(*L) = Nil;
}

address Alokasi_listvillages(infotype X){
	address P = (address) malloc(sizeof(ElmtList));
	if (P!=Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi_listvillages(adress *P){
	free (*P);
}

address Search_listvillages(listvillages L, infotype X){
	address P = First(L);
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

void InsVFirst_listvillages (listvillages *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = Alokasi(X);
	if (P!=Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}
void InsVLast_listvillages (listvillages *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = Alokasi(X);
	if (P!=Nil) {
		InsertLast(L,P);
	}
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_listvillages (listvillages *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
{
	address P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	*X = Info(P);
	Dealokasi(&P);
}
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast_listvillages (listvillages *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address Last = First(*L);
	address PrecLast = Nil;
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

void InsertFirst_listvillages (listvillages *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;	
}

void InsertAfter_listvillages (listvillages *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast_listvillages (listvillages *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmpty(*L)){
		InsertFirst(L,P); 
	} else {
		address Last = First(*L);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_listvillages (listvillages *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP_listvillages (listvillages *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	if (!IsEmpty(*L)){
		address P = Search(*L,X);
		if (P!=Nil){
			if (P==First(*L)){
				DelFirst(L,&P);
			} else {
				address Prec = First(*L);
				while (Next(Prec) != P) {
					Prec = Next(Prec);
				}
				DelAfter(L,&P,Prec);
			}
		}
	}
}

void DelLast_listvillages (listvillages *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address Last = First(*L);
	address PrecLast = Nil;
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

void DelAfter_listvillages (listvillages *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}
