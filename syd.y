%{
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void yyerror(char *s);
int yyparse();
int yylex();

#define DEBUG 1

/* ----------------------------------------------------------- */
/* --------- Declarations for Syntax-Semantic Analysis ------- */
/* ----------------------------------------------------------- */

#define SYM_TABLE_SIZE 41
#define NAME_MAX  32
#define MAX_METHOD_NUMBER 64

#define TRUE_VAL  1
#define FALSE_VAL 0

typedef struct symbol_tag {
   unsigned char name[NAME_MAX+1];  /* -- Variable name .------------------ */
   int timi;                        /* -- Value assigned . ---------------- */
   int parameter;                     /* -- TRUE or FALSE .------------------ */
   struct symbol_tag *NextSymbol;
   struct symbol_tag *PrevSymbol;
} symbol;

typedef struct hash_tab {
   int numbsymbols;
   symbol *table[SYM_TABLE_SIZE];
} HASH_TAB;

typedef struct method_tab{
   char name[NAME_MAX+1];
   HASH_TAB ht;
   int exists; /* -- TRUE or FALSE .------------------ */
} MethodTab;

static int numbmethods=0;
static int currentmethod=-1;

MethodTab mt[MAX_METHOD_NUMBER];

void Init_Hash_Table(HASH_TAB *ht);
symbol *new_symbol(char *name);
int mkkey(char *s);
void addsymb(HASH_TAB *ht, symbol *symbp);
symbol *findsymb(HASH_TAB *ht, char *onoma);
int methodidx(char *name);
void addmethod(char *name);
void currentscope(char *name);
void leavescope(void);
void addvariable(char *name, int parameter);
symbol* findsymbolinmethod(char *name);

%}

%union
{
    int   yint;
    char  ystr[81];
    int   nonterm;
}

%token <yint> RETURN BREAK ELSE IF INT WHILE TRUE FALSE
%token <yint> GT LT GE LE EQ NE
%token <ystr> ID
%token <yint> NUM

 
%type <nonterm> PROGRAM METH_LIST METH PARAMS FORMALS TYPE BODY DECLS DECL_LIST DECL VARS
%type <nonterm> STMTS STMT BLOCK ASSIGN LOCATION METHOD EXPR RELOP ADD_EXPR ADDOP TERM
%type <nonterm> MULOP FACTOR ACTUALS ARGS

%start PROGRAM

%%

PROGRAM            : METH_LIST
                     { 
#if DEBUG
                        printf("Rule #1\n");
#endif 
                     };

METH_LIST            : METH METH_LIST
                     { 
#if DEBUG
                        printf("Rule #3\n");
#endif 
                     }
		       | METH
                     { 
#if DEBUG
                        printf("Rule #4\n");
#endif
                     };
METH            : TYPE ID 
                     { 
#if DEBUG
                        printf("Rule #5\n");
#endif
			addmethod($2);
			currentscope($2);
			}
'(' PARAMS ')' BODY
			{
			leavescope();
			};
                
