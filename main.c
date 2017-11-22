#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "pcolor.h"
#include "peta.h"
#include "player.h"
#include "kata.h"
#include "jam.h"
#include "game.h"

int main(){
	peta main_peta;
	player p1,p2;
	//Queue Q;
	int turn; //Giliran

	boolean new_game;
	time_t time_start = time(NULL);
	start_game(&new_game);

	// Aksi ketika new game
	if (new_game){
		do_new_game(&main_peta,&p1,&p2);

		//CreateTurnQueue12(&Q); //Pemain 1 mulai pertama
	} else {
		int x, y, t;
		FILE *fp;
		fp = fopen("save_game.txt", "r");
		fscanf(fp,"%d %d", &x, &y);
		fscanf(fp,"%d", &t);
		init_peta(&main_peta, x, y, &p1, &p2);
		turn = t;
	}

	display_command();
	int code;
	boolean game_over = false;
	turn = 1;
	do{
        //turn = InfoHead(Q);
		if (turn == 1){
			display_player_info(p1);
			receive_command(&code);
			do_command(code,&p1,&main_peta, turn, time_start,game_over);
		} else {
			display_player_info(p2);
			receive_command(&code);
			do_command(code,&p2,&main_peta, turn, time_start,game_over);
		}
	} while (!game_over);
}
	/*
	do{	
		if (turn == 1){
			display_player_info(p1);
			receive_command(&code);
			do_command(code,&p1,&main_peta, turn, time_start, game_over);
			if(code != 9 && code != 0)
			{
				turn = 2;
			} else turn = 1;
		} else {
			display_player_info(p2);
			receive_command(&code);
			do_command(code,&p2,&main_peta, turn, time_start, game_over);
			if(code != 9 && code != 0)
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
	
