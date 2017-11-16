//file : point.c

#include <stdio.h>
#include "point.h"
#include <math.h>
#include "boolean.h"

#define epsilon 1e-6
#define PI 	3.14159265
#define rad(X) X*PI/180.0

/* *** DEFINISI PROTOTakb fortune cookieIPE PRIMITIF *** */
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

boolean isequal_point(POINT P1, POINT P2){
	return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

void tulis_point (POINT X){
	printf("(%d,%d)",Absis(X),Ordinat(X));
}