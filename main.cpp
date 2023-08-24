#include "head.h"                                // HEADER with all func,const and struck

int main()
{   
    double coeffs[QUANTITY] = {};                   // array of coeffs

    filler_coeffs (coeffs);                          //initialization of coeffs

    struct Roots solutions = {                      // initialization struct for form of solutions
        UNDEFINED_SOL,
        NAN,
        NAN,
    };

    int end = welcome ();                            //all connection in one fuction
    if (end) return 0;

    input_args (coeffs);                             //enter all parametrs with security

    MYASSERT(check_double (coeffs[0]));                //Checking for errors
    MYASSERT(check_double (coeffs[1]));
    MYASSERT(check_double (coeffs[2]));
    
    //3. Processing quadratic solver

    quadratic_solver(&solutions, coeffs);            //call quadratic solver

    int nSolutions = solutions.amount;              // initialization amount of solutions

    MYASSERT(check_double (solutions.amount));         //Checking for errors
    MYASSERT(check_double (solutions.root1));
    MYASSERT(check_double (solutions.root2));

    process_out (&solutions, nSolutions);            //call function of output

    return 0;
}
