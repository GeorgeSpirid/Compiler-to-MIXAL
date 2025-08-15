#include "defs.h"

int numbmethods=0;
int currentmethod=-1;
MethodTab mt[MAX_METHOD_NUMBER];
AstNode *TreeRoot; // poinrter to the root of the AST

int loopdepth=0; // for break checking
int cur_param_count=0;

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
      printf("cannot allocate memory for symbp %s\n", name);
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
      printf("cannot add %s because it has already been defined",name);
      exit(1);
   }
   if (numbmethods>=MAX_METHOD_NUMBER){
      printf("cannot add %s, too many methods",name);
      exit(1);
   }
   int len=strlen(name);
   if(len>NAME_MAX){
      printf("method name %s is too long, so it is shortened\n", name);
   }
   memcpy(mt[numbmethods].name,name,NAME_MAX);
   mt[numbmethods].name[NAME_MAX]='\0';
   Init_Hash_Table(&mt[numbmethods].ht);
   mt[numbmethods].exists=1;
   mt[numbmethods].param_count=0;
   mt[numbmethods].has_return=0;
   numbmethods++;
}

void currentscope(char *name){
   int i=methodidx(name);
   if (i==-1){
      printf("%s method isn't registered\n",name);
      exit(1);
   }
   currentmethod=i;
}

void leavescope(void){
   currentmethod=-1;
}

void addvariable(char *name, int parameter){
   if(currentmethod==-1){
      printf("delaring variable outside of a method\n");
      exit(1);
   }
   HASH_TAB *tempht = &mt[currentmethod].ht;
   if(findsymb(tempht,name)){
      printf("redelaring variable %s in method %s\n",name,mt[currentmethod].name);
      exit(1);
   }
   symbol *temps = new_symbol(name);
   temps->parameter=parameter?1:0;
   addsymb(tempht,temps);
}

symbol* findsymbolinmethod(char *name){
   if(currentmethod==-1){
      printf("looking for a variable outside a method\n");
      exit(1);
   }
   symbol* temps = findsymb(&mt[currentmethod].ht, name);
   if(!temps){
      printf("variable %s not found in method %s\n",name,mt[currentmethod].name);
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


void kena(int n)
{  int i;
   
   for(i=0; i<n; i++) printf(" ");
}
void printAST(AstNode *p, int n)
{
    if (!p) return;
    n=n+3;
    switch (p->NodeType) {
        case astProgram:     kena(n); puts("astProgram"); break;
        case astMethList:    kena(n); puts("astMethList"); break;
        case astMethod:      kena(n); printf("astMethod%s%s\n",
                                 p->SymbolNode ? "=" : "",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : ""); break;
        case astParams:      kena(n); puts("astParams"); break;
        case astParam:       kena(n); printf("astParam%s%s\n",
                                 p->SymbolNode ? "=" : "",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : ""); break;
        case astBody:        kena(n); puts("astBody"); break;
        case astDecls:       kena(n); puts("astDecls"); break;
        case astVarList:     kena(n); puts("astVarList"); break;
        case astStmtSeq:     kena(n); puts("astStmtSeq"); break;
        case astBlock:       kena(n); puts("astBlock"); break;
        case astExprStmt:    kena(n); puts("astExprStmt"); break;
        case astAssign:      kena(n); puts("astAssign"); break;
        case astReturnStmt:  kena(n); puts("astReturnStmt"); break;
        case astIfStmt:      kena(n); puts("astIfStmt"); break;
        case astIfElseStmt:  kena(n); puts("astIfElseStmt"); break;
        case astWhileStmt:   kena(n); puts("astWhileStmt"); break;
        case astBreakStmt:   kena(n); puts("astBreakStmt"); break;
        case astAdd:         kena(n); puts("astAdd"); break;
        case astSub:         kena(n); puts("astSub"); break;
        case astMult:        kena(n); puts("astMult"); break;
        case astDiv:         kena(n); puts("astDiv"); break;
        case astEq:          kena(n); puts("astEq"); break;
        case astNotEq:       kena(n); puts("astNotEq"); break;
        case astLess:        kena(n); puts("astLess"); break;
        case astLeEq:        kena(n); puts("astLeEq"); break;
        case astGreater:     kena(n); puts("astGreater"); break;
        case astGrEq:        kena(n); puts("astGrEq"); break;
        case astId:          kena(n); printf("astId=%s\n",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : "?"); break;
        case astDecimConst:  kena(n); printf("astDecimConst=%s\n",
                                 p->SymbolNode ? (char*)p->SymbolNode->name : "?"); break;
        case astCall:        kena(n); puts("astCall"); break;
        case astArgs:        kena(n); puts("astArgs"); break;
        default:             kena(n); printf("UNKNOWN=%d\n", p->NodeType);
    }
    for (int i=0;i<4;i++) if (p->pAstNode[i]) printAST(p->pAstNode[i], n);
}

AstNode*  mostright(AstNode *p)
{
    if (!p) return NULL;
    if(p->NodeType==astStmtSeq){
      if(p->pAstNode[1]) return mostright(p->pAstNode[1]);
      else return mostright(p->pAstNode[0]);
    }
    return p;
}

int ast_returns(AstNode *s){
   if (!s) return 0;
   if (s->NodeType == astReturnStmt) return 1;
   if (s->NodeType==astStmtSeq) return ast_returns(mostright(s));
   if (s->NodeType==astBlock) return ast_returns(s->pAstNode[0]);
   if (s->NodeType==astIfElseStmt)
      return ast_returns(s->pAstNode[1]) && ast_returns(s->pAstNode[2]);
   return 0;
}

int count_args(AstNode *s) {
    if (!s) return 0;

    if (s->NodeType == astArgs) {
        return count_args(s->pAstNode[0]) + count_args(s->pAstNode[1]);
    }

    // Any non-astArgs node is a single argument
    return 1;
}


int is_zero(AstNode *s){
   return s && s->NodeType==astDecimConst && s->SymbolNode && s->SymbolNode->timi==0;
}

int is_location(AstNode *s){
   return s && s->NodeType==astId;
}