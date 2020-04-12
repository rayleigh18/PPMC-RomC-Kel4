#include <stdio.h>
#include <stdlib.h>

#include "HashCode/hashCode.h"
#include "parser.h"
#include "mencari.h"

void menu();

int main()
{
    // List Variabel
    table *pasanganTable;
    static char arr[250000][50];
    int nGram;
    
    
    //Implementasi Algoritma
    //Menu
    printf("Selamat datang dalam program nGram");
    
    //Penggunaan fungsi input file dan fungsi parser dari file "parser.h"
    FILE* stream = readFile();
    while(stream != NULL)
    {
	    parser(stream, arr);
        
        printf("Masukkan nilai nGram : ");
        scanf("%d",&nGram);
        while(nGram < 2) //Input checker untuk nGram < 2, karena dibawah 2 akan = kata random semua
        {
            printf("nGram harus diatas 2!");
            printf("Masukkan nilai nGram : ");
            scanf("%d",&nGram);
        }
        
        
        
    }
    
    return 0;
}

/*
void menu()
{
    
    
}
*/
