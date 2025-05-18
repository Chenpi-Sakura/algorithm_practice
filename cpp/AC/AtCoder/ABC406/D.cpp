#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> col[N], row[N];

void solve()
{
    int w, h, n; cin >> w >> h >> n;
    for (int i = 0; i <= n; i++)
    {
        col[i].push_back(0); 
        row[i].push_back(0);
    }
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    int q; cin >> q;
    while (q--)
    {
        int op, t; cin >> op >> t;
        if (op == 1)
        {
            cout << row[t][0];
            for (int i = 1; i < row[t].size(); i++)
            {
                
            }
        }
        else 
        {

        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    // cout.tie(0);
    int T = 1; 
    // cin >> T;
    while (T--) solve();
    return 0;
}