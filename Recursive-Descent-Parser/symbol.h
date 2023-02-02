/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef SYMBOL_H
#define SYMBOL_H

#define STRING_MAX 50
#define MAX_SYMBOLS 20
#define NOT_FOUND -1
#define ID 300
#define NUM 301
#define BEGIN 400
#define END 401


struct symbol{
    char name[STRING_MAX];
    int type;
};

struct symbolTable{
    struct symbol table[MAX_SYMBOLS];
    int numSymbols;
};

struct symbolTable mainTable;

void initSymbolTable();

int lookUp(char val[]);

void insertValue(char val[]);

void printTable();


#endif // SYMBOL_H
