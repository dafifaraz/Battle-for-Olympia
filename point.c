//file : point.c

#include <stdio.h>
#include "point.h"
#include <math.h>

#define epsilon 1e-6
#define PI 3.14159265
#define rad(X) X*PI/180.0

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
	POINT P;

	Absis(P) = X;
	Ordinat(P) = Y;

	return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){
	int x,y;
	scanf("%d %d", x, y);

	*P = MakePOINT(x,y);
} 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
