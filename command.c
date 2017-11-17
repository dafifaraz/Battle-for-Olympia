

void printUnitName(Unit U){
    if(Tipe(U) == 'A'){
        printf("Archer ");
    }else
    if(Tipe(U) == 'K'){
        printf("King ");
    }else
    if(Tipe(U) == 'S'){
        printf("Swordsman ");
    }else
    if(Tipe(U) == 'W'){
        printf("White Mage ");
    }
}

/*void printPetakName(PETAK P){
    if(Jenis(P) == 'C'){
        printf("Castle ");
    }else
    if(Jenis(P) == 'V'){
        printf("Village ");
    }else
    if(Jenis(P) == 'N'){
        printf("Normal ");
    }
}*/

void COMAND_ATTACK(player one, player two){
    TabAddress canAttack;
    MakeEmpty(&canAttack);
    printf("Please select enemy you want to attack:\n");
    add_unit P = First_unit(list_unit(two));
    int cntUnit=0;
    while (P != Nil){
        if(canSerang(selected(one), Info_unit(P))){
            printUnitName(Info_unit(P))
            printf("(%d,%d) | Health ",Lokasi(Info_unit(P)).X, Lokasi(Info_unit(P)).Y);
            printf("%d/%d", Health(Info_unit(P)), MaxHealth(Info_unit(P)));
            if(((TipeSerangan(selected(one)) == TipeSerangan(Info_unit(P))) || (Tipe(Info_unit(P))=='K')) && (Attack(ONE.currentUnit)<Health(Info(P)))){
                printf(" (Retaliates)\n");
            }else{
                printf("\n");
            }
            Elmt(canAttack,cntUnit++) = P;
            Neff(canAttack)++;
        }
        P = Next_unit(P);
    }

    printf("Select enemy you want to attack: ");
    int unitYangAkanDiserang;
    scanf("%d", &unitYangAkanDiserang);

    Serang(&selected(one), &Info_unit(Elmt(canAttack,unitYangAkanDiserang)));
    printf("Enemy\'s ");
    printUnitName(Info_unit(Elmt(canAttack,unitYangAkanDiserang)));
    printf("is damaged by %d.\n",Attack(selected(one)));
    
    if(Health(Info_unit(Elmt(canAttack,unitYangAkanDiserang)))<=0){
        printf("Enemy\'s ");
        printUnitName(Info_unit(Elmt(canAttack,unitYangAkanDiserang)));
        printf("is dead.\n");
    }

    if(((TipeSerangan(selected(one)) == TipeSerangan(Info_unit(P))) || (Tipe(Info(P))=='K')) && Health(Elmt(canAttack,unitYangAkanDiserang))>0){
        printf("Enemy\'s ");
        printUnitName(Info(Elmt(canAttack,unitYangAkanDiserang)));
        printf("retaliates.\n");

        printf("Your's ");
        printUnitName(Info(P));
        printf("is damaged by %d.\n", Attack(Info(Elmt(canAttack,unitYangAkanDiserang))));
        if(Health(ONE.currentUnit)<=0){
            printf("Your's ");
            printUnitName(Info(P));
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