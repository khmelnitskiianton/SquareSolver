#include <math.h>
#include <stdio.h>
#include <assert.h>

//--------------------------------------------------------------------------------------
//constants with define and enum

#define EPSILONE 1e-36      //invite epsilone near to 0 for comparing
#define QUANTITY 3          //quantity of parametrs (3 in quadratic equation)

enum solutions{
    INF_SOL  = -1,
    ZERO_SOL = 0,
    ONE_SOL  = 1,
    TWO_SOL = 2,
    NAR = 3,
};

//--------------------------------------------------------------------------------------
//Structure for solutions

struct Roots                //structure form for solutions
{
    int amount;
    double root1;
    double root2;
};

//--------------------------------------------------------------------------------------
//Initialization all Functions

//1. Compare two double numbers
int compare(double x, double y);

//2. Function of checking for overflow numbers
int check(double z);

//3. Function of clean input of rubbish
void clean(void);

//4. Function of enter one double parametr (with security of dumb)
double enter_d(void);

//5. Function of enters many arguments
void input_argu(double *argu);

//6. Function of processing solutions and output
void process_out(Roots *sols, int counter);

//7. Main function of Quadratic solver
void q_solver(Roots *sols, double *argu);

//8. Function of solving specific Linal equations
void l_solver(Roots *sols, double *argu);

//9. Function of making one test
int test_solo(int *n, double a, double b, double c, double x1_cor, double x2_cor, int amount_cor);

//10. Function of all tests(many solo)
void test_all(void);