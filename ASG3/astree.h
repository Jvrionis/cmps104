// James Vrionis
// jvrionis
// asg3
//--------------------------------------------------------------------

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
using namespace std;

#include "auxlib.h"
//--------------------------------------------------------------------

struct location {
   size_t filenr; // index into filename stack 
   size_t linenr; // line number
   size_t offset; // token with current line
};
//--------------------------------------------------------------------

struct astree {

   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node

   // Constructor / deconstructor
   astree (int symbol, const location&, const char* lexinfo);
   ~astree();

   // 3 children of parse tree
   astree* adopt (astree* child1, astree* child2 = nullptr, 
   astree* child3 = nullptr);
   
   // adopt a child / swap symbol 
   astree* adopt_sym (astree* child, int symbol);
   astree* swap_sym (astree* root, int symbol);

   void dump_node (FILE*);
   void dump_tree (FILE*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
   static void debug_print (astree* tree, int depth);
};
//--------------------------------------------------------------------

void destroy (astree* tree1, astree* tree2 = nullptr);
//--------------------------------------------------------------------

void errllocprintf (const location&, const char* format, const char*);
//--------------------------------------------------------------------

#endif
//--------------------------------------------------------------------