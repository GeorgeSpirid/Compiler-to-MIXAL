#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SYM_TABLE_SIZE 41
#define NAME_MAX  32
#define MAX_METHOD_NUMBER 64

#define TRUE_VAL  1
#define FALSE_VAL 0

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


typedef struct symbol_tag {
   unsigned char name[NAME_MAX+1];
   int timi;
   int parameter;
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


extern int numbmethods;
extern int currentmethod;
extern MethodTab mt[MAX_METHOD_NUMBER];
extern AstNode *TreeRoot;


AstNode *MkNode(int tipos,symbol *sn,AstNode *z0,AstNode *z1,AstNode *z2,AstNode *z3);
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


#endif


