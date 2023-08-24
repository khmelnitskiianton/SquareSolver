#include "allfunc.h"

void process_out (Roots *sols, int counter)
{
    switch (counter)
    {
        case INF_SOL:
            printf ("\033[1;32mInfinity of solutions. a = b = c = 0\033[1;0m");
            break;

        case ZERO_SOL:
            printf ("\033[1;32mNo solutions.\033[1;0m");
            break;

        case ONE_SOL:
            printf ("\033[1;32mOne solution. x = %lf\033[1;0m", sols -> root1);
            break;

        case TWO_SOL:
            printf ("\033[1;32mTwo solutions.\nx1 = %lf\nx2 = %lf\033[1;0m", (*sols).root1, (*sols).root2);
            break;

        default:
            printf ("\033[1;31mERROR PROBLEMS IN LOGIC. YOUR LOGIC. CHECK UR BRAINS. AMOUNT NOT NORMAL\033[1;0m");
    }
}