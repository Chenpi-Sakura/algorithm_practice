#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 4e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

bool cmp(PII a, PII b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<PII> ops(m);
    for (int i = 0; i < m; i++) cin >> ops[i].first >> ops[i].second;

    sort(ops.begin(), ops.end(), cmp);

    vector<int> vis(2 * n + 1);
    int lcnt = 0, lst = 2 * n + 1;
    for (int i = 0; i < m; i++)
    {
        if (ops[i].second >= lst) continue;
        if (!vis[ops[i].first])
        {
            vis[ops[i].first] = 1;
            lcnt++;
        }
        lst = ops[i].first;
    }
    if (lcnt > n)
    {
        cout << -1 << endl;
        return;
    }

    string ans = "";
    int x = 0;

    for (int i = 1; i <= 2 * n; i++)
    {
        if (vis[i] || lcnt < n)
        {
            ans += '(';
            x++;
            if (!vis[i]) lcnt++;
        }
        else
        {
            ans += ')';
            x--;
        }
        if (x < 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
