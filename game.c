#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "petak.h"
#include "player.h"
#include "peta.h"
#include "kata.h"
#include "game.h"

void start_game(boolean *new_game){
	printf("\n");
	printf("WELCOME TO THE BATTLE FOR OLYMPIA\n"); 
	printf("\n");
	printf("START\n");
	printf("1. New Game\n");
	printf("2. Load Game\n");
	printf("\n");
	int start_option;
	do {
		printf("Your Input : "); scanf("%d",&start_option); 
		printf("\n");
		if (start_option == 1){
			*new_game = true;
		} else if (start_option == 2){
			*new_game = false;
		} else {
			printf("Invalid input. Try again\n");
			printf("\n");
		}
	} while (start_option < 1 || start_option > 2);
}

void do_new_game(peta *M, player *p1, player *p2){
	boolean valid_peta;
	int input_nbaris, input_nkolom;
	do {
		printf("Length of map row : "); scanf("%d",&input_nbaris);
		printf("\n");
		printf("Length of map column : "); scanf("%d",&input_nkolom);
		printf("\n");
		if (input_nbaris < 8 || input_nkolom < 8 || input_nbaris > MAX_BARIS_peta || input_nkolom > MAX_KOLOM_peta){
			valid_peta = false;
		} else {
			valid_peta = true;
		}
		if (!valid_peta){
			printf("The minimum map area is 8x8 and maximum map area is %dx%d\n",MAX_BARIS_peta,MAX_KOLOM_peta);
			printf("\n");
		}
	} while (!valid_peta);
	init_peta(M, input_nbaris, input_nkolom, p1, p2);
}

void display_command(){
	printf("Available Command\n");
	printf("1.  MOVE\n");
	printf("2.  UNDO\n");
	printf("3.  CHANGE_UNIT\n");
	printf("4.  RECRUIT\n");
	printf("5.  ATTACK\n");
	printf("6.  MAP\n");
	printf("7.  INFO\n");
	printf("8.  END_TURN\n");
	printf("9.  SAVE\n");
	printf("10. EXIT\n");
	printf("11. DISPLAY_COMMAND\n");
	printf("\n");
}

int command_code(char* str){
	int code;
	if (isequal_str(str,"MOVE")){
		code = 1;
	} else if (isequal_str(str,"UNDO")){
		code = 2;
	} else if (isequal_str(str,"CHANGE_UNIT")){
		code = 3;
	} else if (isequal_str(str,"RECRUIT")){
		code = 4;
	} else if (isequal_str(str,"ATTACK")){
		code = 5;
	} else if (isequal_str(str,"MAP")){
		code = 6;
	} else if (isequal_str(str,"INFO")){
		code = 7;
	} else if (isequal_str(str,"END_TURN")){
		code = 8;
	} else if (isequal_str(str,"SAVE")){
		code = 9;
	} else if (isequal_str(str,"EXIT")){
		code = 10;
	} else if (isequal_str(str,"DISPLAY_COMMAND")){
		code = 11;
	} else {
		code = 0;
	}
	return code;
}

void receive_command(int *code){
	char str_command[100];
	do{
		printf("Your input : "); scanf("%s",str_command);
		*code = command_code(str_command);
		if (*code == 0){
			printf("Command %s is not available\n",str_command);
			printf("\n");
		}
	} while (*code == 0);
}

void do_command(int code, player *p, peta *M, int turn, long time_start, boolean game_over){
	switch (code) {
		case 1 :  break;
		case 2 :  break;
		case 3 :  change_unit(p); break;
		case 4 :  break;
		case 5 :  break;
		case 6 :  break;
		case 7 :  break;
		case 8 :  NextTurnQueue(&Q); break;
		case 9 :  call_SAVE(M, turn, time_start); break;
		case 10 : call_EXIT(M, turn, time_start, game_over); break;
		case 11 : display_command(); break;
		default : 
			printf("ERROR\n"); 
			printf("\n"); 
			break;
	}
}