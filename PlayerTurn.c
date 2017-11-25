#include <stdio.h>
#include <stdlib.h>
#include "PlayerTurn.h"
#include "player.h"
#include "peta.h"
#include "stackt.h"

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

void NextTurnQueue(Queue *Q, player *p, peta *M, Stack *S)
{
    int A;
    Del(Q,&A);
    Add(Q,A);
    gold(*p)=gold(*p)+income(*p)-upkeep(*p);
    add_unit P = First_unit(list_unit(*p));
    while (P != Nil){
        move_point(Info_unit(P)) = max_move_point(Info_unit(P)); 
        P = Next_unit(P);
    }
    for (int i=0; i<NBrsEff(*M); i++){
        for (int j=0; j<NBrsEff(*M); j++){
            if (pemilik(unit_petak(petak(*M,i,j))) == simbol_player(*p)){
                move_point(unit_petak(petak(*M,i,j))) = max_move_point(unit_petak(petak(*M,i,j)));
            }
        }
    }
    move_point(selected(*p)) = max_move_point(selected(*p));
    CreateEmptyStack(S);
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
