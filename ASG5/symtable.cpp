//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: symtable.cpp
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include "symtable.h"
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "astree.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
symbol* new_symbol(astree* node){
        symbol* new_sym = new symbol();
        new_sym->attr = node->attr;
        new_sym->fields = nullptr;
        new_sym->lloc = node->lloc;
        new_sym->block_nr=node->block_nr;
        return new_sym;
}
//--------------------------------------------------------------------

void inserts(symbol_table* symtab, astree* node){
        symbol* new_sym = new_symbol(node);
        symbol_entry entry = symbol_entry 
                        (const_cast<string*>(node->lexinfo), new_sym);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
symbol* finds(symbol_table* symtab, astree* node){
        string* lexinfo = (string *)node->lexinfo; 
        if(!symtab->count(lexinfo)) 
                return nullptr;
        symbol* new_sym = new_symbol(node); 
        symbol_entry entry = symbol_entry
                (const_cast<string*> (node->lexinfo), new_sym ); 
       return entry.second; 
}
//--------------------------------------------------------------------

