#include "peta.h"

int main(){
	peta M;
	int NB = 8;
	int NK = 15;
	player p1, p2;
	init_peta(&M,NB,NK,&p1,&p2);
	p1.selected = unit_petak(petak(M,6,1));
	assign_unit(&unit_petak(petak(M,6,3)), 'A', 2);
	display_peta(M,p1);
	char cc;
	scanf("%c", &cc);
	if (cc == 'c'){
		MOVE(p1, &M);
	}
	display_peta(M,p1);
	return 0;
}
