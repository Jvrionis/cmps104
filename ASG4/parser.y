%{
//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg4
//--------------------------------------------------------------------
// Dummy parser for scanner project.
#include <cassert>
#include "lyutils.h"
#include "astree.h"
%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_TRUE TOK_FALSE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT 

%token TOK_PARAMLIST TOK_DECLID TOK_BINOP TOK_UNOP TOK_VARDECL 
%token TOK_FUNCTION TOK_PROTOTYPE TOK_INDEX 
%token TOK_NEWSTRING TOK_RETURNVOID

%right TOK_IF TOK_ELSE
%right '='
%left TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left '+' '-'
%left '*' '/' '%'
%right TOK_POS TOK_NEG '!' TOK_NEW TOK_ORD TOK_CHR
%left TOK_ARRAY TOK_FIELD TOK_FUNCTION
%left '[' '.'

%nonassoc '('

%start start

%%
  
start     : program             { parser::root = $1; }
          ;

program   : program structdef   { $$ = $1->adopt($2); } 
          | program function    { $$ = $1->adopt($2); }
          | program statement   { $$ = $1->adopt($2); }
          | program error '}'   { $$ = $1; }
          | program error ';'   { $$ = $1; }
          |                     { $$ = new_parseroot(); }
          ;

structdef : TOK_STRUCT TOK_IDENT '{' fdeclist '}' 
                                { 
                                  destroy($5); 
                                  $3->adopt($4);
                                  $2->swap_sym(TOK_TYPEID);
                                  $$ = $1->adopt($2,$3); 
                                }
          | TOK_STRUCT TOK_IDENT '{' '}'
                                { 
                                  destroy($4); 
                                  $2->swap_sym(TOK_TYPEID);
                                  $$ = $1->adopt($2,$3); 
                                }
          ;

fdeclist  : fdeclist fielddecl ';'     
                                {
                                  destroy($3); 
                                  $$ = $1->adopt($2);
                                }
          | fielddecl ';'       {destroy($2); $$ = $1;}
          ;

fielddecl : basetype TOK_ARRAY TOK_IDENT
                                { 
                                  $3->swap_sym(TOK_FIELD);
                                  $$ = $2->adopt($1,$3); 
                                }
          | basetype TOK_IDENT  
                                { 
                                  $2->swap_sym(TOK_FIELD);
                                  $$ = $1->adopt($2); 
                                }
          ;

basetype  : TOK_VOID            { $$ = $1; }
          | TOK_INT             { $$ = $1; }
          | TOK_CHAR            { $$ = $1; }
          | TOK_STRING          { $$ = $1; }
          | TOK_IDENT           { 
                                  $1->swap_sym(TOK_TYPEID);
                                  $$ = $1; 
                                }
          ;

function  : identdecl '(' idecllist ')' block     
                                { 
                                  destroy($4); 
                                  $2->swap_sym(TOK_PARAMLIST);
                                  $2->adopt($3); 
                                  $$ = new_node($1,TOK_FUNCTION);
                                  $$ = $$->adopt($1,$2,$5); 
                                }
          | identdecl '(' idecllist ')' ';'       
                                { 
                                  destroy($4,$5);
                                  $2->swap_sym(TOK_PARAMLIST); 
                                  $2->adopt($3); 
                                  $$ = new_node($1,TOK_PROTOTYPE);
                                  $$ = $$->adopt($1,$2); 
                                }
          | identdecl '(' ')' block               
                                { destroy($3); 
                                  $2->swap_sym(TOK_PARAMLIST); 
                                  $$ = new_node($1,TOK_FUNCTION);
                                  $$ = $$->adopt($1,$2,$4); 
                                }
          | identdecl '(' ')' ';'                 
                                { 
                                  destroy($3,$4); 
                                  $2->swap_sym(TOK_PARAMLIST); 
                                  $$ = new_node($1,TOK_PROTOTYPE);
                                  $$ = $$->adopt($1,$2); 
                                }
          ;

idecllist : idecllist ',' identdecl    
                                { 
                                  destroy($2); 
                                  $$ = $1->adopt($3); 
                                }
          | identdecl           { $$ = $1;  }
          ;

identdecl : basetype TOK_ARRAY TOK_IDENT
                                { 
                                  $3->swap_sym(TOK_DECLID);
                                  $$ = $2->adopt($1,$3); 
                                }
          | basetype TOK_IDENT  
                                { 
                                  $2->swap_sym(TOK_DECLID);
                                  $$ = $1->adopt($2); 
                                }
          ;

block     : '{' smtlist '}'     { 
                                  destroy($3); 
                                  $1->swap_sym(TOK_BLOCK);
                                  $$ = $1->adopt($2); 
                                }
          | '{' '}'             { 
                                  destroy($2); 
                                  $1->swap_sym(TOK_BLOCK);
                                  $$ = $1; 
                                }
          ;

smtlist   : smtlist statement   { $$ = $1->adopt($2); }
          | statement           { $$ = $1;  }
          ;

statement : block               { $$ = $1; }
          | vardecl             { $$ = $1; }
          | while               { $$ = $1; }
          | ifelse              { $$ = $1; }
          | return              { $$ = $1; }
          | expr ';'            { destroy($2); $$ = $1;  }
          | ';'                 { $$ = $1; }
          ;

vardecl   : identdecl '=' expr ';'     
                                { 
                                  destroy($4); 
                                  $2->swap_sym(TOK_VARDECL);
                                  $$ = $2->adopt($1,$3); 
                                }
          ;

while     : TOK_WHILE '(' expr ')' statement      
                                { 
                                  destroy($2,$4); 
                                  $$ = $1->adopt($3,$5); 
                                }
          ;

ifelse    : TOK_IF '(' expr ')' statement TOK_ELSE statement 
                                            %prec TOK_ELSE         
                                { 
                                  destroy($2,$4,$6); 
                                  $1->swap_sym(TOK_IFELSE);
                                  $$ = $1->adopt($3,$5,$7); 
                                }
          | TOK_IF '(' expr ')' statement         
                                { 
                                  destroy($2,$4); 
                                  $$ = $1->adopt($3,$5); 
                                }
          ;

return    : TOK_RETURN expr ';' { 
                                  destroy($3); 
                                  $$ = $1->adopt($2); 
                                }
          | TOK_RETURN ';'      { 
                                  destroy($2); 
                                  $1->swap_sym(TOK_RETURNVOID);
                                  $$ = $1; 
                                }
          ;

expr      : expr binop expr     { $$ = $2->adopt($1,$3); }
          | unop expr           { $$ = $1->adopt($2); }
          | allocator           { $$ = $1; }
          | call                { $$ = $1; }
          | '(' expr ')'        { 
                                  destroy($1,$3); 
                                  $$ = $2; 
                                }
          | variable            { $$ = $1; }
          | constant            { $$ = $1; }
          ; 

binop     : TOK_EQ              { $$ = $1; }
          | TOK_NE              { $$ = $1; }
          | TOK_LT              { $$ = $1; }
          | TOK_LE              { $$ = $1; }
          | TOK_GT              { $$ = $1; }
          | TOK_GE              { $$ = $1; }
          | '+'                 { $$ = $1; }
          | '-'                 { $$ = $1; }
          | '*'                 { $$ = $1; }
          | '/'                 { $$ = $1; }
          | '%'                 { $$ = $1; }
          | '='                 { $$ = $1; }
          ;

unop      : '+'                 { $$ = $1->swap_sym(TOK_POS); }
          | '-'                 { $$ = $1->swap_sym(TOK_NEG); }
          | '!'                 { $$ = $1; }   
          | TOK_NEW             { $$ = $1; }  
          | TOK_ORD             { $$ = $1; }  
          | TOK_CHR             { $$ = $1; }
          ;

allocator : TOK_NEW TOK_IDENT '(' ')'  
                                { 
                                  destroy($3,$4); 
                                  $1->swap_sym(TOK_NEW);
                                  $2->swap_sym(TOK_TYPEID);
                                  $$ = $1->adopt($2); 
                                }
          | TOK_NEW TOK_STRING  '(' expr ')'      
                                { 
                                  destroy($2,$3,$5); 
                                  $1->swap_sym(TOK_NEWSTRING);
                                  $$ = $1->adopt($4); 
                                }
          | TOK_NEW basetype  '[' expr ']'        
                                { 
                                  destroy($3,$5); 
                                  $1->swap_sym(TOK_NEWARRAY);
                                  $2->swap_sym(TOK_TYPEID);
                                  $$ = $1->adopt($2,$4); 
                                }
          ;

call      : TOK_IDENT '(' calllist ')' 
                                { destroy($4); 
                                  $2->swap_sym(TOK_CALL);
                                  $$ = $2->adopt($1,$3); 
                                }
          | TOK_IDENT '(' ')'   { 
                                  destroy($3); 
                                  $2->swap_sym(TOK_CALL);
                                  $$ = $2->adopt($1); 
                                }
          ;

calllist  : calllist ','  expr  { 
                                  destroy($2); 
                                  $$ = $1->adopt($3);
                                }
          | expr                { $$ = $1; }
          ;

variable  : TOK_IDENT           { $$ = $1; }
          | expr  '[' expr ']'  { 
                                  destroy($4); 
                                  $2->swap_sym(TOK_INDEX);
                                  $$ = $2->adopt($1,$3);  
                                }
          | expr  '.' TOK_IDENT 
                                { 
                                  $3->swap_sym(TOK_FIELD);
                                  $$ = $2->adopt($1,$3); 
                                }
          ;

constant  : TOK_INTCON          { $$ = $1; }
          | TOK_CHARCON         { $$ = $1; }
          | TOK_STRINGCON       { $$ = $1; }
          | TOK_FALSE           { $$ = $1; }
          | TOK_TRUE            { $$ = $1; }
          | TOK_NULL            { $$ = $1; } 
          ; 

%%


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}




