/*
E - 树上游戏

题目描述
本题是一道交互式问题（你的程序和评测系统通过输入输出进行通信）。
给定一棵包含 N 个顶点的树 G，顶点编号从 1 到 N。第 i 条边连接顶点 Ui 和 Vi。
你将和 Takahashi 在这棵树 G 上玩一个游戏。首先，你决定谁先手谁后手。然后，从先手开始，轮流执行以下操作：
选择一对整数 (i, j)，满足 1 ≤ i < j ≤ N 且以下两个条件：
    1. 图 G 当前没有连接顶点 i 和 j 的边。
    2. 在图 G 中添加连接顶点 i 和 j 的边不会产生奇数环。
无法执行此操作的玩家输掉游戏，另一位玩家获胜。请与 Takahashi 进行游戏并获胜。

什么是奇数环？
图 G 的一个顶点序列 (v0, v1, …, vk) 被称为奇数环，当且仅当满足以下所有条件：
    1. k 是奇数。
    2. v0 = vk。
对于每个 1 ≤ i ≤ k，都存在一条连接 vi-1 和 vi 的边。

数据范围
2 ≤ N ≤ 100
1 ≤ Ui < Vi ≤ N
给定的图是树。
所有输入值均为整数。

交互
这是一道交互式问题（你的程序和评测系统通过输入输出进行通信）。
首先，从标准输入读取 N 和树 G 的边，格式如下：

N
U1 V1
U2 V2
...
UN-1 VN-1

然后，决定你先手还是后手。如果你选择先手，打印 "First"；如果选择后手，打印 "Second"。
然后，游戏开始。
在你的回合，通过打印两个整数 i 和 j（以空格分隔）来输出你选择的数对 (i, j)： i j
在 Takahashi 的回合，两个整数 i 和 j 将通过标准输入给出，以空格分隔： i j
如果 (i, j) = (-1, -1)，则表示他无法再进行任何操作，你获胜。在这种情况下，立即终止你的程序。
否则，(i, j) 是他选择的整数对。

注意
每次输出后，请务必打印换行符并刷新标准输出。否则，你可能会得到 TLE（Time Limit Exceeded）。
如果你产生格式不正确的输出或你的程序过早结束，评测结果将是不确定的。
游戏结束后，立即终止你的程序。否则，评测结果将是不确定的。
*/

/*
    如何判断奇数环，染色法
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
typedef pair<int, int> PII;
vector<int> e[N];
set<PII> es, cs;
int color[N], cnt1, cnt2;

void dfs(int x, int c)
{
    if (c == 1) cnt1++;
    else cnt2++;
    color[x] = c;
    for (int v : e[x])
    {
        if (!color[v]) dfs(v, 3 - c);
    }
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        es.insert({min(u, v), max(u, v)});
    }
    
    // dfs(1, 1);
    for (int i = 1; i <= n; i++) 
    {
        if (!color[i])
        {
            dfs(i, 1);
        }
    }

    // for (int i = 1; i <= n; i++) cout << color[i] << ' ';
    // cout << endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         if (i != j && color[i] != color[j] && es.find({i, j}) == es.end())
    //         {
    //             cs.insert({i, j});
    //             cout << i << ' ' << j << ' ' << color[i]  << ' ' << color[j] << endl;
    //         }
    //     }
    // }

    int m = cnt1 * cnt2 - (n -1);
    // cout << m << endl;

    if (m % 2 == 1)
    {
        cout << "First" << endl;
        while (1)
        {
            bool found = false;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (color[i] != color[j] && es.find({i, j}) == es.end())
                    {
                        cout << i << ' ' << j << endl;
                        es.insert({i, j});
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            int i, j; cin >> i >> j;
            if (i == -1 && j == -1) break;
            es.insert({min(i, j), max(i, j)});
        }
    }
    else
    {
        cout << "Second" << endl;
        while (1)
        {
            int i, j; cin >> i >> j; 
            if (i == -1 && j == -1) break;
            es.insert({min(i, j), max(i, j)});
            bool found = false;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (color[i] != color[j] && es.find({i, j}) == es.end())
                    {
                        cout << i << ' ' << j << endl;
                        es.insert({i, j});
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
    }

    return 0;
}