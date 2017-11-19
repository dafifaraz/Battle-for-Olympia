#include "kata.h"
#include "boolean.h"

int strlen(char* str){
	int i=0;
	while ((int)str[i] != 0) i++;
	return i;
}

boolean isequal_str(char* str1, char* str2){
	if (strlen(str1) != strlen(str2)){
		return false;
	} else {
		int i=0;
		while (i<strlen(str1) && str1[i]==str2[i]) i++;
		return str1[i] == str2[i];
	}
}