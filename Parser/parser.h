#ifndef PARSER_H
#define PARSER_H

FILE* readFile();

void parser(FILE* stream, char ret[250000][50], int *size_ret);

#endif