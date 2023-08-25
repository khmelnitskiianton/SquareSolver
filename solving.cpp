/*!
    \file 
    \brief Running file of calculating quadratic equation 
*/

#include "head.h"

void quadratic_solver (Roots *sols, double *args)
{
    double x1 = NAN;
    double x2 = NAN;
    double d = NAN;

    if (compare (args[0], 0))
    {
        linal_solver (sols, args);
    }
    else
    {
        d = args[1] * args[1] - 4 * args[0] * args[2];
        if (d > 0)
        {   
            double sqrt_d = sqrt (d);
            x1 = (- args[1] + sqrt_d) / (2 * args[0]);
            x2 = (- args[1] - sqrt_d) / (2 * args[0]);
            sols -> amount = 2;
            sols -> root1 = x1;
            sols -> root2 = x2;
        }
        else if (compare (d, 0)) 
        {
            x1 = - args[1] / (2 * args[0]);
            sols -> amount = 1;
            if (compare (x1, 0)) sols -> root1 = fabs (x1);
            else sols -> root1 = x1; 
        }
        else
        {
            sols -> amount = 0;
        }
    }

}

void linal_solver (Roots *sols, double *args)
{
    double x1 = NAN;
    if (compare (args[1], 0))
    {
        if (compare (args[2], 0))
        {
            sols -> amount = -1;
        }
        else
        {
            sols -> amount = 0;
        }
    }
    else
    {
        sols -> amount = 1;
        x1 = - args[2] / args[1];
        if (compare (x1, 0)) sols -> root1 = fabs (x1);
        else sols -> root1 = x1;
    }
}