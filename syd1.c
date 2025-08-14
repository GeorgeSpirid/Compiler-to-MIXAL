#include "defs.h"

int numbmethods=0;
int currentmethod=-1;
MethodTab mt[MAX_METHOD_NUMBER];
AstNode *TreeRoot; // poinrter to the root of the AST


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
        case astStmtSeq:     indent(n); puts("astStmtSeq"); break;
        case astBlock:       indent(n); puts("astBlock"); break;
        case astExprStmt:    indent(n); puts("astExprStmt"); break;
        case astAssign:      indent(n); puts("astAssign"); break;
        case astReturnStmt:  indent(n); puts("astReturnStmt"); break;
        case astIfStmt:      indent(n); puts("astIfStmt"); break;
        case astIfElseStmt:  indent(n); puts("astIfElseStmt"); break;
        case astWhileStmt:   indent(n); puts("astWhileStmt"); break;
        case astBreakStmt:   indent(n); puts("astBreakStmt"); break;
        case astAdd:         indent(n); puts("astAdd"); break;
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
