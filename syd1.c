#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "defs.h" 
#include "syd.tab.h" 

#define LOOP_MAX 1000

extern AstNode *TreeRoot; 
int yyparse(); 

static int genExpr(AstNode *p);
static void add_var(char *name, int v);

FILE *femitc; 
char val_buf[8192]="";
char temp_buf[8192]="";
char var_buf[8192]="";

static int val_array[1000];
static int val_count=0;

static int temp_array[1000];
static int temp_count=0;

static char *var_array[1000];
static int var_count=0;

static int loop_stack[LOOP_MAX];
static int loop_stack_top=-1;

static int label_count=1;
static int new_label(){
   return label_count++;
}

static void emit_call_stmt(AstNode *p){
   char *func_name= p->pAstNode[0]->SymbolNode->name;
   if (p->pAstNode[1]) {
      int arg_temp = genExpr(p->pAstNode[1]->pAstNode[0]);
      fprintf(femitc, " LDA T%d\n", arg_temp);
      fprintf(femitc, " STA A0\n");
      add_var("A0", 0);
   }
   fprintf(femitc, " ENTA L0\n");
   fprintf(femitc, " STA RADR\n");
   fprintf(femitc, " JMP %s\n", func_name);
}

static void push_loop(int label){
   if(loop_stack_top<LOOP_MAX-1){
      loop_stack[++loop_stack_top]=label;
   }
}

static int pop_loop(){
   if(loop_stack_top>=0){
      return loop_stack[loop_stack_top--];
   }
   return -1;
}

static int current_loop(){
   if(loop_stack_top>=0){
      return loop_stack[loop_stack_top];
   }
   return -1;
}

