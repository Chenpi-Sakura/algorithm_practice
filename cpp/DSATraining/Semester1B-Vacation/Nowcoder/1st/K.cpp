#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> a[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        for (int j = 0; j < d; j++)
        {
            int v; cin >> v;
            a[i].push_back(v);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // int isFirst = true;
        queue<PII> order; order.push({i, 0});
        set<PII> s; 
        int x = i, y = a[i][0];
        if (x > y) swap(x, y);
        s.insert({x, y});
        for (int i = 0; i < 2; i++)
        {
            auto [u, j] = order.front(); order.pop();
            j++;
            if (j > a[u].size()) j = 0;
            order.push({a[u][j], j});
            x = a[u][j], y = u;
            if (x > y) swap(x, y);
            s.insert({x, y});
        }
        cout << s.size() << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}