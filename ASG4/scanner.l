%{
//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg4: string_set.cpp
//--------------------------------------------------------------------

#include "lyutils.h"
#define YY_USER_ACTION  { lexer::advance(); }

#define RETURN(SYMBOL) { \
   yylval = new astree (SYMBOL, lexer::lloc, yytext); \
   lexer::tok_dump (SYMBOL); \
   return SYMBOL; \
}
%}

%option 8bit
%option debug
%option nodefault
%option noinput
%option nounput
%option noyywrap
%option warn
/*%option verbose*/

LETTER          [A-Za-z_]
DIGIT           [0-9]
TOK_IDENT       ({LETTER}({LETTER}|{DIGIT})*)

TOK_INTCON      ({DIGIT}+(\.?{DIGIT}*)?)
TOK_CHARCON     ('([^\\'\n]|\\[\\'"0nt])')
TOK_STRINGCON   (\"([^\\"\n]|\\[\\'"0nt])*\")

%%

"#".*           { lexer::include();        }
[ \t]+          { }
\n              { lexer::newline();        }
"//".*          {}

"="             {   RETURN ('=');          }
"+"             {   RETURN ('+');          }
"-"             {   RETURN ('-');          }
"*"             {   RETURN ('*');          }
"/"             {   RETURN ('/');          }
"^"             {   RETURN ('^');          }
"("             {   RETURN ('(');          }
")"             {   RETURN (')');          }
";"             {   RETURN (';');          }


"!="            {   RETURN (TOK_NE);       }
"<="            {   RETURN (TOK_LE);       }
"<"             {   RETURN (TOK_LT);       }
"=="            {   RETURN (TOK_EQ);       }
">="            {   RETURN (TOK_GE);       }
">"             {   RETURN (TOK_GT);       }



false           { RETURN (TOK_FALSE);      }
true            { RETURN (TOK_TRUE);       }
ord             { RETURN (TOK_ORD);        }
chr             { RETURN (TOK_CHR);        }

char            { RETURN (TOK_CHAR);       }
else            { RETURN (TOK_ELSE);       }
if              { RETURN (TOK_IF);         }
int             { RETURN (TOK_INT);        }
new             { RETURN (TOK_NEW);        }
null            { RETURN (TOK_NULL);       }

return          { RETURN (TOK_RETURN);     }
string          { RETURN (TOK_STRING);     }
struct          { RETURN (TOK_STRUCT);     }
void            { RETURN (TOK_VOID);       }
while           { RETURN (TOK_WHILE);      }

{TOK_INTCON}    { RETURN (TOK_INTCON);     }
{TOK_IDENT}     { RETURN (TOK_IDENT);      }
{TOK_CHARCON}   { RETURN (TOK_CHARCON);    }
{TOK_STRINGCON} { RETURN (TOK_STRINGCON);  }

"[]"            { RETURN (TOK_ARRAY);      }
"["             { RETURN ('[');            }
"]"             { RETURN (']');            }
"{"             { RETURN ('{');            }
"}"             { RETURN ('}');            }
","             { RETURN (',');            }
"."             { RETURN ('.');            }
"%"             { RETURN ('%');            }
"!"             { RETURN ('!');            }
.               { lexer::badchar(*yytext); }

%%


