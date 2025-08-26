#include <stdio.h> 
#include <stdlib.h> 
#include "defs.h" 
#include "syd.tab.h" 

extern AstNode *TreeRoot; 
int yyparse(); 

FILE *femitc; 
char alf_buf[8192]="";

static void emit_value_as_alf(char *label,int value){ 
   char buf[32]; 
   snprintf(buf, sizeof(buf), "%d", value); 

   size_t len = strlen(buf); 
   size_t pos=0; 

   while(pos<len){
      char word[6];
      size_t sliced_len=(len-pos>=5)?5:(len-pos);
      size_t pad=(sliced_len<5)?(5-sliced_len):0;

      memcpy(word+pad, buf+pos, sliced_len);
      word[sliced_len+pad]='\0';

      if(pos+sliced_len<len){
         for(size_t i=0; i<pad; i++) word[i]=' ';
         memcpy(word+pad, buf+pos, sliced_len);
      } else{
         memcpy(word,buf+pos,sliced_len);
         for(size_t i=sliced_len; i<5; i++) word[i]=' ';
      }
      word[5]='\0';

      char line[64];
      if(pos==0){
         snprintf(line, sizeof(line), "%s ALF \"%s\"\n",label,word);
      } else {
         snprintf(line, sizeof(line), "     ALF \"%s\"\n", word);
      }

      if(strlen(alf_buf)+strlen(line)<sizeof(alf_buf)){
         strcat(alf_buf, line);
      } else {
         fprintf(stderr, "ALF buffer overflow\n");
         exit(1);
      }

      pos+=sliced_len;
   }
} 

static int evalExpr(AstNode *p){
   if(!p) return 0;
   switch(p->NodeType){
      case astDecimConst:
         return (int)p->SymbolNode->timi;
      case astId:
         return (p->SymbolNode)?(int)p->SymbolNode->timi:0;
      case astAdd:
         return evalExpr(p->pAstNode[0]) + evalExpr(p->pAstNode[1]);
      case astSub:
         return evalExpr(p->pAstNode[0]) - evalExpr(p->pAstNode[1]);
      case astMult:
         return evalExpr(p->pAstNode[0]) * evalExpr(p->pAstNode[1]);
      case astDiv:
      int second=evalExpr(p->pAstNode[1]);
      if(second==0){
         fprintf(stderr, "Error: Division by zero\n");
         exit(1);
      }
      return evalExpr(p->pAstNode[0]) / evalExpr(p->pAstNode[1]);
      default:
         return 0;
   }
}

static void CodeGeneration(AstNode *p){ 
   if(!p) return; 
   switch(p->NodeType){ 
      case astProgram: case astMethList: case astMethod: case astBody: case astStmtSeq: case astBlock: 
      case astDecls: case astVarList:
         for(int i=0; i<4; i++){ CodeGeneration(p->pAstNode[i]); } 
         break; 
      case astReturnStmt:
         AstNode *expr=p->pAstNode[0];
         if(expr){
            int val=evalExpr(expr);
            fprintf(femitc, "  OUT RCONST(19)\n");
            fprintf(femitc, "  HLT\n");
            emit_value_as_alf("RCONST", val);
         }
         break;
      case astAssign:{
            AstNode *child1=p->pAstNode[0];
            AstNode *child2=p->pAstNode[1];
            if(child1 && child1->NodeType==astId && child2){
               int val=evalExpr(child2);
               char *label=(char*)child1->SymbolNode->name;
               emit_value_as_alf(label, val);
               child1->SymbolNode->timi=val;
            }
         break;
      }
      case astDecimConst: break; 
      case astId: break; 
      default: break; 
   } 
} 

int main(){ 
   if(yyparse() == 0){ 
      if(error_count==0)
		   printAST(TreeRoot, -3);
      
      femitc = fopen("output.mixal", "w"); 
      if(!femitc){ 
         fprintf(stderr, "Cannot open output.mixal for writing\n"); 
         return 1; 
      } 
      fprintf(femitc, " ORIG 1000\n"); 
      fprintf(femitc, "MAIN NOP\n"); 

      CodeGeneration(TreeRoot); 

      fprintf(femitc, "%s", alf_buf); // add all the alf lines

      fprintf(femitc, " END MAIN\n"); 
      fclose(femitc); 
   } 
}