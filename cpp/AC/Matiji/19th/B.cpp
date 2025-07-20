#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 15;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int w[N], c[N], ans;
vector<PII> recipe[N];

// 一道简单的DFS题，重在理解DFS的运作原理

void dfs(int u, int ned)
{
    if (ned <= 0) return;
    
    int x = min(w[u], ned);
    ned -= x;
    w[u] -= x;
    if (ned <= 0) return;

    if (c[u] == 0)
    {
        ans += ned;
        return;
    }

    int ned_val = (ned + c[u] - 1) / c[u];
    for (auto p : recipe[u]) dfs(p.first, ned_val * p.second);

    w[u] += ned_val * c[u] - ned;
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        map<int, int> cnt;
        for (int j = 0; j < k; j++)
        {
            int a; cin >> a;
            cnt[a]++;
        }
        cin >> c[i];
        if (k > 0) for (auto x : cnt) recipe[i].push_back(x);
    }
    int m; cin >> m;
    dfs(1, m);
    cout << ans << endl;
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