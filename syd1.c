#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "syd.tab.h"

#define MAX_LOOP 32
static const char* loop_end_lbls[MAX_LOOP];
static int loop_depth=0;

extern AstNode *TreeRoot;
int yyparse();

FILE *femitc;

static void CodeGeneration(AstNode *p);

static int lbl_counter=0;
// Generates a unique label every time it is called
static const char* new_label(const char *prefix){
   static char name[32];
   snprintf(name,sizeof(name),"%s-%d",prefix,++lbl_counter);
   return name;
}

void emit(const char *op,const char *arg)
{
   if(arg && arg[0]!='\0')
      fprintf(femitc," %s %s\n",op,arg);
   else
      fprintf(femitc," %s\n",op);
}

static void BinOp(const char *op,AstNode *p){
   CodeGeneration(p->pAstNode[0]);
   emit("STA","TEMP");
   CodeGeneration(p->pAstNode[1]);
   emit(op,"TEMP");
}

static void ProcessProgram(AstNode *p);
static void ProcessMethList(AstNode *p);
static void ProcessMethod(AstNode *p);
static void ProcessBody(AstNode *p);
static void EmitDecls(AstNode *p);
static void ProcessDecls(AstNode *p);
static void ProcessStmtSeq(AstNode *p);
static void ProcessExprStmt(AstNode *p);


void ProcessDecimConst(AstNode *p){
   fprintf(femitc," LDA =%s=\n",p->SymbolNode->name);
}

void ProcessId(AstNode *p){
   fprintf(femitc," LDA %s\n",p->SymbolNode->name);
}

void ProcessAdd(AstNode *p) {BinOp("ADD", p);}

void ProcessSub(AstNode *p) {BinOp("SUB", p);}

void ProcessMult(AstNode *p) {BinOp("MUL", p);}

void ProcessDiv(AstNode *p) {BinOp("DIV", p);}

static void ProcessRelop(AstNode *p){
   const char *trueLbl=new_label("TRUE");
   const char *endLbl=new_label("END");

   CodeGeneration(p->pAstNode[0]);
   emit("STA","TEMP");
   CodeGeneration(p->pAstNode[1]);
   emit("CMPA","TEMP");

   switch(p->NodeType){
      case astEq: emit("JEQ",trueLbl); break;
      case astNotEq: emit("JNE",trueLbl); break;
      case astLess: emit("JLT",trueLbl); break;
      case astLeEq: emit("JLE",trueLbl); break;
      case astGreater: emit("JGT",trueLbl); break;
      case astGrEq: emit("JGE",trueLbl); break;
      default: break;
   }

   fprintf(femitc," LDA =0=\n");
   fprintf(femitc," JMP %s\n",endLbl);
   fprintf(femitc," %s ENTA 1\n",trueLbl);
   fprintf(femitc," NOP\n",endLbl);
}

void ProcessAssign(AstNode *p){
   CodeGeneration(p->pAstNode[1]);
   fprintf(femitc," STA %s\n",p->pAstNode[0]->SymbolNode->name);  
}

static void ProcessReturn(AstNode *p){
   if(p->pAstNode[0]) CodeGeneration(p->pAstNode[0]);
   emit("HLT","");
}

static void ProcessExprStmt(AstNode *p){
   if(p->pAstNode[0]) CodeGeneration(p->pAstNode[0]);
}

static void ProcessStmtSeq(AstNode *p){
   if(!p) return;
   if(p->pAstNode[0]) CodeGeneration(p->pAstNode[0]);
   if(p->pAstNode[1]) ProcessStmtSeq(p->pAstNode[1]);
}

static void ProcessIfElse(AstNode *p){
   const char *elseLbl=new_label("ELSE");
   const char *endLbl=new_label("ENDIF");

   CodeGeneration(p->pAstNode[0]);
   emit("STA","TEMP");
   fprintf(femitc," LDA TEMP\n");
   fprintf(femitc," JZ %s\n",elseLbl);

   CodeGeneration(p->pAstNode[1]);
   fprintf(femitc," JMP %s\n",endLbl);

   fprintf(femitc," %s NOP\n",elseLbl);
   if(p->pAstNode[2]) CodeGeneration(p->pAstNode[2]);

   fprintf(femitc," %s NOP\n",endLbl);
}