static void add_var(char *name, int v){
   for(int i=0; i<var_count; i++){
      if(strcmp(var_array[i], name)==0){ return;}
   }
   var_array[var_count++]=name;
   var_buf[strlen(var_buf)]=0;
   sprintf(var_buf+strlen(var_buf), "%s CON %d\n", name,v);
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
    case astCall:{
         char *func_name= p->pAstNode[0]->SymbolNode->name;
         if (p->pAstNode[1]) {
            int arg_temp = genExpr(p->pAstNode[1]->pAstNode[0]);
            fprintf(femitc, " LDA T%d\n", arg_temp);
            fprintf(femitc, " STA A0\n");
            add_var("A0", 0);
         }
         int ret_label = new_label();
         fprintf(femitc, " ENTA L%d\n", ret_label);
         fprintf(femitc, " STA RADR\n");
         fprintf(femitc, " JMP %s\n", func_name);
         fprintf(femitc, "L%d NOP\n", ret_label);

         int res_temp = new_temp();
         fprintf(femitc, " LDA RVAL\n");
         fprintf(femitc, " STA T%d\n", res_temp);
         return res_temp;
         break;
      }
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
      case astEq:
      case astNotEq:
      case astLess:
      case astLeEq:
      case astGreater:
      case astGrEq:{
         int left_temp = genExpr(p->pAstNode[0]);
         int right_temp = genExpr(p->pAstNode[1]);
         int result_temp = new_temp();

         int true_label = new_label();
         int end_label = new_label();

         add_val(0);
         fprintf(femitc, " LDA V0\n");
         fprintf(femitc, " STA T%d\n", result_temp);
         fprintf(femitc, " LDA T%d\n", left_temp);
         fprintf(femitc, " SUB T%d\n", right_temp);
         
         switch(p->NodeType){
            case astEq:
               fprintf(femitc, " JAZ L%d\n", true_label);
               break;
            case astNotEq:
               fprintf(femitc, " JAN L%d\n", true_label);
               fprintf(femitc, " JAP L%d\n", true_label);
               break;
            case astLess:
               fprintf(femitc, " JAN L%d\n", true_label);
               break;
            case astLeEq:
               fprintf(femitc, " JAN L%d\n", true_label);
               fprintf(femitc, " JAZ L%d\n", true_label);
               break;
            case astGreater:
               fprintf(femitc, " JAP L%d\n", true_label);
               break;
            case astGrEq:
               fprintf(femitc, " JAP L%d\n", true_label);
               fprintf(femitc, " JAZ L%d\n", true_label);
               break;
         }

         fprintf(femitc, " JMP L%d\n", end_label);
         fprintf(femitc, "L%d NOP\n", true_label);
         add_val(1);
         fprintf(femitc, " LDA V1\n");
         fprintf(femitc, " STA T%d\n", result_temp);
         fprintf(femitc, "L%d NOP\n", end_label);
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
      case astProgram: case astMethList: 
      case astBody: case astStmtSeq: case astBlock: 
      case astDecls: case astVarList:
         for(int i=0; i<4; i++){ 
            if(p->pAstNode[i]) CodeGeneration(p->pAstNode[i]); 
         }
         break; 
      case astMethod:{
         char *func_name = p->SymbolNode->name;
         fprintf(femitc, "%s NOP\n", func_name);
         for(int i=0; i<4; i++){ 
            if(p->pAstNode[i]) CodeGeneration(p->pAstNode[i]); 
         }
         break;
      }
      case astExprStmt:{
         AstNode *expr = p->pAstNode[0];
         if(!expr) break;
         if(expr->NodeType==astCall){
            emit_call_stmt(expr);
         } else {
            CodeGeneration(expr);
         }
         break;
      }
      case astReturnStmt:{
         AstNode *expr = p->pAstNode[0];
         if(!expr){
            fprintf(femitc, " LDA RADR\n");
            fprintf(femitc, " LD1 RADR\n");
            fprintf(femitc, " JMP 0,1\n");
         }
         if(expr->NodeType==astCall){
            emit_call_stmt(expr);
            fprintf(femitc, " LDA RVAL\n");
            fprintf(femitc, " LDA RADR\n");
            fprintf(femitc, " LD1 RADR\n");
            fprintf(femitc, " JMP 0,1\n");
         } else {
            int res_temp = genExpr(p->pAstNode[0]);
            fprintf(femitc, " LDA T%d\n", res_temp);
            fprintf(femitc, " STA RVAL\n");
            fprintf(femitc, " LDA RADR\n");
            fprintf(femitc, " LD1 RADR\n");
            fprintf(femitc, " JMP 0,1\n");
         }
         break;
      }
      case astAssign:{
         char *var_label = p->pAstNode[0]->SymbolNode->name;
         int var_num = p->pAstNode[0]->SymbolNode->timi;
         add_var(var_label,var_num);
         int res_temp = genExpr(p->pAstNode[1]);
         fprintf(femitc, " LDA T%d\n", res_temp);
         fprintf(femitc, " STA %s\n", var_label);
         break;
      }
      case astIfElseStmt:{
         int condition=genExpr(p->pAstNode[0]);
         int else_label = new_label();
         int end_label = new_label();

         fprintf(femitc, " LDA T%d\n", condition);
         fprintf(femitc, " JAZ L%d\n", else_label);

         CodeGeneration(p->pAstNode[1]);
         fprintf(femitc, " JMP L%d\n", end_label);

         fprintf(femitc, "L%d NOP\n", else_label);

         if(p->pAstNode[2]){
            CodeGeneration(p->pAstNode[2]);
         }
         fprintf(femitc, "L%d NOP\n", end_label);
         break;
      }
      case astWhileStmt:{
         int start_label = new_label();
         int end_label = new_label();

         fprintf(femitc, "L%d NOP\n", start_label);
         int condition=genExpr(p->pAstNode[0]);
         fprintf(femitc, " LDA T%d\n", condition);
         fprintf(femitc, " JAZ L%d\n", end_label);

         push_loop(end_label);
         CodeGeneration(p->pAstNode[1]);
         pop_loop();

         fprintf(femitc, " JMP L%d\n", start_label);
         fprintf(femitc, "L%d NOP\n", end_label);
         break;
      }
      case astBreakStmt:{
         int loop_end = current_loop();
         if(loop_end!=-1){
            fprintf(femitc, " JMP L%d\n", loop_end);
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
      fprintf(femitc, "START NOP\n");
      fprintf(femitc, " ENTA L0\n");
      fprintf(femitc, " STA RADR\n");
      fprintf(femitc, " JMP main\n");
      fprintf(femitc, "L0 NOP\n");
      fprintf(femitc, " LDA RVAL\n");
      fprintf(femitc, " STA T0\n");
      fprintf(femitc, " HLT\n");

      CodeGeneration(TreeRoot); 

      fprintf(femitc, " ORIG 2000\n");
      fprintf(femitc, "%s", val_buf); // add all the val lines
      fprintf(femitc, "%s", temp_buf); // add all the temp lines
      fprintf(femitc, "%s", var_buf); // add all the var lines
      fprintf(femitc, "RVAL CON 0\n");
      fprintf(femitc, "RADR CON 0\n");
      fprintf(femitc, " END START\n"); 
      fclose(femitc); 
   }
   return 0;
}