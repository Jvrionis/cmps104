// James Vrionis
// jvrionis
// asg3
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
#include <sys/wait.h> 

using namespace std;

#include "string_set.h"
#include "auxlib.h"
#include "astree.h"
#include "lyutils.h"
//--------------------------------------------------------------------

const string CPP = "/usr/bin/cpp -nostdinc";
FILE* tokout;
string cpp_command;
//--------------------------------------------------------------------

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin.
//void cpp_popen(const char* filename){
void cpp_popen(){    
    yyin = popen(cpp_command.c_str(), "r");
    if (yyin == NULL) {
        syserrprintf(cpp_command.c_str());
        exit (EXIT_FAILURE);

    }else {
        if (yy_flex_debug) {
            fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
                        cpp_command.c_str(), fileno (yyin));
        }
        lexer::newfilename(cpp_command);
        //lexer_newfilename (cpp_command.c_str());
        //scan(filename);
    }
}
//--------------------------------------------------------------------

void cpp_pclose(){
    int pclose_rc = pclose(yyin);
    eprint_status(cpp_command.c_str(), pclose_rc);
    if(pclose_rc != 0 ) exit (EXIT_FAILURE);
}
//--------------------------------------------------------------------

// Grab each token with yylex(), intern it into the stringset, write
// token output to program.tok.
void airtokfile (string filename) {

    string basefile(basename(const_cast<char*> (filename.c_str())));

    char* tokenfile = strdup((basefile.substr(0, basefile.length()-3) + 
                                                       ".tok").c_str());

    tokout = fopen (tokenfile, "w");
    if (tokout == NULL) {
        cout << "Error opening file";
        exit (EXIT_FAILURE);
    }
}
//--------------------------------------------------------------------

// Make .str file containing stringsets
void mstringset (int argc, char** argv, string filename) {
    vector<string> args (&argv[1], &argv[argc]);
    ofstream strfile;

    //set_execname(argv[0]);
    string basefile(basename(const_cast<char*> (filename.c_str())));

    strfile.open(basefile.substr(0, basefile.length()-3) + ".str");
    
    for (const string& arg: args) {
        const string* str = intern_stringset (arg.c_str());
        strfile << "intern(" << arg << ") returned " << str << "->\"" 
                                              << *str << "\"" << endl;
    }

    dump_stringset(strfile);
    strfile.close();
}
//--------------------------------------------------------------------

void mastree(string filename){
    string basefile(basename(const_cast<char*> (filename.c_str())));
    char* astfile = strdup((basefile.substr(0,basefile.length()-3) +
                         ".ast").c_str());
    FILE* outfile = fopen (astfile, "w");
    if (astfile == NULL){ 
        cout << "ERROR mastree: Unable to open file\n"; 
        exit (EXIT_FAILURE);
    }
    //dump(outfile, yyparse_astree);
    astree::dump(outfile, parser::root);
    fclose (outfile);
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
    //cpp_popen (filename.c_str());
}
//--------------------------------------------------------------------

int main (int argc, char* argv[]) {
    
    string filename = argv[argc-1];
    scan_opts (argc, argv, filename);
    
    airtokfile (filename);
    cpp_popen();
    yyparse();
    

    cpp_pclose();
    fclose (tokout);
    mstringset(argc, argv, filename);
    mastree(filename);

    return EXIT_SUCCESS;
}
//--------------------------------------------------------------------
