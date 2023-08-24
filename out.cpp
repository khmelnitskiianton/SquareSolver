#include "head.h"

void process_out (Roots *sols, int counter)
{
    switch (counter)
    {
        case INF_SOL:
            printf ("\033[1;%dmInfinity of solutions. a = b = c = 0\033[1;%dm", GREEN, RESET);
            break;

        case ZERO_SOL:
            printf ("\033[1;%dmNo solutions.\033[1;%dm", GREEN, RESET);
            break;

        case ONE_SOL:
            printf ("\033[1;%dmOne solution. x = %lf\033[1;%dm", GREEN, sols -> root1, RESET);
            break;

        case TWO_SOL:
            printf ("\033[1;%dmTwo solutions.\nx1 = %lf\nx2 = %lf\033[1;%dm", GREEN, (*sols).root1, (*sols).root2, RESET);
            break;

        default:
            printf ("\033[1;%dmERROR PROBLEMS IN LOGIC. YOUR LOGIC. CHECK UR BRAINS. AMOUNT NOT NORMAL\033[1;%dm",RED, RESET);
    }
}