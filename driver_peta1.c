#include "peta.h"

int main(){
	peta M;
	int NB = 8;
	int NK = 8;
	init_peta(&M,NB,NK);
	display_peta(M);
}