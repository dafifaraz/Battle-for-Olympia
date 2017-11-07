#ifndef UNIT_H
#define UNIT_H

/****************************	KONSTANTA UMUM	*************************************/
#define MAX_HEALTH_KING 100
#define MAX_MOVE_PTS_KING 1
#define ATTACK_KING 10
#define HARGA_KING -1

#define MAX_HEALTH_ARCHER 50
#define MAX_MOVE_PTS_ARCHER 2
#define ATTACK_ARCHER 15
#define HARGA_ARCHER 10

#define MAX_HEALTH_SWORDSMAN 75
#define MAX_MOVE_PTS_SWORDSMAN 3 
#define ATTACK_SWORDSMAN 10
#define HARGA_SWORDSMAN 15

#define MAX_HEALTH_WHITEMAG 50
#define MAX_MOVE_PTS_WHITEMAG 2
#define ATTACK_WHITEMAG 5
#define HARGA_WHITEMAG 20

#define HEAL_INCREASE 5

/****************************	TIPE BENTUKAN UnitProperty 	*************************/
typedef struct UnitProperty{
	int maxHealth;
	int health;
	int attack;
	int maxMovePts;
	int movePts;
	char* tipeSerangan;
	boolean kesempatanSerangan;
	Point lokasi;
	int harga;
};

/****************************	TIPE BENTUKAN Unit 	**********************************/
typedef struct Unit{
	char UnitSymbol;
	int whiteMageAbility;
	int milik;
	boolean recruitable; 
	boolean select;
	UnitProperty SpecificProperty;
};

/****************************	SETTER DAN GETTER UnitProperty 	*********************/
#define Health(U) U.SpecificProperty.health
#define MovePts(U) U.SpecificProperty.movePts
#define Kesempatan(U) U.SpecificProperty.kesempatanSerangan
#define Lokasi(U) U.SpecificProperty.lokasi
#define Milik(U) U.Milik;
/***************************	SETUP UNIT ******************************************/
void setup_King(Unit *King, Player P, Peta Map);

void setup_Archer(Unit *Archer, Player P);

void setup_Swordsman(Unit *Swordsman, Player P);

void setup_WhiteMag(Unit *WhiteMag, Player P);

#endif
