#include "point.h"

/***************************	SETUP UNIT ******************************************/
void setup_King(Unit *King, Player P, Peta Map){
	*King.UnitSymbol = 'K';
	*King.whiteMageAbility = 0;
	*King.recruitable = false;
	*King.SpecificProperty.maxHealth = MAX_HEALTH_KING;
	Health(*King) = MAX_HEALTH_KING;
	*King.SpecificProperty.attack = ATTACK_KING;
	*King.SpecificProperty.maxMovePts = MAX_MOVE_PTS_KING;
	*King.SpecificProperty.tipeSerangan = "melee";
	Kesempatan(*King) = true;
	
	if (Name(P) == "Player 1") {
		Lokasi(*King) = pojokBawah(Map);
		Geser(&Lokasi(*King),1,1); 
	} else {
		Lokasi(*King) = pojokAtas(Map);
		Geser(&Lokasi(*King),-1,-1);
	}

	*King.harga = HARGA_KING;
}

void setup_Archer(Unit *Archer, Player P){
	*Archer.UnitSymbol = 'A';
	*Archer.whiteMageAbility = 0;
	*Archer.recruitable = true;
	*Archer.SpecificProperty.maxHealth = MAX_HEALTH_ARCHER;
	Health(*Archer) = MAX_HEALTH_ARCHER;
	*Archer.SpecificProperty.attack = ATTACK_ARCHER;
	*Archer.SpecificProperty.maxMovePts = MAX_MOVE_PTS_ARCHER;
	*Archer.SpecificProperty.tipeSerangan = "ranged";
	Kesempatan(*Archer) = true;
	
	//SETUP LOKASI ARCHER 

	*Archer.harga = HARGA_ARCHER;
}

void setup_Swordsman(Unit *Swordsman, Player P){
	*Swordsman.UnitSymbol = 'S';
	*Swordsman.whiteMageAbility = 0;
	*Swordsman.recruitable = true;
	*Swordsman.SpecificProperty.maxHealth = MAX_HEALTH_SWORDSMAN;
	Health(*Swordsman) = MAX_HEALTH_SWORDSMAN;
	*Swordsman.SpecificProperty.attack = ATTACK_SWORDSMAN;
	*Swordsman.SpecificProperty.maxMovePts = MAX_MOVE_PTS_SWORDSMAN;
	*Swordsman.SpecificProperty.tipeSerangan = "melee";
	Kesempatan(*Swordsman) = true;
	
	//SETUP LOKASI SWORDSMAN

	*Swordsman.harga = HARGA_SWORDSMAN;
}

void setup_WhiteMag(Unit *WhiteMag, Player P){
	*WhiteMag.UnitSymbol = 'W';
	*WhiteMag.whiteMageAbility = HEAL_INCREASE;
	*WhiteMag.recruitable = true;
	*WhiteMag.SpecificProperty.maxHealth = MAX_HEALTH_WHITEMAG;
	Health(*WhiteMag) = MAX_HEALTH_WHITEMAG;
	*WhiteMag.SpecificProperty.attack = ATTACK_WHITEMAG;
	*WhiteMag.SpecificProperty.maxMovePts = MAX_MOVE_PTS_WHITEMAG;
	*WhiteMag.SpecificProperty.tipeSerangan = "melee";
	Kesempatan(*WhiteMag) = true;
	
	//SETUP LOKASI 

	*WhiteMag.harga = HARGA_WHITEMAG;
}