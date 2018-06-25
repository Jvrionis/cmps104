//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: symstack.cpp
//--------------------------------------------------------------------

#include "astree.h"
#include "symstack.h"
#include "symtable.h"
#include <iostream>
#include <unordered_map>

//--------------------------------------------------------------------
// From section 3.2 
void symstack::blocke(){
    block_count++;
    symbol_stack.push_back(nullptr); 
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void symstack::blockl(){
    symbol_stack.pop_back(); 
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void symstack::define_ident(astree* node){
    if (symbol_stack.back()!= nullptr){ // if t
        inserts(symbol_stack.back(), node);
    }
    else{
        symbol_stack.back()=new symbol_table;
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
symbol* symstack::search_ident(astree* node){
    for (auto symbol_table:symbol_stack) {  
        if (symbol_table != nullptr) { 
            symbol* sptr = finds(symbol_table, node);
            if (sptr != nullptr){
                return sptr;
            }
        }
        if(symbol_table==nullptr){
            return nullptr;
        }
    }
    return nullptr;
}
//--------------------------------------------------------------------
