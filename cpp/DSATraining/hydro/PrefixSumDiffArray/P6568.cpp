/*
#P6568. [NOI Online #3 提高组] 水壶

题目描述
有n个容量无穷大的水壶，它们从1~n编号，初始时i号水壶中装有Ai单位的水。
你可以进行不超过k次操作，每次操作需要选择一个满足1≤x≤n-1的编号x，然后把x号水壶中的水全部倒入x+1号水壶中。
最后你可以任意选择恰好一个水壶，并喝掉水壶中所有的水。现在请你求出，你最多能喝到多少单位的水。

输入格式
第一行一个正整数 n，表示水壶的个数。
第二行一个非负整数k，表示操作次数上限。
第三行n个非负整数，相邻两个数用空格隔开，表示水壶的初始装水
量 A1,A2,...,An

输出格式
仅一行

Reflection
本质上就是求前缀和，[i, i+k]区间之和的最大值
*/

#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int a[n + 1] = {0}, s[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    int max = -1, temp;
    for (int i = 0; (i + k + 1) <= n; i++) // i = 0 的原因是 第一张牌也要算，i + k + 1是为了加到i + k + 1的杯子里面
    {
        temp = (s[i + k + 1] - s[i]);
        if (temp > max)
            max = temp;
    }

    cout << max;
    return 0;
}