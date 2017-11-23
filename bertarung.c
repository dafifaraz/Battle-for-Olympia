
#include "bertarung.h"
#include "boolean.h"
#include "unit.h"
#include "player.h"
#include "petak.h"
#include "peta.h"
#include <math.h>

boolean MEC_canAttack(unit A, unit B){
    return  (abs(lokasi_unit(A).X-lokasi_unit(B).X)+abs(lokasi_unit(A).Y-lokasi_unit(B).Y) == 1);
}

boolean MEC_canRetaliates(unit X, unit Y){
    return ((tipe_serang(X)==tipe_serang(Y)) || simbol(Y)=='K') && (health(Y)>0);
}

void MEC_attack(unit *X, unit *Y){
    health(*Y) -= attack(*X);
    if(MEC_canRetaliates(*X,*Y)){
        health(*X) -= attack(*Y);
    }
}

#include <stdio.h>
#include "bertarung.h"
#include "unit.h"

void printUnitName(Unit U){
    if(simbol(U) == 'A'){
        printf("Archer");
    }else
    if(simbol(U) == 'K'){
        printf("King");
    }else
    if(simbol(U) == 'S'){
        printf("Swordsman");
    }else
    if(simbol(U) == 'W'){
        printf("White Mage");
    }
}

void COMMAND_ATTACK(player one, player two){
    add_unit canAttack[5];
    int neff = 0;
    printf("Please select enemy you want to attack:\n");
    add_unit P = First_unit(list_unit(two));
    int cntUnit=0;
    while (P != Nil){
        if(MEC_canAttack(selected(one), Info_unit(P))){
            printf("%d. ",++cntUnit);
            printUnitName(Info_unit(P));
            printf(" (%d,%d) | Health ", lokasi_unit(Info_unit(P)).X, lokasi_unit(Info_unit(P)).Y);
            printf("%d/%d", health(Info_unit(P)), max_health(Info_unit(P)));
            if(((tipe_serangan(selected(one)) == tipe_serangan(Info_unit(P))) || (simbol(Info_unit(P))=='K')) && (MEC_attack(selected(one))<health(Info_unit(P)))){
                printf(" (Retaliates)\n");
            }else{
                printf("\n");
            }
            canAttack[cntUnit] = P;
            neff++;
        }
        P = Next_unit(P);
    }

    printf("Select enemy you want to attack: ");
    int unitYangAkanDiserang;
    scanf("%d", &unitYangAkanDiserang);

    MEC_attack(&selected(one), &Info_unit(canAttack[unitYangAkanDiserang]));
    int xxx = lokasi_unit(Info_unit(canAttack[unitYangAkanDiserang])).X;
    int yyy = lokasi_unit(Info_unit(canAttack[unitYangAkanDiserang])).Y;
    int xxx2 = lokasi_unit(selected(one)).X;
    int yyy2 = lokasi_unit(selected(one)).Y;
    
    assign_petak(&petak(M,xxx,yyy), simbol(Info_unit(Elmt(canAttack, unitYangAkanDiserang))), pemilik(Info_unit(canAttack[unitYangAkanDiserang])), Info_unit(canAttack[unitYangAkanDiserang]));
    assign_petak(&petak(M,xxx2,yyy2), simbol(selected(one)), pemilik(selected(one)), selected(one));
    
    printf("Enemy\'s ");
    printUnitName(Info_unit(canAttack[unitYangAkanDiserang]));
    printf("is damaged by %d.\n",attack(selected(one)));
    
    if(health(Info_unit(canAttack[unitYangAkanDiserang]))<=0){
        printf("Enemy\'s ");
        printUnitName(Info_unit(canAttack[unitYangAkanDiserang]));
        printf("is dead.\n");
    }

    if(((tipe_serang(selected(one)) == tipe_serang(Info_unit(canAttack[unitYangAkanDiserang]))) || (simbol(Info_unit(canAttack[unitYangAkanDiserang]))=='K')) && health(Info_unit(canAttack[unitYangAkanDiserang]))>0){
        printf("Enemy\'s ");
        printUnitName(Info_unit(canAttack[unitYangAkanDiserang]));
        printf("retaliates.\n");

        printf("Your's ");
        printUnitName(selected(one));
        printf("is damaged by %d.\n", attack(Info_unit(canAttack[unitYangAkanDiserang])));
        if(health(selected(one))<=0){
            printf("Your's ");
            printUnitName(selected(one));
            printf("is dead :(\n");
        }
    }
}

/*void COMAND_INFO(){
    POINT coordinate;
    printf("Enter the coordinate of the cell: ");
    BacaPOINT(&coordinate);
    printf("== Cell Info==\n");
    printPetakName(PETA[coordinate.X][coordinate.Y]);
    printf("\n");
    printf("Owned by Player %d\n",Milik(PETA[coordinate.X][coordinate.Y]));
    printf("== Unit Info==");
    printUnitName(Unit(PETA[coordinate.X][coordinate.Y])); //selektor uniit //segera di ganti
}


boolean checkOcc(POINT P){
    return peta[Absis(P)][Ordinat(P)]
}
*/