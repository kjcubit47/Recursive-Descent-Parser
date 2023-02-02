/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "symbol.h"

int main(int argc, char *argv[])
{
    initLexer(argc, argv[1]);
    initSymbolTable();
    printf("\nCompiling %s\n", argv[1]);
    parse();

    return 0;
}