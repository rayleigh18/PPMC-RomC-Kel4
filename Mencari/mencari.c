/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok   : 4
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM)  : Hamdani Fadhli (13217058)
* Nama File   : mencari.c
* Deskripsi   : Implementasi Alokasi araay untuk memncari kata sesuai kata inputan random di awal, dan mencari valuenya  */

#ifndef MAX_HURUF
#define MAX_HURUF 50
#endif

#define SIZE_TABLE 10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../HashCode/hashCode.h"

void popQue(char ret[][50], int size){
    for (int i =0; i < size -1; i++){
        strcpy(ret[i],ret[i+1]);
    }
}

void process(table *pasanganTable, int nGram, FILE *out, int totalKata)
{
	// nGram-1 Kata Pertama
	char queue[nGram][MAX_HURUF];
    char first[10000];
    int  found = 0;

    srand((unsigned int)time(0)); //Seeding for Random Number
	
	fprintf(out, "... ");
	
    int  randomNumb = rand () % (pasanganTable->size+1);
   
    for (int i = randomNumb ; i< (SIZE_TABLE + randomNumb); i++){
            if ((i < SIZE_TABLE ) && (pasanganTable->list[i]!= NULL)){
                strcpy(first , pasanganTable->list[i]->key);
                fprintf (out, "%s ", pasanganTable->list[i]->key);
                found = 1;
                break;
                }
            else if ((i >= SIZE_TABLE && !found) && (pasanganTable->list[i - SIZE_TABLE]!= NULL)){
                strcpy(first , pasanganTable->list[ i - SIZE_TABLE ]->key);
                fprintf (out, "%s ", pasanganTable->list[i - SIZE_TABLE]->key);
                found = 1;
                break;                
            }
        }
    }

    char *temp = strtok(first," ");
    strcpy(queue[0],temp);
    //fprintf(out,"%s ",temp);

    for (int i = 1; i < nGram-1; i++){
        temp = strtok(NULL," ");
        // fprintf(out,"%s ",temp);
        strcpy(queue[i],temp);
    }
    
    // Print Kata di kalimat sebanyak Total Kata
    int countKata = nGram -1;
        while (countKata < totalKata){
            string_tab *val = lookupTable(pasanganTable,wrapWordToString(queue,0,nGram-2));
            if (val != NULL){
                popQue(queue,nGram - 1);
                //printf("%s",wrapWordToString(queue,0,nGram-3));
                int numRand = (val->Neff)*rand()/RAND_MAX;
                if (numRand == val->Neff){
                    numRand = (val->Neff) - 1;
                }
                strcpy(queue[nGram-2],val->array[numRand]);
                fprintf(out,"%s ",val->array[numRand]);
                countKata++;
            }
            else{
				int  randomNumb1 = rand () % (pasanganTable->size+1);
                char first[10000];
                for (int i = randomNumb1; i < SIZE_TABLE + randomNumb1; i++){
                    if (pasanganTable->list[abs(i%SIZE_TABLE)]!= NULL){
                        strcpy(first , pasanganTable->list[abs(i%SIZE_TABLE)]->key);
                        break;
                    }
                }
                char *temp = strtok(first," ");
                strcpy(queue[0],temp);
                fprintf(out,"%s ",temp);
                countKata++;

                for (int i = 1; i < nGram-1 && countKata < totalKata; i++){
                    temp = strtok(NULL," ");
                    fprintf(out,"%s ",temp);
                    strcpy(queue[i],temp);
                    countKata++;
                }
            }
        }
    fprintf(out, " ...");
}

