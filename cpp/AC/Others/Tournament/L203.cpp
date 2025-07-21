/*
L2-3 花非花，雾非雾
题目描述
CC 在梦中遇到了一个美丽序列，但是醒来已经记不清具体数值了。但幸运的是他还记得些某两个数的异或值，和某些具体值。需要你来帮助他完成序列回忆。
即现在有一个长度为 n 的数列 a1, a2, a3 ··· an ,但是不知道具体数值，现在有 q 条信息，每条信息只会是以下 2 种之一。
1 : U x y w  表示 ax ^ ay = w。
2 : S x y      表示 ax = y。

输入格式
第一行包含 2 个整数 n、q。  （1 ≤ n ≤ 4×10^4，1 ≤ q ≤ 4×10^5)
第二到 q+1 行每行给出一条信息。  (1 ≤ x，y ≤ n，1 ≤ ai ≤ 10^9）

输出格式
对于每条信息，若与前面能得出的信息发生矛盾则忽略本条信息。最后只需输出数列 a，如果不能确定唯一的数列则输出sad。
*/

/*
    引入一个虚拟的 0 号节点，将所有已知的值都通过异或关系连接到这个 0 号节点上。我们使用带权并查集来维护节点之间的异或关系。

    原理： 0 与任何数的异或等于其本身
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 5;
int fa[N], diff[N], ans[N], cnt;

int find(int x)
{
    if (fa[x] == x) return x; // 如果更新过，就直接跳过
    int fx = find(fa[x]);
    diff[x] ^= diff[fa[x]]; // 累积异或值    
    return fa[x] = fx;
}

void unite(int x, int y, int w)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        if (fx == 0) swap(fx, fy), swap(x, y);
        fa[fx] = fy;
        diff[fx] = w ^ diff[x] ^ diff[y];
        cnt--;
    }
}

int main()
{
    int n, q; cin >> n >> q;
    cnt = n + 1;
    for (int i = 0; i <= n; i++) fa[i] = i;
    while (q--)
    {
        char c; int x, y; cin >> c >> x >> y;
        if (c == 'U')
        {
            int w; cin >> w;
            unite(x, y, w);
        }
        else
        {
            unite(x, 0, y);
        }
    }
    
    if (cnt != 1) cout << "sad";
    else 
    {
        for (int i = 1; i <= n; i++)
        {
            find(i);
            cout << diff[i] << ' ';
        }
    }
    cout << endl;

    return 0;
}