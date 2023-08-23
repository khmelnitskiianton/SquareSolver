#include "allfunc.h"

//7. Main function of Quadratic solver and 8. Function of solving specific Linal equations

//7.
void q_solver(Roots *sols, double *argu)
{
    double x1 = NAN;
    double x2 = NAN;
    double d = NAN;

    if(compare(argu[0],0))
    {
        l_solver(sols,argu);
    }
    else
    {
        d = argu[1] * argu[1] - 4 * argu[0] * argu[2];
        if(d > 0)
        {
            x1 = (- argu[1] + sqrt(d)) / (2 * argu[0]);
            x2 = (- argu[1] - sqrt(d)) / (2 * argu[0]);
            sols -> amount = 2;
            sols -> root1 = x1;
            sols -> root2 = x2;
        }
        else if(compare(d,0))
        {
            x1 = - argu[1] / (2 * argu[0]);
            sols -> amount = 1;
            sols -> root1 = x1;
        }
        else
        {
            sols -> amount = 0;
        }
    }

}

//8.
void l_solver(Roots *sols, double *argu)
{
    double x1 = NAN;
    if(compare(argu[1],0))
    {
        if(compare(argu[2],0))
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
        x1 = argu[2] / argu[1];
        if (compare(x1,0)) sols -> root1 = fabs(-(argu[2] / argu[1]));
        else sols -> root1 = -(argu[2] / argu[1]);
    }
}