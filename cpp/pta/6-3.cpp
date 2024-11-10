/*
本题要求实现两个函数：一个函数判断给定正整数的各位数字之和是否等于5；另一个函数统计给定区间内有多少个满足上述要求的整数，并计算这些整数的和。

函数接口定义：
int is( int number );
void count_sum( int a, int b );
函数is判断number的各位数字之和是否等于5，是则返回1，否则返回0。

函数count_sum利用函数is统计给定区间[a, b]内有多少个满足上述要求（即令is返回1）的整数，并计算这些整数的和。最后按照格式

count = 满足条件的整数个数, sum = 这些整数的和
进行输出。题目保证0<a≤b≤10000。
*/
#include <stdio.h>

int is(int number);
void count_sum(int a, int b);

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    if (is(a))
        printf("%d is counted.\n", a);
    if (is(b))
        printf("%d is counted.\n", b);
    count_sum(a, b);

    return 0;
}

/* 你的代码将被嵌在这里 */
int is(int number)
{
    int sum = 0;
    for (int n = number; n > 0; n /= 10)
        sum += n % 10;
    if (sum == 5)
        return 1;
    else
        return 0;
}
void count_sum(int a, int b)
{
    int count = 0, sum = 0;
    for (int i = a; i <= b; i++)
    {
        if (is(i))
        {
            count++;
            sum += i;
        }
    }
    printf("count = %d, sum = %d", count, sum);
}