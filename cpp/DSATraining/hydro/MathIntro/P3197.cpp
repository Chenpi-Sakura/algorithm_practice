/*
#P3197. [HNOI2008] 越狱
题目描述
监狱有 n 个房间，每个房间关押一个犯人，有 m 种宗教，每个犯人会信仰其中一种。如果相邻房间的犯人的宗教相同，就可能发生越狱，求有多少种状态可能发生越狱。

答案对 100003 取模。

输入格式
输入只有一行两个整数，分别代表宗教数 m 和房间数 n。

输出格式
输出一行一个整数代表答案。
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100003;

LL quickpow(LL x, LL y)
{
    LL result = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            result = result * x % N;
        x = x * x % N;
        y /= 2;
    }
    return result;
} // 快速幂避免溢出加快运算

LL tick(LL m, LL n)
{
    if (n == 1)
        return 0;
    LL total = quickpow(m, n);
    LL safe = m * quickpow(m - 1, n - 1) % N;
    LL risk = (total - safe + N) % N;
    return risk;
}
// 数学真的很重要啊！！！ 最基本的排列组合，容斥原理！！！

int main()
{
    LL m, n;
    cin >> m >> n;
    cout << tick(m, n);
    return 0;
}