//--------------------------------------------------------------------------------------
//constants with define and enum

const double EPSILONE = 1e-36;      //invite epsilone near to 0 for comparing
const int QUANTITY = 3;          //quantity of parametrs (3 in quadratic equation)

enum solutions {
    INF_SOL  = -1,
    ZERO_SOL = 0,
    ONE_SOL  = 1,
    TWO_SOL  = 2,
    UNDEFINED_SOL = 3,
};

//--------------------------------------------------------------------------------------
//Structure for solutions

struct Roots                //structure form for solutions
{
    int amount;
    double root1;
    double root2;
};

// Main function of Quadratic solver
void quadratic_solver (Roots *sols, double *args);

// Function of solving specific Linal equations
void linal_solver (Roots *sols, double *args);