#include "bertarung.h"
#include "boolean.h"
#include "unit.h"
#include "player.h"
#include "petak.h"
#include "peta.h"
#include <math.h>
#include "stdio.h"

boolean MEC_canAttack(unit A, unit B){
    boolean b1 = pemilik(A) == 1 && pemilik(B) == 2;
    boolean b2 = pemilik(A) == 2 && pemilik(B) == 1;
    return ((b1||b2) && (manhattan_dist(lokasi_unit(A),lokasi_unit(B)) == 1));
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

void printUnitName(unit U){
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

void COMMAND_ATTACK(player *one, player *two, peta *m){

    unit l = unit_petak(petak(*m,Absis(left(lokasi_unit(selected(*one)))),Ordinat(left(lokasi_unit(selected(*one))))));
    unit r = unit_petak(petak(*m,Absis(right(lokasi_unit(selected(*one)))),Ordinat(right(lokasi_unit(selected(*one))))));
    unit u = unit_petak(petak(*m,Absis(up(lokasi_unit(selected(*one)))),Ordinat(up(lokasi_unit(selected(*one))))));
    unit d = unit_petak(petak(*m,Absis(down(lokasi_unit(selected(*one)))),Ordinat(down(lokasi_unit(selected(*one))))));

    int cntUnit = 0;
    int cntUnit2 = 0;

    if (MEC_canAttack(selected(*one),l)) cntUnit2++;
    if (MEC_canAttack(selected(*one),r)) cntUnit2++;
    if (MEC_canAttack(selected(*one),u)) cntUnit2++;
    if (MEC_canAttack(selected(*one),d)) cntUnit2++;

    if (cntUnit2==0){
        printf("No unit to atttack\n");
        return;
    }

    unit uAttack[5];

    printf("Enemy you can attack:\n");
    if (MEC_canAttack(selected(*one),l)){
        //printf("health %d",health(l));
        printf("%d. ",++cntUnit);
        uAttack[cntUnit] = l;
        printUnitName(l);
        printf(" (%d,%d) | Health ", lokasi_unit(l).X, lokasi_unit(r).Y);
        printf("%d/%d\n", health(l), max_health(l));
    }

    if (MEC_canAttack(selected(*one),r)){
        //printf("health %d",health(r));
        printf("%d. ",++cntUnit);
        uAttack[cntUnit] = r;
        printUnitName(r);
        printf(" (%d,%d) | Health ", lokasi_unit(r).X, lokasi_unit(r).Y);
        printf("%d/%d\n", health(r), max_health(r));
    }

    if (MEC_canAttack(selected(*one),u)){
        //printf("health %d",health(u));
        printf("%d. ",++cntUnit);
        uAttack[cntUnit] = u;
        printUnitName(u);
        printf(" (%d,%d) | Health ", lokasi_unit(u).X, lokasi_unit(u).Y);
        printf("%d/%d\n", health(u), max_health(u));
    }

    if (MEC_canAttack(selected(*one),d)){
        //printf("health %d",health(d));
        printf("%d. ",++cntUnit);
        uAttack[cntUnit] = d;
        printUnitName(d);
        printf(" (%d,%d) | Health ", lokasi_unit(d).X, lokasi_unit(d).Y);
        printf("%d/%d\n", health(d), max_health(d));
    }

    printf("Select enemy you want to attack: ");
    int unitYangAkanDiserang;
    scanf("%d", &unitYangAkanDiserang);

    //printf("123456%d", unitYangAkanDiserang);
    unit serang = uAttack[unitYangAkanDiserang];
    
    unit temp1 = selected(*one);
    unit temp2 = serang;

    //printf("%d", health(serang));
    MEC_attack(&selected(*one), &serang);
   //printf("%d",health(serang));

    int xxx = lokasi_unit(serang).X;
    int yyy = lokasi_unit(serang).Y;
    int xxx2 = lokasi_unit(selected(*one)).X;
    int yyy2 = lokasi_unit(selected(*one)).Y;

    unit_petak(petak(*m,xxx,yyy)) = selected(*one);
    unit_petak(petak(*m,xxx2,yyy2)) = serang;
    
    printf("Enemy\'s ");
    printUnitName(serang);
    printf(" is damaged by %d.\n",attack(selected(*one)));
    
    if(health(serang)<=0){
        printf("Enemy\'s ");
        printUnitName(serang);
        printf(" is dead.\n");
    }

    if (((tipe_serang(selected(*one)) == tipe_serang(serang) || (simbol(serang)=='K')) && health(serang) > 0)){
        printf("Enemy\'s ");
        printUnitName(serang);
        printf(" retaliates.\n");
        printf("Your's ");
        printUnitName(selected(*one));
        printf(" is damaged by %d.\n", attack(serang));
        
        if(health(selected(*one)) <=0 ){
            printf("Your's ");
            printUnitName(selected(*one));
            printf(" is dead :(\n");
        }
    }

    add_unit slc_in_list_1 = Search_listunit(list_unit(*one),temp1);
    Info_unit(slc_in_list_1) = selected(*one);

    add_unit slc_in_list_2 = Search_listunit(list_unit(*two),temp2);
    Info_unit(slc_in_list_1) = serang;
    
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