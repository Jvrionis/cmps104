//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg4: lyutils.h
//--------------------------------------------------------------------
#ifndef __UTILS_H__
#define __UTILS_H__

// Lex and Yacc interface utility.
//--------------------------------------------------------------------
#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

#include "astree.h"
#include "auxlib.h"

#define YYEOF 0
//--------------------------------------------------------------------

//--------------------------------------------------------------------
extern FILE* yyin; 
extern FILE* tokfile; 
extern FILE* strfile; 
extern char* yytext; 
extern int yy_flex_debug;
extern int yydebug;
extern size_t yyleng; 
#define YYEOF 0
//--------------------------------------------------------------------

//-------------------------------------------------------------------- 
//astree* new_parseroot (void);
int yylex();
int yylex_destroy();
int yyparse();
void yyerror (const char* message);
int yylval_token(int symbol); 
//--------------------------------------------------------------------

//--------------------------------------------------------------------
struct lexer {
   static location lloc;
   static bool interactive;
   static size_t Previous_yyleng;
   static void advance();
   static void newline();
   static void include();
   static vector<string> iputfiles;
   static void badtoken (char* lexeme);
   static void badchar (unsigned char bad);
   static const string* filename (int filenr);
   static void newfilename (const string& filename);
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
struct parser {
   static astree* root;
   static const char* get_tname (int symbol);
}; 
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Define YYSTYPE and include yyparse.h
#define YYSTYPE astree*
#include "yyparse.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
const char *get_yytname (int symbol);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
astree* new_parseroot(void);
//--------------------------------------------------------------------

#endif
//--------------------------------------------------------------------
