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
	swap_unit(&unit_petak(petak(M,6,1)), &unit_petak(petak(M,4,3)));
	display_peta(M,p1);
	printf("%d\n", pemilik(unit_petak(petak(M,6,1))));
	// printf("%d\n", health(unit_petak(petak(M,6,3))));
	// printf("%d\n", pemilik(unit_petak(petak(M,4,3))));
	return 0;
}
