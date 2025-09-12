
%{

#include "defs.h"
#include <limits.h>

int error_count=0;

void yyerror(const char *s);
int yyparse();
int yylex();

extern int currLine;
extern int currCol;
extern char *yytext;

#define DEBUG 0

static symbol *new_num_symbol(int value);


%}

%define parse.error verbose /* for better error messages */

%union /* all types a grammar symbol can carry */
{
    long long yll; // to check int range
    int yint;
    char  ystr[81];
    struct AstNode_tag *stnode; /* for nonterms that carry an AST node pointer */
}

%token <yint> RETURN BREAK ELSE IF INT WHILE TRUE FALSE
%token <yint> GT LT GE LE EQ NE
%token <ystr> ID
%token <yll> NUM

 
%type <stnode> PROGRAM METH_LIST METH PARAMS FORMALS TYPE BODY DECLS DECL_LIST DECL VARS
%type <stnode> STMTS STMT BLOCK ASSIGN LOCATION METHOD EXPR RELOP ADD_EXPR ADDOP TERM
%type <stnode> MULOP FACTOR ACTUALS ARGS

%start PROGRAM /* parsing begins at this rule */

%%

PROGRAM            : METH_LIST
                     { 
#if DEBUG
                        printf("Rule #1a\n");
#endif 
			TreeRoot=MkNode(astProgram,NULL,$1,NULL,NULL,NULL);
			$$=TreeRoot;
                     }
		|
		{
#if DEBUG
                        printf("Rule #1b\n");
#endif
		}
		| error
		{
#if DEBUG
                        printf("Rule #1c\n");
#endif 
			error_message("Syntax Error","program must have only methods",NULL);
			yyerrok;
			yyclearin;
			$$=MkNode(astProgram,NULL,NULL,NULL,NULL,NULL);
		};

METH_LIST            : METH METH_LIST
                     { 
#if DEBUG
                        printf("Rule #2a\n");
#endif 
			$$=MkNode(astMethList,NULL,$1,$2,NULL,NULL);
                     }
		       | METH
                     { 
#if DEBUG
                        printf("Rule #2b\n");
#endif
			$$=MkNode(astMethList,NULL,$1,NULL,NULL,NULL);
                     }
		| DECL ';' 
		{
#if DEBUG
                        printf("Rule #2c\n");
#endif 
			error_message("Syntax Error","declaration outside of method",NULL);
			yyerrok;
			yyclearin;
		}
		| STMT ';' 
		{
#if DEBUG
                        printf("Rule #2d\n");
#endif 
			error_message("Syntax Error","statement outside of method",NULL);
			yyerrok;
			yyclearin;
		}
		| error ';'
		{
#if DEBUG
                        printf("Rule #2e\n");
#endif 
			error_message("Syntax Error","only methods allowed at the top level",NULL);
			yyerrok;
			yyclearin;
		};
METH            : TYPE ID
{
#if DEBUG
                        printf("Rule #3a\n");
#endif
			addmethod($2);
			currentscope($2);
			cur_param_count=0;
			mt[currentmethod].has_return=0;
} 
		'(' PARAMS ')'
                     { 
#if DEBUG
                        printf("Rule #3b\n");
#endif
			mt[currentmethod].param_count=cur_param_count;
 		}
			 BODY
		{
#if DEBUG
                        printf("Rule #3c\n");
#endif
			if(!mt[currentmethod].has_return){
				error_message("Semantic Error","method doesn't have return value",mt[currentmethod].name);
			}
			symbol *temps=new_symbol($2);
			$$=MkNode(astMethod,temps,$5,$8,NULL,NULL);
			leavescope();
			};
                
PARAMS            : FORMALS TYPE ID
                     { 
#if DEBUG
                        printf("Rule #4a\n");
#endif
			if(findsymb(&mt[currentmethod].ht,$3)){
				error_message("Semantic Error","duplicate parameter in method",$3);
			}
			addvariable($3,TRUE_VAL);
			cur_param_count++;
			symbol *temps=new_symbol($3);
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astParam,NULL,$1,parameter,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #4b\n");
#endif
			$$=MkNode(astParams,NULL,NULL,NULL,NULL,NULL);
                     }
		| error ')'
		{
#if DEBUG
                        printf("Rule #4c\n");
			fprintf(stderr,"Skipping parameters.\n");
#endif
			yyerrok;
		};
