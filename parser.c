/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 4
* Hari dan Tanggal : Rabu, 8 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : parser.c
* Deskripsi : Parsing kata dari file eksternal
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* readFile() {
    FILE* temp;
    char fileName[100];

    printf("File Name: ");
    gets(fileName);

    temp = fopen(fileName, "r");

    return temp;
}

void parser(FILE* stream, char ret[200000][50]) {
	int read;
	char *word = (char *)malloc(100 * sizeof(char));
	char help[50];
    int counter = 0;
    int index = 0;
    int wordcount;

	while(1){
		int j = 0;
		read = fgetc(stream);
        while(read != ' ' && read != '\n' && read != EOF){
            word[j] = read;
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
        if(counter == 300000){
        	break;
        }
	}
    //word counter

    //langsung print
    //printf ("jumlah kata: %d", counter+1);

    //simpan jumlah kata
    wordcount = counter + 1;
    printf ("julmah kata: %d", wordcount);
}

int main(){
	FILE* stream = readFile();
	char arr[200000][50];
    int i;
	parser(stream, arr);

/*  UNTUK PRINT TIAP KATA YANG DISIMPAN
	for(i = 0; i < 100000 && arr[i][0] != 0; i++){
		printf("%s\n", arr[i]);
	}
    printf("%d", i);*/
 
	return 0;
}