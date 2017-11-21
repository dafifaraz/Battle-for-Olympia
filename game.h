#ifndef GAME_H
#define GAME_H

#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "petak.h"
#include "player.h"
#include "peta.h"
#include "kata.h"

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

void do_command(int code, player *p, int turn, long time_start, boolean game_over);
/*I.S. : parameter terdefinisi
  F.S. : menjalankan command yang bersesuaian dengan code */

#endif