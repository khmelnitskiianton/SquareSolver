#include "allfunc.h"

/*
3. Function of clean input of rubbish and 4. Function of enter one double parametr (with security of dumb) and
5. Function of enters many arguments and 6. Function of processing solutions and output
*/

//3.
void clean(void)
{
    int ch = 0;                         //its char, but i use it only for input/output
    while((ch = getchar()) != '\n')     // all rubbish in input line would take
        putchar(ch);
}

//4.
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

//5.
void input_argu(double *argu)
{
    int counter = 0;
    for(int i = 0; i < QUANTITY; i++)
    {
        argu[i] = enter_d();
        counter += 1;
        if (counter == 1) printf("You enter a = %lf !\n", argu[0]);
        if (counter == 2) printf("Now you enter a = %.2lf and b = %.2lf !!\n", argu[0], argu[1]);
        if (counter == 3) printf("Super, you enter a = %.2lf and b = %.2lf and c = %.2lf !!!\n", argu[0], argu[1], argu[2]);
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