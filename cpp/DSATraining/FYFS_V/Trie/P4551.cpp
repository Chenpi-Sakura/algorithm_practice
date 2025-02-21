/*
最长异或路径
题目描述
给定一棵 n 个点的带权树，结点下标从 1 开始到 n。寻找树中找两个结点，求最长的异或路径。
异或路径指的是指两个结点之间唯一路径上的所有边权的异或。

输入格式
第一行一个整数 n，表示点数。
接下来 n−1 行，给出 u,v,w ，分别表示树上的 u 点和 v 点有连边，边的权值是 w。

输出格式
一行，一个整数表示答案。

输入数据 1
4
1 2 3
2 3 4
2 4 6
输出数据 1
7

提示
最长异或序列是 1,2,3，
答案是 7=3⊕4。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 10;
vector<pair<int, int>> adj[N]; // Start by index 1
int xorSum[N]; // Start by index 1
int ch[N * 30][2], idx;

void dfs(int index, int sum)
{
    xorSum[index] = sum;
    int len = adj[index].size();
    for (int i = 0; i < len; i++)
    {
        dfs(adj[index][i].first, sum ^ adj[index][i].second);
    }
}

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][!j])
        {
            res += 1 << i;
            p = ch[p][!j]; 
        }
        else p = ch[p][j];
    }
    return res;
}


int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int n1, n2, w; cin >> n1 >> n2 >> w;
        adj[n1].push_back({n2, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        insert(xorSum[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, query(xorSum[i]));
    }
    cout << ans << endl;
    return 0;
}