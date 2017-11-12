#include "petak.h"
#include "unit.h"
#include "point.h"

const int income_p 10;

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

