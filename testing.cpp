/*!
    \file 
    \brief Running file of Unit tests from txt file 
*/

#include "head.h"

int test_solofile(int *n, double test_data[], int amount_cor)
{   
    MYASSERT (n != NULL);
    double a = test_data[0];
    double b = test_data[1];
    double c = test_data[2];
    double x1_cor = test_data[3];
    double x2_cor = test_data[4];

    struct Roots decisions = {                 
        UNDEFINED_SOL,
        NAN,
        NAN,
    };
    double parametrs[QUANTITY] = {a,b,c};

    quadratic_solver (&decisions, parametrs);


    if (!(compare (decisions.root1, x1_cor) || compare (decisions.root1, x2_cor)) || !(compare (decisions.root2, x2_cor) || compare (decisions.root2, x1_cor)) || !compare (decisions.amount, amount_cor) )
    {
        printf (RED "TEST %d WITH DATA: [a=%.1lf, b=%.1lf, c=%.1lf] IS FAILED: x1 = %lf , x2 = %lf , amount = %d."
        "Expected: x1_cor = %lf , x2_cor = %lf , amount_cor = "
        "%d\n" RESET, *n, parametrs[0], parametrs[1], parametrs[2], decisions.root1, decisions.root2, decisions.amount, x1_cor, x2_cor, amount_cor);
    }
    else
    {
        printf (GREEN "TEST %d WITH DATA: [a=%.1lf, b=%.1lf, c=%.1lf] IS OK!!!\n" RESET, *n, parametrs[0], parametrs[1], parametrs[2]);
    }
    return 1;    
}

int test_allfile (void)
{
    int counter = 1;
    FILE *file_testing = NULL;
    int lot = 0;
    
    char num1[40];
    char num2[40];

    file_testing = fileopening ();

    fscanf (file_testing, "%d", &lot);
    double test_data[5] = {};

    int amount_cor = UNDEFINED_SOL;

    for (int i = 0; i < lot; i++)
    {   
        filler_coeffs (test_data);
        fscanf (file_testing, "%lf %lf %lf %s %s %d", &test_data[0], &test_data[1], &test_data[2], num1, num2, &amount_cor);
        test_data[3] = nan_file(num1);
        test_data[4] = nan_file(num2);
        counter += test_solofile (&counter, test_data, amount_cor);
    }
    if (fclose (file_testing) != 0) printf (RED "ERROR OF CLOSING!\n" RESET); 

    return counter;        
}

double nan_file (char stroka[])
{   
    char *end;
    if (!(strcmp (stroka, "NAN")) || !(strcmp (stroka, "nan")) || !(strcmp (stroka, "N")) || !(strcmp (stroka, "n")) ) return NAN;
    else return strtod (stroka, &end);
}
