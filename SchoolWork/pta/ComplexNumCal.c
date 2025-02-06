/*
7-3 复数四则运算
本题要求编写程序，计算2个复数的和、差、积、商。

输入格式：
输入在一行中按照a1 b1 a2 b2的格式给出2个复数C1=a1+b1i和C2=a2+b2i的实部和虚部。题目保证C2不为0。

输出格式：
分别在4行中按照(a1+b1i) 运算符 (a2+b2i) = 结果的格式顺序输出2个复数的和、差、积、商，数字精确到小数点后1位。如果结果的实部或者虚部为0，则不输出。如果结果为0，则输出0.0。

输入样例1：
2 3.08 -2.04 5.06
输出样例1：
(2.0+3.1i) + (-2.0+5.1i) = 8.1i
(2.0+3.1i) - (-2.0+5.1i) = 4.0-2.0i
(2.0+3.1i) * (-2.0+5.1i) = -19.7+3.8i
(2.0+3.1i) / (-2.0+5.1i) = 0.4-0.6i

输入样例2：
1 1 -1 -1.01
输出样例2：
(1.0+1.0i) + (-1.0-1.0i) = 0.0
(1.0+1.0i) - (-1.0-1.0i) = 2.0+2.0i
(1.0+1.0i) * (-1.0-1.0i) = -2.0i
(1.0+1.0i) / (-1.0-1.0i) = -1.0
*/
#include <stdio.h>
#include <math.h>

const double N = 1e-1;

typedef struct
{
    double real;
    double imag;
}ComNum;

void printComNum(ComNum *n)
{
    if (fabs(n->real) < N)
    {
        n->real = 0.0;
    }
    if (fabs(n->imag) < N)
    {
        n->imag = 0.0;
    }//对接近0的double进行处理
    printf("(");
    printf("%.1lf", n->real);
    if (n->imag >= 0)
    {
        printf("+");
    }
    printf("%.1lfi", n->imag);
    printf(")");
}

void printCom(ComNum *n)
{
    if (fabs(n->real) < N)
    {
        n->real = 0.0;
    }
    if (fabs(n->imag) < N)
    {
        n->imag = 0.0;
    }//对接近0的double进行处理

    if (n->real != 0.0 && n->imag != 0.0)
    {
        printf("%.1lf", n->real);
        if (n->imag > 0)
        {
            printf("+");
        }
        printf("%.1lfi", n->imag);
    }//实部虚部皆存在
    else if (n->real == 0.0 && n->imag != 0.0)
    {
        printf("%.1lfi", n->imag);
    }//仅存在虚部
    else if (n->real != 0.0 && n->imag == 0.0)
    {
        printf("%.1lf", n->real);
    }//仅存在实部
    else
    {
        printf("0.0");
    }//实部虚部皆不存在
}

void output(ComNum *n1, ComNum *n2, char op)
{
    ComNum temp;
    if (op == '+')
    {
        temp.real = n1->real + n2->real;
        temp.imag = n1->imag + n2->imag;
    }
    else if (op == '-')
    {
        temp.real = n1->real - n2->real;
        temp.imag = n1->imag - n2->imag;
    }
    else if (op == '*')
    {
        temp.real = n1->real * n2->real - n1->imag * n2->imag;
        temp.imag = n1->real * n2->imag + n1->imag * n2->real;
    }
    else if (op == '/')
    {
        double denom = n2->real * n2->real + n2->imag * n2->imag;
        temp.real = (n1->real * n2->real + n1->imag * n2->imag) / denom;
        temp.imag = (n1->imag * n2->real - n1->real * n2->imag) / denom;
    }

    printComNum(n1);
    printf(" %c ", op);
    printComNum(n2);
    printf(" = ");
    printCom(&temp);
    printf("\n");
}

int main()
{
    ComNum n1, n2;
    scanf("%lf %lf %lf %lf", &n1.real, &n1.imag, &n2.real, &n2.imag);
    output(&n1, &n2, '+');
    output(&n1, &n2, '-');
    output(&n1, &n2, '*');
    output(&n1, &n2, '/');
    return 0;
}