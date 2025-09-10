#include <stdio.h> 
#include <stdlib.h> 
#include "defs.h" 
#include "syd.tab.h" 

#define LOOP_MAX 1000

extern AstNode *TreeRoot; 
int yyparse(); 

FILE *femitc; 
char val_buf[8192]="";
char temp_buf[8192]="";
char var_buf[8192]="";

static void CodeGeneration(AstNode *p);
static void add_var(char *name, int v);

static int max_argument_count=0;
static int argument_count=0;

static int param_count=0;

static char *current_method_name=NULL;

static int val_array[1000];
static int val_count=0;

static int temp_array[1000];
static int temp_count=0;

static char *var_array[1000];
static int var_count=0;

static int loop_stack[LOOP_MAX];
static int loop_stack_top=-1;

static int label_count=0;

static void proccessParams(AstNode *p){
   if(!p) return;
   if(p->NodeType==astParam){
      if(p->SymbolNode&&p->SymbolNode->name){
         char *param_name=p->SymbolNode->name;
         char new_name[256];
         snprintf(new_name, sizeof(new_name), "%s%s", current_method_name, param_name);
         add_var(strdup(new_name),0);
         fprintf(femitc, " LDA A%d\n", param_count++);
         fprintf(femitc, " STA %s\n", new_name);
      }
   }
   for(int i=0; i<4; i++){
      if(p->pAstNode[i]){
         proccessParams(p->pAstNode[i]);
      }
   }
}

static int new_label(){
   return label_count++;
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
         argument_count=0;
         if(p->pAstNode[1]){
            CodeGeneration(p->pAstNode[1]);
         }
         if(argument_count>max_argument_count){
            max_argument_count=argument_count;
         }

         int radr_temp = new_temp();
         fprintf(femitc, " LDA RADR\n");
         fprintf(femitc, " STA T%d\n", radr_temp);

         int ret_label = new_label();
         fprintf(femitc, " ENTA L%d\n", ret_label);
         fprintf(femitc, " STA RADR\n");
         char *method_name= p->pAstNode[0]->SymbolNode->name;
         fprintf(femitc, " JMP %s\n", method_name);
         fprintf(femitc, "L%d NOP\n", ret_label);
         fprintf(femitc, " LDA T%d\n", radr_temp);
         fprintf(femitc, " STA RADR\n");
         int ret_temp = new_temp();
         fprintf(femitc, " LDA RVAL\n");
         fprintf(femitc, " STA T%d\n", ret_temp);
         return ret_temp;
      }
      case astId:{
         char new_name[256];
         snprintf(new_name, sizeof(new_name), "%s%s", current_method_name, p->SymbolNode->name);
         int temp = new_temp();
         fprintf(femitc, " LDA %s\n", new_name);
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

         fprintf(femitc," JAZ DZ\n");

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
         fprintf(femitc," JMP NDZ\n");

         fprintf(femitc,"DZ NOP\n");
         fprintf(femitc," OUT DZMSG(19)\n");
         fprintf(femitc," HLT\n");

         fprintf(femitc, "NDZ NOP\n");

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
         current_method_name = p->SymbolNode->name;
         fprintf(femitc, "%s NOP\n", p->SymbolNode->name);
         if(p->pAstNode[0]){
            param_count=0;
            proccessParams(p->pAstNode[0]);
         }
         if(p->pAstNode[1]){
            CodeGeneration(p->pAstNode[1]);
         }
         break;
      }
      case astArgs:{
         for(int i=0; i<4; i++){ 
            AstNode *arg = p->pAstNode[i];
            if(!arg) continue;
            if(arg->NodeType==astArgs){
               CodeGeneration(arg);
               continue;
            }
            if(arg->NodeType==astId){
               char *var_name=arg->SymbolNode->name;
               char new_name[256];
               snprintf(new_name, sizeof(new_name), "%s%s", current_method_name, var_name);
               fprintf(femitc, " LDA %s\n", new_name);
            } else if(arg->NodeType==astDecimConst){
               int val=arg->SymbolNode->timi;
               add_val(val);
               if(val>=0)
                  fprintf(femitc, " LDA V%d\n", val);
               else
                  fprintf(femitc, " LDA N%d\n", -val);
            } else{
               int arg_temp = genExpr(arg);
               fprintf(femitc, " LDA T%d\n", arg_temp);
            }
            fprintf(femitc, " STA A%d\n", argument_count++);
         }
         break;
      }
      case astExprStmt:{
         if(p->pAstNode[0]){
            CodeGeneration(p->pAstNode[0]);
         }
         break;
      }
      case astReturnStmt: 
         int res_temp = genExpr(p->pAstNode[0]);
         fprintf(femitc, " LDA T%d\n", res_temp);
         if(strcmp(current_method_name, "main")!=0){
            fprintf(femitc, " STA RVAL\n");
            fprintf(femitc, " LDA RADR\n");
            fprintf(femitc, " LD1 RADR\n");
            fprintf(femitc, " JMP 0,1\n"); 
         }
         break;
      case astAssign:{
         char new_name[256];
         snprintf(new_name, sizeof(new_name),"%s%s", current_method_name, p->pAstNode[0]->SymbolNode->name);
         int var_num = p->pAstNode[0]->SymbolNode->timi;
         add_var(strdup(new_name),var_num);
         int res_temp = genExpr(p->pAstNode[1]);
         fprintf(femitc, " LDA T%d\n", res_temp);
         fprintf(femitc, " STA %s\n", new_name);
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
      int mi=methodidx("main");
      if(mi==-1){
         error_message("Syntax Error","need to have main method",NULL);
      }
      if(mt[mi].param_count != 0){
         error_message("Syntax Error","main cannot have parameters",NULL);
      }
      if(error_count==0){
		   printAST(TreeRoot, -3);
      
         femitc = fopen("output.mixal", "w"); 
         if(!femitc){ 
            fprintf(stderr, "Cannot open output.mixal for writing\n"); 
            return 1; 
         } 
         fprintf(femitc, " ORIG 1000\n"); 

         CodeGeneration(TreeRoot); 

         fprintf(femitc, " HLT\n");
         fprintf(femitc, " ORIG 2000\n");
         fprintf(femitc, "%s", val_buf); // add all the val lines
         fprintf(femitc, "%s", temp_buf); // add all the temp lines
         fprintf(femitc, "%s", var_buf); // add all the var lines
         fprintf(femitc, "RVAL CON 0\n"); 
         fprintf(femitc, "RADR CON 0\n"); 
         for(int i=0;i<max_argument_count;i++){
            fprintf(femitc, "A%d CON 0\n", i);
         }
         fprintf(femitc,"DZMSG ALF RUNTI\n");
         fprintf(femitc," ALF ME ER\n");
         fprintf(femitc," ALF ROR: \n");
         fprintf(femitc," ALF DIVIS\n");
         fprintf(femitc," ALF ION B\n");
         fprintf(femitc," ALF Y ZER\n");
         fprintf(femitc," ALF O    \n");
         fprintf(femitc, " END main\n"); 
         fclose(femitc);
      } else {
         fprintf(stderr, "There were %d errors. No code generated.\n", error_count);
         return 1;
      }
   } 
   return 0;
}