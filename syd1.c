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
   lastReturnIsConst=1;
   lastReturnValue=value;
}

static void emit_value_as_alf(int value){
   char buf[32];
   snprintf(buf, sizeof(buf), "%d", value);
   size_t len = strlen(buf);
   size_t start=0;
   if(len>5){
      start=len-5;
      if(buf[0]=='-'){
         start=len-5;
         if(start<1) start=1;
      }
   }
   size_t slice_len=len-start;
   char word[6];
   size_t pad=(slice_len<5)?(5-slice_len):0;
   for(size_t i=0; i<pad; i++) word[i]=' ';
   memcpy(word+pad, buf+start, slice_len);
   word[5]='\0';
   fprintf(femitc, "VAL     ALF \"%s\"\n", word);

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
            emit_return(atoi(expr->SymbolNode->name));
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

      if(lastReturnIsConst){}
         fprintf(femitc, "        OUT VAL(19)\n", lastReturnValue);

      fprintf(femitc, "        HLT\n");
      if(lastReturnIsConst){
         emit_value_as_alf(lastReturnValue);
      }
      fprintf(femitc, "        END MAIN\n");

      fclose(femitc);
   }
}