/*!
    \file 
    \brief Header file for myassert
*/

/// \details Like assert() this macros call if error, but it don't stop all programm. Only message of error
#define MYASSERT(condition) if (!(condition)) printf ("\033[1;%dmERROR!!! YOU HAVE SOME PIZDEC IN FILE %s , IN FUNCTION %s , LINE %d\033[1;%dm\n", RED, __FILE__, __PRETTY_FUNCTION__, __LINE__, RESET)
