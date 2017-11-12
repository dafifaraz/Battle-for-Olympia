#ifndef UNIT_H
#define UNIT_H

#include "point.h"
#include "boolean.h"
#include <stdlib.h>
/***********************	UNIT 	**************************/

typedef struct{
	int max_health;
	int health;
	int attack;
	int max_move_point;
	int move_point;
	char tipe_serang;
	boolean kesempatan_serang;
	POINT lokasi;
	int harga;
	char simbol;
} unit;

#define max_health(U) (U).max_health
#define health(U) (U).health
#define attack(U) (U).attack
#define max_move_point(U) (U).max_move_point
#define move_point(U) (U).move_point
#define tipe_serang(U) (U).tipe_serang
#define kesempatan_serang(U) (U).kesempatan_serang
#define lokasi_unit(U) (U).lokasi
#define harga(U) (U).harga
#define simbol(U) (U).simbol

// unit di lokasi_u dengan jenis unit belum didefinisikan
unit empty_unit(POINT lokasi_u);

// ambil unit *u, lalu kasih propertinya
void assign_unit(unit *u, char tipe); 

boolean isequal_unit(unit u1, unit u2);

#endif