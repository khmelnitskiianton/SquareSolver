#include "allfunc.h"

//7. Main function of Quadratic solver and 8. Function of solving specific Linal equations

//7.
void quadratic_solver(Roots *sols, double *args)
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

//8.
void linal_solver(Roots *sols, double *argu)
{
    double x1 = NAN;
    if (compare(argu[1], 0))
    {
        if (compare(argu[2], 0))
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
        x1 = - argu[2] / argu[1];
        if (compare(x1, 0)) sols -> root1 = fabs (x1);
        else sols -> root1 = x1;
    }
}