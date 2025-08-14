%{

#include "defs.h" 


void yyerror(char *s);
int yyparse();
int yylex();

#define DEBUG 0

static symbol *new_num_symbol(int value);


%}

%union /* all types a grammar symbol can carry */
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode; /* for nonterms that carry an AST node pointer */
}

%token <yint> RETURN BREAK ELSE IF INT WHILE TRUE FALSE
%token <yint> GT LT GE LE EQ NE
%token <ystr> ID
%token <yint> NUM

 
%type <stnode> PROGRAM METH_LIST METH PARAMS FORMALS TYPE BODY DECLS DECL_LIST DECL VARS
%type <stnode> STMTS STMT BLOCK ASSIGN LOCATION METHOD EXPR RELOP ADD_EXPR ADDOP TERM
%type <stnode> MULOP FACTOR ACTUALS ARGS

%start PROGRAM /* parsing begins at this rule */

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

/* creates symbols with int instead of char* */
static symbol *new_num_symbol(int value) {
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", value);
    symbol *s = new_symbol(buf);  
    s->timi = value;
    return s;
}

void yyerror(char *s)
{
   fputs(s,stderr); putc('\n',stderr);
}

int main(void)
{
   if(yyparse()==0){
      printAST(TreeRoot, -3);
   }
}
