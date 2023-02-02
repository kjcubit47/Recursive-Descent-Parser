/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef PARSER
#define PARSER

#include "lexer.h"
#include "symbol.h"

struct parserData{
    int lookahead;
};

struct parserData parser;

bool match(int t);
void assignStmt();
void factor();
void parse();
void expression();
void term();

#endif // PARSER
