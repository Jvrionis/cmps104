// James Vrionis
// jvrionis
// asg4: lyutils.h
//--------------------------------------------------------------------

#ifndef __UTILS_H__
#define __UTILS_H__

//--------------------------------------------------------------------
// Lex and Yacc interface utility.
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

#include "astree.h"
#include "auxlib.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Var's
extern FILE* yyin;
extern int yydebug;
extern char* yytext;
extern size_t yyleng; 
extern int yy_flex_debug;
//--------------------------------------------------------------------

//-------------------------------------------------------------------- 
int yylex();
int yyparse();
int yylex_destroy();
void yyerror (const char* message);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Lexer():
struct lexer{
    static location lloc;
    static bool interactive;
    static size_t last_yyleng;
    static vector<string> filenames;
    static void advance();
    static void newline();
    static void include();
    static void tok_dump(int symbol);
    static void badtoken (char* lexeme);
    static void badchar (unsigned char bad);
    static const string* filename (int filenr);
    static void newfilename (const string& filename);
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Parser():
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


#endif
//-------------------------------------------------------------------


