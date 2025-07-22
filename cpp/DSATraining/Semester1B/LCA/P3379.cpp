/*
P3379 【模板】最近公共祖先（LCA）
题目描述
如题，给定一棵有根多叉树，请求出指定两个点直接最近的公共祖先。

输入格式
第一行包含三个正整数 N,M,S，分别表示树的结点个数、询问的个数和树根结点的序号。
接下来 N−1 行每行包含两个正整数 x,y，表示 x 结点和 y 结点之间有一条直接连接的边（数据保证可以构成树）。
接下来 M 行每行包含两个正整数 a,b，表示询问 a 结点和 b 结点的最近公共祖先。

输出格式
输出包含 M 行，每行包含一个正整数，依次为每一个询问的结果。

输入输出样例 #1
输入 #1
5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5
输出 #1
4
4
1
4
4
说明/提示
对于 30% 的数据，N≤10，M≤10。
对于 70% 的数据，N≤10000，M≤10000。
对于 100% 的数据，1≤N,M≤500000，1≤x,y,a,b≤N，不保证 a!=b。
样例说明：
该树结构如下：
第一次询问：2,4 的最近公共祖先，故为 4。
第二次询问：3,2 的最近公共祖先，故为 4。
第三次询问：3,5 的最近公共祖先，故为 1。
第四次询问：1,2 的最近公共祖先，故为 4。
第五次询问：4,5 的最近公共祖先，故为 4。
故输出依次为 4,4,1,4,4。
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> e[N];
int dep[N], fa[N][20]; // fa[u][i]是节点 u 的 2 ^ i 次方的父节点

void dfs(int u, int father)
{// 先创建一个 ST表
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : e[u]) if (v != father) dfs(v, u);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) 
        if (dep[fa[u][i]] >= dep[v]) 
            u = fa[u][i];
    if (u == v) return v;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void solve()
{
    int n, m, s; cin >> n >> m >> s;
    for (int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}