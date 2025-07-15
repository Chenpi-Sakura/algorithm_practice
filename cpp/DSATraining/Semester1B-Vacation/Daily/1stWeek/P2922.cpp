#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int trie[N][2], End[N], sum[N], a[N];
int tot = 1;

void insert(int len)
{
    int p = 0;
    for (int i = 1; i <= len; i++)
    {
        if (!trie[p][a[i]]) trie[p][a[i]] = tot++;
        p = trie[p][a[i]];
        sum[p]++;
    }
    End[p]++;
}

int query(int len)
{
    int p = 0, ans = 0;
    for (int i = 1; i <= len; i++)
    {
        if (!trie[p][a[i]]) return ans;
        p = trie[p][a[i]];
        ans += End[p];
    }
    return ans += sum[p] - End[p];
}

void solve()
{
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        for (int i = 1; i <= x; i++) cin >> a[i];
        insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        for (int i = 1; i <= x; i++) cin >> a[i];
        cout << query(x) << endl;
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