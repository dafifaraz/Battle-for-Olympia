#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "pcolor.h"
#include "peta.h"
#include "player.h"
//#include "jam.h"

//konstanta game
#define MAX_BARIS_peta 100
#define MAX_KOLOM_peta 100
#define PANJANG_PAGAR 70

void do_new_game(peta *M, player *p1, player *p2){
//state awal : boolean new_game = true
//state akhir : init peta M
	boolean valid_peta;
	int input_nbaris, input_nkolom;
	do {
		printf(">> Length of map row :\n");
		printf("<< "); scanf("%d",&input_nbaris);
		printf(">> Length of map column :\n");
		printf("<< "); scanf("%d",&input_nkolom);
		if (input_nbaris < 8 || input_nkolom < 8 || input_nbaris > MAX_BARIS_peta || input_nkolom > MAX_KOLOM_peta){
			valid_peta = false;
		} else {
			valid_peta = true;
		}
		if (!valid_peta){
			printf("\n>> The minimum map area is 8x8 and maximum map area is %dx%d\n",MAX_BARIS_peta,MAX_KOLOM_peta);
			printf("\n");
		}
	} while (!valid_peta);
	init_peta(M, input_nbaris, input_nkolom, p1, p2);
}

void display_command(){
//menampilkan daftar command yang tersedia dalam games
	printf("\n>> Available command : ");
	printf("\n>> 1.  MOVE");
	printf("\n>> 2.  UNDO");
	printf("\n>> 3.  CHANGE_UNIT");
	printf("\n>> 4.  RECRUIT");
	printf("\n>> 5.  ATTACK");
	printf("\n>> 6.  MAP");
	printf("\n>> 7.  INFO");
	printf("\n>> 8.  END_turn");
	printf("\n>> 9.  SAVE");
	printf("\n>> 10. EXIT");
	printf("\n>> 11. DISPLAY_COMMAND\n");
}


int strlen(char* str){
//mengembalikan panjang string str
	int i=1;
	while (str[i-1] != '\n') i++;
	return i;
}

boolean isequal_str(char* str1, char* str2){
//true jika dan hanya jika str1 = str2
	if (strlen(str1) != strlen(str2)){
		return false;
	} else {
		int i=0;
		while (i<strlen(str1) && str1[i]==str2[i]){
			i++;
		}
		return str1[i] == str2[i];
	}
}

int command_code(char* str){
//menerima str sebagai command dan mengembalikan integer nomor urut command tsb
	int code;

	if (isequal_str(str,"MOVE\n")){
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
	} else if (isequal_str(str,"END_turn")){
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
//state awal : sembarang
//state akhir : diberikan kode yang merupakan nomor urut command
	do{
		printf("\n>> Your input : ");
		printf("\n<< ");
		char str_command[100];
		scanf("%s",str_command);
		*code = command_code(str_command);
		if (*code == 0){
			printf("\n>> Command %s is not available\n",str_command);
		}
	} while (*code == 0);
}

void start_game(boolean *new_game){
	printf("\n");
	printf("WELCOME TO THE BATTLE FOR OLYMPIA\n");
	printf("\n");

	printf(">> START\n");
	printf(">> 1. New Game\n");
	printf(">> 2. Load Game\n");

	// Terima input new game atau load game hingga valid
	int start_option;
	do {
		printf("<< "); scanf("%d",&start_option);
		if (start_option == 1){
			*new_game = true;
		} else if (start_option == 2){
			*new_game = false;
		} else {
			printf("\n>> Invalid input. Try again\n");
		}
	} while (start_option < 1 || start_option > 2);
}

int main(){
	peta main_peta;
	player p1,p2;
	int turn; //Giliran

	boolean new_game;
	//time_t start_time = time(NULL);
	start_game(&new_game);

	// Aksi ketika new game
	if (new_game){
		do_new_game(&main_peta,&p1,&p2);

		turn = 1; //Pemain 1 mulai pertama
	} else {
	}

	display_command();
	int code = 0;
	boolean game_over = false;
	do{
		if (turn == 1){
			display_player_info(p1);
			receive_command(&code);
			if (code == 10) game_over = true;
			turn = 2;
		} else {
			display_player_info(p2);
			receive_command(&code);
			if (code == 10) game_over = true;
			turn = 1;
		}
	} while (!game_over);

}
