#include <stdio.h> 
#include <stdlib.h> 
#include "defs.h" 
#include "syd.tab.h" 

extern AstNode *TreeRoot; 
int yyparse(); 

FILE *femitc; 
char val_buf[8192]="";
char temp_buf[8192]="";
char var_buf[8192]="";

static int val_array[1000];
static int val_count=0;

static int temp_array[1000];
static int temp_count=0;

static int var_array[1000];
static int var_count=0;

static void add_var(char *name, int v){
   int exists=0;
   for(int i=0; i<var_count; i++){
      if(var_array[i]==v){
         exists=1;
         break;
      }
   }
   if(!exists){
      var_array[var_count++]=v;
      var_buf[strlen(var_buf)]=0;
      sprintf(var_buf+strlen(var_buf), "%s CON %d\n", name,v);
   }
}

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
      if(v>=0)
         sprintf(val_buf+strlen(val_buf), "V%d CON %d\n", v, v);
      else
      sprintf(val_buf+strlen(val_buf), "N%d CON %d\n", -v, v);
   }
}

static void add_temp(int v){
   for(int i=0; i<temp_count; i++){
      if(temp_array[i]==v) return;
   }
   temp_array[temp_count]=v;
   temp_buf[strlen(temp_buf)]=0;
   if(v>=0)
      sprintf(temp_buf+strlen(temp_buf), "T%d CON 0\n", v);
   else
      sprintf(temp_buf+strlen(temp_buf), "TN%d CON 0\n", -v);
}

static int new_temp(){
   int val=temp_count;
   add_temp(val);
   temp_count++;
   return val;
}

static int is_neg_const(AstNode *p){
   return p->NodeType==astSub&&
            p->pAstNode[0]->NodeType==astDecimConst&&
            p->pAstNode[0]->SymbolNode->timi==0&&
            p->pAstNode[1]->NodeType==astDecimConst;
}

static int genExpr(AstNode *p){ 
   if(!p) return -1; 
   switch(p->NodeType){ 
      case astId:{
         int temp = new_temp();
         fprintf(femitc, " LDA %s\n", p->SymbolNode->name);
         fprintf(femitc, " STA T%d\n", temp);
         return temp;
      }
      case astDecimConst:{
         int v= p->SymbolNode->timi;
         add_val(v);
         int temp = new_temp();
         if(v>=0)
            fprintf(femitc, " LDA V%d\n", v);
         else
            fprintf(femitc, " LDA N%d\n", -v);
         fprintf(femitc, " STA T%d\n", temp);
         return temp;
         break;
      }
      case astAdd:
      case astSub:{
         if(is_neg_const(p)){
            int v = -p->pAstNode[1]->SymbolNode->timi;
            add_val(v);
            int temp = new_temp();
            fprintf(femitc, " LDA N%d\n", -v);
            fprintf(femitc, " STA T%d\n", temp);
            return temp;
         }
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
      }
      case astMult:{
         int left_temp = genExpr(p->pAstNode[0]);
         int right_temp = genExpr(p->pAstNode[1]);
         int result_temp = new_temp();

         fprintf(femitc, " LDA T%d\n", left_temp);
         fprintf(femitc, " MUL T%d\n", right_temp);
         fprintf(femitc, " STX T%d\n", result_temp);
         return result_temp;
         break;
      }
      case astDiv:{
         AstNode *left = p->pAstNode[0];
         AstNode *right = p->pAstNode[1];
         int left_temp = genExpr(p->pAstNode[0]);
         int right_temp = genExpr(p->pAstNode[1]);
         int result_temp = new_temp();
         int zero_temp = new_temp();
         
         fprintf(femitc, " LDA T%d\n", right_temp);
         fprintf(femitc, " STA T%d\n", result_temp);
         fprintf(femitc, " LDX T%d\n", left_temp);
         fprintf(femitc, " ENTA 0\n");
         fprintf(femitc, " DIV T%d\n", result_temp);
         if(is_neg_const(left) || is_neg_const(right)){
            if(!(is_neg_const(left) && is_neg_const(right))){
               add_val(-1);
               fprintf(femitc, " MUL N1\n");
               fprintf(femitc, " STX T%d\n", zero_temp);
            fprintf(femitc, " LDA T%d\n", zero_temp);
            }
         }
         fprintf(femitc, " STA T%d\n", result_temp);
         return result_temp;
         break;
      }
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
         for(int i=0; i<4; i++){ 
            if(p->pAstNode[i]) CodeGeneration(p->pAstNode[i]); 
         }
         break; 
      case astReturnStmt: 
         int res_temp = genExpr(p->pAstNode[0]);
         fprintf(femitc, " LDA T%d\n", res_temp);
         break;
      case astAssign:{
         char *var_label = p->pAstNode[0]->SymbolNode->name;
         int var_num = p->pAstNode[0]->SymbolNode->timi;
         add_var(var_label,var_num);
         int res_temp = genExpr(p->pAstNode[1]);
         fprintf(femitc, " LDA T%d\n", res_temp);
         fprintf(femitc, " STA %s\n", var_label);
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

      fprintf(femitc, " HLT\n");
      fprintf(femitc, " ORIG 2000\n");
      fprintf(femitc, "%s", val_buf); // add all the val lines
      fprintf(femitc, "%s", temp_buf); // add all the temp lines
      fprintf(femitc, "%s", var_buf); // add all the var lines
      fprintf(femitc, " END MAIN\n"); 
      fclose(femitc); 
   } 
}