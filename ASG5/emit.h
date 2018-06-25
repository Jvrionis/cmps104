//--------------------------------------------------------------------
// James Vrionis
// jvrionis
// asg5: emit.h
//--------------------------------------------------------------------


//------------------------------------------------------------------
void eheader(FILE* oilfile);
void eprogram(FILE* oilfile, astree* node);
void etypdef(FILE* oilfile, astree* node, astree* parent);
//------------------------------------------------------------------

//------------------------------------------------------------------
void estructdef(FILE* oilfile, astree* node);
void estructdecl(FILE* oilfile, astree* node);
void estringdef(FILE* oilfile, astree* node);
//------------------------------------------------------------------

//------------------------------------------------------------------
void evardef(FILE* oilfile, astree* node);
void evardecl(FILE* oilfile, astree* node);
void eexpression(FILE* oilfile, astree* node);
void ebinop(FILE* oilfile, astree* node);
//------------------------------------------------------------------

//------------------------------------------------------------------
void eunop(FILE* oilfile, astree* node);
void estringcon(FILE* oilfile, astree* node);
void eintcon(FILE* oilfile, astree* node);
void echarcon(FILE* oilfile, astree* node);
//------------------------------------------------------------------

//------------------------------------------------------------------
void efunction(FILE* oilfile, astree* node);
void efunctionname(FILE* oilfile, astree* node);
void efunctparam(FILE* oilfile, astree* node);
void efunctbody(FILE* oilfile, astree* node);
//------------------------------------------------------------------

//------------------------------------------------------------------
void ecallname(FILE* oilfile, astree* node);
void ecallparams(FILE* oilfile, astree* node);
//------------------------------------------------------------------

//------------------------------------------------------------------
void emit(FILE* oilfile, astree* node);
void emain(FILE* oilfile, astree* root);
void eeverything(FILE* oilfile, astree* root);
//------------------------------------------------------------------
