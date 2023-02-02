/***************************************************************
  Student Name: Kyle Cubit
  File Name: lexer.c
  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "lexer.h"
#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int initLexer(int argc, char* argv){
    if (argc < 2){
        printf("%2s", "No arguments given.\n");
        return 1;
    }
    lexer.lineNumber = 1;
    lexer.inputFile = fopen(argv, "r");
    return 0;

}

int lexan(){
    int type = -1;
    while(true){
        char ch[MAX_LENGTH];
        strncpy(ch, "", MAX_LENGTH);
        ch[0] = getc(lexer.inputFile);
        if (ch[0] == ' ' || ch[0] == '\t' ){
            continue;
        }
        if (ch[0] == '\n' ){
            lexer.lineNumber++;
            continue;
        }
        if(ch[0] == '~'){
            while(ch[0] != '\n'){
            ch[0] = getc(lexer.inputFile);
            }
            lexer.lineNumber++;
            continue;
        }
        if (isdigit(ch[0])){
            int i = 1;
            lexer.idLexeme[0] = ch[0];
            while((ch[i] = getc(lexer.inputFile)) != ' ' && ch[i] != '\n'){
                if (ch[i] == ';'){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                 if (ch[i] == ')'){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                 if (ch[i] == '('){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                lexer.idLexeme[i] = ch[i];
                i++;
            }

            lexer.idLexeme[i] = '\0';
            return NUM;
        }
        if (isalpha(ch[0])){
            int i = 1;
           
            lexer.idLexeme[0] = ch[0];
            while((ch[i] = getc(lexer.inputFile)) != ' ' && ch[i] != '\n'){
                
                if (ch[i] == ';'){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                if (ch[i] == '+'){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                  if (ch[i] == '('){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                if(ch[i] == ')'){
                    ungetc(ch[i], lexer.inputFile);
                    break;
                }
                if(ch[i] == '_' && ch[i-1] == '_'){
                    printf("%2s", "ERROR: Identifier cannot contain 2 consecutive underscores");
                    printf("%2c", '\n');
                    printf("%2s", "line ");
                    printf("%2d", lexer.lineNumber);
                    printf("%2s", ": ");
                    printf("%2s", ch);
                    printf("%2c", '\n');
                    exit(0);
                }
                lexer.idLexeme[i] = ch[i];
                i++;
            }
            if(lexer.idLexeme[i-1] == '_'){
                    printf("%2s", "ERROR: Identifier cannot end with an underscore");
                    printf("%2s", "\n");
                    printf("%2s", "line ");
                    printf("%2d", lexer.lineNumber);
                    printf("%2s", ": ");
                    printf("%2s", ch);
                    printf("%2c", '\n');
                    exit(0);
            }
            
            lexer.idLexeme[i] = '\0';
            
            type = lookUp(lexer.idLexeme);
            
            if(lexer.lineNumber == 1){
                    lexer.lineNumber++;
                    return type;
                }
            if (type == NOT_FOUND){
                insertValue(lexer.idLexeme);
                return ID;
            }
            return type; 
        }
        if (ch[0] == EOF){
            ungetc(ch[0], lexer.inputFile);
            fclose(lexer.inputFile);
            return EOF;
        }
                                                      
                                                            // printf("%2s", ch);
        return ch[0];
        
    }

 
}
