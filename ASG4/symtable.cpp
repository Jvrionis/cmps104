// James Vrionis
// jvrionis
// asg4: Symtable.cpp
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include "symtable.h"
#include "yyparse.h"
#include "lyutils.h"
#include <stdio.h>
#include <vector>

using namespace std;
#include <string.h>
//--------------------------------------------------------------------

//--------------------------------------------------------------------
symbol_table symbol::struct_table;
vector<symbol_table> symbol::sym_table;
vector<int> symbol::sym_stack;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
char* atr_to_string (attr_bitset atr) {
    string bstr = "";
    
    if (atr.test (ATTR_int))         { bstr += "int "     ;  }
    if (atr.test (ATTR_void))        { bstr += "void "    ;  }
    if (atr.test (ATTR_null))        { bstr += "null "    ;  }
    if (atr.test (ATTR_string))      { bstr += "string "  ;  }
    
    if (atr.test (ATTR_lval))        { bstr += "lval "    ;  }
    if (atr.test (ATTR_vreg))        { bstr += "vreg "    ;  }
    if (atr.test (ATTR_array))       { bstr += "array "   ;  }
    
    if (atr.test (ATTR_vreg))        { bstr += "vreg "    ;  }
    if (atr.test (ATTR_void))        { bstr += "void "    ;  }
    if (atr.test (ATTR_param))       { bstr += "param "   ;  } 
    if (atr.test (ATTR_const))       { bstr += "const "   ;  } 
    if (atr.test (ATTR_vreg))        { bstr += "vreg "    ;  }
    if (atr.test (ATTR_typeid))      { bstr += "typeid "  ;  }
    
    if (atr.test (ATTR_vaddr))       { bstr += "vaddr "   ;  } 
    if (atr.test (ATTR_struct))      { bstr += "struct "  ;  }
    if (atr.test (ATTR_function))    { bstr += "function ";  }
    if (atr.test (ATTR_variable))    { bstr += "variable ";  }

    return strdup(bstr.c_str());
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void add_symtable(){
   symbol_table new_table;
   symbol::sym_table.push_back(new_table);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
symbol* create_symbol (astree* node) {
    symbol* new_symbol = new symbol();
    new_symbol->attributes = node->attributes;
    new_symbol->fields = nullptr;
    new_symbol->lloc = node->lloc;
    new_symbol->block_nr = node->block_nr;
    new_symbol->parameters = nullptr;
    return new_symbol;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Insert_symbol():
void insert_symbol(symbol_table* table, astree* node){
    const string* key = node->lexinfo;
    symbol* new_symbol = create_symbol(node);
    (*table)[key] = new_symbol;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Insert_param():
void insert_param(vector<symbol*>* vector, astree* node){
    symbol* new_symbol = create_symbol(node);
    (*vector).push_back(new_symbol);
}
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// insert_struct():
// initialize and new empty symbol and asign 0 to block value 
void insert_struct_table(string* key){
    symbol* new_symbol = new symbol();
    
    new_symbol->block_nr = 0;
    new_symbol->attributes[ATTR_struct] = true;
    new_symbol->attributes[ATTR_typeid] = true;
    
    new_symbol->fields = nullptr;
    symbol::struct_table[key] = new_symbol;
}
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// print_node():
void print_node(FILE* outfile,symbol_table table, const string* key){
   symbol* node = table[key];
   printf (outfile,"%s (%zd.%zd.%zd) {%zd} %s\n",key->c_str(), 
                        node->lloc.filenr,node->lloc.linenr, 
                                node->lloc.offset,node->block_nr,
                                    atr_to_string(node->attributes));
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// print__table():
void print__table(string* key){
   symbol* node = symbol::struct_table[key];

   printf ("%s (%zd.%zd.%zd) {%zd} %s\n",key->c_str(),
                    node->lloc.filenr,node->lloc.linenr, 
                                node->lloc.offset,node->block_nr,
                                    atr_to_string(node->attributes));
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// find_symbol():
symbol* find_symbol(symbol_table* table, const string* key){
   if (table->count (key) > 0){
      return (*table)[key];
   }else{
      return nullptr;
   }
}
//--------------------------------------------------------------------

