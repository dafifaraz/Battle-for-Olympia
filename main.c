#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "pcolor.h"
#include "peta.h"
#include "player.h"
#include "kata.h"
#include "jam.h"

//konstanta game
#define MAX_BARIS_peta 100
#define MAX_KOLOM_peta 100
#define PANJANG_PAGAR 70

void start_game(boolean *new_game){
	printf("\n");
	printf("WELCOME TO THE BATTLE FOR OLYMPIA\n"); 
	printf("\n");
	printf("START\n");
	printf("1. New Game\n");
	printf("2. Load Game\n");
	printf("\n");
	// Terima input new game atau load game hingga valid
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
//state awal : boolean new_game = true
//state akhir : init peta M
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
//menampilkan daftar command yang tersedia dalam games
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
//menerima str sebagai command dan mengembalikan integer nomor urut command tsb
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
//state awal : sembarang
//state akhir : diberikan kode yang merupakan nomor urut command
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

void call_SAVE(peta *M, int TURN, long time_start) //incomplete
{
	FILE *fp;
	fp = fopen("save_game.txt", "w");
	if (fp == NULL)
	{
		printf("Save game failed, please try again later\n");
	} else
	{
		fprintf(fp,"%d %d", NBrsEff(*M), NKolEff(*M)); // Besar Map
		fprintf(fp,"%d", TURN);					  // Turn siapa

		/*masukkan state menggunakan fprintf() ke file external*/
	}

	/* NOTE: Hal2 yg perlu disimpen
			Besar map
			Turn siapa
			State petak
			State Player 1 dan 2 (gold, income, upkeep, warna)
			State semua unit
		// Kalo ada yang perlu ditambahin ketik disini yaa!!
	*/

	long time_end = time(NULL);
	JAM tstart = DetikToJAM(time_start);
	JAM tend = DetikToJAM(time_end);
	long durasi = Durasi(tstart, tend);
	printf("Your game have been saved, you have played for %ld minutes this session\n", (durasi/60));

}

void do_command(int code, player *p, peta *M, int turn, long time_start){
	switch (code) {
		case 1 :  break;
		case 2 :  break;
		case 3 :  change_unit(p); break;
		case 4 :  break;
		case 5 :  break;
		case 6 :  break;
		case 7 :  break;
		case 8 :  break;
		case 9 :  call_SAVE(M, turn, time_start); break;
		case 10 :  break;
		case 11 : display_command(); break;
		default : 
			printf("ERROR\n"); 
			printf("\n"); 
			break;
	}
}




int main(){
	peta main_peta;
	player p1,p2;
	int turn; //Giliran

	boolean new_game;
	time_t time_start = time(NULL);
	start_game(&new_game);

	// Aksi ketika new game
	if (new_game){
		do_new_game(&main_peta,&p1,&p2);

		turn = 1; //Pemain 1 mulai pertama
	} else {
	}

	display_command();
	int code;
	boolean game_over = false;
	do{	
		if (turn == 1){
			display_player_info(p1);
			receive_command(&code);
			do_command(code,&p1,&main_peta, turn, time_start);
			if(code != 9)
			{
				turn = 2;
			} else turn = 1;
		} else {
			display_player_info(p2);
			receive_command(&code);
			do_command(code,&p2,&main_peta, turn, time_start);
			if(code != 9)
			{
				turn = 1;
			} else turn = 2;
		}
	} while (!game_over);

}


/* ARSIP 

void call_MOVE(){
	printf("TEST\n");
}
void call_UNDO(){}
void call_CHANGE_UNIT(){}
void call_RECRUIT(){}
void call_ATTACK(){}
void call_MAP(){}
void call_INFO(){}
void call_END_turn(){}


void call_EXIT() //incomplete



		/*LOAD FILE EXTERNAL DAN ASSIGN KE VARIABEL
		/*PANGGIL SEMUA PROSEDUR UNTUK INIT STATE DARI FILE EXT
		
		FILE *fp;
		int input_nbaris, input_nkolom;
		fp = fopen("save_game.txt", "r");
		if (fp == NULL)
		{
			printf("Load game failed\n");
			//break;
		} else {
			
			fscanf(fp, "%d", &input_nbaris);
			fscanf(fp, "%d", &input_nkolom);
			fscanf(fp, "%d", &turn);
			//incomplete
		}
		
		/* INFO ISI FILE EKSTERNAL: 
		baris 1: ukuran peta
		baris 2: 
		*/
	
