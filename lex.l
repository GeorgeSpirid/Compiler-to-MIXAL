%{
#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "syd.tab.h"

#define N  8
#define DEBUG 0

int id_or_keyword(char *s);

int currentline=1;
int currentcol=1;

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
                               return(GT);
			}
">="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(GE);
			}
"<"                         {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(LT);
			}
"<="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(LE);
			}
"=="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(EQ);
			}
"!="                        {
#if DEBUG
                               printf("%s\n",yytext);
#endif
                               strcpy(yylval.ystr,yytext);
                               return(NE);
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
                               printf("id or keyword-%s\n",yytext);
#endif
                               i=id_or_keyword(yytext);
                               if(i==ID) 
                                  strcpy(yylval.ystr,yytext);
                               else 
                                  yylval.yint=i;
                               return(i);
                            }
[0-9]+	    {
#if DEBUG
                               printf("number-%s\n",yytext);
#endif
				if(yytext[0]=='0' && strlen(yytext)>1){
					printf("%s number cannot start with zero",yytext);
					exit(1);
				}
                               yylval.yint=atoi(yytext);
                               return(NUM);
                            }

[ \f\r\t]+                {
#if DEBUG
								printf("%s\n",yytext); 
#endif
							}
"//".* 		  	    {
#if DEBUG
				printf("comment\n");	
#endif
			    }
.                           {
				currentcol++;
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
