/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "symbol.h"
#include <stdio.h>
#include <string.h>

void initSymbolTable()
{
    strncpy(mainTable.table[0].name, "BEGIN", STRING_MAX);
    mainTable.table[0].type = 400;

    strncpy(mainTable.table[1].name, "END.", STRING_MAX);
    mainTable.table[1].type = 401;

    mainTable.numSymbols = 2;
}

int lookUp(char name[]){
    for(int i = 0; i <= mainTable.numSymbols; i++){
        if(!strcasecmp(name, mainTable.table[i].name)){

            return mainTable.table[i].type;
        }


    }
    return NOT_FOUND;
}


void insertValue(char val[]){
    strncpy(mainTable.table[mainTable.numSymbols].name, val, STRING_MAX);
    mainTable.table[mainTable.numSymbols].type = ID;
    mainTable.numSymbols++;
}

void printTable(){
    printf("%2s", "VALUE : TYPE");
    printf("%2s", "\n");
    for (int i = 0; i < mainTable.numSymbols; i++){
        printf("%2s", mainTable.table[i].name);
        printf("%2s", " : ");
        printf("%2d", mainTable.table[i].type);
        printf("%2s", "\n");
    }
}