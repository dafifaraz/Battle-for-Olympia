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

