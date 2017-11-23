#ifndef BERTARUNG_H
#define BERTARUNG_H

#include "boolean.h"
#include "unit.h"
#include "player.h"
#include "peta.h"
#include "petak.h"
#include <math.h>


boolean MEC_canAttack(unit A, unit B);

boolean MEC_canRetaliates(unit X, unit Y);

void MEC_attack(unit *X, unit *Y);

void printUnitName(unit U);

void COMMAND_ATTACK(player one, player two);
#endif