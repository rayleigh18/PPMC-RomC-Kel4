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
    
    srand((unsigned int)time(0)); //Seeding for Random Number
    
    int  randomNumb = rand () % (pasanganTable->size+1);
    
    // (Untuk Debugging)
    //fprintf(out,"... %d ... ",a); 
    // fprintf(out,"|| ... %d ...",(pasanganTable->size+1));
    int found = 0;
    for (int i = randomNumb; i < SIZE_TABLE; i++){
        if (pasanganTable->list[i]!= NULL){
            strcpy(first , pasanganTable->list[i]->key);
            found = 1;
            break;
        }
    }

    for (int i=0; (i < randomNumb) && !found; i++){
        if (pasanganTable->list[i]!= NULL){
            strcpy(first , pasanganTable->list[i]->key);
            found = 1;
        }
    }

    char *temp = strtok(first," ");
    strcpy(queue[0],temp);
    fprintf(out,"%s ",temp);

    for (int i = 1; i < nGram-1; i++){
        temp = strtok(NULL," ");
        fprintf(out,"%s ",temp);
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
        }
}

/*
// fungsi nulis kata acak ke string di [hasil]
tulisKataAcak(char* hasil, int n) {
 int i, r;
 r = rand() % n +1;
 for(i = 0; i < MAX_PANJANG_KATA; i++) {
    *hasil = array_kata_referensi[r][i];
    hasil++;
    if (array_kata_referensi[r][i] == '\0') break;
 }
}

// fungsi buat ngopi string
copy(char* in, char* out){
    out = in;
}

// diasumsiin bentuk fungsi lookupnya gini, fungsinya ngeset valueOut jadi value dari key
lookup(table* t, char** key, char** valueOut);

// fungsi generator
generate(int nGram, int banyakKata, table* t, char** out) {
    kataTerakhir[banyakKata][MAX_PANJANG_KATA];
    int i, j, counter = 0;

    // isi kata awal dengan kata acak
    for (i = 0; i < nGram; i++) {
        tulisKataAcak(kataTerakhir[i], banyakKata);
        copy(kataTerakhir[i], out[i]);
        //menulis sebanyak i kata
        counter = i;
    }

    // loop generasi kata
    while (counter < banyakKata) {
    // ambil kata selanjutnya, disimpan ke hasil
        lookup(t, kataTerakhir, out[counter]);
        // geser array kataTerakhir
        for (j = 1; j < nGram; j++) {
            copy(kataTerakhir[j], kataTerakhir[j-1]);
            }
        copy(kataTerakhir[j], out[counter]);
        counter++;
    }
}

// fungsi untuk menggabungkan hasil
tempelinArray(char** in, int banyakKata, char* out) {
    int i, j;
    // loop penyatuan
    for (i = 0; i < banyakKata; i++) {
        if (in[i][0] == '\0')
            break;

        // kalo bukan yg pertama, tulis spasi dulu
        if (i != 0) {
            *out = ' ';
            out++;
        }

        // tulis kata
        for (j = 0; j < MAX_PANJANG_KATA; j++) {
            *out = in[i][j];
            out++;
            if (in[i][j] == '\0')
                break;
        }
    }
 // tutup string
 *out = '\0';
}*/

// // pengujian HAHA w sebenrnya bingung gimana cara ngujinya omo
// int main() {
//  char hasil[2000][MAX_PANJANG_KATA], hasilString[10000];

//  // awalan isi kalimat, trus tabel
//  generate(8, 2000, table, hasil);
//  tempelinArray(hasil, 2000, hasilString);
// }
