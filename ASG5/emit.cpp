//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: emit.cpp
//--------------------------------------------------------------------
#include <string>
#include <string.h>
#include <iostream>
#include <libgen.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "emit.h"

//--------------------------------------------------------------------
int strcon_nr=1, int intcon_nr=1, charcon_nr=1;
//--------------------------------------------------------------------


//--------------------------------------------------------------------
void eheader(FILE* oilfile){
    fprintf(oilfile,"#define __OCLIB_C__\n");
    fprintf(oilfile, "#include \"oclib.oh\"\n\n");
}
//--------------------------------------------------------------------


//--------------------------------------------------------------------
void etypedef(FILE* oilfile, astree* node, astree* parent){    
    if (strcmp(node->lexinfo->c_str(),"int")==0){
        fprintf(oilfile, "int");
        if (node->attr[ATTR_array]){
            fprintf(oilfile, "*");
        }
        fprintf(oilfile, " ");
    }
    else if (strcmp(node->lexinfo->c_str(),"string")==0){
        fprintf(oilfile, "char*");
        if (node->attr[ATTR_array]){
            fprintf(oilfile, "*");
        }
        fprintf(oilfile, " ");
    }
    else {
        fprintf(oilfile, "struct %s*", parent->emit_code);
        if (node->attr[ATTR_array]){
            fprintf(oilfile, "*");
        }
        fprintf(oilfile, " ");
    }

}
//--------------------------------------------------------------------


