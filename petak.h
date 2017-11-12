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

#endif
