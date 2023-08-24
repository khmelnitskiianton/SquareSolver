#include "allfunc.h"

//1. Compare two double numbers and 2. Function of checking for overflow numbers

//1.
int compare (double x, double y)
{
    if ((isnan (x) == 1)&&(isnan (y) == 1))
        return 1;
    if (fabs (x - y) < EPSILONE)         //with help of epsilone equal to ==
        return 1;
    else
        return 0;
}

//2.
int check_double (double z)
{
    return (isnan (z) || isfinite (z));
}

//16.
double nan_file(char stroka[])
{   
    char * end;
    if (!(strcmp (stroka, "NAN")) || !(strcmp (stroka, "nan")) || !(strcmp (stroka, "N")) || !(strcmp (stroka, "n")) ) return NAN;
    else return strtod (stroka, &end);
}