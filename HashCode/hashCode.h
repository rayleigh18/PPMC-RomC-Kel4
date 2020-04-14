/* EL2208 Praktikum Pemecahan Masalah dengan C
*Modul 8 - TUGAS BESAR
*Kelompok    : 
*Hari/Tanggal: Wednesday/09-04-2020
*Asisten/NIM : Hamdani Fadhli / 13217058
*Nama File   : hashCode.h
*Deskripsi   : Membuat pasangan key value dengan menggunakan konsep Hashing
*/
#ifndef HASHCODE_H
#define HASHCODE_H

#ifndef MAX_HURUF
#define MAX_HURUF 50
#endif

#ifndef MAX_WRAP_WORD
#define MAX_WRAP_WORD 10000
#endif

/*
    string_tab adalah tab untuk array of string
    untuk mendapatkan string ke [i] 
    list[i]
*/
typedef struct string_tab{
    char **array;
    int Neff;
}string_tab;

typedef struct node{
    char* key;
    string_tab *val;
    struct node *next;
}node;

typedef struct table{
    int size;
    node **list;
}table;

table *createTable(int size);

int hashCode(table *t, char* key);

void insert(table *t, char* key, char* value);
/*
/ Menambahkan hasil parsing ke dalam table
/ Buat ngeliat, format keluaran 
/ OUTPUT : alamat dari string_tab
*/
string_tab* lookupTable(table *t, char* key);

/*
/ Menambahkan hasil parsing ke dalam table
/ Pemanggilan fungsi ini setelah parsing, dengan masukan ret adalah array string
/ 
*/
void addKeyValToTable(table *t, char ret[][50], int size_ret, int nGram);

/*
/ Menggabung kata-kata dengan array char
/
*/
char* wrapWordToString(char ret[][50], int begin, int end);


#endif