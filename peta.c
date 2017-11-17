#include "peta.h"
#include "point.h"
#include "petak.h"
#include "player.h"
#include "unit.h"
#include <time.h>
#include <math.h>

void empty_peta(peta *M, int NB, int NK, player *p1, player *p2){
//Terbentuk peta yang kosong yang diisi oleh 2 player yang kosong
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
	for (int i=0; i<NB; i++){
		for (int j=0; j<NK; j++){
			petak(*M,i,j) = empty_petak(MakePOINT(i,j));
		}
	}
	init_player(p1,'R','1'); //'R' = red, '1' = P1
	init_player(p2,'B','2'); //'B' = blue, '2' = P2
}

void bangun_kerajaan(peta *M, player *p1, player *p2){
//Terbentuk kondisi awal permainan, peta dibangun kerajaan, unit yang ada disimpan ke listunit player
//p1 dan p2 merupakan player kosong
	POINT lokasi_p1 = MakePOINT(NBrsEff(*M) - 2, 1);
	POINT lokasi_p2 = MakePOINT(1, NKolEff(*M) - 2);

	unit king_p1 = unit_petak(petak(*M,Absis(lokasi_p1),Ordinat(lokasi_p1)));
	unit king_p2 = unit_petak(petak(*M,Absis(lokasi_p2),Ordinat(lokasi_p2)));
	
	assign_unit(&king_p1, 'K', 1);					//unit yang ada di tower p1 diisi properti king
	InsVFirst_listunit(&list_unit(*p1),king_p1);	//king p1 ditambahkan ke dalam list_unit p1
	
	assign_unit(&king_p2, 'K', 2);
	InsVFirst_listunit(&list_unit(*p2),king_p2);	
	
	assign_petak(&(petak(*M,Absis(lokasi_p1),Ordinat(lokasi_p1))), 'T', 1, king_p1);
	petak_khusus(*p1,0) = petak(*M,Absis(lokasi_p1),Ordinat(lokasi_p1));
	
	assign_petak(&(petak(*M,Absis(lokasi_p2),Ordinat(lokasi_p2))), 'T', 2, king_p2);
	petak_khusus(*p2,0) = petak(*M,Absis(lokasi_p2),Ordinat(lokasi_p2));	
	
	POINT lokasi_CL_P1 = MakePOINT(Absis(lokasi_p1),Ordinat(lokasi_p1) - 1);
	POINT lokasi_CU_P1 = MakePOINT(Absis(lokasi_p1) - 1,Ordinat(lokasi_p1));
	POINT lokasi_CR_P1 = MakePOINT(Absis(lokasi_p1),Ordinat(lokasi_p1) + 1);
	POINT lokasi_CD_P1 = MakePOINT(Absis(lokasi_p1) + 1,Ordinat(lokasi_p1));
	
	POINT lokasi_CL_P2 = MakePOINT(Absis(lokasi_p2),Ordinat(lokasi_p2) - 1);
	POINT lokasi_CU_P2 = MakePOINT(Absis(lokasi_p2) - 1,Ordinat(lokasi_p2));
	POINT lokasi_CR_P2 = MakePOINT(Absis(lokasi_p2),Ordinat(lokasi_p2) + 1);
	POINT lokasi_CD_P2 = MakePOINT(Absis(lokasi_p2) + 1,Ordinat(lokasi_p2));
	
	assign_petak(&(petak(*M,Absis(lokasi_CL_P1),Ordinat(lokasi_CL_P1))), 'C', 1, empty_unit(lokasi_CL_P1));		
	petak_khusus(*p1,1) = petak(*M,Absis(lokasi_CL_P1),Ordinat(lokasi_CL_P1));
	
	assign_petak(&(petak(*M,Absis(lokasi_CU_P1),Ordinat(lokasi_CU_P1))), 'C', 1, empty_unit(lokasi_CU_P1));
	petak_khusus(*p1,2) = petak(*M,Absis(lokasi_CU_P1),Ordinat(lokasi_CU_P1));
	
	assign_petak(&(petak(*M,Absis(lokasi_CR_P1),Ordinat(lokasi_CR_P1))), 'C', 1, empty_unit(lokasi_CR_P1));
	petak_khusus(*p1,3) = petak(*M,Absis(lokasi_CR_P1),Ordinat(lokasi_CR_P1));
	
	assign_petak(&(petak(*M,Absis(lokasi_CD_P1),Ordinat(lokasi_CD_P1))), 'C', 1, empty_unit(lokasi_CD_P1));
	petak_khusus(*p1,4) = petak(*M,Absis(lokasi_CD_P1),Ordinat(lokasi_CD_P1));
	
	assign_petak(&(petak(*M,Absis(lokasi_CL_P2),Ordinat(lokasi_CL_P2))), 'C', 1, empty_unit(lokasi_CL_P2));
	petak_khusus(*p2,1) = petak(*M,Absis(lokasi_CL_P2),Ordinat(lokasi_CL_P2));
	
	assign_petak(&(petak(*M,Absis(lokasi_CU_P2),Ordinat(lokasi_CU_P2))), 'C', 1, empty_unit(lokasi_CU_P2));
	petak_khusus(*p2,2) = petak(*M,Absis(lokasi_CU_P2),Ordinat(lokasi_CU_P2));
	
	assign_petak(&(petak(*M,Absis(lokasi_CR_P2),Ordinat(lokasi_CR_P2))), 'C', 1, empty_unit(lokasi_CR_P2));
	petak_khusus(*p2,3) = petak(*M,Absis(lokasi_CR_P2),Ordinat(lokasi_CR_P2));
	
	assign_petak(&(petak(*M,Absis(lokasi_CD_P2),Ordinat(lokasi_CD_P2))), 'C', 1, empty_unit(lokasi_CD_P2));
	petak_khusus(*p2,4) = petak(*M,Absis(lokasi_CD_P2),Ordinat(lokasi_CD_P2));
}

