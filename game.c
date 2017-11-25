#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "petak.h"
#include "player.h"
#include "peta.h"
#include "kata.h"
#include "jam.h"
#include "game.h"
#include "bertarung.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void start_game(boolean *new_game){
	printf("\n");
	printf("WELCOME TO THE BATTLE FOR OLYMPIA\n"); 
	printf("\n");
	printf("START\n");
	printf("1. New Game\n");
	printf("2. Load Game\n");
	printf("\n");
	char start_option;
	for (;;)
	{
		printf("Your input: ");
		scanf("%c",&start_option);
		if (start_option == '1')
		{
			*new_game = true;
			break;
		} else if (start_option == '2')
		{
			*new_game = false;
			break;
		}
		printf("Invalid input. Try again.\n");
		scanf("%c",&start_option);
	}
	printf("\n");
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

boolean isAdaMusuh(POINT P_Select, POINT P2, peta M){
	//Cek Horizontalnya (doang)
	boolean ada = false;

	if (Ordinat(P_Select) == Ordinat(P2)){
		if (Absis(P_Select) > Absis(P2)){
			for (int i = Absis(P2) + 1; i < Absis(P_Select); ++i){
				if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 1) && (pemilik(unit_petak(petak(M,i,Ordinat(P2)))) == 2))
					ada = true;
				else if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 2) && (pemilik(unit_petak(petak(M,i,Ordinat(P2)))) == 1))
					ada = true;
			}
		}
		else if (Absis(P_Select) < Absis(P2)){
			for (int i = Absis(P_Select) + 1; i < Absis(P2); ++i){
				if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 1) && (pemilik(unit_petak(petak(M,i,Ordinat(P2)))) == 2))
					ada = true;
				else if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 2) && (pemilik(unit_petak(petak(M,i,Ordinat(P2)))) == 1))
					ada = true;
			}
		}
	}

	//Cek Vertikalnya (doang)
	else if (Absis(P_Select) == Absis(P2)){
		if (Ordinat(P_Select) > Ordinat(P2)){
			for (int i = Ordinat(P2) + 1; i < Ordinat(P_Select); ++i){
				if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 1) && (pemilik(unit_petak(petak(M,Absis(P2),i))) == 2))
					ada = true;
				else if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 2) && (pemilik(unit_petak(petak(M,Absis(P2),i))) == 1))
					ada = true;
			}
		}
		else if (Ordinat(P_Select) < Ordinat(P2)){
			for (int i = Ordinat(P_Select) + 1; i < Ordinat(P2); ++i){
				if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 1) && (pemilik(unit_petak(petak(M,Absis(P2),i))) == 2))
					ada = true;
				else if ((pemilik(unit_petak(petak(M,Absis(P_Select),Ordinat(P_Select)))) == 2) && (pemilik(unit_petak(petak(M,Absis(P2),i))) == 1))
					ada = true;
			}
		}
	}
	return ada;	
}

