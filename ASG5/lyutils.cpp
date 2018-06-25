//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: lyutils.cpp
//--------------------------------------------------------------------
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxlib.h"
#include "lyutils.h"
#include "astree.h"

//--------------------------------------------------------------------
bool lexer::interactive = true;
location lexer::lloc = {0, 1, 0};
size_t lexer::Previous_yyleng = 0;
vector<string> lexer::iputfiles;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
astree* parser::root = nullptr;
astree* yyparse_astree = nullptr;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
const string* lexer::filename (int filenr) {
   return &lexer::iputfiles.at(filenr);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void lexer::newfilename (const string& filename) {
   lexer::lloc.filenr = lexer::iputfiles.size();
   lexer::iputfiles.push_back (filename);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void lexer::advance() {
   if (not interactive) {
      if (lexer::lloc.offset == 0) {
         printf (";%2zd.%3zd: ",
                 lexer::lloc.filenr, lexer::lloc.linenr);
      }
      printf ("%s", yytext);
   }
   lexer::lloc.offset += Previous_yyleng;
   Previous_yyleng = yyleng;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void lexer::newline() {
   ++lexer::lloc.linenr;
   lexer::lloc.offset = 0;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// for file number, line number, offset, the symbol, and lexinfo
int yylval_token(int symbol){ 
   yylval=new astree(symbol, lexer::lloc, yytext);
   fprintf(tokfile, "%zu \t %zu.%zu \t %i \t %13.13s \t\t (%s) \n",
           lexer::lloc.filenr, lexer::lloc.linenr, 
           lexer::lloc.offset, yylval->symbol, 
           parser::get_tname(symbol), yylval->lexinfo->c_str()); 
   return symbol; 
}

//--------------------------------------------------------------------
void lexer::badchar (unsigned char bad) {
   char buffer[16];
   snprintf (buffer, sizeof buffer,
             isgraph (bad) ? "%c" : "\\%03o", bad);
   errllocprintf (lexer::lloc, "invalid source character (%s)\n",
                  buffer);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void lexer::badtoken (char* lexeme) {
   errllocprintf (lexer::lloc, "invalid token (%s)\n", lexeme);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void lexer::include() {
   size_t linenr;
   static char filename[0x1000];
   assert (sizeof filename > strlen (yytext));
   int scan_rc = sscanf (yytext, "# %zd \"%[^\"]\"", &linenr, filename);
   fprintf(tokfile, "%s\n", yytext);
   if (scan_rc != 2) {
      errprintf ("%s: invalid directive, ignored\n", yytext);
   }else{
      if (yy_flex_debug){
        fprintf (stderr, "--included # %zd \"%s\"\n",
                                            linenr, filename);
      }
      lexer::lloc.linenr = linenr - 1;
      lexer::newfilename (filename);
   }
}

//--------------------------------------------------------------------
void yyerror (const char* message) {
   assert (not lexer::iputfiles.empty());
   errllocprintf (lexer::lloc, "%s\n", message);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
astree* new_parseroot(void){
  yyparse_astree=new astree(TOK_ROOT, {0,0,0}, "root");
  return yyparse_astree;
}
//--------------------------------------------------------------------
