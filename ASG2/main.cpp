// James Vrionis
// jvrionis
// asg2
//--------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#include "string_set.h"
#include "auxlib.h"
#include "astree.h"
#include "lyutils.h"
//--------------------------------------------------------------------

const string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;
FILE* tok_out;
string cpp_command;
//--------------------------------------------------------------------
void scan(string filename){ 
    string basefile(basename(const_cast<char*> (filename.c_str())));

    char* tokenfile = strdup((basefile.substr(0, basefile.length()-3) + 
                        ".tok").c_str());


    tok_out = fopen (tokenfile, "w");
    if(tok_out == NULL){
        cout << "Error: .tok failed to open ";
    }else{
        for (;;) {
            int token = yylex();
            if (yy_flex_debug) fflush (NULL);
            if (token == YYEOF) break;
            const string* tok = intern_stringset (yytext);
            (void)tok;
            DEBUGF('m', "token=%d", token);
        }
    }
    fclose(tok_out);
}
//--------------------------------------------------------------------

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin.
void cpp_popen(const char* filename){
    yyin = popen(cpp_command.c_str(), "r");
    if (yyin == NULL) {
        syserrprintf(cpp_command.c_str());
        exit (EXIT_FAILURE);

    }else {
        if (yy_flex_debug) {
            fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
                        cpp_command.c_str(), fileno (yyin));
        }
        lexer::newfilename(cpp_command.c_str());
        //lexer_newfilename (cpp_command.c_str());
        scan(filename);
    }
}
//--------------------------------------------------------------------

void cpp_pclose(){
    int pclose_rc = pclose(yyin);
    eprint_status(cpp_command.c_str(), pclose_rc);
    if(pclose_rc != 0 ) exit (EXIT_FAILURE);
}
//--------------------------------------------------------------------


void scan_opts (int argc, char** argv, string filename){
    int opt;
    opterr = 0;
    yy_flex_debug = 0; 
    yydebug = 0;
    filename = argv[argc-1];
    
    // string filename = argv[argc-1]; char* filename2 = argv[argc-1];
    // string command = CPP + " " + filename2; ofstream outfile;
    // check: (if true)
    // 1) correct use, 
    // 2) check for options 
    
    size_t i = filename.rfind('.', filename.length());
        if(i == string::npos || filename.substr(i, 
                filename.length()-i) != ".oc"){
        cerr << "Incorrect input file. Please provide a .oc file" 
                                                        << endl;
        exit(EXIT_FAILURE);
    }else{
        while ((opt = getopt (argc, argv, "@:D:ly")) != -1){
            switch (opt){
                case 'l': cout <<"Option"<< opt <<"used"<< endl; break;
                case 'y': cout <<"Option"<< opt <<"used"<< endl; break;
                case '@': set_debugflags (optarg); break;
                case 'D': 
                    cpp_command = CPP + " -D" + optarg + " " + filename;
                    break;
                default:
                    cerr << "Bad option" << opt << endl; break;
            }
        }
    }
    if(optind > argc ){
        errprintf("Usage: oc [-ly] [-@ flags..] [-D string] %s\n",
                      "program.oc");
        exit(EXIT_FAILURE);
    }
    // Pipe through CPP to open file
    cpp_popen (filename.c_str());
}
//--------------------------------------------------------------------

int main (int argc, char* argv[]) {
    
    vector<string> args (&argv[1], &argv[argc]);
    string filename = argv[argc-1];
    
    char* filenameptr = argv[argc-1];
    
    cpp_command = CPP + " " + filenameptr;
    ofstream str_output;


    // sift through input (cpp)
    // insert string sets
    set_execname (argv[0]);

    // make program.str with string sets
    string basefile(basename(const_cast<char*> (filename.c_str())));
 
    // scan the options, then begin to scan input file
    // printf ("command=\"%s\"\n", command.c_str());
    scan_opts(argc, argv, filename);

    // open the program.str file to dump the stringset
    str_output.open(basefile.substr(0, basefile.length()-3) + ".str");
    
    for(const string& arg: args){
        const string* str = intern_stringset (arg.c_str());
        str_output << "intern(" << arg << ") returned " << str 
                   << "->\""  << *str << "\"" << endl;
    }
    // string_set::dump(str_output);
    dump_stringset(str_output);
    str_output.close();

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------
