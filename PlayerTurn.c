#include <stdio.h>
#include <stdlib.h>
#include "PlayerTurn.h"

/*pakai dengan menggunakan & ex.NextTurnQueue(&Q)*/

void CreateTurnQueue12(Queue *Q)
{
    CreateEmpty(Q,2);
    Add(Q,1);
    Add(Q,2);
}


void CreateTurnQueue21(Queue *Q)
{
    CreateEmpty(Q,2);
    Add(Q,2);
    Add(Q,1);
}

void NextTurnQueue(Queue *Q, player *p)
{
    int A;
    Del(Q,&A);
    Add(Q,A);
    gold(*p)=gold(*p)+income(*p)-upkeep(*p);
}

/*while (Not Game Over || Not Exit){
if(InfoHead(Q)==1)
    {
        printf("Giliran player 1!!!");
        COMMAND DI TURN PLAYER 1
        NextTurnQueue(&Q);
    }
else if(InfoHead(Q)==2)
    {
        printf("Giliran player 2!!!");
        COMMAND DI TURN PLAYER 2
        NextTurnQueue(&Q);
    }
}*/
