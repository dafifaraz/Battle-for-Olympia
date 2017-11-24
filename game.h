#ifndef GAME_H
#define GAME_H

#include <time.h>
#include "boolean.h"
#include "pcolor.h"
#include "peta.h"
#include "player.h"
#include "kata.h"
#include "jam.h"
#include "bertarung.h"
#include "PlayerTurn.h"

#define MAX_BARIS_peta 100
#define MAX_KOLOM_peta 100

void start_game(boolean *new_game);
/*I.S. 	: Sembarang
  Proses: Ditampilkan di layar pesan pembuka, user diminta memilih new game atau load game
  F.S. 	: new_game bernilai true jika ser memilih new game, sebaliknya false */

void do_new_game(peta *M, player *p1, player *p2);
/*I.S. 	: Sembarang
 Proses: User diminta memasukkan input baris dan kolom peta dan divalidasi
 F.S.	: Terbentuk peta M yang valid, p1 dan p2 diinisiasi */

void display_command();
/*I.S. : Sembarang 
  F.S. : Ditampilkan daftar command yang tersedia pada permainan */

int command_code(char *str);
/*str adakah string. return integer 0 jika bukan command. Jika tidak, 1 : MOVE, 2 : UNDO, 3 : CHANGE_UNIT
  4 : RECRUIT, 5 : ATTACK, 6 : MAP, 7 : INFO, 8 : END_TURN, 9 : SAVE, 10 : EXIT, 11 : DISPLAY_COMMAND */

void receive_command (int *code);
/*I.S.  : Sembarang
  Proses: Meminta user memasukkan command dan divalidasi hingga valid.
  F.S. 	: code merupakan command_code dari command valid oleh user */

boolean is_tercapai(POINT slc, POINT tujuan, peta m, int max_move);

void MOVE(player *P, peta *M);

void call_SAVE(peta *M, int TURN, long time_start); //incomplete

void call_EXIT(peta *M, int TURN, long time_start, boolean game_over);

void do_recruit(player *P, POINT loc_new, peta *M);

void recruit(player *P, peta *M);

void do_command(int code, player *p, player *q, peta *M, int turn, long time_start, boolean game_over, Queue *Q);
/*I.S. : parameter terdefinisi
  F.S. : menjalankan command yang bersesuaian dengan code */

#endif