/* EL2208 Praktikum Pemecahan Masalah dengan C
*Modul 8 - TUGAS BESAR
*Kelompok    : 7
*Hari/Tanggal: Wednesday/09-04-2020
*Asisten/NIM : Hamdani Fadhli / 13217058
*Nama File   : hashCode.h
*Deskripsi   : Implementasi hashCode.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashCode.h"

table *createTable(int size){
    table *t = (table*)malloc(sizeof(table));
    t->size = size;
    t->list = (node**)malloc(sizeof(node*)*size);

    int i;
    for(i = 0; i < size;i++){
        (t->list)[i] = NULL;
    }
    return t;
}

int hashCode(table *t, char* key){
    //sumber : https://cp-algorithms.com/string/string-hashing.html
    const int p = 91;
    int hash  = 0;
    for (int i = 0; i < strlen(key);i++){
        hash += (((int)key[i]) *(int) pow(p,i))%(t->size);
    }
    return hash%(t->size);
}

void addVal(string_tab *arrayOfString, char *val){
    for (int i = 0; i < arrayOfString->Neff; i++){
        if (strcmp(arrayOfString->array[i],val) == 0){
            return;
        }
    }
    arrayOfString->array = (char**)realloc(arrayOfString->array,((arrayOfString->Neff) + 1)*sizeof(char*));
    (arrayOfString->array)[arrayOfString->Neff] = (char*)malloc(20*sizeof(char));
    
    strcpy((arrayOfString->array)[arrayOfString->Neff],val);
    arrayOfString->Neff += 1;
}

// insert new elemen to table
void insert(table *t, char* key, char* value){
    int num = hashCode(t, key);
    node *list = (t->list)[num];
    node *temp = list;

    while(temp){
        if(strcmp(temp->key,key) == 0){
            
            addVal(temp->val,value);
            return;
        }
    }
    node *newNode = (node*)malloc(sizeof(node));
    newNode->key = (char*)malloc(sizeof(char)*20);
    strcpy((newNode->key), key);
    newNode->val = (string_tab*)malloc(sizeof(string_tab));
    (newNode->val)->array = (char**)malloc(sizeof(char*));
    
    newNode->val->array[0] = (char*)malloc(sizeof(char)*20);
    strcpy(newNode->val->array[0],value);
    newNode->val->Neff = 1;
    newNode->next = list;
    (t->list)[num] = newNode;
}

string_tab* lookupTable(table *t, char* key){
    int num = hashCode(t,key);
    node *list = (t->list)[num];
    node *temp = list;
    while(temp){
        if (strcmp(temp->key, key) == 0){
            return (temp->val);
        }
        temp = temp->next;
    }
    return NULL;
}

char* wrapWordToString(char **ret, int begin, int end){
    int len = 100;
    char *res = (char*)malloc(len*sizeof(char));
    res[0] = '\0';

    int i;
    if (begin <= end){
        strcat(res,ret[begin]);
    }
    for (i = begin + 1; i <= end; i++){
        if (strlen(res) + strlen(ret[i]) >= len-1){
            len = strlen(res) + strlen(ret[i]);
            res = (char*)realloc(res, (len+1)*sizeof(char));
        }
        strcat(res," ");
        strcat(res,ret[i]);
    }    
    return res;
}

void addKeyValToTable(table *t, char **ret, int size_ret){
    
    // for (i = 0; i < size_ret; i++){

    // }
}

int main(){
    int n;
    int i;
    scanf("%d",&n);
    char **temp;
    temp = (char**)malloc(n*sizeof(char*));
    for (i = 0; i < n; i++){
        temp[i] = (char*)malloc(20*sizeof(char));
    }
    for(i = 0; i < n; i++){
        scanf("%s", temp[i]);
    }
    for (i = 0; i < n-1; i++){
        printf("%s\n",wrapWordToString(temp,i,i+1));
    }
    return  0;
}