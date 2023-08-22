#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "allfunc.h" // HEADER with all func,const and struck

//--------------------------------------------------------------------------------------
//MAIN

int main(void)
{
    //1. initialization all parametrs

    double a = NAN, b = NAN, c = NAN;

    //2. Enter all data(with security)

    printf("    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------------------------\n");
    printf("Enter parametrs(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "       Please enter only normal double numbers!!!\n");

    a = enter();
    b = enter();
    c = enter();

    //3. Processing qua_solver

    struct Roots solutions = {    // initialization struct for form of solutions
        NAR,
        NAN,
        NAN,
    };

    assert(isnan(a) || isfinite(a));
    assert(isnan(b) || isfinite(b));
    assert(isnan(c) || isfinite(c));

    qua_solver(&solutions,a,b,c);  //call quadratic solver

    int counter = (int)solutions.amount; // initialization amount of solutions

    assert(isnan(solutions.amount) || isfinite(solutions.amount));
    assert(isnan(solutions.root1) || isfinite(solutions.root1));
    assert(isnan(solutions.root2) || isfinite(solutions.root2));

    process(&solutions, counter);  //call function of output

    return 0;
}

//--------------------------------------------------------------------------------------
// Describe all functions

//1.
int compare(double x, double y)
{
    if (fabs(x - y) < EPSILONE)   //with help of epsilone equal to ==
        return 1;
    else
        return 0;
}

//2.
void clean(void)
{
    int ch = 0; //its char, but i use it only for input/output
    while((ch = getchar()) != '\n')   // all rubbish in input line would take
        putchar(ch);
}

//3.
double enter(void)
{
    double h = NAN;
    while((scanf("%lf",&h) != 1) || check(h))   //realization of security with char and biggest numbers
    {
        clean();
        printf("\nWtf? Its not double number. Another attemp you piece of shit!\n");
    }
    return h;
}

//4.
void qua_solver(Roots *sols, double a, double b, double c)
{
    double x1 = NAN;
    double x2 = NAN;
    double d = NAN;

    if(compare(a,0))
    {
        lin_solver(sols,b,c);
    }
    else
    {
        d = b * b - 4 * a * c;
        if(d > 0)
        {
            x1 = (- b + sqrt(d)) / (2 * a);
            x2 = (- b - sqrt(d)) / (2 * a);
            sols -> amount = 2;
            sols -> root1 = x1;
            sols -> root2 = x2;
        }
        else if(compare(d,0))
        {
            x1 = - b / (2 * a);
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
void lin_solver(Roots *sols, double b, double c)
{
    double x1 = NAN;
    if(compare(b,0))
    {
        if(compare(c,0))
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
        x1 = c/b;
        if (compare(x1,0)) sols -> root1 = fabs(-(c/b));
        else sols -> root1 = -(c/b);

    }
}

//6.
void process(Roots *sols, int counter)
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
            printf("ERROR PROBLEMS IN LOGIC. COUNTER NOT NORMAL");
    }
}

//7.
int check(double z)
{
    return !(isnan(z) || isfinite(z));
}

