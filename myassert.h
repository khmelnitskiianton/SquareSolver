/*!
    \file 
    \brief Header file for myassert
*/
/// \details Like assert() this macros call if error, but it don't stop all programm. Only message of error

#define MYASSERT(condition)                                                                                                              \
    do {                                                                                                                                         \
        if (!(condition))                                                                                                                        \
        {                                                                                                                                        \
            printf (RED "ERROR!!! YOU HAVE SOME PIZDEC IN FILE %s , IN FUNCTION %s , LINE %d\n" RESET, __FILE__, __PRETTY_FUNCTION__, __LINE__); \
            assert(0);                                                                                                                           \
        }                                                                                                                                        \
    } while(0)                                                                                                                                   
