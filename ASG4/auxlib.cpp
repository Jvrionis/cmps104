// James Vrionis
// jvrionis
// asg4: auxlib.cpp
// Utility Code provided by Wesley Mackey
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#ifdef __APPLE__
#include <sys/wait.h>
#else
#include <wait.h>
#endif
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/wait.h>

#include "auxlib.h"
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// int exec::get_exitstatus (void){
//     return exit_status;
// }
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// void set_exitstatus (int newexitstatus){
//     if (exitstatus < newexitstatus) exitstatus = newexitstatus;
//     DEBUGF ('x', "exitstatus = %d\n", exitstatus);
// }
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Var's
int exec::exit_status = EXIT_SUCCESS;
string exec::execname; 
bool alldebugflags = false;
const char* debugflags = "";
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Eprint_signal():
static void eprint_signal (const char* kind, int signal){
   eprintf (", %s %d", kind, signal);
   const char* sigstr = strsignal (signal);
   if (sigstr != NULL) fprintf (stderr, " %s", sigstr);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Eprint_status():
void eprint_status (const char* command, int status){
   if (status == 0) return; 
   eprintf ("%s: status 0x%04X", command, status);
   if (WIFEXITED (status)){
      eprintf (", exit %d", WEXITSTATUS (status));
   }
   if (WIFSIGNALED (status)){
      eprint_signal ("Terminated", WTERMSIG (status));
      #ifdef WCOREDUMP
      if (WCOREDUMP (status)) eprintf (", core dumped");
      #endif
   }
   if (WIFSTOPPED (status)){
      eprint_signal ("Stopped", WSTOPSIG (status));
   }
   if (WIFCONTINUED (status)){
      eprintf (", Continued");
   }
   eprintf ("\n");
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// veprintf():
void veprintf (const char* format, va_list args){
   assert (exec::execname.size() != 0);
   assert (format != NULL);
   fflush (NULL);
   if (strstr (format, "%:") == format){
      fprintf (stderr, "%s: ", exec::execname.c_str());
      format += 2;
   }
   vfprintf (stderr, format, args);
   fflush (NULL);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Eprintf():
void eprintf (const char* format, ...){
   va_list args;
   va_start (args, format);
   veprintf (format, args);
   va_end (args);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Errprintf():
void errprintf (const char* format, ...){
   va_list args;
   va_start (args, format);
   veprintf (format, args);
   va_end (args);
   exec::exit_status = EXIT_FAILURE;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Syserrprintf():
void syserrprintf (const char* object){
   errprintf ("%:%s: %s\n", object, strerror (errno));
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Stubprintf():
void __stubprintf (const char* file, int line, const char* func,
                   const char* format, ...){
   va_list args;
   fflush (NULL);
   printf ("%s: %s[%d] %s: ", exec::execname.c_str(), file, line, func);
   va_start (args, format);
   vprintf (format, args);
   va_end (args);
   fflush (NULL);
}     
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Set_dubugflags():
void set_debugflags (const char* flags){
   debugflags = flags;
   if (strchr (debugflags, '@') != NULL) alldebugflags = true;
   DEBUGF ('x', "Debugflags = \"%s\", all = %d\n",
           debugflags, alldebugflags);
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Is_debugflag():
bool is_debugflag (char flag){
   return alldebugflags or strchr (debugflags, flag) != NULL;
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// Debugprintf():
void __debugprintf (char flag, const char* file, int line,
                    const char* func, const char* format, ...){
    va_list args;
    if (not is_debugflag (flag)) return;
    fflush (NULL);
    va_start (args, format);
    fprintf (stderr, "DEBUGF(%c): %s[%d] %s():\n",
                                       flag, file, line, func);
    vfprintf (stderr, format, args);
    va_end (args);
    fflush (NULL);
}
//-------------------------------------------------------------------


