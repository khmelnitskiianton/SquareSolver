#include "allfunc.h"

FILE * openfile(void)
{
    FILE *file_testing = NULL;
    if ((file_testing = fopen ("tests.txt", "r")) == NULL) //check for opening
    {
        printf ("!!! ERROR OF OPENING FILE !!!\n");
        assert(0);
    }
    else return file_testing;
}
