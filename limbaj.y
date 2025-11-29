%{
#include <iostream>
#include <vector>
#include <cstring>
#include "SymTable.h"
#include "AST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
class SymTable* classes;
class SymTable* functions;
class SymTable* temp;
std::string current_function;
int errorCount = 0;
std::string current_struct_type;
char error_message[256];
%}
%union {
    struct ASTNode* node;
    int Int;
    float Float;
    char* string;
}
%token  BGIN END ASSIGN IF WHILE FOR LE EQ GE AND OR PRINT TYPEOF BGINF BGINC BGIND ENDF ENDC ENDD STRUCT RETURN REAL FAKE ELSE
%token<string> ID TYPE STRING CHAR NRFLOAT
%type<node> e b boole reality_check
%token<Int> NR
%start progr
%left '+' '-'  
%left '*' '/' 
%left OR
%left AND
%%
progr : sections 
          {                          
          current = new SymTable("main", current); 
          cout << "Am intrat în scope-ul lui main \n";
          }
           main {
               //current->printVars();
               cout << "Am iesit din scope-ul main-ului \n";
               current = current->getParent();
               //current->printVars();
               //current = current->getParent();
               cout << "Am iesit din global\n";
               if (errorCount == 0) cout<< "The program is correct!" << endl;}
      ;

sections : section
          | sections section;

section : globals
          | functions
          | classes;

globals : BGIND { 
                    //cout << "Am intrat în scope-ul variabilelor globale \n";
                } 
          declarations 
          ENDD {
               //current->printVars();             
               //cout << "Am iesit din scope-ul variabilelor global \n";
          }

          ;

declarations : decl           
	      |  declarations decl    
	      ;

classes : BGINC class_declarations ENDC 
          ;

class_declarations : clas
          | class_declarations clas
          ;

clas : STRUCT ID '{'  
                    {
                         current_struct_type = $2;
                         classes->addClass($2,$2);
                         //classes = new SymTable($2, classes); 
                         cout << "Am intrat în scope-ul clasei \"" << $2 << "\"\n";
                    }
     class_members '}' optional_object_decl
     ;

