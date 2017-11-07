#include <stdio.h>
#include "peta.h"

int main(){
	PETA M;
	NBrsEff(M) = 5;
	NKolEff(M) = 18;
	initAwal(&M);
	MAP(M);

	return 0;
}