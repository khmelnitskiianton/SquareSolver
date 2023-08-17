#include <stdio.h>
#include <math.h>

#define EPSILONE 1e-10 //invite constant because of comparing

int compare(double x, double y);

int main(void)
{
    //1 initialization all parametrs

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    double d = 0;

    //2 Enter all data

    printf("Enter quadratic equation: ax^2 + bx + c = 0. Parametrs is floating point numbers, like 1.0\n");
    printf("a = ");
    scanf("%lf",&a);
    printf("b = ");
    scanf("%lf",&b);
    printf("c = ");
    scanf("%lf",&c);
    printf("(%.4lf)*x^2 + (%.4lf)*x + (%.4lf) = 0\n", a,b,c);

    //3 Enumeration

    if(compare(a,0))
    {
        if(compare(b,0))
        {
            if(compare(c,0))
            {
                printf("Infinity of solutions. a = b = c = 0");
            }
            else
            {
                printf("No solutions. %.4lf = 0",c);
            }
        }
        else
        {
            x1 = -(c/b);
            printf("One solution. x = %.4lf", x1);
        }
    }
    else
    {
        d = b*b-4*a*c;
        if(d > 0)
        {
            x1 = (-b + sqrt(d))/(2*a);
            x2 = (-b - sqrt(d))/(2*a);
            printf("Discriminant is more then 0.Two solutions:\nx1 = %.4lf\nx2 = %.4lf\n",x1,x2);
        }
        else if(compare(d,0))
        {
            x1 = -b/(2*a);
            printf("Discriminant equal to 0.One solution:\nx = %.4lf\n", x1);
        }
        else
        {
            printf("Discriminant is less then 0.No solutions.\n");
        }
    }
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
