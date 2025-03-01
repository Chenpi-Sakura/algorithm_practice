/*
*/
#include<bits/stdc++.h> 
#include <vector>
using namespace std;

const int N = 1e4 + 10;
struct edge
{
    int u, v, w;
    bool operator < (const edge &t)const
    {return w < t.w;}
};
vector<edge> e;
int fa[N];
int n, m, s, t;

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int kruskal()
{
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) fa[i] = i;
    int maxW = 0;
    for (auto i : e)
    {
        if (find(s) == find(t)) return maxW;
        int x = find(i.u);
        int y = find(i.v);
        if (x != y)
        {
            fa[x] = y;
            maxW = max(maxW, i.w);
        }
    }
    return maxW;
}

int main( )
{
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    int ans = kruskal();
    cout << ans << endl;
    return 0;
}