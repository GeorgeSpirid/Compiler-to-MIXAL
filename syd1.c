#include <stdio.h> 
#include <stdlib.h> 
#include "defs.h" 
#include "syd.tab.h" 

extern AstNode *TreeRoot; 
int yyparse(); 

FILE *femitc; 
char val_buf[8192]="";
char temp_buf[8192]="";

static int val_array[1000];
static int val_count=0;

static int temp_array[1000];
static int temp_count=0;

static void add_val(int v){
   int exists=0;
   for(int i=0; i<val_count; i++){
      if(val_array[i]==v){
         exists=1;
         break;
      }
   }
   if(!exists){
      val_array[val_count++]=v;
      val_buf[strlen(val_buf)]=0;
      sprintf(val_buf+strlen(val_buf), "V%d CON %d\n", v, v);
   }
}

static void add_temp(int v){
   for(int i=0; i<temp_count; i++){
      if(temp_array[i]==v) return;
   }
   temp_array[temp_count]=v;
   temp_buf[strlen(temp_buf)]=0;
   sprintf(temp_buf+strlen(temp_buf), "T%d CON 0\n", v);
}

static int new_temp(){
   int val=temp_count;
   add_temp(val);
   temp_count++;
   return val;
}

static int genExpr(AstNode *p){ 
   if(!p) return -1; 
   switch(p->NodeType){ 
      case astDecimConst:
         add_val(p->SymbolNode->timi);
         int temp = new_temp();
         fprintf(femitc, " LDA V%d\n", p->SymbolNode->timi);
         fprintf(femitc, " STA T%d\n", temp);
         return temp;
         break;
      case astAdd:
      case astSub:
         int left_temp = genExpr(p->pAstNode[0]);
         int right_temp = genExpr(p->pAstNode[1]);
         int result_temp = new_temp();
         fprintf(femitc, " LDA T%d\n", left_temp);
         if(p->NodeType == astAdd){
            fprintf(femitc, " ADD T%d\n", right_temp);
         } else if(p->NodeType == astSub){
            fprintf(femitc, " SUB T%d\n", right_temp);
         }
         fprintf(femitc, " STA T%d\n", result_temp);
         return result_temp;
         break;
      case astMult:
         left_temp = genExpr(p->pAstNode[0]);
         right_temp = genExpr(p->pAstNode[1]);
         result_temp = new_temp();

         fprintf(femitc, " LDA T%d\n", left_temp);
         fprintf(femitc, " MUL T%d\n", right_temp);
         fprintf(femitc, " STX T%d\n", result_temp);
         return result_temp;
         break;
      case astDiv:
         left_temp = genExpr(p->pAstNode[0]);
         right_temp = genExpr(p->pAstNode[1]);
         result_temp = new_temp();
         
         fprintf(femitc, " LDA T%d\n", right_temp);
         fprintf(femitc, " STA T%d\n", result_temp);
         fprintf(femitc, " LDX T%d\n", left_temp);
         fprintf(femitc, " ENTA 0\n");
         fprintf(femitc, " DIV T%d\n", result_temp);
         fprintf(femitc, " STA T%d\n", result_temp);
         return result_temp;
         break;
      default: 
         return -1; 
         break;
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
         int res_temp = genExpr(p->pAstNode[0]);
         fprintf(femitc, " LDA T%d\n", res_temp);
         break;
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

      fprintf(femitc, " HLT\n");
      fprintf(femitc, " ORIG 2000\n");
      fprintf(femitc, "%s", val_buf); // add all the val lines
      fprintf(femitc, "%s", temp_buf); // add all the temp lines
      fprintf(femitc, " END MAIN\n"); 
      fclose(femitc); 
   } 
}