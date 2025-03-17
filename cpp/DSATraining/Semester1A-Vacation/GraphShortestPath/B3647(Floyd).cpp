#include<bits/stdc++.h> 
using namespace std;

const int N = 105;
const int inf = 0x3f3f3f3f;
int n, m, d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main( )
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) d[i][j] = inf;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        d[u][v] = min(w, d[u][v]); d[v][u] = min(w, d[v][u]);
    }
    floyd();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}