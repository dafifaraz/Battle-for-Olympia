#ifndef BERTARUNG_H
#define BERTARUNG_H

#include "boolean.h"
#include "unit.h"
#include "player.h"
#include "peta.h"
#include "petak.h"
#include <math.h>


boolean MEC_canAttack(Unit B, Unit B);

boolean MEC_canRetaliates(Unit X, Unit Y);

void MEC_attack(Unit *X, Unit *Y);

void printUnitName(Unit U);

void COMAND_ATTACK(player one, player two);
#endif