/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 4
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : parser.c
* Deskripsi : Parsing kata dari file eksternal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

FILE* readFile() {
    FILE* temp;
    char fileName[100];
	
	//Input File Name
    printf("Input File Name                     : ");
    gets(fileName);

    temp = fopen(fileName, "r");
    // Check File dengan nama file tersebut, apakah ada atau tidak
    while (temp == NULL){
        if (strcmp(fileName, "exit") == 0){ // Keluar program apabila inputan file = "exit"
            printf("You've already left this program!");
            exit(1);
        }
        printf("This file doesn't exist, try again! \nInput File Name                     : ");
        gets(fileName);

        temp = fopen(fileName, "r");
    }


    return temp;
}

void parser(FILE* stream, char ret[250000][50], int *total_word) {
	int read;
	char *word = (char *)malloc(100 * sizeof(char));
	char help[50];
	int index = 0;
	int counter = 0;
    int wordcount;
	while(1){
		int j = 0;
		read = fgetc(stream);
        while(read != ' ' && read != '\t' && read != '\n' && read != EOF){
//cek apakah ascii
//referensi:
//https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_71/rtref/isascii.htm
            if (isascii(read)){
            word[j] = read;                
            }
            else{
//membaca petik dua non ascii pada teks ->membaca selain ascii
            word[j] = '\"' ;            
            read = fgetc(stream);
            read = fgetc(stream);
            
            }
            j++;
            read = fgetc(stream);
        }

        if(j == 0 && read != EOF){
        	continue;
        }

        for(int z = 0; z < j; z++){
            help[z] = word[z];
        }

        help[j] = '\0';
        for(int i = 0; i <= j; i++){
        	ret[index][i] = help[i];
        }
        index++;

        if(read == EOF){
            break;
        }
        counter++;
        if(counter == 250000){
        	break;
        }
	}
    //word counter

    //langsung print
    //printf ("jumlah kata: %d", counter+1);

    //simpan jumlah kata
    wordcount = counter + 1;
    *total_word = wordcount;
    //printf ("julmah kata: %d", wordcount);
}

// int main(){
// 	FILE* stream = readFile();
// //menggunakan static storage untuk penyimpanan kata yang lebih banyak untuk teks yang panjang
// //referensi
// //https://www.geeksforgeeks.org/storage-classes-in-c/
// //https://www.researchgate.net/post/What_is_the_maximum_size_of_an_array_in_C
// 	static char arr[250000][50];
// 	parser(stream, arr);
// /*  UNTUK PRINT TIAP KATA YANG DISIMPAN (debugging)
// 	for(int i = 0; i < 250000 && arr[i][0] != 0; i++){
// 		printf("%s\n", arr[i]);
// 	}*/
// 	return 0;
// }
