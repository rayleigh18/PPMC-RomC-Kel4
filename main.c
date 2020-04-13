/* EL2208 Praktikum Pemecahan Masalah dengan C
*Modul 8 - TUGAS BESAR
*Kelompok    : 
*Hari/Tanggal: Minggu/14-04-2020
*Asisten/NIM : Hamdani Fadhli / 13217058
*Nama File   : main.c
*Deskripsi   : Sebagai Main Program dan Penggabung Semua Fungsi-Fungsi yang ada
*/

#include <stdio.h>
#include <stdlib.h>

#include "HashCode/hashCode.h"
#include "Parser/parser.h"
#include "Mencari/mencari.h"

void menu();
#ifndef MAX_HURUF
#define MAX_HURUF 50
#endif

int main()
{
    // List Variabel
    table *pasanganTable = createTable(10000);
    static char ret[250000][MAX_HURUF];
    int size_ret;
    int nGram;
    
    
    //Implementasi Algoritma
    //Menu
    printf("Selamat datang dalam program nGram");
    
    //Penggunaan fungsi input file dan fungsi parser dari file "parser.h"
    FILE* stream = readFile();
    while(stream != NULL)
    {
	    parser(stream, ret, &size_ret);
        
        printf("Masukkan nilai nGram : ");
        scanf("%d",&nGram);
        while(nGram < 2) //Input checker untuk nGram < 2, karena dibawah 2 akan = kata random semua
        {
            printf("nGram harus diatas 2!");
            printf("Masukkan nilai nGram : ");
            scanf("%d",&nGram);
        }
        // adding to table
        addKeyValToTable(pasanganTable,ret,size_ret,nGram);
        
        
    }
    
    return 0;
}

/*
void menu()
{
    
    
}
*/
