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
   char buf[32]; snprintf(buf, sizeof(buf), "%d", value); 
   size_t len = strlen(buf); size_t start=0; 
   if(len>5){ start=len-5; if(buf[0]=='-'){ start=len-5; if(start<1) start=1; } } 
   size_t slice_len=len-start; char word[6]; 
   size_t pad=(slice_len<5)?(5-slice_len):0; 
   for(size_t i=0; i<pad; i++) word[i]=' '; 
   memcpy(word+pad, buf+start, slice_len); word[5]='\0'; 
   fprintf(femitc, "VAL ALF \"%s\"\n", word); 
} 

static int evalConst(AstNode *p, int *ok){
    if(!p){ *ok=0; return 0; }
    switch(p->NodeType){
        case astDecimConst:
            *ok=1;
            return p->SymbolNode->timi;
        case astSub: {
            int ok1=0, ok2=0;
            int v1=evalConst(p->pAstNode[0], &ok1);
            int v2=evalConst(p->pAstNode[1], &ok2);
            if(ok1 && ok2){ *ok=1; return v1 - v2; }
            break;
        }
        case astAdd: {
            int ok1=0, ok2=0;
            int v1=evalConst(p->pAstNode[0], &ok1);
            int v2=evalConst(p->pAstNode[1], &ok2);
            if(ok1 && ok2){ *ok=1; return v1 + v2; }
            break;
        }
        // add astMult, astDiv if needed
    }
    *ok=0;
    return 0;
}

static void CodeGeneration(AstNode *p){ 
   if(!p) return; 
   switch(p->NodeType){ 
      case astProgram: case astMethList: case astMethod: case astBody: case astStmtSeq: case astBlock: 
         for(int i=0; i<4; i++){ CodeGeneration(p->pAstNode[i]); } 
         break; 
      case astReturnStmt:
         AstNode *expr=p->pAstNode[0];
         int ok=0;
         int val=evalConst(expr, &ok);
         if(ok){
            emit_return(val);
         }
         break;
      case astDecimConst: break; 
      case astId: break; 
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
      fprintf(femitc, " ORIG 1000\n"); 
      fprintf(femitc, "MAIN NOP\n"); 
      CodeGeneration(TreeRoot); 
      if(lastReturnIsConst){} 
      fprintf(femitc, " OUT VAL(19)\n", lastReturnValue); 
      fprintf(femitc, " HLT\n"); 
      if(lastReturnIsConst){ emit_value_as_alf(lastReturnValue); } 
      fprintf(femitc, " END MAIN\n"); 
      fclose(femitc); 
   } 
}