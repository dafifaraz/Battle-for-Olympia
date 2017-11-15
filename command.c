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
void printPetakName(PETAK P){
    if(Jenis(P) == 'C'){
        printf("Castle ");
    }else
    if(Jenis(P) == 'V'){
        printf("Village ");
    }else
    if(Jenis(P) == 'N'){
        printf("Normal ");
    }
}

void COMAND_ATTACK(Player ONE, Player TWO){
    TabAddress canAttack;
    MakeEmpty(&canAttack);
    printf("Please select enemy you want to attack:\n");
    address P = First(TWO.unit);
    int cntUnit=0;
    while (P != Nil){
        if(canSerang(ONE.currentUnit, Info(P))){
            printUnitName(Info(P))
            printf("(%d,%d) | Health ",Lokasi(Info(P)).X, Lokasi(Info(P)).Y);
            printf("%d/%d", Health(Info(P)), MaxHealth(Info(P)));
            if(((TipeSerangan(ONE.currentUnit) == TipeSerangan(Info(P))) || (Tipe(Info(P))=='K')) && (Attack(ONE.currentUnit)<Health(Info(P)))){
                printf(" (Retaliates)\n");
            }else{
                printf("\n");
            }
            Elmt(canAttack,cntUnit) = P;
            Neff(canAttack)++;
        }
        P = Next(P);
    }

    printf("Select enemy you want to attack: ");
    int unitYangAkanDiserang;
    scanf("%d", &unitYangAkanDiserang);

    Serang(&ONE.currentUnit, &Info(Elmt(canAttack,unitYangAkanDiserang)));
    printf("Enemy\'s ");
    printUnitName(Info(Elmt(canAttack,unitYangAkanDiserang)));
    printf("is damaged by %d.\n",Attack(ONE.currentUnit));
    
    if(Health(Info(Elmt(canAttack,unitYangAkanDiserang)))<=0){
        printf("Enemy\'s ");
        printUnitName(Info(Elmt(canAttack,unitYangAkanDiserang)));
        printf("is dead.\n");
    }

    if(((TipeSerangan(ONE.currentUnit) == TipeSerangan(Info(P))) || (Tipe(Info(P))=='K')) && Health(Elmt(canAttack,unitYangAkanDiserang))>0){
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

void COMAND_INFO(){
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
