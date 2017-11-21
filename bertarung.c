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