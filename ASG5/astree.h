//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: astree.h
//--------------------------------------------------------------------
#ifndef __ASTREE_H__
#define __ASTREE_H__

#include "auxlib.h"
//#include "symtable.h"

#include <bitset>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
enum {  ATTR_void, ATTR_int, ATTR_null, ATTR_string, ATTR_struct, 
        ATTR_array, ATTR_function, ATTR_variable, ATTR_field, 
        ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const, ATTR_vreg, 
        ATTR_vaddr, ATTR_bitset_size
};
using attr_bitset = bitset<ATTR_bitset_size>;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
struct location {
   size_t filenr;
   size_t linenr;
   size_t offset;
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
struct astree {
   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   attr_bitset attr;
   size_t block_nr;
   const char* emit_code;

   // AST Functions.
   astree (int symbol, const location&, const char* lexinfo);
   ~astree();
   astree* adopt (astree* child1, astree* child2 = nullptr,
                                     astree* child3 = nullptr);
   astree* adopt_sym (astree* child, int symbol);
   void dump_node (FILE*);
   void dump_tree (FILE*, astree*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void attr_print(astree* node, FILE* outfile);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
astree* create_funct(astree* identdecl, 
                  astree* paramlist, astree* block);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
astree* create_proto(astree* identdecl, astree* paramlist);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void destroy (astree* tree1, astree* tree2 = nullptr);
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void errllocprintf (const location&, const char* format, const char*);
//--------------------------------------------------------------------

#endif
//--------------------------------------------------------------------
