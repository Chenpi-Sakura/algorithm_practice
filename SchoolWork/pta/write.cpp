#include <stdio.h>
int main()
{
    int N, i, max, min, p, q, t1, t2, n1, n2;
    scanf("%d", &N);
    int a[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0], min = a[0];
    n1 = 0;
    n2 = 0;
    for (q = 0; q < N; q++)
    {
        if (a[q] < min)
        {
            min = a[q];
            n1 = q;
        }
    }
    t1 = a[0];
    a[0] = min;
    a[n1] = t1;
    for (p = 0; p < N; p++)
    {
        if (a[p] > max)
        {
            max = a[p];
            n2 = p;
        }
    }
    t2 = a[N - 1];
    a[N - 1] = max;
    a[n2] = t2;
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}