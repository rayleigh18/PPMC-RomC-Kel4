/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok          : 4
* Hari dan Tanggal  : Rabu, 15 April 2020
* Asisten (NIM)     : Hamdani Fadhli (13217058)
* Nama File         : mencari.c
* Deskripsi         : IMplementais Alokasi araay untuk memncari kata sesuai kata inputan random di awal, dan mencari valuenya  */

#ifndef MAX_PANJANG_KATA
#define MAX_PANJANG_KATA 100
#endif
#include <stdio.h>
#include <string.h>
#include "mencari.h"
#include "HashCode/hashCode.h"

// fungsi nulis kata acak ke string di [hasil]
tulisKataAcak(char* hasil, int n, char array_kata_referensi[r][i]) {
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
lookup(table* t, char** key, char** valueOut){
string_tab* res = lookupTable(t, *key);
valueOut = res->array;
}

// fungsi generator
generate(int nGram, int banyakKata, table* t, char** out, char array_kata_referensi[r][i]) {
    char kataSelanjytnya[MAX_PANJANG_KATA], kataTerakhir[banyakKata][MAX_PANJANG_KATA];
    int i, j, counter = 0;

    // isi kata awal dengan kata acak
    for (i = 0; i < nGram; i++) {
        tulisKataAcak(kataTerakhir[i], banyakKata, array_kata_referensi[r][i]);
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
}
