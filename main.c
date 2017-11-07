#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "pcolor.h"

#define MAX_BARIS_PETA 100
#define MAX_KOLOM_PETA 100
#define PANJANG_PAGAR 70

void print_text(char c, char* text){
	int rest = PANJANG_PAGAR - strlen(text);
	int awal = rest/2; 
	int akhir = rest - awal;
	
	for (int i=0; i<=awal; i++) printf("%c",c);
	
	if (strlen(text)>0){
		printf("   ");	
	} else {
		for (int i=0; i<3; i++) printf("%c",c); 
	}

	int cnt = 0;
	for (int i=0; i<strlen(text); i++) printf("%c",text[i]);

	if (strlen(text)>0){
		printf("   ");	
	} else {
		for (int i=0; i<3; i++) printf("%c",c); 
	}

	for (int i=0; i<=akhir; i++) printf("%c",c);
	printf("\n");
}

void start_game(boolean *new_game){
	printf("\n");
	print_text('*',"");
	print_text('*',"WELCOME TO THE BATTLE FOR OLYMPIA");
	print_text('*',"");
	printf("\n");

	printf(">> START\n");
	printf(">> 1. New Game\n");
	printf(">> 2. Load Game\n");

	// Terima input new game atau load game hingga valid
	int start_option;
	do {
		printf("<< "); scanf("%d",&start_option);
		if (start_option == 1){
			printf("\n");
			print_text('*',"NEW GAME"); 
			printf("\n");
			*new_game = true;
		} else if (start_option == 2){
			printf("\n");
			print_text('*',"LOAD GAME"); 
			printf("\n");
			*new_game = false;
		} else {
			printf("\n>> Invalid input. Try again\n");
		}
	} while (start_option < 1 || start_option > 2);
}

void do_new_game(int *input_nbaris, int *input_nkolom){
	boolean valid_peta;
	do {
		printf(">> Length of map row :\n");
		printf("<< "); scanf("%d",input_nbaris);
		printf(">> Length of map column :\n");
		printf("<< "); scanf("%d",input_nkolom);
		
		if (*input_nbaris < 8 || *input_nkolom < 8 || *input_nbaris > MAX_BARIS_PETA || *input_nkolom > MAX_KOLOM_PETA){
			valid_peta = false;
		} else {
			valid_peta = true;
		}

		if (!valid_peta){
			printf("\n>> The minimum map area is 8x8 and maximum map area is %dx%d\n",MAX_BARIS_PETA,MAX_KOLOM_PETA);
			printf("\n");
		}
	} while (!valid_peta);
}

void display_command(){
	printf("\n>> Available command : ");
	printf("\n>> 1.  MOVE");
	printf("\n>> 2.  UNDO");
	printf("\n>> 3.  CHANGE_UNIT");
	printf("\n>> 4.  RECRUIT");
	printf("\n>> 5.  ATTACK");
	printf("\n>> 6.  MAP");
	printf("\n>> 7.  INFO");
	printf("\n>> 8.  END_TURN");
	printf("\n>> 9.  SAVE");
	printf("\n>> 10. EXIT");
	printf("\n>> 11. DISPLAY_COMMAND\n");
}

int command_code(char* str){
	int code;
	
	if (!strcmp(str,"MOVE")){
		code = 1;
	} else if (!strcmp(str,"UNDO")){
		code = 2;
	} else if (!strcmp(str,"CHANGE_UNIT")){
		code = 3;
	} else if (!strcmp(str,"RECRUIT")){
		code = 4;
	} else if (!strcmp(str,"ATTACK")){
		code = 5;
	} else if (!strcmp(str,"MAP")){
		code = 6;
	} else if (!strcmp(str,"INFO")){
		code = 7;
	} else if (!strcmp(str,"END_TURN")){
		code = 8;
	} else if (!strcmp(str,"SAVE")){
		code = 9;
	} else if (!strcmp(str,"EXIT")){
		code = 10;
	} else if (!strcmp(str,"DISPLAY_COMMAND")){
		code = 11;
	} else {
		code = 0;
	}
	return code;
}

void receive_command(char* str_command, int *code){
	scanf("%s",str_command);
	*code = command_code(str_command);
	if (*code == 0){
		printf("\n>> Command %s is not available\n",str_command);
	}
}


void call_MOVE(){}
void call_UNDO(){}
void call_CHANGE_UNIT(){}
void call_RECRUIT(){}
void call_ATTACK(){}
void call_MAP(){}
void call_INFO(){}
void call_END_TURN(){}
void call_SAVE(){}
void call_EXIT(){}

void do_command(int code){
	switch (code) {
		case 1 : call_MOVE(); printf("TEST\n"); break;
		case 2 : call_UNDO(); break;
		case 3 : call_CHANGE_UNIT(); break;
		case 4 : call_RECRUIT(); break;
		case 5 : call_ATTACK(); break;
		case 6 : call_MAP(); break;
		case 7 : call_INFO(); break;
		case 8 : call_END_TURN(); break;
		case 9 : call_SAVE(); break;
		case 10 : call_EXIT(); break;
		default : break;
	}
}

int main(){
	PETA MAIN_PETA;
	PLAYER ONE,TWO;
	int TURN; //Giliran
	boolean new_game;
	start_game(&new_game);

	// Aksi ketika new game
	if (new_game){
		//Baca Baris dan Kolom, setel kondisi awal
		int input_nbaris, input_nkolom;
		do_new_game(&input_nbaris, &input_nkolom);
		NBrsEff(MAIN_PETA) = input_nbaris;
		NKolEff(MAIN_PETA) = input_nkolom;
		initAwal(&MAIN_PETA);
		/*disini tambah setup player
		  player perlu data di map
		  currentUnit di set ke King, state awal

		  kira-kira kaya gini

		  ONE.currentUnit = MAIN_PETA.P[NBrsEff(*M)-2][1].unit;
		  TWO.currentUnit = MAIN_PETA.P[1][NKolEff(*M)-2].unit;
		*/
		TURN = 1; //Pemain 1 mulai pertama
	} else { /*** LOAD GAME ***/

	}


	
	display_command();
	boolean game_over = false;
	int command;
	do{
		char* str_command; int code;
		receive_command(str_command, &code);
		do_command(code);
		if (code == 0) game_over = true;
	} while (!game_over); 

}