void MOVE(player *P, peta *M, player *q, Stack *S){ 
	POINT loc = (*P).selected.lokasi;
	unit slc = (*P).selected; //unit yang sedang dipilih
	state X;
	PrevPos(X) = loc; 
	/***************************	TULIS PETA 	*****************************/
	printf("\n");
	printf("  ");
	for (int i=0; i<NKolEff(*M); i++){
		for (int j=0; j<4; j++){
			if (i<10 && j==1){
				printf("%d",i);
			} else if (i>=10 && j == 1){
				printf("%d",i);
			} else {
				printf(" ");
			}
		}				
	}
	printf("\n");
	for (int i=0; i<NBrsEff(*M); i++){
		printf("  ");
		for (int j=0; j<4*NKolEff(*M); j++){
			printf("*");
		}
		printf("*");
		for (int j=0; j<4; j++){
			if (j==2){
				printf("%d",i);
				if (i<10){
					printf(" ");
				}
			} else {
				printf("  ");
			}
			for (int k=0; k<NKolEff(*M); k++){
				POINT Current = MakePOINT(i,k);
				for (int l=0; l<4; l++){
					if (j!=0){
						if (l == 0){
							printf("*");
						} else if (l == 2){
							if (j==1){
								if (milik_petak(petak(*M,i,k)) == 1){
										print_red(jenis_petak(petak(*M,i,k)));	
									} else if (milik_petak(petak(*M,i,k)) == 2) {
										print_cyan(jenis_petak(petak(*M,i,k)));
									} else {
										printf("%c",jenis_petak(petak(*M,i,k)));
									}
							} else if (j==2){
								if (isequal_unit(unit_petak(petak(*M,i,k)),empty_unit(MakePOINT(i,k))) && (manhattan_dist(Current, loc) <= move_point(slc)) && 
									(isAdaMusuh(loc, MakePOINT(i,k), *M) == 0) && (Absis(loc) == i || Ordinat(loc) == k)){
									printf("#");
								} 
								else if (isequal_unit(unit_petak(petak(*M,i,k)),empty_unit(MakePOINT(i,k)))){
									printf(" ");
								}
								else {
									if (isequal_unit(unit_petak(petak(*M,i,k)),selected(*P))){
										print_green(simbol(unit_petak(petak(*M,i,k))));
									} else if (pemilik(unit_petak(petak(*M,i,k))) == 1){
										print_red(simbol(unit_petak(petak(*M,i,k))));	
									} else if (pemilik(unit_petak(petak(*M,i,k))) == 2){
										print_cyan(simbol(unit_petak(petak(*M,i,k))));
									} else {
										printf("ERROR"); //Error
									}
								}
							} else {
								printf(" ");
							}
						} else {
							printf(" ");
						}
					} else {
						printf(" ");
					}
				}	
				if (k == NKolEff(*M) - 1 && j!=0){
					printf("*");
				}
			}
			printf("\n");
		}
	}
	printf("  ");
	for (int i=0; i<4*NKolEff(*M)+1; i++) printf("*");
	printf("\n");
/******************************************	AKHIR TULIS PETA ***************************/
	int x,y; 
	boolean moved = false;
	if (move_point(slc) <= 0){
		printf("Movement point = 0. Your selected unit can't move\n");
	} else {
		do{
			printf("Please enter cell's coordinate x y: ");
			scanf("%d %d",&x,&y);
			if (manhattan_dist(MakePOINT(x,y),loc) > move_point(slc) || !isequal_unit(unit_petak(petak(*M,x,y)),empty_unit(MakePOINT(x,y))) || 
				isAdaMusuh(loc, MakePOINT(x,y), *M) || !(Absis(loc) == x || Ordinat(loc) == y)) {
				printf("Sorry. You can't move there\n");
			} else {
				unit temp = selected(*P);
				swap_unit(&unit_petak(petak(*M,x,y)), &unit_petak(petak(*M,Absis(loc), Ordinat(loc))));
				
				if (jenis_petak(petak(*M,x,y)) == 'V'){
					move_point(selected(*P)) = 0;
					if (milik_petak(petak(*M,x,y)) == simbol_player(*q)){
						DelP_listpetak (&list_petak(*q), petak(*M,x,y));
						milik_petak(petak(*M,x,y)) = simbol_player(*P);
						income(*q) -= INCOME_INC;
					}
					InsVFirst_listpetak (&list_petak(*P), petak(*M,x,y));
					income(*P) += INCOME_INC;			
				} else {
					move_point(unit_petak(petak(*M,x,y))) -= manhattan_dist(loc,MakePOINT(x,y));				
				}

				printf("Your selected unit has been moved to (%d,%d)\n",x,y);
				// Searching unit di list
				NextPos(X) = MakePOINT(x,y);
				selected(*P) = unit_petak(petak(*M,x,y));
				add_unit slc_in_list = Search_listunit(list_unit(*P),temp);
				Info_unit(slc_in_list) = selected(*P);
				moved = true;
				Push(S, X); // Push ke stack of state setiap unit bergerak;
			}
	} while (moved == false);		
	}
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

void call_SAVE(peta *M, int TURN, long time_start) //incomplete
{
	FILE *fp;
	fp = fopen("save_game.txt", "w");
	if (fp == NULL)
	{
		printf("Save game failed, please try again later\n");
	} else
	{
		fprintf(fp,"%d %d\n", NBrsEff(*M), NKolEff(*M)); // Besar Map
		fprintf(fp,"%d\n", TURN);					  // Turn siapa
		
		/*masukkan state menggunakan fprintf() ke file external*/
	}

	/* NOTE: Hal2 yg perlu disimpen
			Besar map !!DONE!!
			Turn siapa !!DONE!!
			State petak (ingat bahwa letak village perlu disave karena random)
			State Player 1 dan 2 (gold, income, upkeep, warna)
			State semua unit
		// Kalo ada yang perlu ditambahin ketik disini yaa!!
	*/

	long time_end = time(NULL);
	JAM tstart = DetikToJAM(time_start);
	JAM tend = DetikToJAM(time_end);
	long durasi = Durasi(tstart, tend);
	if (durasi < 120)
	{
		printf("Your game have been saved, you have played for %ld seconds this session\n", (durasi));
	} else
	{
		printf("Your game have been saved, you have played for %ld minutes this session\n", (durasi/60));
	}

}

void call_EXIT(peta *M, int TURN, long time_start, boolean game_over)
{
	char savegame;
	printf("Would you like to save the game? (y/n)\n");
	scanf("%c",&savegame);
	do {
		scanf("%c",&savegame);
		if (savegame != 'y' && savegame != 'n'){
			printf("Tidak valid");
		}
	} while (savegame != 'y' && savegame != 'n');

    if (savegame == ('y'))
    {
        call_SAVE(M, TURN, time_start);
    } else if (savegame == ('n'))
    {
    }
	printf("Exiting the game...\n");
	game_over = true;
	exit('\n');
}

/*
void CreateTurnQueue12(Queue *Q)
{
    CreateEmpty(Q,2);
    Add(Q,1);
    Add(Q,2);
}

void CreateTurnQueue21(Queue *Q)
{
    CreateEmpty(Q,2);
    Add(Q,2);
    Add(Q,1);
}

void NextTurnQueue(Queue *Q)
{
    int A;
    Del(Q,&A);
    Add(Q,A);
} */

void do_recruit(player *P, POINT loc_new, peta *M){
	printf("List of recruits\n");
	int cnt = 1;
	if (gold(*P) >= H_ARCHER){
		printf("%d. Archer | Health: %d | ATK: %d | ATK_type: %c | Price: %dG\n", cnt,MH_ARCHER,ATK_ARCHER,TS_ARCHER,H_ARCHER);
		cnt++;
	} 
	if (gold(*P) >= H_SWORDSMAN){
		printf("%d. Swordsman | Health: %d | ATK: %d | ATK_type: %c | Price: %dG\n", cnt,MH_SWORDSMAN,ATK_SWORDSMAN,TS_SWORDSMAN,H_SWORDSMAN);
		cnt++;
	} 
	if (gold(*P) >= H_WHITEMAGE) { // gold(P) >= H_WHITEMAGE
		printf("%d. Whitemage | Health: %d | ATK: %d | ATK_type: %c | Price: %dG\n", cnt,MH_WHITEMAGE,ATK_WHITEMAGE,TS_WHITEMAGE,H_WHITEMAGE);
		cnt++;
	}
	
	int no_rec;
	do {
		printf("Enter no unit you want to recruit\n");
		scanf("%d",&no_rec);
		if (no_rec < 1 || no_rec > 3){
			printf("Invalid input\n");
		}	
	} while (no_rec < 1 || no_rec > 3);					
		
	unit new_u;
	if (no_rec == 1){
		gold(*P) = gold(*P) - H_ARCHER;
		new_u = unit_petak(petak(*M,Absis(loc_new),Ordinat(loc_new)));
		assign_unit(&new_u,'A',simbol_player(*P));
		printf("You have recruit an archer\n");
	} else if (no_rec == 2){
		gold(*P) = gold(*P) - H_SWORDSMAN;
		new_u = unit_petak(petak(*M,Absis(loc_new),Ordinat(loc_new)));
		assign_unit(&new_u,'S',simbol_player(*P));
		printf("You have recruit a swordsman\n");
	} else {
		gold(*P) = gold(*P) - H_WHITEMAGE;
		new_u = unit_petak(petak(*M,Absis(loc_new),Ordinat(loc_new)));
		assign_unit(&new_u,'W',simbol_player(*P));
		printf("You have recruit a whitemage\n");
	}		
	InsVLast_listunit(&list_unit(*P),new_u);
	assign_petak(&(petak(*M,Absis(loc_new),Ordinat(loc_new))),'C',simbol_player(*P),new_u);
	upkeep(*P) += UP_KEEP_DEC;
}	

void recruit(player *P, peta *M){
	int id_p = simbol_player(*P);
	petak pt;
	if (id_p == 1){
		pt = petak(*M,NBrsEff(*M)-2,1);	
	} else {
		pt = petak(*M,1,NKolEff(*M)-2);	
	}

	if (simbol(unit_petak(pt)) == 'K' && pemilik(unit_petak(pt)) == id_p){
		petak l = petak(*M,Absis(left(lokasi_petak(pt))),Ordinat(left(lokasi_petak(pt))));
		petak r = petak(*M,Absis(right(lokasi_petak(pt))),Ordinat(right(lokasi_petak(pt))));
		petak u = petak(*M,Absis(up(lokasi_petak(pt))),Ordinat(up(lokasi_petak(pt))));
		petak d = petak(*M,Absis(down(lokasi_petak(pt))),Ordinat(down(lokasi_petak(pt))));

		boolean b1 = simbol(unit_petak(l)) == ' ';
		boolean b2 = simbol(unit_petak(r)) == ' ';
		boolean b3 = simbol(unit_petak(u)) == ' ';
		boolean b4 = simbol(unit_petak(d)) == ' ';

		if (b1 || b2 || b3 || b4){
			int x = Absis(lokasi_petak(pt));
			int y = Ordinat(lokasi_petak(pt));
			int x1, y1;
			
			do{
				printf(">> Enter coordinat x y of your castle\n");
				printf("<< ");
				scanf("%d %d",&x1,&y1);
				if (abs(x-x1) + abs(y-y1) != 1){
					printf(">> This cell is not your castle\n");
				} else {
					POINT slc = MakePOINT(x1,y1);
					if (isequal_point(lokasi_petak(l),slc) && b1){
						do_recruit(P,slc,M);
					} else if (isequal_point(lokasi_petak(r),slc) && b2){
						do_recruit(P,slc,M);
					} else if (isequal_point(lokasi_petak(u),slc) && b3){
						do_recruit(P,slc,M);
					} else if (isequal_point(lokasi_petak(d),slc) && b4){
						do_recruit(P,slc,M);
					} else {
						printf(">> Your selected castle is occupied\n");						
					}	
				}				
			} while (abs(x-x1) + abs(y-y1) != 1);

		} else {
			printf(">> Recruit failed. Your castles are full\n");
		}

	} else {
		printf(">> Recruit failed. Your king is not in tower\n");
	}
}

void infopetak(peta M)
{
    int X, Y;
    petak p;
    unit u;

    printf("Enter the coordinate of the cell: ");scanf(" %d %d",&X,&Y);
    while (!(0<=X && X<=NBrsEff(M)-1 && 0<=Y && Y<=NKolEff(M)-1)){
    	printf("Your coordinate is out of bounds\n");
	    printf("Enter the coordinate of the cell: ");scanf(" %d %d",&X,&Y);
    }
    p=petak(M,X,Y);
    printf("== Cell Info ==\n");
    if(jenis_petak(p)=='V')
    {
        printf("Village\n");
    }
    else if(jenis_petak(p)=='C')
    {
        printf("Castle\n");
    }
    else if(jenis_petak(p)=='T')
    {
        printf("Tower\n");
    }
    else
    {
        printf("Empty Land\n");
    }
    if (jenis_petak(p)!=' '){
    printf("Owned by Player %d\n", milik_petak(p));
    printf("\n");}

    printf("== Unit Info ==\n");
    u=unit_petak(p);


    if(simbol(u)=='K')
    {
        printf("King\n");
    }
    else if(simbol(u)=='A')
    {
        printf("Archer\n");
    }
    else if(simbol(u)=='S')
    {
        printf("Swordsman\n");
    }
    else if(simbol(u)==' ')
    {
        printf("No Unit\n");
    }
    else
    {
        printf("White Mage\n");
    }

    if(simbol(u)!=' '){
    	printf("Owned by Player %d\n", pemilik(u));
    	printf("Health %d/%d | ATK %d | DEF %c\n",health(u),max_health(u),attack(u),tipe_serang(u));
    }
}

void do_command(int code, player *p, player *q, peta *M, int turn, long time_start, boolean game_over,Queue *Q, Stack *S){
	switch (code) {
		case 1 :  MOVE(p,M,q,S); break;
		case 2 :  break;
		case 3 :  change_unit(p); break;
		case 4 :  recruit(p,M); break;
		case 5 :  COMMAND_ATTACK(p,q,M); break;
		case 6 :  display_peta(*M,*p); break;
		case 7 :  infopetak(*M); break;
		case 8 :  NextTurnQueue(Q,p,M); break;
		case 9 :  call_SAVE(M, turn, time_start); break;
		case 10 : call_EXIT(M, turn, time_start, game_over); break;
		case 11 : display_command(); break;
		default : 
			printf("ERROR\n"); 
			printf("\n"); 
			break;
	}
}

