// James Vrionis
// jvrionis
// asg4: astree.cpp
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "auxlib.h"
#include "yyparse.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Initializing Constructor()
astree::astree (int symbol_, const location& lloc_, const char* info){
    symbol = symbol_;
    lloc = lloc_;
    lexinfo = string_set::intern (info);
// lexinfo = intern_stringset (info);
// vector defaults to empty -- no children
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Destructor():
astree::~astree(){
    while (not children.empty()){
        astree* child = children.back();
        children.pop_back();
        delete child;
    }
    if (yydebug){
        fprintf (stderr, "Deleting astree (");
        astree::dump (stderr, this);
        fprintf (stderr, ")\n");
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Adopt(): 3 children
astree* astree::adopt (astree* child1, astree* child2, 
                                                      astree* child3){
    if (child1 != nullptr) children.push_back (child1);
    if (child2 != nullptr) children.push_back (child2);
    if (child3 != nullptr) children.push_back (child3);
    return this;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Adopt_sym():
astree* astree::adopt_sym (astree* child, int symbol_){
    symbol = symbol_;
    return adopt (child);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Swap_sym():
astree* astree::swap_sym(int symbol_){ 
    symbol = symbol_;
    return this;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Dump_node():
void astree::dump_node (FILE* outfile){
    fprintf (outfile, "%p->{%s %zd.%zd.%zd \"%s\":",this, 
                parser::get_tname (symbol), lloc.filenr, lloc.linenr, 
                    lloc.offset, lexinfo->c_str());
    for (size_t child = 0; child < children.size(); ++child){
        fprintf (outfile, " %p", children.at(child));
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Dump_tree():
void astree::dump_tree (FILE* outfile, int depth){
    fprintf (outfile, "%*s", depth * 3, "");
    dump_node (outfile);
    fprintf (outfile, "\n");
    for (astree* child: children){ 
        child->dump_tree (outfile, depth + 1);
    }
    fflush (NULL);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Dump():
void astree::dump (FILE* outfile, astree* tree){
    if (tree == nullptr) fprintf (outfile, "nullptr\n");
    else tree->dump_node (outfile);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Print():
void astree::print (FILE* outfile, astree* tree, int depth){
    for (int i = 0; i < depth; i++){
        fprintf(outfile,"%*s", i, "|  ");
    }
    fprintf (outfile, "%s \"%s\" %zd.%zd.%zd\n",
            parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
            tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset);
    for (astree* child: tree->children){
        astree::print (outfile, child, depth + 1);
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Destroy():
void destroy (astree* tree1, astree* tree2, astree* tree3){
   if (tree1 != nullptr) delete tree1;
   if (tree2 != nullptr) delete tree2;
   if (tree3 != nullptr) delete tree3;
}
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// Errllocprintf():
void errllocprintf (const location& lloc, const char* format,
                                                    const char* arg){
    static char buffer[0x1000];
    assert (sizeof buffer > strlen (format) + strlen (arg));
    snprintf (buffer, sizeof buffer, format, arg);
    errprintf ("%s:%zd.%zd: %s", lexer::filename (lloc.filenr), 
                                    lloc.linenr, lloc.offset,buffer);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// New_parseroot():
//creates empty tree node for end of file
astree* new_parseroot(){
    astree* node = new astree (TOK_ROOT,{0, 0, 0}, "");
    return node;
}
//--------------------------------------------------------------------

//------------------------------------------------------------------
// New_node():
//used to synthisize TOK_FUNCTION and TOK_PROTOTYPE 
astree* new_node(astree* node, int symbol){
    astree* out_node = new astree (symbol,node->lloc, "");
    return out_node;
}
//--------------------------------------------------------------------