PARAMS            : FORMALS TYPE ID
                     { 
#if DEBUG
                        printf("Rule #6\n");
#endif
			addvariable($3,TRUE_VAL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #7\n");
#endif
                     };
FORMALS            : FORMALS TYPE ID ','
                     { 
#if DEBUG
                        printf("Rule #8\n");
#endif
			addvariable($3,TRUE_VAL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #9\n");
#endif
                     };
TYPE            : INT
                     { 
#if DEBUG
                        printf("Rule #10\n");
#endif
                     };
BODY            : '{' DECLS STMTS '}'
                     { 
#if DEBUG
                        printf("Rule #11\n");
#endif
                     };
DECLS            : DECL_LIST DECL
                     { 
#if DEBUG
                        printf("Rule #12\n");
#endif
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #13\n");
#endif
                     };
DECL_LIST            : DECL_LIST DECL
                     { 
#if DEBUG
                        printf("Rule #14\n");
#endif
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #15\n");
#endif
                     };
DECL            : TYPE ID VARS ';'
                     { 
#if DEBUG
                        printf("Rule #16\n");
#endif
			addvariable($2,FALSE_VAL);
                     }
		       | TYPE ID '=' EXPR VARS ';' 
                     { 
#if DEBUG
                        printf("Rule #17\n");
#endif
			addvariable($2,FALSE_VAL);
                     };
VARS            : ',' ID VARS
                     { 
#if DEBUG
                        printf("Rule #18\n");
#endif
                     }
		       | ',' ID '=' EXPR VARS
                     { 
#if DEBUG
                        printf("Rule #19\n");
#endif
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #20\n");
#endif
                     };
STMTS            : STMTS STMT
                     { 
#if DEBUG
                        printf("Rule #21\n");
#endif
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #22\n");
#endif
                     };
STMT            : ASSIGN ';'
                     { 
#if DEBUG
                        printf("Rule #23\n");
#endif
                     }
		       | RETURN EXPR ';'
		{ 
#if DEBUG
                        printf("Rule #24\n");
#endif
                     }
			| IF '(' EXPR ')' STMT ELSE STMT
		{ 
#if DEBUG
                        printf("Rule #25\n");
#endif
                     }
			| WHILE '(' EXPR ')' STMT
		{ 
#if DEBUG
                        printf("Rule #26\n");
#endif
                     }
			| BREAK ';'
		{ 
#if DEBUG
                        printf("Rule #27\n");
#endif
                     }
			| BLOCK
		{ 
#if DEBUG
                        printf("Rule #28\n");
#endif
                     }
		       | ';'
                     { 
#if DEBUG
                        printf("Rule #29\n");
#endif
                     };
BLOCK            : '{' STMTS '}'
                     { 
#if DEBUG
                        printf("Rule #30\n");
#endif
                     };
ASSIGN            : LOCATION '=' EXPR
                     { 
#if DEBUG
                        printf("Rule #31\n");
#endif
                     };
LOCATION            : ID
                     { 
#if DEBUG
                        printf("Rule #32\n");
#endif
			findsymbolinmethod($1);
                     };
METHOD            : ID
                     { 
#if DEBUG
                        printf("Rule #33\n");
#endif
			if(methodidx($1)==-1){
				fprintf(stderr,"method %s isn't declared\n",$1);
				exit(1);
			}
                     };
EXPR            : ADD_EXPR RELOP ADD_EXPR
                     { 
#if DEBUG
                        printf("Rule #34\n");
#endif
                     }
		| ADD_EXPR
                     { 
#if DEBUG
                        printf("Rule #35\n");
#endif
                     };
RELOP            : LE
                     { 
#if DEBUG
                        printf("Rule #36\n");
#endif
                     }
		| LT
                     { 
#if DEBUG
                        printf("Rule #37\n");
#endif
                     }
		| GT
                     { 
#if DEBUG
                        printf("Rule #38\n");
#endif
                     }
		| GE
                     { 
#if DEBUG
                        printf("Rule #39\n");
#endif
                     }
		| EQ
                     { 
#if DEBUG
                        printf("Rule #40\n");
#endif
                     }
		| NE
                     { 
#if DEBUG
                        printf("Rule #41\n");
#endif
                     };
ADD_EXPR            : ADD_EXPR ADDOP TERM
                     { 
#if DEBUG
                        printf("Rule #42\n");
#endif
                     }
		| TERM
                     { 
#if DEBUG
                        printf("Rule #43\n");
#endif
                     };
ADDOP            : '+'
                     { 
#if DEBUG
                        printf("Rule #44\n");
#endif
                     }
		| '-'
                     { 
#if DEBUG
                        printf("Rule #45\n");
#endif
                     };
TERM            : TERM MULOP FACTOR
                     { 
#if DEBUG
                        printf("Rule #46\n");
#endif
                     }
		| FACTOR
                     { 
#if DEBUG
                        printf("Rule #47\n");
#endif
                     };
MULOP            : '*'
                     { 
#if DEBUG
                        printf("Rule #48\n");
#endif
                     }
		| '/'
                     { 
#if DEBUG
                        printf("Rule #49\n");
#endif
                     };
FACTOR            : '(' EXPR ')'
                     { 
#if DEBUG
                        printf("Rule #50\n");
#endif
                     }
		| LOCATION
                     { 
#if DEBUG
                        printf("Rule #51\n");
#endif
                     }
		| NUM
                     { 
#if DEBUG
                        printf("Rule #52\n");
#endif
                     }
		| TRUE
                     { 
#if DEBUG
                        printf("Rule #53\n");
#endif
                     }
		| FALSE
                     { 
#if DEBUG
                        printf("Rule #54\n");
#endif
                     }
		| METHOD '(' ACTUALS ')'
                     { 
#if DEBUG
                        printf("Rule #55\n");
#endif
                     };
ACTUALS            : ARGS EXPR
                     { 
#if DEBUG
                        printf("Rule #56\n");
#endif
                     }
		|
                     { 
#if DEBUG
                        printf("Rule #57\n");
#endif
                     };
ARGS            : ARGS EXPR ','
                     { 
#if DEBUG
                        printf("Rule #58\n");
#endif
                     }
		|
                     	{ 
#if DEBUG
                        printf("Rule #59\n");
#endif
                     };
%%

void Init_Hash_Table(HASH_TAB *ht)
{  
   ht->numbsymbols=0;
   int i;

   for(i=0; i<SYM_TABLE_SIZE; i++)
      ht->table[i]=NULL;
}

symbol *new_symbol(char *name)
{  symbol *symbp;
   symbp=(symbol *)malloc(sizeof(symbol));

   if(!symbp){
      fprintf(stderr,"cannot allocate memory for symbp %s\n", name);
      exit(1);
   }
   memset(symbp,0,sizeof(symbol));
   strncpy(symbp->name,name,(strlen(name)>NAME_MAX)?NAME_MAX:strlen(name));
   symbp->timi=0;
   symbp->parameter=0;
   symbp->NextSymbol=NULL;
   symbp->PrevSymbol=NULL;
   return(symbp);
}

int mkkey(char *s)
{  char *p;
   int athr=0;

   for(p=s; *p; p++) athr=athr+(*p);
   return (athr % SYM_TABLE_SIZE);
}

void addsymb(HASH_TAB *ht, symbol *symbp)
{  int i;
   symbol *p;

   i=mkkey(symbp->name);
   p=ht->table[i];
   symbp->NextSymbol=p;
   symbp->PrevSymbol=NULL;
   if(p) p->PrevSymbol=symbp;
   ht->table[i]=symbp;
   ht->numbsymbols++;
}

symbol *findsymb(HASH_TAB *ht, char *onoma)
{  int i;
   symbol *p;

   i=mkkey(onoma);
   p=ht->table[i];
   while(p && (strcmp(p->name,onoma) !=0))
      p=p->NextSymbol;
   return(p);
}

int methodidx(char *name){
   for(int i=0;i<numbmethods;++i){
      if(strcmp(mt[i].name,name)==0)
         return i;
   }
   return -1;
}

void addmethod(char *name){
   if(methodidx(name)!=-1){
      fprintf(stderr, "cannot add %s because it has already been defined",name);
      exit(1);
   }
   if (numbmethods>=MAX_METHOD_NUMBER){
      fprintf(stderr, "cannot add %s, too many methods",name);
      exit(1);
   }
   strncpy(mt[numbmethods].name,name,NAME_MAX);
   mt[numbmethods].name[NAME_MAX]='\0';
   Init_Hash_Table(&mt[numbmethods].ht);
   mt[numbmethods].exists=1;
   numbmethods++;
}

void currentscope(char *name){
   int i=methodidx(name);
   if (i==-1){
      fprintf(stderr,"%s method isn't registered\n",name);
      exit(1);
   }
   currentmethod=i;
}

void leavescope(void){
   currentmethod=-1;
}

void addvariable(char *name, int parameter){
   if(currentmethod==-1){
      fprintf(stderr,"delaring variable outside of a method\n");
      exit(1);
   }
   HASH_TAB *tempht = &mt[currentmethod].ht;
   if(findsymb(tempht,name)){
      fprintf(stderr,"redelaring variable %s in method %s\n",name,mt[currentmethod].name);
      exit(1);
   }
   symbol *temps = new_symbol(name);
   temps->parameter=parameter?1:0;
   addsymb(tempht,temps);
}

symbol* findsymbolinmethod(char *name){
   if(currentmethod==-1){
      fprintf(stderr,"looking for a variable outside a method\n");
      exit(1);
   }
   symbol* temps = findsymb(&mt[currentmethod].ht, name);
   if(!temps){
      fprintf(stderr,"variable %s not found in method %s\n",name,mt[currentmethod].name);
      exit(1);
   }
   return temps;
}

void yyerror(char *s)
{
   fputs(s,stderr); putc('\n',stderr);
}

int main(void)
{
   yyparse();
}
