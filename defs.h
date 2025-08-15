#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SYM_TABLE_SIZE 41 /*  is prime, good for hash distribution with % */
#define NAME_MAX  32
#define MAX_METHOD_NUMBER 64

#define TRUE_VAL  1
#define FALSE_VAL 0

/* AST node type tag for node kinds, with offset to avoid collisions with token codes in parser generator */
#define astProgram       435
#define astMethList      436
#define astMethod        437
#define astParams        438
#define astParam         439
#define astBody          440
#define astDecls         441
#define astVarList       442
#define astStmtSeq       443
#define astBlock         444
#define astExprStmt      445
#define astAssign        446
#define astReturnStmt    447
#define astIfStmt        448
#define astIfElseStmt    449
#define astWhileStmt     450
#define astBreakStmt     451
#define astNullStmt      452
#define astAdd           453
#define astSub           454
#define astMult          455
#define astDiv           456
#define astEq            457
#define astNotEq         458
#define astLess          459
#define astLeEq          460
#define astGreater       461
#define astGrEq          462
#define astId            463
#define astDecimConst    464
#define astCall          465
#define astArgs          466

/* !!! identifier table entries */
typedef struct symbol_tag {
   unsigned char name[NAME_MAX+1];
   int timi;
   int parameter;
   struct symbol_tag *NextSymbol;
   struct symbol_tag *PrevSymbol;
} symbol;

/* per scope per method */
typedef struct hash_tab {
   int numbsymbols; /* tracks population */
   symbol *table[SYM_TABLE_SIZE]; /* 41 buckets */
} HASH_TAB;

/* per method */
typedef struct method_tab{
   char name[NAME_MAX+1];
   HASH_TAB ht;
   int exists; /* to avoid duplicates */
   int param_count;
   int has_return; /* TRUE if we see a return */
} MethodTab;

typedef struct AstNode_tag {
    int NodeType; /* one of the tags above */
    struct symbol_tag *SymbolNode;
    struct AstNode_tag *pAstNode[4]; /* up to 4 children */
} AstNode;


extern int numbmethods; /* number of defined methods */
extern int currentmethod; /* index to mt[] for active spot */
extern MethodTab mt[MAX_METHOD_NUMBER];
extern AstNode *TreeRoot; /* AST root for program */
extern int loopdepth;
extern int cur_param_count;

AstNode *MkNode(int tipos,symbol *sn,AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3); /* creates an AST node */
static void indent(int n); /* spaces for display */
void printAST(AstNode *p, int n); /* display the tree */
void Init_Hash_Table(HASH_TAB *ht); /* reset counters to zero */
symbol *new_symbol(char *name); /* allocate and initialize symbol */
int mkkey(char *s); /* hash function for sumbol names */
void addsymb(HASH_TAB *ht, symbol *symbp); /* add symbp into ht */
symbol *findsymb(HASH_TAB *ht, char *onoma); /* return symbol if in ht with onoma */
int methodidx(char *name); /* return index of method in mt */
void addmethod(char *name); /* add new MethodTab with name to mt */
void currentscope(char *name); /* set currentscope to method with name when entering it */
void leavescope(void); /* currentscope=-1, not in a method, there cannnot be nested methods */
void addvariable(char *name, int parameter); /* create symbol and add it to current methods table */
symbol* findsymbolinmethod(char *name); /* return symbol if in current methods hash table */
AstNode* mostright(AstNode *p);
int ast_returns(AstNode *s);
int count_args(AstNode *s);
int is_zero(AstNode *s);
int is_location(AstNode *s);


#endif


