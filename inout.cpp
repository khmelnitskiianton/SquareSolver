#include "allfunc.h"

/*
3. Function of clean input of rubbish and 4. Function of enter one double parametr (with security of dumb) and
5. Function of enters many arguments and 6. Function of processing solutions and output
*/

//3.
void clean_buffer (void)
{
    int ch = 0;                         //its char, but i use it only for input/output
    while((ch = getchar ()) != '\n')     // all rubbish in input line would take
        putchar (ch);
}

//4.
double enter_double (void)
{
    double num = NAN;
    while((scanf ("%lf", &num) != 1) || !(check_double (num)))   //realization of security with char and biggest numbers
    {
        clean_buffer ();
        printf ("\nWtf? Its not double number. Maybe it is a single number. Another attempt you piece of shit, hey you, MAAAAN!\n");
    }
    return num;
}

//5.
void input_args (double *args)
{
    int amount = 0;
    for(int i = 0; i < QUANTITY; i++)
    {
        args[i] = enter_double ();
        amount += 1;
        if (amount == 1) printf ("You enter a = %.2lf !\n", args[0]);
        if (amount == 2) printf ("Now you enter a = %.2lf and b = %.2lf !!\n", args[0], args[1]);
        if (amount == 3) printf ("Super, you enter a = %.2lf and b = %.2lf and c = %.2lf !!!\n", args[0], args[1], args[2]);
    }
}

//6.
void process_out (Roots *sols, int counter)
{
    switch (counter)
    {
        case INF_SOL:
            printf ("Infinity of solutions. a = b = c = 0");
            break;

        case ZERO_SOL:
            printf ("No solutions.");
            break;

        case ONE_SOL:
            printf ("One solution. x = %lf", sols -> root1);
            break;

        case TWO_SOL:
            printf ("Two solutions.\nx1 = %lf\nx2 = %lf", (*sols).root1, (*sols).root2);
            break;

        default:
            printf ("ERROR PROBLEMS IN LOGIC. YOUR LOGIC. CHECK UR BRAINS. AMOUNT NOT NORMAL");
    }
}

//11.
int welcome (void)
{
    int ch = 0;

    printf ("    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------\n");
    printf ("Enter arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "   Please enter only normal double numbers!!!\n");
    printf ("    YOU WANT TO USE AUTO TESTING ???\n"
           "    Enter Y or N\n");

    ch = getchar ();
    clean_buffer ();
    if (toupper (ch) == 'Y') test_all ();

    printf ("Do you want to continue use this program ??? Enter Y or N\n");

    ch = getchar ();
    clean_buffer ();

    if (toupper (ch) == 'Y')
    {
        printf("NOW enter 3 arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
               "    After every number press enter/tab/space!\n");
        return 0;    
    }
    else return 1;
}
//12.
void filler_coeffs(double *args)
{
    for(int i = 0; i < QUANTITY; i++)               //initialization of array
    {
        args[i] = NAN;
    }
}