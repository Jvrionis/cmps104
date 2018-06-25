//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg4: symstack.h
//--------------------------------------------------------------------

#ifndef _SYMSTACK_H
#define _SYMSTACK_H

#include "astree.h"
#include "symtable.h"
//--------------------------------------------------------------------


//--------------------------------------------------------------------
extern size_t block_count;
//--------------------------------------------------------------------
//--------------------------------------------------------------------
struct symstack {
    vector <symbol_table*> symbol_stack;
    void blocke(); // Enter
    void blockl(); // Leave 
    // define new identifier
    void define_ident(astree* node); 
    // search for identifier
    symbol* search_ident(astree* node);

};
//--------------------------------------------------------------------
#endif
//--------------------------------------------------------------------


