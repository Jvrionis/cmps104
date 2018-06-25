// James Vrionis
// jvrionis
// asg3
//--------------------------------------------------------------------
#ifndef __STRING_SET_H__
#define __STRING_SET_H__

#include <iostream>
#include <string>
using namespace std;
//--------------------------------------------------------------------

const string* intern_stringset (const char*);
//const string* string_set::dump (const char*);
/* Insert a new string into the hash set and return a pointer to the
string just inserted. If it is already there, nothing is inserted, and
the previously-inserted string is returned. */
//--------------------------------------------------------------------

void dump_stringset (std::ostream&);
//void string_set::dump (std::ostream&);
/* Dumps out the string set in debug format, which might look as
illustrated in Figure 1. In other words, print the hash header number
followed by spaces, then the hash number and then the address of the
string followed by the string itself. In the this example, the two
strings in bucket 3 have collided. */
//--------------------------------------------------------------------

#endif
