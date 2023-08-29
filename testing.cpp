/*!
    \file 
    \brief Running file of Unit tests from txt file 
*/

#include "head.h"

int test_solofile (int *n, Test_Arguments *test_data)
{   
    MYASSERT(n != NULL);

    struct Roots decisions = {                 
        UNDEFINED_SOL,
        NAN,
        NAN,
    };

    double parametrs[QUANTITY] = {test_data -> a, test_data -> b, test_data -> c};

    quadratic_solver (&decisions, parametrs);

    if (!(compare (decisions.root1, test_data -> x1_cor) || compare (decisions.root1, test_data -> x2_cor)) || !(compare (decisions.root2, test_data -> x2_cor) || compare (decisions.root2, test_data -> x1_cor)) || !compare (decisions.amount, test_data -> amount_cor) )
    {
        printf (RED "TEST %d WITH DATA: [a=%.1lf, b=%.1lf, c=%.1lf] IS FAILED: x1 = %lf , x2 = %lf , amount = %d."
        "Expected: x1_cor = %lf , x2_cor = %lf , amount_cor = "
        "%d\n" RESET, *n, parametrs[0], parametrs[1], parametrs[2], decisions.root1, decisions.root2, decisions.amount, test_data -> x1_cor, test_data -> x2_cor, test_data -> amount_cor);
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
    
    char num1[400] = "";
    char num2[400] = "";

    file_testing = fileopening ();

    fscanf (file_testing, "%d", &lot);

    struct Test_Arguments test_data {
        NAN,
        NAN,
        NAN,
        NAN,
        NAN,
        UNDEFINED_SOL,
    };

    for (int i = 0; i < lot; i++)
    {   
        fscanf (file_testing, "%lf %lf %lf %s %s %d", &test_data.a, &test_data.b, &test_data.c, num1, num2, &test_data.amount_cor);
        test_data.x1_cor = nan_file(num1);
        test_data.x2_cor = nan_file(num2);
        counter += test_solofile (&counter, &test_data);
    }
    if (fclose (file_testing) != 0) printf (RED "ERROR OF CLOSING!\n" RESET); 

    return counter;        
}

double nan_file (char stroka[])
{   
    char *end = NULL;
    if (!(strcmp (stroka, "NAN")) || !(strcmp (stroka, "nan")) || !(strcmp (stroka, "N")) || !(strcmp (stroka, "n")) ) return NAN;
    else return strtod (stroka, &end);
}
