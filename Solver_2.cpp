#include <stdio.h>
#include <math.h>

int main(void)
{
    //1 Enter data

    double a,b,c;
    printf("Enter quadratic equation: ax^2 + bx + c = 0. Parametrs is floating point numbers, like 1.0\n");
    printf("a = ");
    scanf("%lf",&a);
    printf("b = ");
    scanf("%lf",&b);
    printf("c = ");
    scanf("%lf",&c);
    printf("(%.4lf)*x^2 + (%.4lf)*x + (%.4lf) = 0\n", a,b,c);

    //2 Check for zero parameters

    int flag_a,flag_b,flag_c;
    flag_a = fabs(a) < 0.0001;   //a = 0?
    flag_b = fabs(b) < 0.0001;   //b = 0?
    flag_c = fabs(c) < 0.0001;   //c = 0?

    double x1,x2,d;
    x1 = 0.0;
    x2 = 0.0;
    d = 0.0;

    //3 Enumeration

    if(flag_a)
    {
        if(flag_b)
        {
            if(flag_c)
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
        else if(fabs(d) < 0.0001)
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
