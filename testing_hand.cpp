#include "head.h"

//9. Function of making one test and 10. Function of all tests(many solo)

//9.
int test_solo(int *n, double a, double b, double c, double x1_cor, double x2_cor, int amount_cor)
{
    struct Roots decisions = {                  // initialization struct and array
        UNDEFINED_SOL,
        NAN,
        NAN,
    };
    double parametrs[QUANTITY] = {a,b,c};

    quadratic_solver (&decisions, parametrs);

    if (!(compare (decisions.root1, x1_cor) || compare (decisions.root1, x2_cor)) || !(compare (decisions.root2, x2_cor) || compare (decisions.root2, x1_cor)) || !compare (decisions.amount, amount_cor) )
    {
        printf("\033[1;31mTEST %d FAILED: x1 = %lf , x2 = %lf , amount = %d."
        "Expected: x1_cor = %lf , x2_cor = %lf , amount_cor = "
        "%d\033[1;0m\n", *n, decisions.root1, decisions.root2, decisions.amount, x1_cor, x2_cor, amount_cor);
    }
    else
    {
        printf ("\033[1;32mTEST %d OK\033[1;0m\n", *n);
    }
    return 1;
}

//10.
int test_all(void)
{
    int counter = 1;
    counter += test_solo (&counter, 0, 0, 0, NAN, NAN, INF_SOL);
    counter += test_solo (&counter, 1, 2, 1, -1, NAN, ONE_SOL);
    counter += test_solo (&counter, 0, 1, 0, 0, NAN, ONE_SOL);
    counter += test_solo (&counter, 0, 0, 1, NAN, NAN, ZERO_SOL);
    counter += test_solo (&counter, 1, 0, 1, NAN, NAN, ZERO_SOL);
    counter += test_solo (&counter, 1, 0, -2, sqrt(2), -sqrt(2), TWO_SOL);
    counter += test_solo (&counter, -1, 0, 4, 2, -2, TWO_SOL);
    return counter;
}
