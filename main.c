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

void Menu();

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
    
    
    //Implementasi Algoritma
    //Menu
    printf("WELCOME!\n");
    printf("This is Batch C/ Group 4's nGram Program\n\n\n");
    printf("Rules :\n");
    printf("1. To left this program, type 'exit' on File Name \n");
    printf("2. To input another file, type 0 on total word(s) \n");
    printf("3. This Program works for 0 < nGram < Total Word(s) \n\n");
    
    //Penggunaan fungsi input file dan fungsi parser dari file "parser.h"
    FILE* stream = readFile();
    while(stream != NULL){
        int totalKata;
	    parser(stream, ret, &size_ret);
        
        //Input nGram
        printf("Input nGram value : ");
        scanf("%d",&nGram);
        while(nGram < 2) //Input checker untuk nGram < 2, karena dibawah 2 akan = kata random semua
        {
            printf("nGram must be greater than 2!");
            printf("Input nGram value                   : ");
            scanf("%d",&nGram);
        }
        
        //Input totalKata
        printf("Input Total Word(s)                 :");
        scanf("%d",&totalKata);
        
        //Untuk keluar dari Total Kata, totalkata = 0
        while (totalKata != 0){
			//Checker apabila Total Kata < nGram
			while(totalKata < nGram){
				if (totalKata < 0){ //Checker apabila Total Kata < 0
					printf("Total word(s) can't be negative!!\n");
					printf("Input another Total Word(s)         : ");
					scanf("%d",&totalKata);
					
				}
				else{
					printf("Total Word(s) can't be smaller than nGram!\n");
					printf("Input another Total Word(s)         : ");
					scanf("%d",&totalKata);
				}
			}
			
            // adding to table
            addKeyValToTable(pasanganTable,ret,size_ret,nGram);
            
            //File output hasil program
            FILE *out;
            out = fopen("out.txt","w");
            
            // Fungsi Process dari file mencari.h untuk menuliskan hasil output pada file out.txt
            process(pasanganTable, nGram, out, totalKata);

            fclose(out);
			
			//Input kembali total kata baru
            printf("Masukkan Total New Word(s)          : ");
            scanf("%d",&totalKata);
        }
        
        scanf("%c");
        fclose(stream);
        stream = readFile();
    }
    
    return 0;
}
