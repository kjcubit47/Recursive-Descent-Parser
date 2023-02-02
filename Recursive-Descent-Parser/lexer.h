/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50

struct lexer
{
    FILE *inputFile;
    int lineNumber;
    char idLexeme[MAX_LENGTH];
};

struct lexer lexer;

int initLexer(int argc, char *argv);

int lexan();

#endif // LEXER
