// James Vrionis
// jvrionis
// asg4: string_set.h
//--------------------------------------------------------------------

#ifndef __STRING_SET__
#define __STRING_SET__

//--------------------------------------------------------------------
// void dump_stringset (std::ostream&);
// void string_set::dump (std::ostream&);
// Dumps out the string set in debug format, which might look as
// illustrated in Figure 1. In other words, print the hash header 
// number followed by spaces, then the hash number and then the 
// address of the string followed by the string itself. In the this 
// example, the two strings in bucket 3 have collided. 
//--------------------------------------------------------------------

//--------------------------------------------------------------------
#include <string>
#include <unordered_set>
using namespace std;

#include <stdio.h>
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// String_set(): 
struct string_set {
   string_set();
   static unordered_set<string> set;
   static const string* intern (const char*);
   //const string* string_set::dump (const char*);
   static void dump (FILE*);
};
//--------------------------------------------------------------------

#endif
//--------------------------------------------------------------------

