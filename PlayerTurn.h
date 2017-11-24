#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "player.h"
#include "peta.h"

/*pakai dengan menggunakan & ex.NextTurnQueue(&Q)*/

void CreateTurnQueue12(Queue *Q);

void CreateTurnQueue21(Queue *Q);

void NextTurnQueue(Queue *Q, player *p, peta *M);
