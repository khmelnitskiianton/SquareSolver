//--------------------------------------------------------------------------------------
//constants with define and enum

#define EPSILONE 1e-36      //invite epsilone near to 0 for comparing

enum solutions{
    INF_SOL = -1,
    ZERO_SOL = 0,
    ONE_SOL = 1,
    TWO_SOL = 2,
    NAR = 3,
};

//--------------------------------------------------------------------------------------
//Structure for solutions

struct Roots          //structure form for solutions
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
void qua_solver(Roots *sols, double a, double b, double c);

//5. Function of solving specific linal equations
void lin_solver(Roots *sols, double b, double c);

//6. Function of processing solutions and output
void process(Roots *sols, int counter);

//7. Function of checking for overflow numbers
int check(double z);
