%{

#include "defs.h" 

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

typedef struct AstNode_tag {
    int NodeType;
    struct symbol_tag *SymbolNode;
    struct AstNode_tag *pAstNode[4];
} AstNode;

static int numbmethods=0;
static int currentmethod=-1;

MethodTab mt[MAX_METHOD_NUMBER];

int TopOfStack=-1;
symbol *vs[30];

symbol *p,*p1,*p2,*p3;

AstNode *TreeRoot;

AstNode *MkNode(int tipos,symbol *sn,AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3);
static symbol *new_num_symbol(int value);
static void indent(int n);
void printAST(AstNode *p, int n);
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
    struct AstNode_tag *stnode;
}

%token <yint> RETURN BREAK ELSE IF INT WHILE TRUE FALSE
%token <yint> GT LT GE LE EQ NE
%token <ystr> ID
%token <yint> NUM

 
%type <stnode> PROGRAM METH_LIST METH PARAMS FORMALS TYPE BODY DECLS DECL_LIST DECL VARS
%type <stnode> STMTS STMT BLOCK ASSIGN LOCATION METHOD EXPR RELOP ADD_EXPR ADDOP TERM
%type <stnode> MULOP FACTOR ACTUALS ARGS

%start PROGRAM

%%

PROGRAM            : METH_LIST
                     { 
#if DEBUG
                        printf("Rule #1\n");
#endif 
			TreeRoot=MkNode(astProgram,NULL,$1,NULL,NULL,NULL);
			$$=TreeRoot;
                     };

METH_LIST            : METH METH_LIST
                     { 
#if DEBUG
                        printf("Rule #3\n");
#endif 
			$$=MkNode(astMethList,NULL,$1,$2,NULL,NULL);
                     }
		       | METH
                     { 
#if DEBUG
                        printf("Rule #4\n");
#endif
			$$=MkNode(astMethList,NULL,$1,NULL,NULL,NULL);
                     };
METH            : TYPE ID
{
			addmethod($2);
			currentscope($2);
} 
		'(' PARAMS ')' BODY
                     { 
#if DEBUG
                        printf("Rule #5\n");
#endif
			
			symbol *temps=new_symbol($2);
			$$=MkNode(astMethod,temps,$7,NULL,NULL,NULL);
			leavescope();
			};
                
PARAMS            : FORMALS TYPE ID
                     { 
#if DEBUG
                        printf("Rule #6\n");
#endif
			addvariable($3,TRUE_VAL);
			symbol *temps=new_symbol($3);
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astParam,NULL,$1,parameter,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #7\n");
#endif
			$$=MkNode(astParams,NULL,NULL,NULL,NULL,NULL);
                     };
FORMALS            : FORMALS TYPE ID ','
                     { 
#if DEBUG
                        printf("Rule #8\n");
#endif
			addvariable($3,TRUE_VAL);
			symbol *temps=new_symbol($3);
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astParam,NULL,$1,parameter,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #9\n");
#endif
			$$=NULL;
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
			$$=MkNode(astBody,NULL,$2,$3,NULL,NULL);
                     };
DECLS            : DECL_LIST DECL
                     { 
#if DEBUG
                        printf("Rule #12\n");
#endif
			$$=MkNode(astBody,NULL,$1,$2,NULL,NULL);

                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #13\n");
#endif
			$$=MkNode(astBody,NULL,NULL,NULL,NULL,NULL);
                     };
DECL_LIST            : DECL_LIST DECL
                     { 
#if DEBUG
                        printf("Rule #14\n");
#endif
			$$=MkNode(astDecls,NULL,$1,$2,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #15\n");
#endif
			$$=NULL;
                     };
DECL            : TYPE ID VARS ';'
                     { 
#if DEBUG
                        printf("Rule #16\n");
#endif
			addvariable($2,FALSE_VAL);
			symbol *temps=new_symbol($2);
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$3,NULL,NULL);
                     }
		       | TYPE ID '=' EXPR VARS ';' 
                     { 
#if DEBUG
                        printf("Rule #17\n");
#endif
			addvariable($2,FALSE_VAL);
			symbol *temps=new_symbol($2);
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod($2), NULL, 					NULL,NULL,NULL),$4,NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$5,NULL,NULL);
                     };
