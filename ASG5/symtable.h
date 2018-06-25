//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: symtable.h
//--------------------------------------------------------------------

#ifndef _SYMTABLE_H
#define _SYMTABLE_H

#include "astree.h"
#include <unordered_map>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
//--------------------------------------------------------------------

struct symbol;
using symbol_table=unordered_map<const string*, symbol*>;
using symbol_entry=pair<const string*, symbol*>;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
struct symbol{
        attr_bitset attr;
        symbol_table* fields;
        location lloc;
        size_t block_nr;
        vector<symbol*>* parameters;
};
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//taken from pdf 2.2
symbol* new_symbol(astree* node);   
void inserts(symbol_table* symbtab, astree* node);
symbol* finds(symbol_table* symtab, astree* node);
symbol* findstype(symbol_table* symtab, astree* node);
#endif
//--------------------------------------------------------------------

