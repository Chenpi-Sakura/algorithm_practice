/*
题目描述
动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。A 吃 B，B 吃 C，C 吃 A。
现有 N 个动物，以 1 到 N 编号。每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这 N 个动物所构成的食物链关系进行描述：

第一种说法是 1 X Y，表示 X 和 Y 是同类。
第二种说法是 2 X Y，表示 X 吃 Y。 

此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
当前的话与前面的某些真的话冲突，就是假话；
当前的话中 X 或 Y 比 N 大，就是假话；
当前的话表示 X 吃 X，就是假话。 你的任务是根据给定的 N 和 K 句话，输出假话的总数。

输入格式
第一行两个整数，N,K，表示有 N 个动物，K 句话。
第二行开始每行一句话（按照题目要求，见样例）

输出格式
一行，一个整数，表示假话的总数。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 5e4;
int f[N * 3 + 10];

int find(int x)
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

int main( )
{
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n * 3; i++) f[i] = i;
    while (k--)
    {
        int t, x, y; cin >> t >> x >> y;
        if (x > n || y > n) {ans++; continue;}
        if (t == 1)
        {
            if ((find(x + n) == find(y)) || (find(x) == find(y + n))) ans++;
            else
            {
                f[find(x)] = find(y);
                f[find(x + n)] = find(y + n);
                f[find(x + n + n)] = find(y + n + n);
            }
        }
        else
        {
            if (((find(x) == find(y)) || find(x) == find(y + n))) ans++;
            else
            {
                f[find(x + n)] = find(y);
                f[find(x + n + n)] = find(y + n);
                f[find(x)] = find(y + n + n);
            }
        }
    }
    cout << ans << endl;
    return 0;
}