VARS            : ',' ID VARS
                     { 
#if DEBUG
                        printf("Rule #18\n");
#endif
			symbol *temps=new_symbol($2);
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$3,NULL,NULL);
                     }
		       | ',' ID '=' EXPR VARS
                     { 
#if DEBUG
                        printf("Rule #19\n");
#endif
			symbol *temps=new_symbol($2);
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod($2), NULL, 					NULL,NULL,NULL),$4,NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$5,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #20\n");
#endif
			$$=NULL;
                     };
STMTS            : STMTS STMT
                     { 
#if DEBUG
                        printf("Rule #21\n");
#endif
			$$=MkNode(astStmtSeq,NULL,$1,$2,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #22\n");
#endif
			$$=MkNode(astStmtSeq,NULL,NULL,NULL,NULL,NULL);
                     };
STMT            : ASSIGN ';'
                     { 
#if DEBUG
                        printf("Rule #23\n");
#endif
			$$=MkNode(astExprStmt,NULL,$1,NULL,NULL,NULL);
                     }
		       | RETURN EXPR ';'
		{ 
#if DEBUG
                        printf("Rule #24\n");
#endif
			$$=MkNode(astReturnStmt,NULL,$2,NULL,NULL,NULL);
                     }
			| IF '(' EXPR ')' STMT ELSE STMT
		{ 
#if DEBUG
                        printf("Rule #25\n");
#endif
			$$=MkNode(astIfElseStmt,NULL,$3,$5,$7,NULL);
                     }
			| WHILE '(' EXPR ')' STMT
		{ 
#if DEBUG
                        printf("Rule #26\n");
#endif
			$$=MkNode(astWhileStmt,NULL,$3,$5,NULL,NULL);
                     }
			| BREAK ';'
		{ 
#if DEBUG
                        printf("Rule #27\n");
#endif
			$$=MkNode(astBreakStmt,NULL,NULL,NULL,NULL,NULL);
                     }
			| BLOCK
		{ 
#if DEBUG
                        printf("Rule #28\n");
#endif
			$$=$1;
                     }
		       | ';'
                     { 
#if DEBUG
                        printf("Rule #29\n");
#endif
			$$=MkNode(astNullStmt,NULL,NULL,NULL,NULL,NULL);
                     };
BLOCK            : '{' STMTS '}'
                     { 
#if DEBUG
                        printf("Rule #30\n");
#endif
			$$=MkNode(astBlock,NULL,$2,NULL,NULL,NULL);
                     };
ASSIGN            : LOCATION '=' EXPR
                     { 
#if DEBUG
                        printf("Rule #31\n");
#endif
			$$=MkNode(astAssign,NULL,$1,$3,NULL,NULL);
                     };
LOCATION            : ID
                     { 
#if DEBUG
                        printf("Rule #32\n");
#endif
			symbol *temps=findsymbolinmethod($1);
			$$=MkNode(astId,temps,NULL,NULL,NULL,NULL);
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
			symbol *temps=new_symbol($1);
			$$=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     };
EXPR            : ADD_EXPR RELOP ADD_EXPR
                     { 
#if DEBUG
                        printf("Rule #34\n");
#endif
			$$=MkNode($2->NodeType,NULL,$1,$3,NULL,NULL);
                     }
		| ADD_EXPR
                     { 
#if DEBUG
                        printf("Rule #35\n");
#endif
			$$=$1;
                     };
RELOP            : LE
                     { 
#if DEBUG
                        printf("Rule #36\n");
#endif
			$$=MkNode(astLeEq,NULL,NULL,NULL,NULL,NULL);
                     }
		| LT
                     { 
#if DEBUG
                        printf("Rule #37\n");
#endif
			$$=MkNode(astLess,NULL,NULL,NULL,NULL,NULL);
                     }
		| GT
                     { 
#if DEBUG
                        printf("Rule #38\n");
#endif
			$$=MkNode(astGreater,NULL,NULL,NULL,NULL,NULL);
                     }
		| GE
                     { 
#if DEBUG
                        printf("Rule #39\n");
#endif
			$$=MkNode(astGrEq,NULL,NULL,NULL,NULL,NULL);
                     }
		| EQ
                     { 
#if DEBUG
                        printf("Rule #40\n");
#endif
			$$=MkNode(astEq,NULL,NULL,NULL,NULL,NULL);
                     }
		| NE
                     { 
#if DEBUG
                        printf("Rule #41\n");
#endif
			$$=MkNode(astNotEq,NULL,NULL,NULL,NULL,NULL);
                     };
ADD_EXPR            : ADD_EXPR ADDOP TERM
                     { 
#if DEBUG
                        printf("Rule #42\n");
#endif
			$$=MkNode($2->NodeType,NULL,$1,$3,NULL,NULL);
                     }
		| TERM
                     { 
#if DEBUG
                        printf("Rule #43\n");
#endif
			$$=$1;
                     };
ADDOP            : '+'
                     { 
#if DEBUG
                        printf("Rule #44\n");
#endif
			$$=MkNode(astAdd,NULL,NULL,NULL,NULL,NULL);
                     }
		| '-'
                     { 
#if DEBUG
                        printf("Rule #45\n");
#endif
			$$=MkNode(astSub,NULL,NULL,NULL,NULL,NULL);
                     };
TERM            : TERM MULOP FACTOR
                     { 
#if DEBUG
                        printf("Rule #46\n");
#endif
			$$=MkNode($2->NodeType,NULL,$1,$3,NULL,NULL);
                     }
		| FACTOR
                     { 
#if DEBUG
                        printf("Rule #47\n");
#endif
			$$=$1;
                     };
MULOP            : '*'
                     { 
#if DEBUG
                        printf("Rule #48\n");
#endif
			$$=MkNode(astMult,NULL,NULL,NULL,NULL,NULL);
                     }
		| '/'
                     { 
#if DEBUG
                        printf("Rule #49\n");
#endif
			$$=MkNode(astDiv,NULL,NULL,NULL,NULL,NULL);
                     };
FACTOR            : '(' EXPR ')'
                     { 
#if DEBUG
                        printf("Rule #50\n");
#endif
			$$=$2;
                     }
		| LOCATION
                     { 
#if DEBUG
                        printf("Rule #51\n");
#endif
			$$=$1;
                     }
		| NUM
                     { 
#if DEBUG
                        printf("Rule #52\n");
#endif
			symbol *temps=new_num_symbol($1);
			$$=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
		| TRUE
                     { 
#if DEBUG
                        printf("Rule #53\n");
#endif
			symbol *temps=new_num_symbol(1);
			$$=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
		| FALSE
                     { 
#if DEBUG
                        printf("Rule #54\n");
#endif
			symbol *temps=new_num_symbol(0);
			$$=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
		| METHOD '(' ACTUALS ')'
                     { 
#if DEBUG
                        printf("Rule #55\n");
#endif
			$$=MkNode(astCall,NULL,$1,$3,NULL,NULL);
                     };
ACTUALS            : ARGS EXPR
                     { 
#if DEBUG
                        printf("Rule #56\n");
#endif
			AstNode *last=MkNode(astArgs,NULL,$2,NULL,NULL,NULL);
			$$=MkNode(astArgs,NULL,$2,NULL,NULL,NULL);
                     }
		|
                     { 
#if DEBUG
                        printf("Rule #57\n");
#endif
			$$=NULL;
                     };
ARGS            : ARGS EXPR ','
                     { 
#if DEBUG
                        printf("Rule #58\n");
#endif
			$$=MkNode(astArgs,NULL,$1,MkNode(astArgs,NULL,$2,NULL,NULL,NULL),NULL,NULL);
                     }
		|
                     	{ 
#if DEBUG
                        printf("Rule #59\n");
#endif
			$$=NULL;
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

AstNode *MkNode(int tipos,symbol *sn,
              AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3)
{  AstNode *p;

   p=(AstNode *)malloc(sizeof(AstNode));
   if(!p)
   {
      printf("Out of memory\n");
      exit(1);
   }
   else
   {
      p->NodeType=tipos;
      p->SymbolNode=sn;
      p->pAstNode[0]=z0;
      p->pAstNode[1]=z1;
      p->pAstNode[2]=z2;
      p->pAstNode[3]=z3;
      return(p);
   }
}


static symbol *new_num_symbol(int value) {
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", value);
    symbol *s = new_symbol(buf);  
    s->timi = value;
    return s;
}

static void indent(int n){ for(int i=0;i<n;i++) putchar(' '); }

void printAST(AstNode *p, int n)
{
    if (!p) return;
    n += 2;
    switch (p->NodeType) {
        case astProgram:     indent(n); puts("astProgram"); break;
        case astMethList:    indent(n); puts("astMethList"); break;
        case astMethod:      indent(n); printf("astMethod%s%s\n",
                                 p->SymbolNode ? "=" : "",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : ""); break;
        case astParams:      indent(n); puts("astParams"); break;
        case astParam:       indent(n); printf("astParam%s%s\n",
                                 p->SymbolNode ? "=" : "",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : ""); break;
        case astBody:        indent(n); puts("astBody"); break;
        case astDecls:       indent(n); puts("astDecls"); break;
        case astVarList:     indent(n); puts("astVarList"); break;
        case astStmtSeq:     indent(n); puts("astStmtSeq"); break;      /* reused */
        case astBlock:       indent(n); puts("astBlock"); break;
        case astExprStmt:    indent(n); puts("astExprStmt"); break;     /* reused */
        case astAssign:      indent(n); puts("astAssign"); break;       /* reused */
        case astReturnStmt:  indent(n); puts("astReturnStmt"); break;
        case astIfStmt:      indent(n); puts("astIfStmt"); break;       /* reused */
        case astIfElseStmt:  indent(n); puts("astIfElseStmt"); break;   /* reused */
        case astWhileStmt:   indent(n); puts("astWhileStmt"); break;    /* reused */
        case astBreakStmt:   indent(n); puts("astBreakStmt"); break;
        case astAdd:         indent(n); puts("astAdd"); break;          /* reused */
        case astSub:         indent(n); puts("astSub"); break;
        case astMult:        indent(n); puts("astMult"); break;
        case astDiv:         indent(n); puts("astDiv"); break;
        case astEq:          indent(n); puts("astEq"); break;
        case astNotEq:       indent(n); puts("astNotEq"); break;
        case astLess:        indent(n); puts("astLess"); break;
        case astLeEq:        indent(n); puts("astLeEq"); break;
        case astGreater:     indent(n); puts("astGreater"); break;
        case astGrEq:        indent(n); puts("astGrEq"); break;
        case astId:          indent(n); printf("astId=%s\n",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : "?"); break;
        case astDecimConst:  indent(n); printf("astDecimConst=%s\n",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : "?"); break;
        case astCall:        indent(n); puts("astCall"); break;
        case astArgs:        indent(n); puts("astArgs"); break;
        default:             indent(n); printf("UNKNOWN=%d\n", p->NodeType);
    }
    for (int i=0;i<4;i++) if (p->pAstNode[i]) printAST(p->pAstNode[i], n);
}

void yyerror(char *s)
{
   fputs(s,stderr); putc('\n',stderr);
}

int main(void)
{
   yyparse();
   printAST(TreeRoot, 0);
}
