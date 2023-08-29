/*!
    \file 
    \brief Running file of oppening txt file for reading
*/

#include "head.h"

FILE * fileopening (void)
{
    FILE *file_testing = NULL;
    if ((file_testing = fopen ("tests.txt", "r")) == NULL) //check for opening
    {
        MYASSERT(0);
    }
    return file_testing;
}
