// James Vrionis
// jvrionis
// asg5: main.cpp
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#ifdef __APPLE__
#include <sys/wait.h>
#else
#include <wait.h>
#endif
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include <string>
#include <iostream>
using namespace std;

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxlib.h"
#include "string_set.h"
#include "astree.h"
#include "lyutils.h"
#include "symstack.h"
#include "symtable.h"
#include "typecheck.h"
#include "emit.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
string CPP = "/usr/bin/cpp -nostdinc";
string cpp_command;
constexpr size_t LINESIZE=1024; 
extern astree* yyparse_astree;
size_t block_count = 1;

const char* filename;
const char* output_file;
const char* oil_output_name;
const char* tok_output_name;
const char* sym_output_name;
const char* str_output_name;
const char* ast_output_name;
FILE* oilfile;
FILE* tok_output_file;
FILE* sym_output_file;
FILE* ast_output_file;
FILE* str_output_file;


//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Attach extension to suffix 
// <output_file>.<extension>
const char* suffix(const char* filename ,const char* extension){
   const char* output_file =  strtok ((char*)filename,".");
   strcat ((char*)output_file, extension);
   return output_file;
}
//--------------------------------------------------------------------
   
//--------------------------------------------------------------------
// '.tok' format to file named output
//  Read from yyparse 
void format(){   
    // creates the output file name with the ".tok" extension
    if(tok_output_file == NULL){
        cerr <<"Suffix Error(1): Unable to open file"<< endl;
    }
    const char* tok_output_name = suffix(filename ,".tok");
    tok_output_file = fopen (tok_output_name, "w");
    
    yyparse();
    fclose(tok_output_file);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim){
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin. 
void cpp_popen (const char* filename){

    string command = CPP + " " + filename;
   
    yyin = popen (command.c_str(), "r");
    if (yyin == NULL) {
        exec::exit_status = EXIT_FAILURE;
        fprintf (stderr, "%s: %s: %s\n",exec::execname.c_str(), 
                          command.c_str(), strerror (errno));
        exit (exec::exit_status);
   }else {
        if (yy_flex_debug) {
            fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
            cpp_command.c_str(), fileno (yyin));
        }
      //lexer::newfilename(cpp_command);
      format();
   }
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Close C preprocessor pipe.
void cpp_pclose(){
   exec::exit_status = EXIT_SUCCESS;
   int pclose_rc = pclose (yyin);
   eprint_status (cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) exit (exec::exit_status) ;
}
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// Scan and set options.
void scan_opts (int argc, char** argv){    
    int opt;
    yy_flex_debug = 0, opterr = 0, yydebug = 0, opterr = 0;
    lexer::interactive = isatty (fileno (stdin)) && 
                                             isatty (fileno (stdout));

// // string filename = argv[argc-1];char* filename2 = argv[argc-1];
// // string command = CPP + " " + filename2; ofstream outfile;
// // check: (if true)
// //  1) correct use, 
// //  2) check for options 
    
    if( optind > argc){
        cerr<<"Error(2): Incorrect input file. Please provide a .oc " 
                        "file" << endl;
        exit(exec::exit_status);
    }else{
        while ((opt = getopt (argc, argv, "@:D:ly")) != -1){
            switch (opt){
                case 'l': cout <<"Option"<< opt <<"used"<< endl; break;
                case 'y': cout <<"Option"<< opt <<"used"<< endl; break;
                case '@': set_debugflags (optarg); break;
                case 'D': cpp_command = CPP+" -D"+optarg+" "+filename;
                        break;
                default:
                    cerr << "Error(3): Bad option " << 
                                             opterr << endl; 
                        break;
            }
        }
    }
    if (optind > argc){
        //cerr << "Usage Error(4)..   " << endl;
        errprintf ("Usage: oc [-ly] [-@ flags..] [-D string] %s\n",
                                          exec::execname.c_str());
        exit (exec::exit_status);
    }
   //size_t i = filename.rfind('.', filename.length());
   // Pipe through CPP in order to open file
   filename = optind == argc ? "-" :argv[optind];
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
int main (int argc, char** argv){
    // execname to the name of the executable "oc"
    // set exit status to EXIT_SUCCESS by defualt
    // Arguments read into argv via scan_opts 
    //opens input file, close input file
    
    exec::execname = basename (argv[0]);
    exec::exit_status = EXIT_SUCCESS;
    scan_opts (argc, argv);
    
    cpp_popen (filename);
    cpp_pclose();


    if(exec::exit_status == EXIT_FAILURE){
         cerr << "Main Error(5): check input/output " << endl;
    return exec::exit_status;
    }
    // for '.sym' file extension 
    const char* sym_output_name = suffix(filename ,".sym");
    sym_output_file = fopen (sym_output_name, "w");

    // '.oil' file extension to file output
    oilfile = fopen (oil_output_name, "w");

    fclose(oilfile);

    // '.str' file extension to file output
    const char* str_output_name = suffix(filename ,".str");
    str_output_file = fopen (str_output_name, "w");

    // '.ast' file extension to file output
    const char* ast_output_name = suffix(filename ,".ast");
    ast_output_file = fopen (ast_output_name, "w");

    if(str_output_file == NULL){
        cerr<<"Main Error(6): open file issues"<<endl;
    }

    string_set::dump (str_output_file);
    fclose(str_output_file);

    if(ast_output_file == NULL){
        cerr <<"Main Error(7): File open error"<<endl;
    }

    if (parser::root != NULL){
        astree::print (ast_output_file, parser::root, 0); 
    }
    fclose(ast_output_file);

    return EXIT_SUCCESS;

}
//--------------------------------------------------------------------


