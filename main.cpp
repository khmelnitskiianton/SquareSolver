/*!
    \file 
    \brief Main running file 
*/

#include "head.h"                              

int main()
{   
    double coeffs[QUANTITY] = {};                 

    filler_coeffs (coeffs);                   

    struct Roots solutions = {                      
        UNDEFINED_SOL,
        NAN,
        NAN,
    };

    int end = welcome ();               
    if (end) 
    {
        printf ("\n" MAGENTA "GOODBYE FRIEND!!! OPEN ME ONE MORE TIME!\n" RESET "\n");
        return 0;
    }
    input_args (coeffs);                       
    MYASSERT (check_double (coeffs[0]));            
    MYASSERT (check_double (coeffs[1]));
    MYASSERT (check_double (coeffs[2]));

    quadratic_solver (&solutions, coeffs);        

    int nSolutions = solutions.amount;          

    MYASSERT (check_double (solutions.amount));      
    MYASSERT (check_double (solutions.root1));
    MYASSERT (check_double (solutions.root2));

    process_out (&solutions, nSolutions);      
    printf ("\n" MAGENTA "GOODBYE FRIEND!!! OPEN ME ONE MORE TIME!\n" RESET);
    return 0;
}
