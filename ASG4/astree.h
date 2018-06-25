// James Vrionis
// jvrionis
// asg4: astree.h
// Utility Code provided by Wesley Mackey
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include "symtable.h"
using namespace std;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Struct()                             
//struct location{
//   size_t filenr;
//   size_t linenr;
//   size_t offset;
//};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Astree():
struct astree{

   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node

   // Functions
   astree (int symbol, const location&, const char* lexinfo);
   ~astree();
   astree* adopt (astree* child1, astree* child2 = nullptr, 
                                    astree* child3 = nullptr);
   astree* adopt_sym (astree* child, int symbol);
   astree* swap_sym (int symbol_);
   
   void dump_node (FILE*);
   void dump_tree (FILE*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// New_parseroot():
astree* new_parseroot();
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// New_node():
astree* new_node(astree* node, int symbol);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Destroy():
// Makes tree(1..3) null
void destroy (astree* tree1, astree* tree2 = nullptr, 
                                             astree* tree3 = nullptr);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Errlocprintf():
void errllocprintf (const location&, const char* format, const char*);
//--------------------------------------------------------------------


#endif
//--------------------------------------------------------------------

