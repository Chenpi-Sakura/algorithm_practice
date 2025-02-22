/*
图的存储
题目描述
给定一个 n 个顶点 m 条边的无向图。请以邻接矩阵和邻接表的形式输出这一张图。

输入格式
第一行输入两个正整数 n 和 m，表示图的顶点数和边数。
第二行开始，往后 m 行，每行输入两个以空格隔开的正整数 u,v，表示 u,v 顶点之间有一条边直接相连。

输出格式
首先输出 n 行 n 列的矩阵，以空格隔开每一行之间的数表示邻接矩阵。第 i 行第 j 列的数为 1 则表示顶点 i,j 之间有一条边直接相连；若为 0 则表示没有直接相连的边。
再往后输出 n 行。第 i 行首先先输出一个整数 di，表示这个顶点的度数，再按照从小到大的顺序，依次输出与顶点 i 直接相连的所有顶点。
*/

#include<bits/stdc++.h> 
#include <vector>
using namespace std;

const int N = 1e3 + 10;
int matrix[N][N];
vector<int> adj[N];

int main( )
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
        if (adj[u].empty()) adj[u].push_back(0);
        if (adj[v].empty()) adj[v].push_back(0);
        adj[u][0]++; adj[v][0]++;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin() + 1, adj[i].end());
        int len = adj[i].size();
        for (int j = 0; j < len; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}