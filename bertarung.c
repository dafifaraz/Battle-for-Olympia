boolean canSerang(Unit A, Unit B){
    return  (abs(A.SpecificProperty.lokasi.X-B.SpecificProperty.lokasi.X)+abs(A.SpecificProperty.lokasi.X-B.SpecificProperty.lokasi.X) == 1);

}

void Serang(Unit *X, Unit *Y){
    Health(*Y) -= Attack(*X);
    if( ((TipeSerangan(*X)==TipeSerangan(*Y)) || Tipe(*Y)=='K') && (Health(*Y)>0)){
        //RETALIATION
        Health(*X) -= Attack(*Y);
    }
}