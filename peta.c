#include "peta.h"
#include "point.h"
#include "petak.h"

void empty_peta(peta *M, int NBrsEff, int NKolEff){
	NBrsEff(*M) = NBrsEff;
	NKolEff(*M) = NKolEff;
	for (int i=0; i<NBrsEff; i++){
		for (int j=0; j<NKolEff; j++){
			petak(*M,i,j) = empty_petak(MakePOINT(i,j));
		}
	}
}
