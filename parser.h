/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 4
* Hari dan Tanggal : Rabu, 8 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : parser.h
* Deskripsi : Parsing kata dari file eksternal
*/

#include <stdio.h>
#include "parser.c"

FILE* readFile();
void parser(FILE* stream, char ret[100000][15]);