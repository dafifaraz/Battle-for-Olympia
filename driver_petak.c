#include "petak.h"
#include <stdio.h>
#include "point.h"
#include "unit.h"

int main(){

	unit u1 = empty_unit(MakePOINT(1,1));
	assign_unit(&u1,'W',2);

	petak p1 = empty_petak(MakePOINT(1,1));
	
	printf("%d %d\n", Absis(lokasi_petak(p1)), Ordinat(lokasi_petak(p1)));
	printf("%c\n", jenis_petak(p1));
	printf("%d\n", milik_petak(p1));
	printf("%c\n", simbol(unit_petak(p1)));
	printf("%d\n", income_petak(p1));

	printf("\nASSIGN\n");

	assign_petak(&p1, 'V', 1, u1);

	printf("%d %d\n", Absis(lokasi_petak(p1)), Ordinat(lokasi_petak(p1)));
	printf("%c\n", jenis_petak(p1));
	printf("%d\n", milik_petak(p1));
	printf("%c\n", simbol(unit_petak(p1)));
	printf("%d\n", income_petak(p1));

	printf("CHECK\n");
	printf("%c\n",simbol(unit_petak(p1)));
}