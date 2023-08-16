#include <stdio.h>
#include <TXLib.h>
#include <math.h>

int main(void)
{
    //1 ���� - ���� ������
    float a,b,c;
    printf("������� ���������� ���������: ax^2 + bx + c = 0. ������������-����� � ��������� ������, ���� 1.0\n");
    printf("a = ");
    scanf("%f",&a);
    printf("b = ");
    scanf("%f",&b);
    printf("c = ");
    scanf("%f",&c);
    printf("���������� ���������: (%f)*x^2 + (%f)*x + (%f) = 0\n", a,b,c);

    //2 ���� - �������� ���� ���������� �� 0
    int flag_a,flag_b,flag_c;
    flag_a = fabs(a) < 0.0001;   //a = 0?
    flag_b = fabs(b) < 0.0001;   //b = 0?
    flag_c = fabs(c) < 0.0001;   //c = 0?

    float x1,x2,d;

    //3 ���� - �������� ���� ������� � ����� �������

    if(flag_a)
    {
        if(flag_b)
        {
            if(flag_c)
            {
                printf("������� ����������� ���-��. a = b = c = 0");
            }
            else
            {
                printf("������� ���. %f = 0",c);
            }
        }
        else
        {
            x1 = -(c/b);
            printf("������� ����. x = %f", x1);
        }
    }
    else
    {
        d = b*b-4*a*c;
        if(d > 0)
        {
            x1 = (-b + sqrtf(d))/(2*a);
            x2 = (-b - sqrtf(d))/(2*a);
            printf("������������ ������ 0.��� �������:\nx1 = %f\nx2 = %f\n",x1,x2);
        }
        else if(fabs(d) < 0.0001)
        {
            x1 = -b/(2*a);
            printf("������������ ����� 0.������� ����:\nx = %f\n", x1);
        }
        else
        {
            printf("������������ ������ 0.������� ���.\n");
        }
    }

    return 0;
}
