#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "peta.h"
#include "point.h"
#include "petak.h"
#include "player.h"
#include "unit.h"

int RNG(int x)
//menghasilkan Random Number dari 0 sampai x-1 dengan sebelumnya ada srand
{
    int r;

    r=rand()%x;

    return r;
}

int RNGbatas(int min, int maks)
//menghasilkan Random Number dari min sampai maks dengan sebelumnya ada srand
{
    int r;

    r=rand()%(maks-min+1)+min;

    return r;
}


void PasangDesa(int jumlah_village, peta *M)//MASIH FULL RANDOM, KLO MAU PK BATAS GANTI RNG DAN X Y NYA :)
{
    int i = 0;
    int x = NBrsEff(*M)+1;//indeks maks peta + 1 itu bnr ga?
    int y = NKolEff(*M)+1;//
    int A,B;

    srand(time(NULL));//Untuk seed rand()

    while (i<=jumlah_village)
    {
        A=RNG(x);B=RNG(y)
        POINT Random_location = MakePOINT(A,B);
        if (/*jenis_petak(p)==' ' ? tidak ada bangunan*/)//Tolong ini gmn
        {
            assign_petak(&(petak(*M,Absis(Random_location),Ordinat(Random_location))), 'V', 0, empty_unit(Random_location));
            i++;
        }

    }
}

