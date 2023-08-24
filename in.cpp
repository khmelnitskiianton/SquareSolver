#include "allfunc.h"

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
        printf ("\n\033[1;31mWtf? Its not double number. Maybe it is a single number. Another attempt you piece of shit, hey you, MAAAAN!\033[1;0m\n");
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
        if (amount == 1) printf ("\033[1;34mYou enter a = %.2lf !\033[1;0m\n", args[0]);
        if (amount == 2) printf ("\033[1;34mNow you enter a = %.2lf and b = %.2lf !!\033[1;0m\n", args[0], args[1]);
        if (amount == 3) printf ("\033[1;34mSuper, you enter a = %.2lf and b = %.2lf and c = %.2lf !!!\033[1;0m\n", args[0], args[1], args[2]);
    }
}

//11.
int welcome (void)
{
    int ch = 0;

    printf ("\033[1;35m    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------\033[1;0m\n");
    printf ("\033[1;36mEnter arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "   Please enter only normal double numbers!!!\033[1;0m\n");
    printf ("\033[1;33m    YOU WANT TO USE AUTO TESTING ???\n"
           "    Enter Y or N\033[1;0m\n");

    ch = getchar ();
    clean_buffer ();
    if (toupper (ch) == 'Y') test_allfile ();

    printf ("\033[1;33m    Do you want to continue use this program ??? \n    Enter Y or N \033[1;0m\n");

    ch = getchar ();
    clean_buffer ();

    if (toupper (ch) == 'Y')
    {
        printf ("\033[1;32mNOW enter 3 arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
               "    After every number press enter/tab/space!\033[1;0m\n");
        return 0;    
    }
    else return 1;
}
//12.
void filler_coeffs (double *args)
{
    for(int i = 0; i < QUANTITY; i++)               //initialization of array
    {
        args[i] = NAN;
    }
}