FORMALS            : FORMALS TYPE ID ','
                     { 
#if DEBUG
                        printf("Rule #5a\n");
#endif
			addvariable($3,TRUE_VAL);
			cur_param_count++;
			symbol *temps=new_symbol($3);
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astParam,NULL,$1,parameter,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #5b\n");
#endif
			$$=NULL;
                     };
TYPE            : INT
                     { 
#if DEBUG
                        printf("Rule #6a\n");
#endif
                     };
BODY            : '{' DECLS STMTS '}'
                     { 
#if DEBUG
                        printf("Rule #7a\n");
#endif
			$$=MkNode(astBody,NULL,$2,$3,NULL,NULL);
                     };
DECLS            : DECL_LIST DECL
                     { 
#if DEBUG
                        printf("Rule #8a\n");
#endif
			$$=MkNode(astBody,NULL,$1,$2,NULL,NULL);

                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #8b\n");
#endif
			$$=MkNode(astBody,NULL,NULL,NULL,NULL,NULL);
                     };
DECL_LIST            : DECL_LIST DECL
                     { 
#if DEBUG
                        printf("Rule #9a\n");
#endif
			$$=MkNode(astDecls,NULL,$1,$2,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #9b\n");
#endif
			$$=NULL;
                     };
DECL            : TYPE ID VARS ';'
                     { 
#if DEBUG
                        printf("Rule #10a\n");
#endif
			addvariable($2,FALSE_VAL);
			symbol *temps=new_symbol($2);
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$3,NULL,NULL);
                     }
		       | TYPE ID '=' EXPR VARS ';' 
                     { 
#if DEBUG
                        printf("Rule #10b\n");
#endif
			addvariable($2,FALSE_VAL);
			symbol *temps=new_symbol($2);
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod($2), NULL,NULL,NULL,NULL),$4,NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$5,NULL,NULL);
                     }
		| TYPE error ';'
		{
#if DEBUG
                        printf("Rule #10c\n");
#endif 
			yyerrok;
			$$=MkNode(astDecls,NULL,NULL,NULL,NULL,NULL);
		};
VARS            : ',' ID VARS
                     { 
#if DEBUG
                        printf("Rule #11a\n");
#endif
			addvariable($2,FALSE_VAL);
			symbol *temps=new_symbol($2);
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$3,NULL,NULL);
                     }
		       | ',' ID '=' EXPR VARS
                     { 
#if DEBUG
                        printf("Rule #11b\n");
#endif
			addvariable($2,FALSE_VAL);
			symbol *temps=new_symbol($2);
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod($2), NULL,NULL,NULL,NULL),$4,NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			$$=MkNode(astDecls,NULL,var,$5,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #11c\n");
#endif
			$$=NULL;
                     };
STMTS            : STMTS STMT
                     { 
#if DEBUG
                        printf("Rule #12a\n");
#endif
			if(ast_returns($1)){
				error_message("Semantic Error","cannot reach code after return",mt[currentmethod].name);
			}
			$$=MkNode(astStmtSeq,NULL,$1,$2,NULL,NULL);
                     }
		       | 
                     { 
#if DEBUG
                        printf("Rule #12b\n");
#endif
			$$=MkNode(astStmtSeq,NULL,NULL,NULL,NULL,NULL);
                     };
