/*#P3811. 【模板】模意义下的乘法逆元

题目背景
这是一道模板题

题目描述
给定 n,p 求 1∼n 中所有整数在模 p 意义下的乘法逆元。

这里 a 模 p 的乘法逆元定义为 ax ≡ 1(modp) 的解。

输入格式
一行两个正整数 
n,p。

输出格式
输出 n 行，第 i 行表示 i 在模 p 下的乘法逆元。

Reflection 1：
不就是找一个数乘上去然后满足模 p = 1吗？

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        int x = 1;
        while ((i * x) % p != 1)
        {
            x++;
        }
        cout << x << endl;
    }
    return 0;
}
暴力枚举真的很帅！！！

Reflection 2:
这肯定不能暴力枚举，只能寻求一个更加高效的算法了

'''核心 贝祖等式'''

a * x + b * y = gcd(a, b)

a * x + b * y = gcd(a, b) = gcd(b, a mod b)
⇒ b * x + (a mod b) * y
⇒ b * x + (a − ⌊a / b⌋ * b) * y
⇒ a * y + b * (x − ⌊a / b⌋ * y)
(⌊  ⌋ 是向下取整的意思)

x => y      y => x - a / b * y
*/

#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) 
{
    if (b == 0) 
    {
        x = 1;  // 基本情况：gcd(a, 0) = a，解是 x = 1, y = 0
        y = 0;
        return a;
    }

    int gcd = extended_gcd(b, a % b, x, y);  // 递归求解 gcd
    int temp = x;
    x = y;
    y = temp - (a / b) * y;  // 更新 x 和 y
    return gcd;
}

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        if (extended_gcd(i, p, x, y) == 1)
        {
            x = (x + p) % p;
            cout << x << endl;
        }
    }

    return 0;
}