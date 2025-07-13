%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

#define N  10
#define DEBUG 0
int id_or_keyword(char *s);
%}

%%

"*"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('*');
			    }
"/"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('/');
			    }
"%"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('%');
			}
"+"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('+');
			}
"-"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('-');
			}
"="                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('=');
			}
">"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('>');
			}
">="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('>=');
			}
"<"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('<');
			}
"<="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('<=');
			}
"=="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('==');
			}
"<>"                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('<>');
			}
"("                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('(');
			}
")"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(')');
			}
"{"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('{');
			}
"}"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return('}');
			}
","                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(',');
			}
";"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(';');
			}
"true"			    {
#if DEBUG
				printf("%s\n",yytext);
#endif
				yylval.yint=1;
				return(TRUE);
			    }
"false"			    {
#if DEBUG
				printf("%s\n",yytext);
#endif
				yylval.yint=0;
				return(FALSE);
			    }
[a-zA-Z]([a-zA-Z0-9_])*   {  int i;
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               i=id_or_keyword(yytext);
                               if(i==ID) 
                                  strcpy(yylval.ystr,yytext);
                               else 
                                  yylval.yint=i;
                               return(i);
                            }
"-"?([1-9][0-9]*|0)	    {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(NUM);
                            }

[ \f\n\r\t]+                {
#if DEBUG
								printf("%s\n",yytext); 
#endif
							}
"//".* 		  	    {
				printf("comment\n");	
			    }
.                           {
                               printf("Illegal character %s\n",yytext);
                            }  
    

%%

static char *kid[N]={"return","break","true","false","else","if","int","while"};
static int kval[N]={RETURN,BREAK,TRUE,FALSE,ELSE,IF,INT,WHILE};

int id_or_keyword(char *s)
{  int i,k;

   for(i=0; (i < N) && (strcmp(s,kid[i]) != 0); i++);
   if(i < N)
      return kval[i];
   else
      return ID;
}
