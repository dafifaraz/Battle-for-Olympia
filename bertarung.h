#ifndef BERTARUNG_H
#define BERTARUNG_H

#include "bertarung.h"
#include "boolean.h"
#include "unit.h"
#include "player.h"
#include "petak.h"
#include "peta.h"
#include <math.h>
#include "stdio.h"

boolean MEC_canAttack(unit A, unit B);

<<<<<<< HEAD
=======
boolean MEC_canAttack(unit A, unit B);

>>>>>>> 519e8f7a9204bf8febe88e7ecb1236c066b8a6f6
boolean MEC_canRetaliates(unit X, unit Y);

void MEC_attack(unit *X, unit *Y);

void printUnitName(unit U);

<<<<<<< HEAD
void COMMAND_ATTACK(player *one, player *two, peta *m);
=======
void COMMAND_ATTACK(player one, player two);
>>>>>>> 519e8f7a9204bf8febe88e7ecb1236c066b8a6f6
#endif