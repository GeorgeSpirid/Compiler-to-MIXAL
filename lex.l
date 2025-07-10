%{
#include <stdio.h>
%}

%%

[0-9]+                      {
                               printf("%s\n",yytext);
                            }
"+"                         {
                               printf("%s\n",yytext);
                            }
[ \f\n\r\t]+                printf("%s",yytext); 
.                           {
                               printf("Wrong character %s\n",yytext);
                            }    

%%

int main(void)
{
   yylex();
}
