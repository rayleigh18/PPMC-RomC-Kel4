/* EL2208 Praktikum Pemecahan Masalah dengan C
*Modul 8 - TUGAS BESAR
*Kelompok    : 
*Hari/Tanggal: Rabu/15-04-2020
*Asisten/NIM : Hamdani Fadhli / 13217058
*Nama File   : main.c
*Deskripsi   : Sebagai Main Program dan Penggabung Semua Fungsi-Fungsi yang ada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashCode/hashCode.h"
#include "Parser/parser.h"
#include "Mencari/mencari.h"

#ifndef MAX_HURUF
#define MAX_HURUF 50
#endif
#ifndef SIZE_TABLE
#define SIZE_TABLE 10000
#endif

int main()
{
    // List Variabel
    table *pasanganTable = createTable(SIZE_TABLE);
    static char ret[250000][MAX_HURUF];
    // char **ret;
    // ret = (char**)malloc(250000*sizeof(char*));
    // for (int i = 0; i < 250000; i++){
    //     ret = (char*)malloc(MAX_HURUF*sizeof(char));
    // }
    int size_ret;
    int nGram;

    FILE *out;
    out = fopen("out.txt","w");
    
    
    //Implementasi Algoritma
    //Menu
    printf("Selamat datang dalam program nGram\n");
    
    //Penggunaan fungsi input file dan fungsi parser dari file "parser.h"
    FILE* stream = readFile();
    while(stream != NULL)
    {
        int totalKata;
	    parser(stream, ret, &size_ret);
        
        printf("Masukkan nilai nGram : ");
        scanf("%d",&nGram);
        while(nGram < 2) //Input checker untuk nGram < 2, karena dibawah 2 akan = kata random semua
        {
            if (nGram == -1){
                exit(1);
            }
            printf("nGram harus diatas 2!");
            printf("Masukkan nilai nGram : ");
            scanf("%d",&nGram);
        }
        printf("Masukkan total kata : ");
        scanf("%d",&totalKata);
        
        // adding to table
        addKeyValToTable(pasanganTable,ret,size_ret,nGram);
        
        // Input nGram kata pertama pada file text
		process(pasanganTable, nGram, out, totalKata);
        /*char queue[nGram][MAX_HURUF];
        char first[10000];
        for (int i = 0; i < SIZE_TABLE; i++){
            if (pasanganTable->list[i]!= NULL){
                strcpy(first , pasanganTable->list[i]->key);
            }
        }
        
        char *temp = strtok(first," ");
        strcpy(queue[0],temp);
        fprintf(out,"%s ",temp);

        for (int i = 1; i < nGram-1; i++){
            temp = strtok(NULL," ");
            fprintf(out,"%s ",temp);
            strcpy(queue[i],temp);
        }*/
		/*
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
                char first[10000];
                for (int i = 0; i < SIZE_TABLE; i++){
                    if (pasanganTable->list[i]!= NULL){
                        strcpy(first , pasanganTable->list[i]->key);
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
        }  */      
    }
    
    return 0;
}