optional_object_decl: ID ';' {   
                                   //current->printVars();
                                   cout << "Am iesit din scope-ul clasei " << current_struct_type << "\n";
                                   //current=current->getParent();
                               if(!current->existsId($1)) {
                                    
                                    current->addClass(current_struct_type.c_str(),$1);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                              }
                    | //epsilon
                         {  
                                   //current->printVars();
                                   cout << "Am iesit din scope-ul clasei " << current_struct_type << " \n";
                         //current=current->getParent();
                         } 
                    ;

class_members : decl_class
                    | func_class
                    | func_class class_members
                    | decl_class class_members

functions : BGINF function_declarations ENDF
          ;

function_declarations : func
          | function_declarations func
          ;

decl_class :     TYPE ID ';' { 
                              if(!classes->existsIdRecursive($2)) {
                                    classes->addClassParam($1,$2,current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
               | TYPE ID ASSIGN boole ';' { 
                              if(!classes->existsIdRecursive($2)) {
                                $4->evaluate();
                                if(strcmp($1,$4->type.c_str())==0){
                                    classes->addClassParam($1,$2,current_struct_type,$4->evaluate());
                                }
                                else{
                                    errorCount++;
                                    yyerror("Can only assign real or fake to bool value");
                                }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
               | TYPE ID ASSIGN e ';' { 
                              if(!classes->existsIdRecursive($2)) {
                                    $4->evaluate();
                                    if(strcmp($1,$4->type.c_str())==0){
                                    classes->addClassParam($1,$2,current_struct_type,$4->evaluate());
                                    }
                                    else{
                                        errorCount++;
                                        yyerror("Can't define variable with a different type of value!");
                                    }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                            delete($4);
                          }

               | TYPE ID '['NR']' ASSIGN '{' call_list '}' ';' { 
                              if(!classes->existsIdRecursive($2)) {
                                    classes->addClassParam($1,$2,current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
               | TYPE ID ',' list_id { 
                              if(!classes->existsIdRecursive($2)) {
                                    classes->addClassParam($1,$2,current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
               | TYPE ID '['NR']' ';'  { 
                              if(!classes->existsIdRecursive($2)) {
                                    classes->addClassParam($1,$2,current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
               | ID ID ASSIGN '{' call_list '}' ';' { 
                              if(!classes->existsIdRecursive($2)) {
                                    classes->addClassParam($1,$2,current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }      
           ;


func_class: TYPE ID  '(' 
                         {        
                            current_function = $2;
                              if(!classes->existsIdRecursive($2)) {
                                   classes->addClassParam($1,$2,current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
                         list_param_class ')' {
                                   classes = new SymTable($2, classes);
                                    cout << "Am intrat in scope-ul funcției \"" << $2 << "\"\n";
                         }
                         optional_function_body_class
                         {   
                              //classes->printVars();             
                              cout << "Am iesit din scope-ul funcției \"" << $2 << "\"\n";
                              classes = classes->getParent(); 
                              }
               ;

optional_function_body_class : '{'  {temp = current; current = classes; } list_class '}' {current = temp;}
                    | ';' //se termina decl functiei

list_class : statement ';'  
     | control  
     | decl 
     | list_func statement ';'  
     | list_func control  
     | list_func decl 
     ;

list_param_class : param_class 
            | list_param_class ','  param_class 
            ;

param_class :  TYPE ID { 
                    classes->addParamsToClassFunc($1,$2,current_struct_type,current_function,"0");
                       
                }  

func:         TYPE ID  '(' 
                         {        
                            current_function = $2;
                            cout<<current_function;
                              if(!functions->existsIdRecursive($2)) {
                                   functions->addFunc($1,$2);
                                    cout << "Am intrat in scope-ul funcției \"" << $2 << "\"\n";
                                    
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
                         list_param ')' {
                                   functions = new SymTable($2, functions);
                         }
                         optional_function_body_func
                         {   
                              functions->printVars();             
                              cout << "Am iesit din scope-ul funcției \"" << $2 << "\"\n";
                              functions = functions->getParent(); 
                              }
               ;

optional_function_body_func : '{'  { temp = current; current = functions;} list_func '}' {current = temp;}
                    | ';' //se termina decl functiei

list_func : statement ';'  
     | control  
     | decl 
     | list_func statement ';'  
     | list_func control  
     | list_func decl 
     ;

decl       :     TYPE ID ';' { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
               | TYPE ID ASSIGN boole ';' { 
                              if(!current->existsId($2)) {
                                $4->evaluate();
                                if(strcmp($1,$4->type.c_str())==0){
                                    current->addVar($1,$2,$4->evaluate());
                                }
                                else{
                                    errorCount++;
                                    yyerror("Can only assign real or fake to bool value");
                                }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
               | TYPE ID ASSIGN e ';' { 
                              if(!current->existsId($2)) {
                                    $4->evaluate();
                                    if(strcmp($1,$4->type.c_str())==0){
                                        current->addVar($1,$2,$4->evaluate());
                                    }
                                    else{
                                        errorCount++;
                                        yyerror("Can't define variable with a different type of value!");
                                    }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                            delete($4);
                          }
     
               | TYPE ID '['NR']' ASSIGN '{' call_list '}' ';' { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
               | TYPE ID ',' list_id { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
               | TYPE ID '['NR']' ';'  { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
               | ID ID ASSIGN '{' call_list '}' ';' { 
                              if(!current->existsId($2)) {
                                    current->addVar($1,$2);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }      
           ;

list_id :   ID ',' list_id
          | ID ';' 

list_param :  param 
            | list_param ','  param 
            ;
            
param : TYPE ID { 
                    functions->addFuncParam($1,$2,current_function);
                }      
      ; 
      

main : BGIN list END  
     ;
     

list :  statement ';' 
     | control
     | decl
     | list statement ';'
     | list control 
     | list decl 
     ;

control : IF '(' boole ')' '{' 
                                   {current = new SymTable("if block", current); 
                                   cout << "Am intrat în scope-ul unui if block \n";}
                              
                               list 
                              
                                   {//current->printVars();             
                                   cout << "Am iesit din scope-ul if block-ului\n";
                                   current = current->getParent();}
                              '}' optional_else
          
          | WHILE '(' boole ')' '{'
                                        {current = new SymTable("while block", current); 
                                        cout << "Am intrat în scope-ul unui while block \n";}
                                   list
                                        {//current->printVars();             
                                        cout << "Am iesit din scope-ul while block-ului\n";
                                        current = current->getParent();}
                                '}'
          
          | FOR '('  
                         {current = new SymTable("for block", current); 
                         cout << "Am intrat în scope-ul unui for block \n";}
               for_init  boole ';' statement ')' '{' list  '}'
                          {//current->printVars();   
                         cout << "Am iesit din scope-ul for block-ului\n";
                          current = current->getParent();}
          ;

optional_else : ELSE '{' {
                    current = new SymTable("else block", current); 
                   cout << "Am intrat în scope-ul unui else block \n";
            }
            list '}'{
               cout << "Am iesit din scope-ul else block-ului\n";
                current = current->getParent();
            }
            | ELSE statement ';'
            | //epsilon
            ;

for_init: statement ';'
          |decl
          ;

statement:  ID ASSIGN e {
        $3->evaluate();
        if(current->getRoot() == "global"){
            if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Variable used before definition");
            }
          else {
            if($3->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid");
            }
            else{
                if(current->getType($1) == $3->type ){
                    current->changeValue($1, $3->evaluate());
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!",current->getType($1).c_str(),$3->type.c_str());
                    yyerror(error_message);
                }
            }
          }
        }
        else if(current->getRoot() == "functions"){
            if(temp->existsIdRecursive($1)){
                if(temp->getType($1) == $3->type){
                    temp->changeValue($1,$3->evaluate());
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!",current->getType($1).c_str(),$3->type.c_str());
                    yyerror(error_message);
                }            }
            if(!current->existsIdFunction($1,current_function)){
              errorCount++;
              yyerror("Variable used before definition");
            }
            else{
                if(current->getTypeFunction($1,current_function) == $3->type){
                   current->changeValueFunction($1,$3->evaluate(),current_function);
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!", $3->type.c_str(), current->getTypeFunction($1,current_function).c_str());
                    yyerror(error_message);
                }
            }
        }
        else if(current->getRoot() == "classes"){
            if(current->existsIdInClass($1, current_struct_type)){
                if(current->getTypeInClass($1,current_struct_type) == $3->type){
                    current->changeValueInClass($1,$3->evaluate(),current_struct_type);
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!", $3->type.c_str(), current->getTypeInClass($1,current_struct_type).c_str());
                    yyerror(error_message);
                }
            }
            else if(current->existsIdInClassFunc($1, current_struct_type,current_function)){
                if(current->getTypeInClassFunc($1,current_struct_type,current_function) == $3->type){
                    //current->changeValueInClassFunc($1,$3->evaluate(),current_struct_type,current_function);
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!", $3->type.c_str(), current->getTypeInClassFunc($1,current_struct_type,current_function).c_str());
                    yyerror(error_message);
                }
            }
            else{
                errorCount++;
                yyerror("Variable used before definition");
            }
        }
    
            delete($3);
}
          | ID ASSIGN boole {if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Variable used before definition");
          }
        else {
            if($3->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid");
            }
            else{
                if(current->getType($1) == $3->type ){
                    current->changeValue($1, $3->evaluate());
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!\n",current->getType($1).c_str(),$3->type.c_str());
                    yyerror(error_message);
                }
            }
            delete($3);
          }
      }
        
          | ID '(' call_list ')' {
            if(!classes->existsIdInClass($1,current_struct_type) && !functions->existsIdRecursive($1)){

              errorCount++;
              yyerror("Function used before definition");
            }

      }
          | PRINT '(' boole ')' {
            if($3->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                printf("Value of expression is %s\n", $3->evaluate().c_str());
                delete($3);
            }
          }
          | PRINT '(' e ')' {
            if($3->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                printf("Value of expression is %s\n", $3->evaluate().c_str());
                delete($3);
            }
            
            
          }
          | TYPEOF '(' boole ')' {
            if($3->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                std::cout << "Value of expression is " << $3->evaluate() << " and type is " << $3->type << std::endl;
                delete($3);
            }
          }
          | TYPEOF '(' e ')'{
            if($3->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                std::cout << "Value of expression is " << $3->evaluate() << " and type is " << $3->type << std::endl;
                delete($3);
            }
          }
          | ID '[' NR ']' ASSIGN e {
          if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Array used before definition");
          }
                  else {
            if($6->evaluate() == "invalid"){
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
            current->changeValue($1, $6->evaluate());
            delete($6);
            }
          }
      }
          | ID '[' NR ']' ASSIGN boole  {
          if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Array used before definition");
          }
                  else {
            if($6->evaluate() == "invalid"){
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
            current->changeValue($1, $6->evaluate());
            delete($6);
            }
          }
      }
          | ID '@' ID {
          if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Object used before definition");
          }
          if (!current->existsIdRecursive($3)) {
              errorCount++;
              yyerror("Member used before definition");
          }
      }
          | ID '@' ID ASSIGN e {
          if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Object used before definition");
          }
          else if (!current->existsIdRecursive($3)) {
              errorCount++;
              yyerror("Member used before definition");
          }
          else {
                if($5->evaluate() == "invalid"){
                    errorCount++;
                    yyerror("Expression is invalid");
                }
                else{
                    current->changeValue($1, $5->evaluate());
                    delete($5);
                }
          }
      }
          | ID '@' ID ASSIGN boole {
          if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Object used before definition");
              current->changeValue($1, $5->evaluate());
          }
          else if (!current->existsIdRecursive($3)) {
              errorCount++;
              yyerror("Member used before definition");
          }
          else {
                if($5->evaluate() == "invalid"){
                    errorCount++;
                    yyerror("Expression is invalid");
                }
                else{
                    current->changeValue($1, $5->evaluate());
                    delete($5);
                }
          }
      }
          | ID '@' ID '(' call_list ')' {
          if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Object used before definition");
          }
          if (!current->existsIdRecursive($3)) {
              errorCount++;
              yyerror("Method used before definition");
          }
      }
          | RETURN anye
         ;

e : e '+' e    {/*$$=$1+$3; */$$ = new ASTNode($1,$3); $$->value = "+"; }
  | e '*' e    {/*$$=$1*$3;*/$$ = new ASTNode($1, $3); $$->value = "*"; }
  | e '-' e    {/*$$ = $1-$3;*/ $$ = new ASTNode($1, $3); $$ -> value = "-"; }
  | e '/' e    {/*$$ = $1/$3;*/ $$ = new ASTNode($1, $3); $$ -> value = '/'; }
  |'(' e ')'   {/*$$= $2;*/ $$ = $2;    }
  | STRING     { $$ = new ASTNode($1, "string");}
  | CHAR       { $$ = new ASTNode($1, "char");}
  | NR         {/*$$=$1;*/  $$ = new ASTNode($1,"int"); }
  | NRFLOAT    {/*$$=$1;*/  $$ = new ASTNode($1,"float"); }
  | ID         { 
    if(current->getRoot() == "global"){
        if (!current->existsIdRecursive($1)) {
              errorCount++;
              snprintf(error_message,256,"Variable used before definition:%s", $1);
              $$ = new ASTNode("invalid","null");
              yyerror(error_message);
        }
        else if(current->getValueAsString($1) == "invalid"){
            errorCount++;
            snprintf(error_message,256,"Use of variable %s with invalid value!", $1);
              $$ = new ASTNode("invalid","null");
                yyerror(error_message);
        }
        else{
            $$ = new ASTNode(current->getValueAsString($1), current->getType($1));
        }
    }
    else if(current->getRoot() == "functions"){
        if(temp->existsIdRecursive($1)){
            if(temp->getValueAsString($1) == "invalid"){
                errorCount++;
                snprintf(error_message,256,"Use of variable %s with invalid value!", $1);
                $$ = new ASTNode("invalid","null");
                yyerror(error_message);
            }
            else{
                $$ = new ASTNode(temp->getValueAsString($1), temp->getType($1));
            }
        }
        else if(!current->existsIdFunction($1,current_function)){
              errorCount++;
              snprintf(error_message,256,"Variable used before definitions:%s", $1);
              $$ = new ASTNode("invalid","null");
              yyerror(error_message);
        }
        else if(current->getValueFunction($1,current_function) == "invalid"){
            errorCount++;
            snprintf(error_message,256,"Use of variable %s with invalid value!", $1);
            $$ = new ASTNode("invalid","null");
            yyerror(error_message);
        }
        else{
            $$ = new ASTNode(current->getValueFunction($1, current_function), current->getTypeFunction($1,current_function));
        }
    }
    else if(current->getRoot() == "classes"){
            if(current->getValueInClass($1,current_struct_type) == "invalid") {
                errorCount++;
                snprintf(error_message,256,"Use of variable %s with invalid value!", $1);
                $$ = new ASTNode("invalid", "null");
                yyerror(error_message);
            }
            else{
                if(current->existsIdInClass($1,current_struct_type)){
                    $$ = new ASTNode(current->getValueInClass($1, current_struct_type), current->getTypeInClass($1,current_struct_type));
                }
                else if (current->existsIdInClassFunc($1, current_struct_type, current_function)){
                    $$ = new ASTNode("0", "int");
                }
                else {
                    errorCount++;
                snprintf(error_message,256,"Use of uninitialized variable %s", $1);
                $$ = new ASTNode("invalid","null");
                yyerror(error_message);
                }
            }
    }
}
  
  | ID '(' call_list ')' {
        if(strcmp($1,current_function.c_str()) == 0){
            $$ = new ASTNode(1, functions->getType($1));
        }
        else if (!functions->existsIdRecursive($1) && !classes->existsIdInClass($1,current_struct_type)) {
              errorCount++;
              yyerror("Variable used before definition");
            $$ = new ASTNode("invalid","null");
          }
          else {
            $$ = new ASTNode(1, functions->getType($1));
            }
  }
  | ID '@' ID  {
            if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Variable used before definition");
              $$ = new ASTNode("invalid","null");            }
            else {
                //cout<<"!!!!!!!!!!!!1"<<$3<< ' '<<current->getType($1)<<endl;
                if(classes->existsIdInClass($3,current->getType($1))){
                    $$ = new ASTNode(1, classes->getTypeInClass($3,current->getType($1)));
                }
                else{
                    errorCount++;
                    yyerror("Variable not in class");
              $$ = new ASTNode("invalid","null");                }
            }
            } 
    | ID '[' NR ']' {
        if (!current->existsIdRecursive($1)) {
              errorCount++;
              yyerror("Variable used before definition");
          }
         $$ = new ASTNode(1, current->getType($1));
         }
  //De facut sa verifice daca exista in clasa $1.
  
  ;
  
b : e '<' e { 
        $$ = new ASTNode($1,$3); $$->value = "<"; 
  }
  | e '>' e { 
    $$ = new ASTNode($1,$3); $$->value = ">";   
    }
  | e EQ e  { 
    $$ = new ASTNode($1,$3); $$->value = "==";   }
  | e LE e  { 
    $$ = new ASTNode($1,$3); $$->value = "<=";   }
  | e GE e  { 
    $$ = new ASTNode($1,$3); $$->value = ">=";   }
  | e EQ reality_check { $$ = new ASTNode($1,$3); $$->value = "==";}
  | reality_check EQ e { $$ = new ASTNode($1,$3); $$->value = "==";}
  | REAL    {    $$ = new ASTNode("real","bool");  }
  | FAKE    {  $$ = new ASTNode("fake","bool");   }
  ;

reality_check :  REAL    {    $$ = new ASTNode("real","bool");  }
            | FAKE    {  $$ = new ASTNode("fake","bool");   }

boole : boole OR boole { 
    $$ = new ASTNode($1,$3); $$->value = "||";
        }
      | boole AND boole {
    $$ = new ASTNode($1,$3); $$->value = "&&";
        }
      | b {
            $$ = $1;
        }
      | '(' boole ')' {
            $$ = $2;
        }
      ;
        
call_list : e 
          | boole 
          | call_list ',' boole
          | call_list ',' e
          | //epsilon 
          { if(current->getRoot() == "global"){
            cout<<current->ids[current_function].params.parameters.size()<<endl;
            if(current->ids[current_function].params.parameters.size() != 0){
                errorCount++;
                yyerror("Invalid function call");
            }
            }
          }
            | call_list ',' {
            if(current->getRoot() == "global"){
                if(functions->ids[current_function].params.parameters.size() != 0){
                    errorCount++;
                    yyerror("Invalid function call");
                }   
            }
            else if(current->getRoot() == "functions" || current->getRoot() == "classes"){
                errorCount++;
                yyerror("Cannot declare function without a variable at the end");
            }
            }
           ;

anye : boole
     | e
     ;
%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     ofstream fout("SymTables.txt",std::ios::trunc);
     yyin=fopen(argv[1],"r");
     current = new SymTable("global",nullptr);
     classes = new SymTable("classes",nullptr);
     functions = new SymTable("functions", nullptr);
     cout << "Am intrat in scope-ul global\n";
     yyparse();
     current->printVars();
     classes->printVars();
     functions->printVars();
     delete current;
     delete classes;
     delete functions;
}