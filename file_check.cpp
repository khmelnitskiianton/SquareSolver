#include "allfunc.h"

FILE * openfile (void)
{
    FILE *file_testing = NULL;
    if ((file_testing = fopen ("tests.txt", "r")) == NULL) //check for opening
    {
        printf ("\033[1;31m!!! ERROR OF OPENING FILE !!!\033[1;0m\n");
        assert(0);
    }
    else return file_testing;
}
