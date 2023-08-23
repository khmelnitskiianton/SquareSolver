#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

//--------------------------------------------------------------------------------------
//constants with define and enum

const double EPSILONE = 1e-36;      //invite epsilone near to 0 for comparing
const int QUANTITY = 3;          //quantity of parametrs (3 in quadratic equation)

enum solutions {
    INF_SOL  = -1,
    ZERO_SOL = 0,
    ONE_SOL  = 1,
    TWO_SOL  = 2,
    NAR      = 3,
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
int compare (double x, double y);

//2. Function of checking for overflow numbers
int check_double (double z);

//3. Function of clean input of rubbish
void clean_buffer (void);

//4. Function of enter one double parametr (with security of dumb)
double enter_double (void);

//5. Function of enters many arguments
void input_args (double *args);

//6. Function of processing solutions and output
void process_out (Roots *sols, int counter);

//7. Main function of Quadratic solver
void quadratic_solver (Roots *sols, double *args);

//8. Function of solving specific Linal equations
void linal_solver (Roots *sols, double *args);

//9. Function of making one test
int test_solo (int *n, double a, double b, double c, double x1_cor, double x2_cor, int amount_cor);

//10. Function of all tests (many solo)
int test_all (void);

//11. Function of connection
int welcome (void);

//12. Function for filler of NAN
void filler_coeffs(double *args);