//--------------------------------------------------------------------
void estructdef(FILE* oilfile, astree* root){
    estructdecl(oilfile, root);
    for (astree* child: root->children) {
      estructdecl(oilfile, child);
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void estructdecl(FILE* oilfile, astree* node){
    if (node->symbol==TOK_STRUCT){
        astree* left=nullptr; astree* right=nullptr;
        if (node->children.size()>=1){
            left=node->children[0];
            fprintf(oilfile, "struct ");
            std::string structname="s_";
            structname.append(left->lexinfo->c_str());
            node->emit_code=structname.c_str();
            fprintf(oilfile, "%s {\n", node->emit_code);
            if (node->children.size()>=2){
                right=node->children[1];
                astree* rleft=nullptr;
                if (right->children.size()>=1){
                    for(; right !=nullptr; ){
                        fprintf(oilfile, "\t");
                        rleft=right->children[0];
                        etypedef(oilfile, right, node);
                        std::string fieldname="f_";
                        fieldname.append(left->lexinfo->c_str());
                        fieldname.append("_");
                        fieldname.append(rleft->lexinfo->c_str());
                        right->emit_code=fieldname.c_str();
                        fprintf(oilfile, "%s \n", right->emit_code);

                        if (right->children.size()>=2){
                            right=right->children[1];
                        }
                        else{
                            right=nullptr;
                        }
                    }

                }
            }   
            fprintf(oilfile, "\n}\n");    
        }
    }
}


//--------------------------------------------------------------------
void estringdef(FILE* oilfile, astree* node){
    estringcon(oilfile, node);
    for (astree* child: node->children) {
      estringdef(oilfile, child);
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void estringcon(FILE* oilfile, astree* node){
    if (node->symbol==TOK_STRINGCON){
        std::string varname = "s";
        varname += std::to_string(stringcon_nr);
        node->emit_code=varname.c_str();

        fprintf(oilfile, "char* %s = %s \n", node->emit_code, 
                                             node->lexinfo->c_str());
        stringcon_nr++;
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void evardef(FILE* oilfile, astree* node){
    evardecl(oilfile, node);
    for (astree* child: node->children){
      evardecl(oilfile, child);
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void evardecl(FILE* oilfile, astree* node){
    if (node->symbol==TOK_VARDECL){
        astree* left=nullptr;
        astree* left2=nullptr;
        std::string varname="__";
        if (node->children.size()>=1){
            left=node->children[0];
            if (left->children.size()>=1){
                left2=left->children[0];
                varname.append(left2->lexinfo->c_str());
                left->emit_code=varname.c_str();
                left2->emit_code=varname.c_str();
                fprintf(oilfile, "%s %s;\n", left->lexinfo->c_str(),
                                             left2->emit_code);
            }
        }
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void efunction(FILE* oilfile, astree* node){
    if (node->symbol==TOK_FUNCTION){
        if (node->children.size()>=1){
            efunctionname(oilfile, node);
        }
        if (node->children.size()>=2){
             efunctparam(oilfile, node);
        }
        if (node->children.size()>=3){
            efunctbody(oilfile, node);
        }
    }
    for (astree* child: node->children) {
      efunction(oilfile, child);
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void efunctionname(FILE* oilfile, astree* node){
    astree* left=node->children[0];
    astree* left2=left->children[0];
    fprintf(oilfile, "%s __%s (",left->lexinfo->c_str(), 
                                 left2->lexinfo->c_str());
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void efunctparam(FILE* oilfile, astree* node){
    astree* paramhead = nullptr;
    if(node->children.size()>=2){
        fprintf(oilfile, "\n");
        paramhead = node->children[1]->children[0];
        fprintf(oilfile, "%s",paramhead->emit_code);
        astree* plist=nullptr;
        astree* nexthead=nullptr;
        int i=1;

        if (paramhead->children.size()>=1){
            plist=paramhead->children[0];
                fprintf(oilfile, "\t%s _%zu_%s",
                    paramhead->lexinfo->c_str(),
                    paramhead->block_nr, plist->lexinfo->c_str());
        }

        if (paramhead->children.size()>=2){
            nexthead=paramhead->children[i];
            while(nexthead!=nullptr){
                plist=nexthead->children[0];
                fprintf(oilfile, ";\n\t%s _%zu_%s",
                    nexthead->lexinfo->c_str(),
                    nexthead->block_nr,plist->lexinfo->c_str());

                if (paramhead->children.size()>=i+1){
                    i++;
                    nexthead=paramhead->children[i];
                }
                else{
                    nexthead=nullptr;
                }
            }
        }
    }
    fprintf(oilfile, ") \n");

}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void efunctbody(FILE* oilfile, astree* node){
    fprintf(oilfile, "{\n");
    astree* head=node->children[2];

    fprintf(oilfile, "}\n");
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void ebinop(FILE* oilfile, astree* node) {
    astree* left=node->children[0];
    astree* right=node->children[1];
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void eunop(FILE* oilfile, astree* node){
    astree* left=node->children[0];
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void eexpression(FILE* oilfile, astree* node){
    switch(node->symbol)
    {
        case '+': {
            ebinop(oilfile, node);
            break;
        }
        case '-': { 
            ebinop(oilfile, node);
            break;
        }
        case '*': {
            ebinop(oilfile, node);
            break;
        }
        case '/': {
            ebinop(oilfile, node);
            break;
        }
        case '%': {
            ebinop(oilfile, node);
            break;
        }
        case TOK_GT: {
            ebinop(oilfile, node);
            break;
        }
        case TOK_LT: {
            ebinop(oilfile, node);
            break;
        }
        case TOK_GE: {
            ebinop(oilfile, node);
            break;
        }
        case TOK_LE: {
            ebinop(oilfile, node);
            break;
        }        
        case TOK_EQ: {
            ebinop(oilfile, node);
            break;
        }
        case TOK_NE: {
            ebinop(oilfile, node);
            break;
        }
        case '=': {
            ebinop(oilfile, node);
            break;
        }
        case TOK_POS: {
            eunop(oilfile, node);
            break;
        }
        case TOK_NEG: {
            eunop(oilfile, node);
            break;
        }
        default: break;
    }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void eintcon(FILE* oilfile, astree* node) {
    string varname = "a";
    varname += std::to_string(intcon_nr);
    node->emit_code=varname.c_str();

    fprintf(oilfile, "int* %s = %s\n ", node->emit_code, 
                                        node->lexinfo->c_str());
    intcon_nr++;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void echarcon(FILE* oilfile, astree* node) {
    string varname = "c";
    varname += std::to_string(charcon_nr);
    node->emit_code=varname.c_str();

    fprintf(oilfile, "char** %s = %s", node->emit_code, 
                                      node->lexinfo->c_str());
    charcon_nr++;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void ecallname(FILE* oilfile, astree* node) {
    astree* left=node->children[0];
    fprintf(oilfile, "\t__%s",left->lexinfo->c_str());
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void ecallparams(FILE* oilfile, astree* node) {
    fprintf(oilfile, "(");
    astree* paramhead = nullptr;
    if(node->children.size()>=2){
        paramhead = node->children[1];
        fprintf(oilfile, "%s",paramhead->emit_code);
        int i=0;
        astree* plist=nullptr;
        if (paramhead->children.size()>=1){
            plist=paramhead->children[i];
            while(plist!=nullptr){
                fprintf(oilfile, ";\n %s",plist->emit_code);
                i++;
                if (paramhead->children.size()>=(i+1)){
                    plist=paramhead->children[i];
                }
                else{
                    plist=nullptr;
                }
            }
        }
    }
    fprintf(oilfile, ") \n");
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void emitIF(FILE* oilfile, astree* node){
    emit(oilfile, node-> children[0]);
    fprintf(oilfile, "\t__(!if%s) go to fi_%zd_%zd_%zd;\n",
        node->children[0]->lexinfo->c_str(),
        node->lloc.filenr,node->lloc.linenr, node->lloc.offset);
    emit(oilfile, node->children[1]);
        fprintf(oilfile, "fi_%zd_%zd_%zd:;\n",
        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);

}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void emitWhile(FILE* oilfile, astree* node){
    fprintf(oilfile, "while_%zd_%zd_%zd:;\n", 
        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
    emit(oilfile, node->children[0]);
    
    fprintf(oilfile, "\t__(!if%s) go to break_%zd_%zd_%zd:;\n", 
        node->children[0]->lexinfo->c_str(),
        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
    emit(oilfile,node->children[1]);
    
    fprintf(oilfile, "\t__goto while_%zd_%zd_%zd:;",
        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
    
    fprintf(oilfile, "break_%zd_%zd_%zd:;\n", 
        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void emitIFELSE(FILE* oilfile, astree* node){
    emit(oilfile, node->children[0]);
    
    fprintf(oilfile, "\t__(!if%s) go to else_%zd_%zd_%zd:;\n",
        node->children[0]->lexinfo->c_str(),
        node->lloc.filenr, node->lloc.linenr, node-> lloc.offset);
    emit(oilfile, node->children[1]);
    
    fprintf(oilfile, "\t__goto fi_%zd_%zd_%zd;\n",
    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
    fprintf(oilfile, "else_%zd_%zd_%zd:;\n", 
        node->lloc.filenr, node->lloc.linenr, node-> lloc.offset);
    emit(oilfile, node->children[2]);
    fprintf(oilfile, "fi_%zd_%zd_%zd\n",
    node->lloc.filenr, node->lloc.linenr, node -> lloc.offset);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void emitIF(FILE* oilfile, astree* node){
    emit(oilfile, node-> children[0]);
    fprintf(oilfile, "\t__(!if%s) go to fi_%zd_%zd_%zd;\n",
        node->children[0]->lexinfo->c_str(),
        node->lloc.filenr,node->lloc.linenr, node->lloc.offset);
    emit(oilfile, node->children[1]);
        fprintf(oilfile, "fi_%zd_%zd_%zd:;\n",
        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);

}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void emit(FILE* oilfile, astree* node){

    switch(node->symbol)
    {
        case TOK_PROTOTYPE:
        case TOK_STRINGCON: 
        case TOK_INTCON: 
        case TOK_CHARCON: 
        {
            break;
        }
        case TOK_FUNCTION: 
        {
            break;
        }
        case TOK_CALL: {
            ecallname(oilfile, node);
            ecallparams(oilfile, node);
            break;
        }
        case TOK_WHILE:{
            emitWhile(oilfile, node);
            break;
        }
        case TOK_IF:{
            emitIF(oilfile, node);
            break;
        }
        case TOK_emitIFELSE:{
            emitIFELSE(oilfile, node);
            break;
        }
        default:{
            break;
        }
    }

}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void emain(FILE* oilfile, astree* root){
    fprintf(oilfile, "\nvoid __ocmain(void)\n{ \n");
    emit(oilfile, root);
    for (astree* child: root->children) {
      emit(oilfile, child);
    }
    fprintf(oilfile, "}\n");
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void eprogram(FILE* oilfile, astree* node){
    estructdef(oilfile, node);
    estringdef(oilfile, node);
    evardef(oilfile, node);
    efunction(oilfile, node);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
int emit_operands(astree* node){
    return 
      node->symbol == TOK_IDENT
    ||node->symbol == TOK_INTCON
    ||node->symbol == TOK_CHARCON;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
void eeverything(FILE* oilfile, astree* root){
    eheader(oilfile);
    eprogram(oilfile, root);
    emain(oilfile, root);
}
//--------------------------------------------------------------------


