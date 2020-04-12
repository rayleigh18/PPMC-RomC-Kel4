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
        if(counter == 250000){
        	break;
        }
	}

}

int main(){
	FILE* stream = readFile();
	static char arr[250000][50];
	parser(stream, arr);
	for(int i = 0; i < 250000 && arr[i][0] != 0; i++){
		printf("%s\n", arr[i]);
	}
	return 0;
}