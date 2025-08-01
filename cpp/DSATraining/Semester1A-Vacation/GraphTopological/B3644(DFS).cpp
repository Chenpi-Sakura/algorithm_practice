/*
算法的核心是变色法，一路搜一路给点变色，如果有拓扑序，每个点的颜色都会从 0 → -1 → 1，经历三次变色。
1.初始状态，所有点染色为0。 
2.枚举每个点，进入 x 点，把 x 染色为-1。然后，枚举 x 的儿子 y ，如果 y 的颜色为0，说明没碰过该点，进入 y 继续走.
3.如果枚举完 x 的儿子，没发现环，则 x 染色为 1，并把 x 压入tp数组。 
4.如果发现有个熊孩子的颜色为-1，说明回到了祖先节点，发现了环，则一路返回false，退出程序。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> e[N], tp;
int c[N]; // 染色数组
int n;

bool dfs(int x)
{
    c[x] = -1;
    for (int y : e[x])
    {
        if (c[y] < 0) return 0; // 发现祖先节点，有环
        else if (!c[y]) if (!dfs(y)) return 0;
    }
    c[x] = 1;
    tp.push_back(x);
    return 1;
}

bool toposort()
{
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
            if (!dfs(i)) 
                return 0;
    }
    reverse(tp.begin(), tp.end());
    return 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        while (d != 0)
        {
            e[i].push_back(d);
            cin >> d;
        }
    }
    if (!toposort()) cout << -1;
    else for (auto x : tp) cout << x << " ";
    cout << endl;

    return 0;
}