/*!
    \file 
    \brief Running file of output, and resulting 
*/

#include "head.h"

void process_out (Roots *sols, int counter)
{
    switch (counter)
    {
        case INF_SOL:
            printf (GREEN "Infinity of solutions. a = b = c = 0\n" RESET);
            break;

        case ZERO_SOL:
            printf (GREEN "No solutions.\n" RESET);
            break;

        case ONE_SOL:
            printf (GREEN "One solution. x = %lf\n" RESET, sols -> root1);
            break;

        case TWO_SOL:
            printf (GREEN "Two solutions.\nx1 = %lf\nx2 = %lf\033[1;%dm\n" RESET, (*sols).root1, (*sols).root2);
            break;

        default:
            printf (RED "ERROR PROBLEMS IN LOGIC. YOUR LOGIC. CHECK UR BRAINS. AMOUNT NOT NORMAL\n" RESET);
    }
}