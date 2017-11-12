#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	int gold;
	List list_unit;
	List list_villages;
	int income;
	int upkeep;
	char warna;
} player;


#endif