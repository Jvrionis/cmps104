%{
// James Vrionis
// jvrionis
// Dummy parser for scanner project.
// asg3
//--------------------------------------------------------------------

#include "lyutils.h"
#include "auxlib.h"


#define YY_USER_ACTION  { lexer::advance(); }

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn

LETTER          [A-Za-z_]
DIGIT           [0-9]

MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
INTEGER         ({DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)

NUMBER          ({MANTISSA}{EXPONENT}?)
CHAR            ('([^\\'\n]|\\[\\'"0nt])')
STRING          (\"([^\\"\n]|\\[\\'"0nt])*\")
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)

%%

"#".*           { lexer::include(); }
[ \t]+          { } 
\n              { lexer::newline(); }



"if"            { return yylval_token (TOK_IF); }
"else"          { return yylval_token (TOK_ELSE); }
"while"         { return yylval_token (TOK_WHILE); }
"return"        { return yylval_token (TOK_RETURN); }
"ord"           { return yylval_token (TOK_ORD); }
"chr"           { return yylval_token (TOK_CHR); }
"true"          { return yylval_token (TOK_TRUE); }
"false"         { return yylval_token (TOK_FALSE); }
"int"           { return yylval_token (TOK_INT); }
"string"        { return yylval_token (TOK_STRING); }
"bool"          { return yylval_token (TOK_BOOL); }
"char"          { return yylval_token (TOK_CHAR); }
"struct"        { return yylval_token (TOK_STRUCT); }
"void"          { return yylval_token (TOK_VOID); }
"new"           { return yylval_token (TOK_NEW); }
"null"          { return yylval_token (TOK_NULL); }


"=="            { return yylval_token (TOK_EQ); }
"<="            { return yylval_token (TOK_LE); }
">="            { return yylval_token (TOK_GE); }
"!="            { return yylval_token (TOK_NE); }
"<"             { return yylval_token (TOK_LT); }
">"             { return yylval_token (TOK_GT); }


{CHAR}          { return yylval_token (TOK_CHARCON); }
{STRING}        { return yylval_token (TOK_STRINGCON); }
{INTEGER}       { return yylval_token (TOK_INTCON); }
{IDENT}         { return yylval_token (TOK_IDENT); }
"[]"            { return yylval_token (TOK_ARRAY); }

"="             { return yylval_token ('=');       }
"+"             { return yylval_token ('+');       }
"-"             { return yylval_token ('-');       }
"*"             { return yylval_token ('*');       }
"/"             { return yylval_token ('/');       }
"^"             { return yylval_token ('^');       }
"("             { return yylval_token ('(');       }
")"             { return yylval_token (')');       }
";"             { return yylval_token (';');       }
"["             { return yylval_token ('[');       }
"]"             { return yylval_token (']');       }
"{"             { return yylval_token ('{');       }
"}"             { return yylval_token ('}');       }
","             { return yylval_token (',');       }
"."             { return yylval_token ('.');       }
"%"             { return yylval_token ('%');       }
"!"             { return yylval_token ('!');       }

{NOTNUMBER}     { lexer::badtoken (yytext);
                  return yylval_token (NUMBER); }
.               { lexer::badchar (*yytext); }


%%

