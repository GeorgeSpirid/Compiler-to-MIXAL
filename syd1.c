#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "syd.tab.h"

extern AstNode *TreeRoot;
int yyparse();

FILE *femitc;

static int lastReturnIsConst=0;
static int lastReturnValue=0;

static void emit_return(int value){
   char num[6];
   snprintf(num, sizeof(num), "%d", value);
   size_t len = strlen(num);
   fprintf(femitc, "BUF     ALF  \"%s\"\n", num);
   fprintf(femitc, "        OUT BUF(%zu)\n",len);
}

static void CodeGeneration(AstNode *p){
   if(!p) return;
   switch(p->NodeType){
      case astProgram:
      case astMethList:
      case astMethod:
      case astBody:
      case astStmtSeq:
      case astBlock:
         for(int i=0; i<4; i++){
            CodeGeneration(p->pAstNode[i]);
         }
         break;
      case astReturnStmt:
         AstNode *expr=p->pAstNode[0];
         if(expr&&expr->NodeType==astDecimConst){
            lastReturnIsConst=1;
            lastReturnValue=atoi(expr->SymbolNode->name);
         }
         break;
      case astDecimConst:
         break;
      case astId:
         break;
      default: break;
   }
}

int main(){
   if(yyparse() == 0){
      femitc = fopen("output.mixal", "w");
      if(!femitc){
         fprintf(stderr, "Cannot open output.mixal for writing\n");
         return 1;
      }
      fprintf(femitc, "        ORIG 1000\n");
      fprintf(femitc, "MAIN    NOP\n");

      CodeGeneration(TreeRoot);

      if(lastReturnIsConst)
         emit_return(lastReturnValue);

      fprintf(femitc, "        HLT\n");
      fprintf(femitc, "TEMP    CON 0\n");
      fprintf(femitc, "        END MAIN\n");

      fclose(femitc);
   }
}