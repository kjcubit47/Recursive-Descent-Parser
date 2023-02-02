/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

void parse(){

    parser.lookahead = lexan();
    if(!match(BEGIN)){
        printf("%2s","syntax error\n");
        printf("%2s","line number:");
        printf("%2d", lexer.lineNumber);
        printf("%2s","\n");
        printf("%2s", "expected symbol : \"BEGIN\"\n");
        exit(0);
    }
    while(parser.lookahead != EOF){


        if(parser.lookahead == ID){
            assignStmt();
        }
        else{
             if(!match(END)){
                 printf("%2s","syntax error\n");
                printf("%2s","line number:");
                printf("%2d", lexer.lineNumber);
                printf("%2s","\n");
                printf("%2s", "expected symbol : \"END\"\n");
             }  
        }
    }
   printf("%2s", "Compilation Success ");
   printf("%2s", "\n");
   printf("%2s", "Lines compiled : ");
   printf("%2d", lexer.lineNumber);
   printf("%2c", '\n');

}

bool match(int t){
    if (parser.lookahead == t){
        parser.lookahead = lexan();
        return true;
    }
    return false;
}

void assignStmt(){

    match(ID);
    if (parser.lookahead != '='){

        printf("%2s","expected symbol: \"=\"\n");
        exit(0);
    }
    else{
        match(parser.lookahead);
        expression();
        match(';');
    }
}

void factor(){
    if (parser.lookahead == ID){
        match(ID);
    }
    else if (parser.lookahead == NUM){
        match(NUM);
    }
    else if (parser.lookahead == '('){
        if(!match('(')){
             printf("%2s","syntax error\n");
            printf("%2s","line number:");
            printf("%2d", lexer.lineNumber);
            printf("%2s","\n");
            printf("%2s", "expected ");
            printf("%2c", '"');
            printf("%2c", '(');
            printf("%2c", '"');
            printf("%2c", '\n');
        }
        expression();
        if(!match(')')){
            printf("%2s","syntax error\n");
            printf("%2s","line number:");
            printf("%2d", lexer.lineNumber);
            printf("%2s","\n");
            printf("%2s", "expected ");
            printf("%2c", '"');
            printf("%2c", ')');
            printf("%2c", '"');
            printf("%2c", '\n');
            exit(0); 
        } 
    }
    else{
        exit(0);
    }
}

void term(){
    factor();
    while(parser.lookahead == '*' || parser.lookahead == '/'){
        match(parser.lookahead);
        factor();
    }

}

void expression(){
    term();
    while(parser.lookahead == '+' || parser.lookahead == '-'){
        match(parser.lookahead);
        term();
    }

}

