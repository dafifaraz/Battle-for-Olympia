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
void TulisPOINT (POINT P){
	printf("(%d,%d)\n", Absis(P), Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
	boolean equal;
	equal = false;
	if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)){
		equal = true;
	}

	return equal;
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
	boolean eq2 = false;

	if (EQ(P1,P2) == false){
		eq2 = true;
	}

	return eq2;
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
	boolean origin = false;

	if (Absis(P) == 0 && Ordinat(P) == 0){
		origin = true;
	}

	return origin;
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P){
	boolean yes = false;

	if (Ordinat(P) == 0){
		yes = true;
	}

	return yes;
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
	boolean yes = false;

	if (Absis(P) == 0){
		yes = true;
	}

	return yes;
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
	int kuad;
	if (Absis(P) > 0 && Ordinat(P) > 0){
		kuad = 1;
	}

	else if (Absis(P) < 0 && Ordinat(P) > 0){
		kuad = 2;
	}
	else if (Absis(P) < 0 && Ordinat(P) < 0){
		kuad = 3;
	}
	else {
		kuad = 4;
	}

	return kuad;
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
	Absis(P) = Absis(P) + 1;

	return P;
}
/* Mengirim salinan P dengan absis ditambah satu */              
POINT NextY (POINT P){
	Ordinat(P) = Ordinat(P) + 1;

	return P;
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, int deltaX, int deltaY){
	Absis(P) = Absis(P) + deltaX;
	Ordinat(P) = Ordinat(P) + deltaY;

	return P;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX){
	if(SbX = true){
		Ordinat(P) = Ordinat(P) * -1;
	}
	else{
		Absis(P) = Absis(P) * -1;
	}

	return P;

}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P){
	float jarak;

	jarak = Ordinat(P) * Ordinat(P) + Absis(P) * Absis(P);
	jarak = sqrt(jarak);

	return jarak;
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
	float dx, dy;
	float panjang;

	dy = Ordinat(P2) - Ordinat(P1);
	dx = Absis(P2) - Absis(P1);

	panjang = dx * dx + dy * dy;
	panjang = sqrt(panjang);

	return panjang;


}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, int deltaX, int deltaY){
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P){
	Ordinat(*P) = 0;
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
	Absis(*P) = 0;
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX){
	if(SbX = true){
		Ordinat(*P) = Ordinat(*P) * (-1.0);
	}
	else{
		Absis(*P) = Absis(*P) * (-1.0);
	}
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut){
	float r, theta;
	r = sqrt(Absis(*P)*Absis(*P) + Ordinat(*P)*(Ordinat(*P)));
	theta = atan(Absis(*P)/Ordinat(*P));
	theta = theta - Sudut;

	Absis(*P) = r * cos(theta);
	Ordinat(*P) = r * sin(theta);
}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
