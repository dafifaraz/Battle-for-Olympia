#include "kata.h"
#include <stdio.h>
int main(){
	char pita[100];
	scanf("%s",pita);
	printf("%d\n", isequal_str(pita,"MOVE"));
}