/*!
    \file 
    \brief Running file of comparing double numbers
*/

#include "head.h"

int compare (double x, double y)
{
    if (((isnan (x) == 1) && (isnan (y) == 1)) || (fabs (x - y) < EPSILONE))
        return 1;
    else
        return 0;
}

int check_double (double z)
{
    return (isnan (z) || isfinite (z));
}