void init_peta(peta *M, int NBrsEff, int NKolEff){
	empty_peta(M, NBrsEff, NKolEff);
	bangun_kerajaan(M);
	PasangDesa(NBrsEff*NKolEff/20, M);
}

void display_peta(peta M){
	printf("\n");
	for (int i=0; i<NBrsEff(M); i++){
		for (int j=0; j<4*NKolEff(M)+1; j++){
			printf("*");
		}
		for (int j=0; j<4; j++){
			for (int k=0; k<NKolEff(M); k++){
				for (int l=0; l<4; l++){
					if (j!=0){
						if (l == 0){
							printf("*");
						} else if (l == 2){
							if (j == 0){
								printf("");
							} else if (j==1){
								if (isequal_petak(petak(M,i,k),empty_petak(MakePOINT(i,k)))){
									printf(" ");
								} else {
									printf("%c",jenis_petak(petak(M,i,k)));
								}
							} else if (j==2){
								if (isequal_unit(unit_petak(petak(M,i,k)),empty_unit(MakePOINT(i,k)))){
									printf(" ");
								} else {
									printf("%c",simbol(unit_petak(petak(M,i,k))));
								}
							} else {
								printf(" ");
							}
						} else {
							printf(" ");
						}
					}
				}	
				if (k == NKolEff(M) - 1 && j!=0){
					printf("*");
				}
			}
			printf("\n");
		}
	}
	for (int i=0; i<4*NKolEff(M)+1; i++) printf("*");
	printf("\n");
}

int RNGbatas(int min, int maks){
//menghasilkan Random Number dari min sampai maks dengan sebelumnya ada srand
    int r;

    r=rand()%(maks-min+1)+min;

    return r;
}

