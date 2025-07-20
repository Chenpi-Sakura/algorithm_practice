#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> store[m + 1];
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        store[a].push_back(b);
    }
    sort(store, store + n);
    int ans = 0;
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (n > store[i].first)
        {
            n += store[i].second - store[i].first;
            vis[i] 
            ans++;
        }
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