// James Vrionis
// jvrionis
// asg4: buildsym.cpp
//--------------------------------------------------------------------

#include "auxlib.h"
#include "astree.h"
#include "lyutils.h"
#include "string_set.h"
#include "symtable.h"
#include "buildsym.h"
#include "yyparse.h"

int counter = 0;
//--------------------------------------------------------------------
void build_symtable (FILE* outfile, astree* tree, int block_nr){
    int i = 0; 
    while ( i < block_nr) { i++; } 
    switch(tree->symbol){
        case TOK_ROOT :
        {   for (astree* child: tree->children){
                build_symtable (outfile, child, (size_t)block_nr);
            }
            tree->block_nr = (size_t)block_nr;
            break;
        }
        case TOK_TYPEID :
            break;
        case TOK_STRUCT :              
            break;
        case TOK_STRING :
            break;
        case TOK_DECLID :
            break;
        case TOK_INT :
            if (find_symbol( &symbol::sym_table[(size_t)block_nr],
                    tree->lexinfo) == nullptr){
                        tree->block_nr = (size_t)block_nr;
                insert_symbol (&symbol::sym_table[(size_t)block_nr],
                                                               tree);
            }
            break;
        case TOK_PARAMLIST :
        {
            if (find_symbol( &symbol::sym_table[(size_t)block_nr],
                tree->lexinfo) == nullptr){
                    tree->block_nr = (size_t)block_nr;
                insert_symbol (&symbol::sym_table[(size_t)block_nr], 
                                                              tree);
            }
            break;
        }
              
        case TOK_PROTOTYPE :
        {
        const string* key = tree->children[0]->children[0]->lexinfo;
        symbol* prototype_sym = create_symbol(tree);
        if (tree->children[1]->children.size() >= 1){
            
            add_symtable();
            vector<symbol*>* params = new vector<symbol*>;
            astree* param_list_head = tree->children[1]->children[0];
            insert_param (params, param_list_head);
            counter += 1;
            
            build_symtable (outfile, param_list_head, counter);

            for (auto itr = param_list_head->children.begin();
                  itr != param_list_head->children.end(); itr++) {
                  insert_param (params, *itr);
                  build_symtable (outfile, *itr,counter);
            }
            prototype_sym->parameters = params;
        }
        if (find_symbol( &symbol::sym_table[(size_t)block_nr],
                  key) == nullptr){
            symbol_entry new_sym (key,prototype_sym);
            tree->block_nr = (size_t)block_nr;
            symbol::sym_table[(size_t)block_nr].insert(new_sym);  
        }else if (find_symbol( &symbol::sym_table[(size_t)block_nr],
                     key)->parameters != nullptr){
            if (prototype_sym->parameters != nullptr){
               if (find_symbol( &symbol::sym_table[(size_t)block_nr],
                  key)->parameters->size() != 
                  prototype_sym->parameters->size()){
                  perror("Redefinition of Prototype");
                }
                perror("Redefinition of Prototype");
            }
         } 
        while (astree* child: tree->children) {
            build_symtable (outfile, child, (size_t)block_nr);
        }
            break;
        }
        default :
        {
            while(astree* child: tree->children){
                build_symtable (outfile, child, (size_t)block_nr);
            }
            tree->block_nr = (size_t)block_nr;
            break;
        
        }
    }
}
//------------------------------------------------------------------


//------------------------------------------------------------------
void traverse (FILE* outfile, astree* tree, int block_nr) {
    int i =0; 
    while (i < block_nr ) {
        i++;
    }
    for (astree* child: tree->children) {
        traverse (outfile, child, block_nr);
    }
    switch(tree->symbol) {
        case TOK_ROOT :
            break;
        case TOK_TYPEID :
            break;
        case TOK_STRUCT :              
            break;
        case TOK_STRING :
            break;
        case TOK_DECLID :
            break;
        case TOK_VARDECL :
            break;
        case TOK_INT :
        {      
            const string* key = tree->lexinfo;
            tree->attributes[ATTR_int] = true;
            tree->attributes[ATTR_variable] = true;
            tree->attributes[ATTR_lval] = true;
            tree->struct_node = 
                    symbol::sym_table[tree->block_nr][key];

            symbol::sym_table[tree->block_nr][key]
                        ->attributes = tree->attributes;
            break;
        case TOK_INTCON :
            break;  
        case TOK_PROTOTYPE :
        {
            const string* key = tree->children[0]
                                        ->children[0]->lexinfo;
            tree->attributes[ATTR_function] = true;
            tree->struct_node 
               = symbol::sym_table[tree->block_nr][key];
            symbol::sym_table[tree->block_nr][key]->attributes
                                                 = tree->attributes;
            break;
        }
    }      
}
//------------------------------------------------------------------

//------------------------------------------------------------------
void print_symtable (FILE* outfile, astree* tree, int block_nr){
    if (tree->block_nr > 0){
        fprintf(outfile,"  ");
    }
    switch(tree->symbol) {
        case TOK_ROOT : 
            break;
        case TOK_TYPEID :
            break;
        case TOK_STRUCT :              
            break;
        case TOK_STRING :
            break;
        case TOK_DECLID :
            break;
        case TOK_VARDECL :
            break;
        case TOK_INT :
        {
            const string* key = tree->lexinfo;
            print_node(outfile,symbol::sym_table[tree->block_nr],key);
            break;
        }
        case TOK_INTCON :
            break;
        case TOK_PROTOTYPE :
        {
            const string* key 
                        = tree->children[0]->children[0]->lexinfo;
            print_node(outfile,symbol::sym_table[(size_t)block_nr],
                                                                key);
            break; 
        }
    }
    for (astree* child: tree->children){
        print_symtable (outfile, child, (size_t)block_nr);
    }
}
//-----------------------------------------------------------------


