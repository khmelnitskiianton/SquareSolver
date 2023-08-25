/*!
    \file 
    \brief Running file of input and entering 
*/

#include "head.h"

void clean_buffer (void)
{
    int ch = 0;                     
    while ((ch = getchar ()) != '\n') {}   
}

double enter_double (void)
{
    double num = NAN;
    while((scanf ("%lf", &num) != 1) || !(check_double (num)))
    {   
        clean_buffer ();
        printf ("\n\033[1;31mWtf? Its not normal double number. Maybe it is infinite/NAN number or letters. Another attempt you piece of shit, hey you, MAAAAN!\033[1;0m\n");
    }
    return num;
}

void input_args (double *args)
{
    int amount = 0;
    for (int i = 0; i < QUANTITY; i++)
    {
        args[i] = enter_double ();
        amount += 1;
        if (amount == 1) printf ("\033[1;34mYou enter a = %.2lf !\033[1;0m\n", args[0]);
        if (amount == 2) printf ("\033[1;34mNow you enter a = %.2lf and b = %.2lf !!\033[1;0m\n", args[0], args[1]);
        if (amount == 3) printf ("\033[1;34mSuper, you enter a = %.2lf and b = %.2lf and c = %.2lf !!!\033[1;0m\n", args[0], args[1], args[2]);
    }
}

int welcome (void)
{
    printf ("\n\033[1;%dm    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------\033[1;%dm\n", MAGENTA, RESET);
    printf ("\n\033[1;%dmEnter arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "   Please enter only normal double numbers!!!\033[1;%dm\n", CYAN, RESET);
    printf ("\n\033[1;%dm    YOU WANT TO USE AUTO TESTING ???\n"
           "        Enter Y or N\033[1;%dm\n            ", YELLOW, RESET);

    if (user_choice () == 'Y') test_allfile ();

    printf ("\033[1;%dm    Do you want to continue use this program ??? \n    "
        "   Enter Y or N \033[1;%dm\n           ", YELLOW, RESET);

    if (user_choice () == 'Y')
    {
        printf ("\033[1;%dmNOW enter 3 arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
               "    After every number press enter/tab/space!\033[1;%dm\n", GREEN, RESET);
        return 0;    
    }
    else
    { 
    return 1;
    }
}

void filler_coeffs (double *args)
{
    for (int i = 0; i < QUANTITY; i++)               //initialization of array
    {
        args[i] = NAN;
    }
}

int user_choice (void)
{
    int ch = 0;
    ch = getchar ();
    while (toupper (ch) != 'N')
    {
        if ((toupper (ch)) == 'Y') break;
        printf ("\033[1;%dmPRINT Y OR N! WHAT THE FUCK DONT YOU UNDERSTAND, BASTARD?\033[1;%dm\n", RED, RESET);
        clean_buffer ();
        ch = getchar ();
    }
    printf ("\033[1;%dmYou choose %c !\033[1;%dm\n", CYAN, ch, RESET);
    clean_buffer ();
    return toupper (ch);
}