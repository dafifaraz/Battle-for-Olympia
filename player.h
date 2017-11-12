#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	int gold;
	List list_unit;
	List list_villages;
	int income;
	int upkeep;
	char warna;
	char simbol; // 1 : player 1, 2 player 2
} player;

#define gold(p) p.gold;
#define list_unit(p) p.list_unit;
#define list_villages(p) p.list_villages;
#define income(p) p.income;
#define upkeep(p) p.upkeep;
#define warna(p) p.warna;
#define simbol(p) p.simbol;

#endif