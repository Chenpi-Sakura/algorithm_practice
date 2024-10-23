#include <stdio.h>
int main()
{
    int N;
    int a = 0, n = 0, b = 0, max = 0;
    double c = 0.0, d = 0.0;

    scanf("%d", &N);
    while (1)
    {
        scanf("%d", &a);
        if (a % 3 == 0)
        {
            if (a >= max)
            {
                max = a;
            }
        }
        else if (a % 3 == 1)
        {
            b++;
        }
        else if (a % 3 == 2)
        {
            c += a;
            d++;
        }
        n++;
        if (n == N)
        {
            break;
        }
    }

    if (a != 0)
    {
        printf("%d ", max);
    }
    else
    {
        printf("NONE ");
    }

    if (b != 0)
    {
        printf("%d ", b);
    }
    else
    {
        printf("NONE ");
    }

    if (c != 0)
    {
        printf("%.1lf", c / d);
    }
    else
    {
        printf("NONE");
    }

    return 0;
}