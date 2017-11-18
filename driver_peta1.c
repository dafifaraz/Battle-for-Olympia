#include "peta.h"

int main(){
	peta M;
	int NB = 8;
	int NK = 15;
	init_peta(&M,NB,NK);
	player p1;
	p1.selected = unit_petak(petak(M,6,1));
	display_peta(M);
	char cc;
	scanf("%c", &cc);
	if (cc == 'c'){
		MOVE(p1, &M);
	}
	return 0;
}
