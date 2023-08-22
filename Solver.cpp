#include <stdio.h>
#include <math.h>

#define EPSILONE 1e-10 //invite constant because of comparing

int compare(double x, double y);

double data(void);

void clean(void);

void solver(double *solutions,double a, double b, double c);

int main(void)
{
    //1 initialization all parametrs

    double x = NAN;
    double y = NAN;
    double z = NAN;

    //2 Enter all data

    printf("Enter parametrs(numbers) of quadratic equation: ax^2 + bx + c = 0.\n");
    x = data();
    y = data();
    z = data();

    //3 Enumeration

    //array of solutions, first - count, second and third - numbers
    double solutions[3] = {NAN,NAN,NAN};

    solver(solutions,x,y,z);

    int counter = (int)solutions[0];

    if(counter == -1) printf("Infinity of solutions. a = b = c = 0");
    if(counter == 0) printf("No solutions.");
    if(counter == 1) printf("One solution. x = %lf", solutions[1]);
    if(counter == 2) printf("Two solutions.\nx1 = %lf\nx2 = %lf",solutions[1],solutions[1]);

    return 0;
}

// function equal to == for double
int compare(double x, double y)
{
    if (fabs(x - y) < EPSILONE)
        return 1;
    else
        return 0;
}

//function to clear rubbish
void clean(void)
{
    int ch = 0;//its char, but i use it only for input/output
    while((ch = getchar()) != '\n')
        putchar(ch);
}

//function of correct enter one double parametr
double data(void)
{
    double h = NAN;
    while((scanf("%lf",&h) != 1))
    {
        clean();
        printf("\nWtf? Its not number. Another attemp you piece of shit!\n");
    }
    return h;
}

void solver(double *solutions, double a, double b, double c)
{
    double x1 = NAN;
    double x2 = NAN;
    double d = NAN;

    if(compare(a,0))
    {
        if(compare(b,0))
        {
            if(compare(c,0))
            {
                //printf("Infinity of solutions. a = b = c = 0");
                solutions[0] = -1;
            }
            else
            {
                //printf("No solutions. %lf = 0",c);
                solutions[0] = 0;
            }
        }
        else
        {
            x1 = -(c/b);
            //printf("One solution. x = %lf", x1);
            solutions[0] = 1;
            solutions[1] = x1;
        }
    }
    else
    {
        d = b*b-4*a*c;
        if(d > 0)
        {
            x1 = (-b + sqrt(d))/(2*a);
            x2 = (-b - sqrt(d))/(2*a);
            //printf("Discriminant is more then 0.Two solutions:\nx1 = %lf\nx2 = %lf\n",x1,x2);
            solutions[0] = 2;
            solutions[1] = x1;
            solutions[2] = x2;
        }
        else if(compare(d,0))
        {
            x1 = -b/(2*a);
            //printf("Discriminant equal to 0.One solution:\nx = %lf\n", x1);
            solutions[0] = 1;
            solutions[1] = x1;
        }
        else
        {
            //printf("Discriminant is less then 0.No solutions.\n");
            solutions[0] = 0;
        }
    }

}

