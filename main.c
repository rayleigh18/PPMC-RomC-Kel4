/* EL2208 Praktikum Pemecahan Masalah dengan C
*Modul 8 - TUGAS BESAR
*Kelompok    : 
*Hari/Tanggal: Jumat / 17 April 2020
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

void menu();

int main()
{
    // List Variabel
    table *pasanganTable = createTable(SIZE_TABLE);
    static char ret[250000][MAX_HURUF];

    int size_ret;
    int nGram;
    int totalKata;
    
    FILE *stream;
    FILE *out;
    
    
    //Implementasi Algoritma
    //Menu dan deskripsi program
    printf("WELCOME!\n");
    printf("This is Batch C/ Group 4's nGram Program\n");
    printf("This program will help you make random sentence, you need to input file Name, number of nGram, and number of sentence. The Random Senteces will be saved in 'out.txt'\n\n");
    printf("Rules :\n");
    printf("1. Input File Name to program with extension Text File (.txt) \n2. To left this program, type 'exit' on File Name \n");
    printf("3. To input another file, type 0 on total word(s) \n");
    printf("4. This Program works for 0 < nGram < Total Word(s) \n\n");
    //Menu
    menu();
    
    //Penggunaan fungsi input file dan fungsi parser dari file "parser.h"
    stream = readFile();
    while(stream != NULL){  
	    parser(stream, ret, &size_ret);
        
        //Input nGram
        printf("Input nGram value                   : ");
        scanf("%d",&nGram);
        while(nGram < 2) //Input checker untuk nGram < 2, karena dibawah 2 akan = kata random semua
        {
            printf("nGram must be greater than 2!\n");
            printf("Input nGram value                   : ");
            scanf("%d",&nGram);
        }
        
        //Input totalKata
        printf("Input Total Word(s)                 : ");
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
            
            //Open File Output : out.txt for writing results
            out = fopen("out.txt","w");
            
            // Fungsi Process dari file mencari.h untuk menuliskan hasil output pada file out.txt
            process(pasanganTable, nGram, out, totalKata);
            fclose(out);
			
			//Input kembali total kata baru
            printf("Input another Total Word(s)         : ");
            scanf("%d",&totalKata);
        }
        
        scanf("%c");
        fclose(stream);
        stream = readFile();
    }
    
    return 0;
}

void menu(){
	printf("WELCOME!\n");
    printf("This is Batch C/ Group 4's nGram Program\n\n");
    printf("Rules :\n");
    printf("1. Input File Name to program with extension Text File (.txt) \n");
    printf("2. To left this program, type 'exit' on File Name \n");
    printf("3. To input another file, type 0 on total word(s) \n");
    printf("4. This Program works for 0 < nGram < Total Word(s) \n\n");
}
