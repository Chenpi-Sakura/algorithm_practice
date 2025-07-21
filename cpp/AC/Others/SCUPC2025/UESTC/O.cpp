#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
//vector<int> e[N];
int din[N], dout[N];

int main()
{
    int n, m; cin >> n >> m;
    while (m--)
    {
        int u, v; cin >> u >> v;
        //e[u].push_back(v);
        dout[u]++; din[v]++;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (din[i] == 0) x++;
        if (dout[i] == 0) y++;
    }
    if (x >= 2 || y >= 2) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}