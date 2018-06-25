//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg4: typecheck.h
// Header file for Utility Code 
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include "astree.h"
#include "auxlib.h"
#include "symstack.h"
#include "symtable.h"
#include "typecheck.h"
#include "lyutils.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
astree* current_field=nullptr;
astree* current_struct=nullptr;
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void printhelper(FILE* symbolf, astree* node){
    astree* left=nullptr;   
    
    if (node->children.size()>=1){
        left=node->children[0];
        fprintf (symbolf, "%s (%zd.%zd.%zd) ",
                        left->lexinfo->c_str(), node->lloc.filenr, 
                                node->lloc.linenr, node->lloc.offset);
    }else{
        fprintf (symbolf, "%s (%zd.%zd.%zd) {%zu} ",
        node->lexinfo->c_str(), node->lloc.filenr, node->lloc.linenr, 
        node->lloc.offset, node->block_nr);
    }
    if (node->attr[ATTR_struct]) { fprintf(symbolf, "struct \"%s\" ",
                                  current_struct->lexinfo->c_str()); }
    if (node->attr[ATTR_field])  { fprintf(symbolf, "field {%s} ",
                                   current_field->lexinfo->c_str()); }
    if (node->attr[ATTR_function])  { fprintf(symbolf, "function "); }
    if (node->attr[ATTR_void])      { fprintf(symbolf, "void ");     }
    if (node->attr[ATTR_typeid])    { fprintf(symbolf, "type_id ");  }
    if (node->attr[ATTR_vreg])      { fprintf(symbolf, "vreg ");     }
    if (node->attr[ATTR_vaddr])     { fprintf(symbolf, "vaddr ");    }
    if (node->attr[ATTR_int])       { fprintf(symbolf, "int ");      }
    if (node->attr[ATTR_null])      { fprintf(symbolf, "null ");     }
    if (node->attr[ATTR_string])    { fprintf(symbolf, "string ");   }
    if (node->attr[ATTR_const])     { fprintf(symbolf, "const ");    }
    if (node->attr[ATTR_void])      { fprintf(symbolf, "void ");     }
    if (node->attr[ATTR_array])     { fprintf(symbolf, "array ");    }
    if (node->attr[ATTR_variable])  { fprintf(symbolf, "variable "); }
    if (node->attr[ATTR_lval])      { fprintf(symbolf, "lval ");     }
    if (node->attr[ATTR_param])     { fprintf(symbolf, "param ");    }

    fprintf(symbolf, "\n");
}
//--------------------------------------------------------------------
bool pchecker(astree* left, astree* right){
    size_t i = 0; 
    while(i < ATTR_function){
        if (left->attr[i]==1 && right->attr[i]==1){
            return true;
        }
        i++;   
    }
    return false;

}
//--------------------------------------------------------------------



//--------------------------------------------------------------------
void typcheckr(FILE* symbolf, astree* node, 
                  symstack* symbol_stack, symbol_table* symbol_table){
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void typecheck(FILE* symbolf, astree* parseroot, 
            symstack* symbol_stack, symbol_table* symbol_table){
    for (astree* child: parseroot->children) {
      typecheck(symbolf, child, symbol_stack, symbol_table);
    }
    typcheckr(symbolf, parseroot, symbol_stack, symbol_table);
}
//--------------------------------------------------------------------
