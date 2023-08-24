#include "allfunc.h"

//13.
int test_solofile(int *n, double mass[], int amount_cor)
{
    double a = mass[0];
    double b = mass[1];
    double c = mass[2];
    double x1_cor = mass[3];
    double x2_cor = mass[4];

    struct Roots decisions = {                  // initialization struct and array
        NAR,
        NAN,
        NAN,
    };
    double parametrs[QUANTITY] = {a,b,c};

    quadratic_solver (&decisions, parametrs);


    if (!(compare (decisions.root1, x1_cor) || compare (decisions.root1, x2_cor)) || !(compare (decisions.root2, x2_cor) || compare (decisions.root2, x1_cor)) || !compare (decisions.amount, amount_cor) )
    {
        printf("TEST %d FAILED: x1 = %lf , x2 = %lf , amount = %d."
        "Expected: x1_cor = %lf , x2_cor = %lf , amount_cor = "
        "%d\n", *n, decisions.root1, decisions.root2, decisions.amount, x1_cor, x2_cor, amount_cor);
    }
    else
    {
        printf ("TEST %d OK\n", *n);
    }
    return 1;    
}

//14.
int test_allfile (void)
{
    int counter = 1;
    FILE *file_testing;
    int lot = 0;
    
    char num1[40];
    char num2[40];

    file_testing = openfile();

    fscanf (file_testing, "%d", &lot);
    double mass[5] = {};

    int amount_cor = 3;

    for (int i = 0; i < lot; i++)
    {   
        filler_coeffs (mass);
        fscanf (file_testing, "%lf %lf %lf %s %s %d", &mass[0], &mass[1], &mass[2], num1, num2, &amount_cor);
        mass[3] = nan_file(num1);
        mass[4] = nan_file(num2);
        counter += test_solofile (&counter, mass, amount_cor);
    }

    if (fclose (file_testing) != 0) printf ("ERROR OF CLOSING\n");  //check for closing

    return counter;        
}