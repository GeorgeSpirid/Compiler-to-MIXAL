%{
#include <stdio.h>
#include <string.h>
#include "defs.h"

#define N  10
int id_or_keyword(char *s);
%}

%%

"*"                         {
                               printf("%s",yytext);
                            }
"/"                         {
                               printf("%s",yytext);
                            }
"%"                         {
                               printf("%s",yytext);
                            }
"+"                         {
                               printf("%s",yytext);
                            }
"-"                         {
                               printf("%s",yytext);
                            }
"="                         {
                               printf("%s",yytext);
                            }
">"                         {
                               printf("%s",yytext);
                            }
">="                        {
                               printf("%s",yytext);
                            }
"<"                         {
                               printf("%s",yytext);
                            }
"<="                        {
                               printf("%s",yytext);
                            }
"=="                        {
                               printf("%s",yytext);
                            }
"<>"                        {
                               printf("%s",yytext);
                            }
"("                         {
                               printf("%s",yytext);
                            }
")"                         {
                               printf("%s",yytext);
                            }
"{"                         {
                               printf("%s",yytext);
                            }
"}"                         {
                               printf("%s",yytext);
                            }
","                         {
                               printf("%s",yytext);
                            }
";"                         {
                               printf("%s",yytext);
                            }
"true"			    {
				printf("%s - 1",yytext);
			    }
"false"			    {
				printf("%s - 0",yytext);
			    }
[a-zA-Z]([a-zA-Z0-9_])*   {  int i = id_or_keyword(yytext);
    switch (i) {
        case RETURN: printf("KEYWORD: return\n"); break;
        case BREAK:  printf("KEYWORD: break\n");  break;
        case ELSE:   printf("KEYWORD: else\n");   break;
        case IF:     printf("KEYWORD: if\n");     break;
        case INT:    printf("KEYWORD: int\n");    break;
        case WHILE:  printf("KEYWORD: while\n");  break;
        case TRUE:   printf("KEYWORD: true\n");   break;
        case FALSE:  printf("KEYWORD: false\n");  break;
        case NUM:    printf("KEYWORD: num\n");    break;
        case ID:     printf("ID: %s\n", yytext);  break;
        default:     printf("UNKNOWN TOKEN: %s\n", yytext); break;
    }
                            }
"-"?([1-9][0-9]*|0)	    {
				printf("num - %s",yytext); 
			    }
[ \f\n\r\t]+                printf("%s",yytext); 
"//".* 		  	    {
				printf("comment");	
			    }
.                           {
                               printf("Illegal character %s\n",yytext);
                            }  
    

%%

static char *kid[N]={"id","num","return","break","true","false","else","if","int","while"};
static int kval[N]={ID,NUM,RETURN,BREAK,TRUE,FALSE,ELSE,IF,INT,WHILE};

int id_or_keyword(char *s)
{  int i,k;

   for(i=0; (i < N) && (strcmp(s,kid[i]) != 0); i++);
   if(i < N)
      return kval[i];
   else
      return ID;
}

int main(void)
{
   yylex();
   return 0;
}