void PasangDesa(int jumlah_village, peta *M){
//MASIH FULL RANDOM, KLO MAU PK BATAS GANTI RNG DAN X Y NYA :) //done, mantap '-'b
//Sudah diedit, random buat setengah peta, dan random buat setengahnya lagi
    int i = 0;
    int x = NBrsEff(*M)-1;
    int y = NKolEff(*M)-1;
    int A,B;

    srand(time(NULL));//Untuk seed rand()

    while (i<=jumlah_village)
    {   
        if (i <= jumlah_village/2){
            //Random untuk bagian kiri peta
            A=RNGbatas(0,x/2);
            B=RNGbatas(0,y/2);
        }
        else {
            //Random untuk bagian kanan peta
            A=RNGbatas(x/2 + 1, x);
            B=RNGbatas(y/2 + 1, y);
        }
        //random location, jika petak kosong, tanam village
        POINT Random_location = MakePOINT(A,B);
        if (isequal_petak(petak(*M,Absis(Random_location),Ordinat(Random_location)),empty_petak(Random_location)))
        {
            assign_petak(&(petak(*M,Absis(Random_location),Ordinat(Random_location))), 'V', 0, empty_unit(Random_location));
            i++;
        }
    }
}

int manhattan_dist(POINT x1, POINT x2){
	return abs(Absis(x1) - Absis(x2)) + abs(Ordinat(x1) - Ordinat(x2));
}

void MOVE(player P, peta *M){
	POINT loc = P.selected.lokasi;
	unit slc = unit_petak(petak(*M,Absis(loc), Ordinat(loc))); //unit yang sedang dipilih

	add_unit address_slc_in_list = Search_listunit(list_unit(P),slc); //search unit slc di listunit player p;

	//Tampilkan Peta dan koordinat petak yang dapat dijangkau
	printf("\n");
	for (int i=0; i<NBrsEff(*M); i++){
		for (int j=0; j<4*NKolEff(*M)+1; j++){
			printf("*");
		}
		for (int j=0; j<4; j++){
			for (int k=0; k<NKolEff(*M); k++){
				for (int l=0; l<4; l++){
					if (j!=0){
						if (l == 0){
							printf("*");
						} else if (l == 2){
							if (j == 0){
								printf("");
							} else if (j==1){
								if (isequal_petak(petak(*M,i,k),empty_petak(MakePOINT(i,k)))){
									printf(" ");
								} else {
									printf("%c",jenis_petak(petak(*M,i,k)));
								}
							} else if (j==2){

								//BELUM DICEK KALAU ADA UNIT PLAYER LAIN DIANTARANYA
								if (isequal_unit(unit_petak(petak(*M,i,k)),empty_unit(MakePOINT(i,k))) && (manhattan_dist(MakePOINT(i,k), loc) <= max_move_point(slc))){
									printf("#");
								} 
								else if (isequal_unit(unit_petak(petak(*M,i,k)),empty_unit(MakePOINT(i,k)))){
									printf(" ");
								}
								else {
									printf("%c",simbol(unit_petak(petak(*M,i,k))));
								}
							} else {
								printf(" ");
							}
						} else {
							printf(" ");
						}
					}
				}	
				if (k == NKolEff(*M) - 1 && j!=0){
					printf("*");
				}
			}
			printf("\n");
		}
	}
	for (int i=0; i<4*NKolEff(*M)+1; i++) printf("*");
	printf("\n");

	do{
		printf(">> Please enter cell's coordinate x y : \n");
		printf("<< \n");
		int x,y; 
		scanf("%d %d",&x,&y);
		//invalid jika jarak lebih dari max_move_point atau ada unit lain disana 
		//BALUM DICEK KALAU ADA UNIT PLAYER LAIN DIANTARANYA
		if (manhattan_dist(MakePOINT(x,y),loc) > max_move_point(slc) || !isequal_unit(unit_petak(petak(*M,x,y)),empty_petak(MakePOINT(x,y)))) {
			printf(">> Sorry. You can't move there\n");
		} else {
			unit_petak(petak(*M,x,y)) = 
			printf(">> Your selected unit has been moved to (%d,%d)\n",x,y);
		}
	} while (manhattan_dist(MakePOINT(x,y),loc) > max_move_point(slc));
}