static void ProcessWhile(AstNode *p){
   const char *startLbl=new_label("WHILE");
   const char *endLbl=new_label("ENDW");

   loop_end_lbls[loop_depth++]=endLbl;

   fprintf(femitc,"%s NOP\n",startLbl);
   CodeGeneration(p->pAstNode[0]);
   emit("STA","TEMP");
   fprintf(femitc," LDA TEMP\n");
   fprintf(femitc," JZ %s\n",endLbl);

   CodeGeneration(p->pAstNode[1]);
   fprintf(femitc," JMP %s\n",startLbl);

   fprintf(femitc," %s NOP\n",endLbl);
   loop_depth--;
}

static void ProcessBreak(){
   if(loop_depth>0){
      fprintf(femitc," JMP %s\n",loop_end_lbls[loop_depth-1]);
   }
}

static void EmitDecls(AstNode *p){
   if(!p) return;
   if(p->NodeType==astDecls){
      AstNode *var=p->pAstNode[0];
      if(var && var->NodeType==astVarList){
         AstNode *temp=var->pAstNode[0];
         if(temp && temp->NodeType==astAssign){
            CodeGeneration(temp->pAstNode[0]);
         }
      }
   }
}

static void ProcessBody(AstNode *p){
   EmitDecls(p->pAstNode[0]);
   if(p->pAstNode[1]) CodeGeneration(p->pAstNode[1]);
}

static void ProcessMethod(AstNode *p){
   if(p->SymbolNode && strcmp(p->SymbolNode->name,"main")==0){
      ProcessBody(p->pAstNode[0]);
   }
}

static void ProcessMethList(AstNode *p){
   if(!p) return;
   if(p->NodeType==astMethList){
      if (p->pAstNode[0]) ProcessMethod(p->pAstNode[0]); 
      if (p->pAstNode[1]) ProcessMethList(p->pAstNode[1]); 
   } else {
      ProcessMethod(p);
   }
}

static void ProcessProgram(AstNode *p){
   if(p->pAstNode[0]) ProcessMethList(p->pAstNode[0]);
}

void CodeGeneration(AstNode *p){
   if(!p) return;
   switch (p->NodeType) {
      case astProgram: ProcessProgram(p); break;
      case astMethList: ProcessMethList(p); break;
      case astMethod: ProcessMethod(p); break;
      case astBody: ProcessBody(p); break;
      case astDecls: break;
      case astVarList: break;
      case astStmtSeq: ProcessStmtSeq(p); break;
      case astExprStmt: ProcessExprStmt(p); break;
      case astReturnStmt: ProcessReturn(p); break;
      case astIfElseStmt: ProcessIfElse(p); break;
      case astWhileStmt: ProcessWhile(p); break;
      case astBreakStmt: ProcessBreak(); break;
      case astDecimConst: ProcessDecimConst(p); break;
      case astId: ProcessId(p); break;
      case astAdd: ProcessAdd(p); break;
      case astSub: ProcessSub(p); break;
      case astMult: ProcessMult(p); break;
      case astDiv: ProcessDiv(p); break;
      case astAssign: ProcessAssign(p); break;
      case astEq: case astNotEq: case astLess: case astLeEq: case astGreater: case astGrEq: ProcessRelop(p); break;
      default: 
         break;
   }
}

int main(){
   if(yyparse()==0){
      femitc=fopen("output.mix","w");

      fprintf(femitc," ORIG 1000\n");
      fprintf(femitc," TEMP CON 0\n");

      CodeGeneration(TreeRoot);

      fprintf(femitc," HLT\n");
      fprintf(femitc," END\n");

      fclose(femitc);
   }
   return 0;
}

