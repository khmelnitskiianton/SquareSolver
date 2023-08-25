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
        printf ("\n" RED "Wtf? Its not normal double number. Maybe it is infinite/NAN number or letters. Another attempt you piece of shit, hey you, MAAAAN!" RESET "\n");
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
        if (amount == 1) printf (BLUE "You enter a = %.2lf !" RESET "\n", args[0]);
        if (amount == 2) printf (BLUE "Now you enter a = %.2lf and b = %.2lf !!" RESET "\n", args[0], args[1]);
        if (amount == 3) printf (BLUE "Super, you enter a = %.2lf and b = %.2lf and c = %.2lf !!!" RESET "\n", args[0], args[1], args[2]);
    }
}

int welcome (void)
{
    printf ("\n" MAGENTA "    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------" RESET "\n");
    printf ("\n" CYAN "Enter arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "   Please enter only normal double numbers!!!" RESET "\n");
    printf ("\n" YELLOW "    YOU WANT TO USE AUTO TESTING ???\n"
           "        Enter Y or N" RESET "\n            ");

    if (user_choice () == 'Y') test_allfile ();

    printf (YELLOW "    Do you want to continue use this program ??? \n    "
        "   Enter Y or N" RESET"\n           ");

    if (user_choice () == 'Y')
    {
        printf (GREEN "Enter 3 arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
               "    After every number press enter/tab/space!" RESET "\n");
        return 0;    
    }
    else
    { 
    return 1;
    }
}

void filler_coeffs (double *args)
{
    for (int i = 0; i < QUANTITY; i++)             
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
        printf ( RED "PRINT Y OR N! WHAT THE FUCK DONT YOU UNDERSTAND, BASTARD?" RESET "\n");
        clean_buffer ();
        ch = getchar ();
    }
    printf (CYAN "You choose %c !" RESET "\n", ch);
    clean_buffer ();
    return toupper (ch);
}