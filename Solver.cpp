#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "allfunc.h"                    // HEADER with all func,const and struck
#include "mytest.h"

//--------------------------------------------------------------------------------------
//MAIN

int main()
{
    //1. initialization all parametrs
    char ch = 'a';

    double coeffs[QUANTITY];            // array of coeffs

    for(int i = 0; i < QUANTITY; i++)   //initialization of array
    {
        coeffs[i] = NAN;
    }

    struct Roots solutions = {          // initialization struct for form of solutions
        NAR,
        NAN,
        NAN,
    };

    //2. enter all data(with security)

    printf("    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------\n");
    printf("Enter arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "       Please enter only normal double numbers!!!\n");
    printf("    YOU WANT TO USE AUTO TESTING ???\n"
        "   Enter Y or N\n");

    scanf("%c", &ch);

    if (ch == 'y' or ch == 'Y') test_all();

    printf("  NOW TIME TO HAND ENTER !!!\n");

    input_argu(coeffs);                    //enter all parametrs with security

    //3. Processing q_solver

    assert(check(coeffs[0]));              //Checking for errors
    assert(check(coeffs[1]));
    assert(check(coeffs[2]));

    q_solver(&solutions,coeffs);           //call quadratic solver

    int counter = (int)solutions.amount;   // initialization amount of solutions

    assert(check(solutions.amount));       //Checking for errors
    assert(check(solutions.root1));
    assert(check(solutions.root2));

    process_out(&solutions, counter);      //call function of output

    return 0;
}

//--------------------------------------------------------------------------------------
// Describe all functions

//1.
int compare(double x, double y)
{
    if ((isnan(x) == 1)&&(isnan(y) == 1))
        return 1;
    if (fabs(x - y) < EPSILONE)         //with help of epsilone equal to ==
        return 1;
    else
        return 0;
}

//2.
void clean(void)
{
    int ch = 0;                         //its char, but i use it only for input/output
    while((ch = getchar()) != '\n')     // all rubbish in input line would take
        putchar(ch);
}

//3.
double enter_d(void)
{
    double h = NAN;
    while((scanf("%lf",&h) != 1) || !(check(h)))   //realization of security with char and biggest numbers
    {
        clean();
        printf("\nWtf? Its not double number. Another attemp you piece of shit!\n");
    }
    return h;
}

//4.
void q_solver(Roots *sols, double *argu)
{
    double x1 = NAN;
    double x2 = NAN;
    double d = NAN;

    if(compare(argu[0],0))
    {
        l_solver(sols,argu);
    }
    else
    {
        d = argu[1] * argu[1] - 4 * argu[0] * argu[2];
        if(d > 0)
        {
            x1 = (- argu[1] + sqrt(d)) / (2 * argu[0]);
            x2 = (- argu[1] - sqrt(d)) / (2 * argu[0]);
            sols -> amount = 2;
            sols -> root1 = x1;
            sols -> root2 = x2;
        }
        else if(compare(d,0))
        {
            x1 = - argu[1] / (2 * argu[0]);
            sols -> amount = 1;
            sols -> root1 = x1;
        }
        else
        {
            sols -> amount = 0;
        }
    }

}

//5.
void l_solver(Roots *sols, double *argu)
{
    double x1 = NAN;
    if(compare(argu[1],0))
    {
        if(compare(argu[2],0))
        {
            sols -> amount = -1;
        }
        else
        {
            sols -> amount = 0;
        }
    }
    else
    {
        sols -> amount = 1;
        x1 = argu[2] / argu[1];
        if (compare(x1,0)) sols -> root1 = fabs(-(argu[2] / argu[1]));
        else sols -> root1 = -(argu[2] / argu[1]);
    }
}

//6.
void process_out(Roots *sols, int counter)
{
    switch(counter)
    {
        case INF_SOL:
            printf("Infinity of solutions. a = b = c = 0");
            break;
        case ZERO_SOL:
            printf("No solutions.");
            break;
        case ONE_SOL:
            printf("One solution. x = %lf", sols->root1);
            break;
        case TWO_SOL:
            printf("Two solutions.\nx1 = %lf\nx2 = %lf",(*sols).root1,(*sols).root2);
            break;
        default:
            printf("ERROR PROBLEMS IN LOGIC. AMOUNT NOT NORMAL");
    }
}

//7.
int check(double z)
{
    return (isnan(z) || isfinite(z));
}

//8.
void input_argu(double *argu)
{
    for(int i = 0; i < QUANTITY; i++)
    {
        argu[i] = enter_d();
    }
}
