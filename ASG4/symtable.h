//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg4: Symtable.h
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//--------------------------------------------------------------------

//                                                                //
// http://www2.ucsc.edu/courses/cmps104a-wm/:/                    //
//                Examples/interpreters/old-2004/eval-operators.c //
using namespace std;

//--------------------------------------------------------------------
enum{  ATTR_void, ATTR_int, ATTR_null, ATTR_string,
       ATTR_struct, ATTR_array, ATTR_function, ATTR_variable,
       ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const,
       ATTR_vreg, ATTR_vaddr, ATTR_bitset_size };
//--------------------------------------------------------------------

//--------------------------------------------------------------------

//--------------------------------------------------------------------
struct symbol;

// bitset give value of last item in list  
using attr_bitset = bitset<ATTR_bitset_size>;
using symbol_table = unordered_map<const string*, symbol*>;
using symbol_entry = pair<const string*,symbol*>;
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// Location struct():
struct location{
    size_t filenr;
    size_t linenr;
    size_t offset;
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Struct symbol():
struct symbol{
    attr_bitset attributes;
    symbol_table* fields;
    location lloc;
    size_t block_nr;
    vector<symbol*>* parameters;  

    static symbol_table struct_table;
    static vector<symbol_table> sym_table;
    static vector<int> sym_stack;
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Function Prototypes(): 
char* atr_to_string(attr_bitset atr);
struct astree;


void insert_symbol(symbol_table* table,astree* node);
void insert_param(vector<symbol*>* vector, astree* node);
symbol* find_symbol(symbol_table* table, const string* key);
void add_symtable();

symbol* create_symbol (astree* node);

void insert_struct_table(string* key);
void print_node(FILE* outfile,symbol_table table, const string* key);
//--------------------------------------------------------------------


#endif
//--------------------------------------------------------------------