STMT            : ASSIGN ';'
                     { 
#if DEBUG
                        printf("Rule #13a\n");
#endif
			if(!$1 || !is_location($1->pAstNode[0])){
				error_message("Semantic Error","assignment target is not a variable",NULL);
			}
			$$=MkNode(astExprStmt,NULL,$1,NULL,NULL,NULL);
                     }
		       | RETURN EXPR ';'
		{ 
#if DEBUG
                        printf("Rule #13b\n");
#endif
			if(currentmethod==-1){
				error_message("Semantic Error","return outside of a method",NULL);
			}			
			mt[currentmethod].has_return=1;
			$$=MkNode(astReturnStmt,NULL,$2,NULL,NULL,NULL);
                     }
			| IF '(' EXPR ')' STMT ELSE STMT
		{ 
#if DEBUG
                        printf("Rule #13c\n");
#endif
			$$=MkNode(astIfElseStmt,NULL,$3,$5,$7,NULL);
                     }
			| IF '(' EXPR ')' STMT error
		{ 
#if DEBUG
                        printf("Rule #13c\n");
#endif
			error_message("Syntax Error","missing else in if statement",NULL);
			yyerrok;
			$$=MkNode(astIfElseStmt,NULL,NULL,NULL,NULL,NULL);
		}
			| WHILE '(' EXPR ')' 
		{ 
#if DEBUG
                        printf("Rule #13d\n");
#endif
			loopdepth++;
		} 
			STMT
		{
#if DEBUG
                        printf("Rule #13e\n");
#endif
			loopdepth--;
			$$=MkNode(astWhileStmt,NULL,$3,$6,NULL,NULL);
                     }
			| BREAK ';'
		{ 
#if DEBUG
                        printf("Rule #13f\n");
#endif
			if(loopdepth==0){
				error_message("Semantic Error","break outside of loop",NULL);
			}
			$$=MkNode(astBreakStmt,NULL,NULL,NULL,NULL,NULL);
                     }
			| BLOCK
		{ 
#if DEBUG
                        printf("Rule #13g\n");
#endif
			$$=$1;
                     }
		       | ';'
                     { 
#if DEBUG
                        printf("Rule #13h\n");
#endif
			$$=MkNode(astNullStmt,NULL,NULL,NULL,NULL,NULL);
                     }
		| error ';'
		{
#if DEBUG
                        printf("Rule #13i\n");
			fprintf(stderr,"Skipping statement.\n");
#endif
			yyerrok;
			$$=MkNode(astNullStmt,NULL,NULL,NULL,NULL,NULL);
		};
BLOCK            : '{' STMTS '}'
                     { 
#if DEBUG
                        printf("Rule #32\n");
#endif
			$$=MkNode(astBlock,NULL,$2,NULL,NULL,NULL);
                     };
ASSIGN            : LOCATION '=' EXPR
                     { 
#if DEBUG
                        printf("Rule #14a\n");
#endif
			$$=MkNode(astAssign,NULL,$1,$3,NULL,NULL);
                     };
LOCATION            : ID
                     { 
#if DEBUG
                        printf("Rule #15a\n");
#endif
			symbol *temps=findsymbolinmethod($1);
			$$=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     };
METHOD            : ID
                     { 
#if DEBUG
                        printf("Rule #16a\n");
#endif
			if(methodidx($1)==-1){
				error_message("Semantic Error","undeclared method",$1);
			}
			symbol *temps=new_symbol($1);
			$$=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     };
EXPR            : ADD_EXPR RELOP ADD_EXPR
                     { 
#if DEBUG
                        printf("Rule #17a\n");
#endif
			$$=MkNode($2->NodeType,NULL,$1,$3,NULL,NULL);
                     }
		| ADD_EXPR
                     { 
#if DEBUG
                        printf("Rule #17b\n");
#endif
			$$=$1;
                     };
RELOP            : LE
                     { 
#if DEBUG
                        printf("Rule #18a\n");
#endif
			$$=MkNode(astLeEq,NULL,NULL,NULL,NULL,NULL);
                     }
		| LT
                     { 
#if DEBUG
                        printf("Rule #18b\n");
#endif
			$$=MkNode(astLess,NULL,NULL,NULL,NULL,NULL);
                     }
		| GT
                     { 
#if DEBUG
                        printf("Rule #18c\n");
#endif
			$$=MkNode(astGreater,NULL,NULL,NULL,NULL,NULL);
                     }
		| GE
                     { 
#if DEBUG
                        printf("Rule #18d\n");
#endif
			$$=MkNode(astGrEq,NULL,NULL,NULL,NULL,NULL);
                     }
		| EQ
                     { 
#if DEBUG
                        printf("Rule #18e\n");
#endif
			$$=MkNode(astEq,NULL,NULL,NULL,NULL,NULL);
                     }
		| NE
                     { 
#if DEBUG
                        printf("Rule #18f\n");
#endif
			$$=MkNode(astNotEq,NULL,NULL,NULL,NULL,NULL);
                     };
ADD_EXPR            : ADD_EXPR ADDOP TERM
                     { 
#if DEBUG
                        printf("Rule #19a\n");
#endif
			$$=MkNode($2->NodeType,NULL,$1,$3,NULL,NULL);
                     }
		| TERM
                     { 
#if DEBUG
                        printf("Rule #19b\n");
#endif
			$$=$1;
                     };
ADDOP            : '+'
                     { 
#if DEBUG
                        printf("Rule #20a\n");
#endif
			$$=MkNode(astAdd,NULL,NULL,NULL,NULL,NULL);
                     }
		| '-'
                     { 
#if DEBUG
                        printf("Rule #20b\n");
#endif
			$$=MkNode(astSub,NULL,NULL,NULL,NULL,NULL);
                     };
