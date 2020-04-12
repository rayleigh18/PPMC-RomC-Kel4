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

void parser(FILE* stream, char ret[250000][50]) {
	int read;
	char *word = (char *)malloc(100 * sizeof(char));
	char help[50];
	int index = 0;
	int counter = 0;
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
        if(counter == 250000){
        	break;
        }
	}
}

int main(){
	FILE* stream = readFile();
	//Menggunakan static storage untuk menambahkan muatan array (agar dapat menampung teks dengan jumlah kata yang banyak
	//referensi
	//https://www.researchgate.net/post/What_is_the_maximum_size_of_an_array_in_C
	//https://www.geeksforgeeks.org/storage-classes-in-c/
	static char arr[250000][50];
	parser(stream, arr);
	for(int i = 0; i < 250000 && arr[i][0] != 0; i++){
		printf("%s\n", arr[i]);
	}
	return 0;
}
