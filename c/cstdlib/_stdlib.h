//**************************
// Author:  yh
// Time:    2022/1/13
//**************************

#ifndef CESSENCE__STDLIB_H
#define CESSENCE__STDLIB_H
/*
C Standard General Utilities Library
This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.

Functions
String conversion
atof
Convert string to double (function )
atoi
Convert string to integer (function )
atol
Convert string to long integer (function )
atoll
Convert string to long long integer (function )
strtod
Convert string to double (function )
strtof
Convert string to float (function )
strtol
Convert string to long integer (function )
strtold
Convert string to long double (function )
strtoll
Convert string to long long integer (function )
strtoul
Convert string to unsigned long integer (function )
strtoull
Convert string to unsigned long long integer (function )

Pseudo-random sequence generation
rand
Generate random number (function )
srand
Initialize random number generator (function )

Dynamic memory management
calloc
Allocate and zero-initialize array (function )
free
Deallocate memory block (function )
malloc
Allocate memory block (function )
realloc
Reallocate memory block (function )

Environment
abort
Abort current process (function )
atexit
Set function to be executed on exit (function )
at_quick_exit
Set function to be executed on quick exit (function )
exit
Terminate calling process (function )
getenv
Get environment string (function )
quick_exit
Terminate calling process quick (function )
system
Execute system command (function )
_Exit
Terminate calling process (function )

Searching and sorting
bsearch
Binary search in array (function )
qsort
Sort elements of array (function )

Integer arithmetics
abs
Absolute value (function )
div
Integral division (function )
labs
Absolute value (function )
ldiv
Integral division (function )
llabs
Absolute value (function )
lldiv
Integral division (function )

Multibyte characters
mblen
Get length of multibyte character (function )
mbtowc
Convert multibyte sequence to wide character (function )
wctomb
Convert wide character to multibyte sequence (function )

Multibyte strings
mbstowcs
Convert multibyte string to wide-character string (function )
wcstombs
Convert wide-character string to multibyte string (function )

Macro constants
EXIT_FAILURE
Failure termination code (macro )
EXIT_SUCCESS
Success termination code (macro )
MB_CUR_MAX
Maximum size of multibyte characters (macro )
NULL
Null pointer (macro )
RAND_MAX
Maximum value returned by rand (macro )

Types
div_t
Structure returned by div (type )
ldiv_t
Structure returned by ldiv (type )
lldiv_t
Structure returned by lldiv (type )
size_t
Unsigned integral type (type )
 */
#endif //CESSENCE__STDLIB_H
