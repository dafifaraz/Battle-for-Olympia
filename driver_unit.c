#include "unit.h"
#include "point.h"
#include <stdio.h>

int main(){
	unit u1 = empty_unit(MakePOINT(1,1));
	assign_unit(&u1,'W',1);
	unit u2 = empty_unit(MakePOINT(1,1));
	assign_unit(&u2,'W',1);
	printf("%d\n",isequal_unit(u1,u2));
}