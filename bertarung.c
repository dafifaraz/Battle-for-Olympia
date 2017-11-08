boolean MEC_canAttack(Unit A, Unit B){
    return  (abs(A.SpecificProperty.lokasi.X-B.SpecificProperty.lokasi.X)+abs(A.SpecificProperty.lokasi.X-B.SpecificProperty.lokasi.X) == 1);

}

boolean MEC_canRetaliates(Unit X, Unit Y){
    return ((TipeSerangan(X)==TipeSerangan(Y)) || Tipe(Y)=='K') && (Health(Y)>0);
}


void MEC_attack(Unit *X, Unit *Y){
    Health(*Y) -= Attack(*X);
    if(MEC_canRetaliates(*X,*Y)){
        //RETALIATION
        Health(*X) -= Attack(*Y);
    }
}