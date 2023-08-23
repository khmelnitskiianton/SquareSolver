#include "allfunc.h"                    // HEADER with all func,const and struck

int main()
{
    //1. initialization all parametrs

    char ch1 = 'n';
    char ch2 = 'y';

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
            "   Please enter only normal double numbers!!!\n");
    printf("    YOU WANT TO USE AUTO TESTING ???\n"
        "    Enter Y or N\n");

    scanf("%c", &ch1);
    clean();

    if (ch1 == 'y' || ch1 == 'Y') test_all();

    printf("Do you want to continue use this program ??? Enter Y or N\n");

    scanf("%c", &ch2);
    clean();

    if (ch2 != 'y' && ch2 != 'Y') return 0;

    printf("NOW enter 3 arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
    "After every number press enter/tab/space!\n");

    input_argu(coeffs);                    //enter all parametrs with security

    assert(check(coeffs[0]));              //Checking for errors
    assert(check(coeffs[1]));
    assert(check(coeffs[2]));
    
    //3. Processing q_solver

    q_solver(&solutions,coeffs);           //call quadratic solver

    int counter = solutions.amount;   // initialization amount of solutions

    assert(check(solutions.amount));       //Checking for errors
    assert(check(solutions.root1));
    assert(check(solutions.root2));

    process_out(&solutions, counter);      //call function of output

    return 0;
}