TERM            : TERM MULOP FACTOR
                     { 
#if DEBUG
                        printf("Rule #21a\n");
#endif
			if($2->NodeType==astDiv){
			    if(is_zero($3))
				error_message("Semantic Error","division by zero",NULL);
			}
			$$=MkNode($2->NodeType,NULL,$1,$3,NULL,NULL);
                     }
		| FACTOR
                     { 
#if DEBUG
                        printf("Rule #21b\n");
#endif
			$$=$1;
                     };
MULOP            : '*'
                     { 
#if DEBUG
                        printf("Rule #21c\n");
#endif
			$$=MkNode(astMult,NULL,NULL,NULL,NULL,NULL);
                     }
		| '/'
                     { 
#if DEBUG
                        printf("Rule #21d\n");
#endif
			$$=MkNode(astDiv,NULL,NULL,NULL,NULL,NULL);
                     };
FACTOR            : '(' EXPR ')'
                     { 
#if DEBUG
                        printf("Rule #22a\n");
#endif
			$$=$2;
                     }
		| LOCATION
                     { 
#if DEBUG
                        printf("Rule #22b\n");
#endif
			$$=$1;
                     }
		| NUM
                     { 
#if DEBUG
                        printf("Rule #22c\n");
#endif
			if($1<INT_MIN || $1>INT_MAX){
				error_message("Semantic Error","numeric constant out of range",NULL);
				$$=MkNode(astDecimConst,NULL,NULL,NULL,NULL,NULL);
			} else{
				symbol *temps=new_num_symbol((int)$1);
				$$=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
			}
                     }
		| TRUE
                     { 
#if DEBUG
                        printf("Rule #22d\n");
#endif
			symbol *temps=new_num_symbol(1);
			$$=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
		| FALSE
                     { 
#if DEBUG
                        printf("Rule #22e\n");
#endif
			symbol *temps=new_num_symbol(0);
			$$=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
		| METHOD '(' ACTUALS ')'
                     { 
#if DEBUG
                        printf("Rule #22f\n");
#endif
			if(!$1 || !$1->SymbolNode){
				error_message("Semantic Error","method symbol missing in call",(char*)$1->SymbolNode->name);
			}
			int mi=methodidx((char*)$1->SymbolNode->name);
			if(mi==-1){
				error_message("Semantic Error","undeclared method",(char*)$1->SymbolNode->name);
			}
			int ca=count_args($3);
			if(ca != mt[mi].param_count){
				error_message("Syntax Error","method needs different number of arguments",mt[mi].name);
			}
			$$=MkNode(astCall,NULL,$1,$3,NULL,NULL);
                     } 
		| '-' FACTOR
		{
#if DEBUG
		printf("Rule #22g\n");
#endif
		symbol *temps=new_num_symbol(0);
		$$=MkNode(astSub,NULL,MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL),$2,NULL,NULL);
		};
                     
ACTUALS            : ARGS EXPR
                     { 
#if DEBUG
                        printf("Rule #23a\n");
#endif
			if($1==NULL){
				$$=MkNode(astArgs,NULL,$2,NULL,NULL,NULL);
			}else{
			        $$ = MkNode(astArgs, NULL, $1, MkNode(astArgs, NULL, $2, 				NULL, NULL, NULL), NULL, NULL);
			}
                     }
		|
                     { 
#if DEBUG
                        printf("Rule #23b\n");
#endif
			$$=NULL;
                     };
ARGS            : ARGS EXPR ','
                     { 
#if DEBUG
                        printf("Rule #24a\n");
#endif
			$$=MkNode(astArgs,NULL,$1,MkNode(astArgs,NULL,$2,NULL,NULL,NULL),NULL,NULL);
                     }
		|
                     	{ 
#if DEBUG
                        printf("Rule #24b\n");
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


void yyerror(const char *s)
{
   error_message("Syntax Error",s,NULL);
}

// main used without syd1.c
/* int main(void)
{
   if(yyparse()==0){
	int mi=methodidx("main");
	if(mi==-1){
		error_message("Syntax Error","need to have main method",NULL);
	}
	if(mt[mi].param_count != 0){
		error_message("Syntax Error","main cannot have parameters",NULL);
	}
	fflush(stdout);
	if(error_count==0){
		printAST(TreeRoot, -3);
	} else {
		fprintf(stderr,"Parsing failed.\n");
	}
   }
} */


#include "syd2.y"
