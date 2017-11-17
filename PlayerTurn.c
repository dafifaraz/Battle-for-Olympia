#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

/*pakai dengan menggunakan & ex.NextTurnQueue(&Q)*/

void CreateTurnQueue(Queue *Q)
{
    CreateEmpty(Q,2);
    Add(Q,1);
    Add(Q,2);
}

void NextTurnQueue(Queue *Q)
{
    int A;
    Del(Q,&A);
    Add(Q,A);
}

/*while (Not Game Over || Not Exit){
if(InfoHead(Q)==1)
    {
        printf("Giliran player 1!!!");
        COMMAND DI TURN PLAYER 1
    }
else if(InfoHead(Q)==2)
    {
        printf("Giliran player 2!!!");
        COMMAND DI TURN PLAYER 2
    }
}*/
