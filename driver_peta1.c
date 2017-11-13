#include "peta.h"

int main(){
	peta M;
	int NB = 10;
	int NK = 40;
	init_peta(&M,NB,NK);
	display_peta(M);
}