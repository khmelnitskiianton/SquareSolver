//4. Добавить accert
//5. Сделать документацию, doxygen
//7. Более прикольный вывод

#include <stdio.h>
#include <math.h>

//--------------------------------------------------------------------------------------
//constants with define

#define EPSILONE 1e-10      //invite epsilone near to 0 for comparing
#define INF_SOLUTIONS -1    //constant of -1 for case [0 0 0]
#define NAR 3               //Not a Root for some shit with amount of solutions

//--------------------------------------------------------------------------------------
//Structure for solutions

struct solver_form          //structure form for solutions
{
    int amount;
    double root1;
    double root2;
};

//--------------------------------------------------------------------------------------
//Initialization all Functions

//1. Compare two double numbers
int compare(double x, double y);

//2. Function of enter one double parametr (with security of dumb)
double enter(void);

//3. Function of clean input of rubbish
void clean(void);

//4. Main function of square solver
void qua_solver(solver_form *sols, double a, double b, double c);

//5. Function of solving specific linal equations
void lin_solver(solver_form *sols, double b, double c);

//6. Function of processing solutions and output
void process(solver_form *sols, int counter);

//7. Function of checking for overflow numbers
int check(double z);

//--------------------------------------------------------------------------------------
//MAIN

int main(void)
{
    //1. initialization all parametrs

    double a = NAN;
    double b = NAN;
    double c = NAN;

    //2. Enter all data(with security)

    printf("Enter parametrs(numbers) of quadratic equation: ax^2 + bx + c = 0.\n");

    a = enter();
    b = enter();
    c = enter();

    //3. Processing qua_solver

    struct solver_form solutions = {    // initialization struct for form of solutions
        NAR,
        NAN,
        NAN,
    };

    qua_solver(&solutions,a,b,c);  //call quadratic solver

    int counter = (int)solutions.amount; // initialization amount of solutions

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
        printf("\nWtf? Its not number. Another attemp you piece of shit!\n");
    }
    return h;
}

//4.
void qua_solver(solver_form *sols, double a, double b, double c)
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
void lin_solver(solver_form *sols, double b, double c)
{
    if(compare(b,0))
    {
        if(compare(c,0))
        {
            sols -> amount = INF_SOLUTIONS;
        }
        else
        {
            sols -> amount = 0;
        }
    }
    else
    {
        sols -> amount = 1;
        sols -> root1 = -(c/b);
    }
}

//6.
void process(solver_form *sols, int counter)
{
    switch(counter)
    {
        case INF_SOLUTIONS:
            printf("Infinity of solutions. a = b = c = 0");
            break;
        case 0:
            printf("No solutions.");
            break;
        case 1:
            printf("One solution. x = %lf", sols->root1);
            break;
        case 2:
            printf("Two solutions.\nx1 = %lf\nx2 = %lf",(*sols).root1,(*sols).root2);
            break;
        default:
            printf("You have some shit and problems in logic");
    }
}

//7.
int check(double z)
{
    return !(isnan(z) || isfinite(z));
}
