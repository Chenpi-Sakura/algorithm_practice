#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int kinds[N];
unordered_map<int, int> cnt;

void solve()
{ 
    int n, q; cin >> n >> q;
    cnt.clear();
    memset(kinds, 0, sizeof(kinds));
    for (int i = 0; i < n; i++)
    {
        int idx; cin >> idx;
        cnt[idx]++;
    }
    int s = 0;
    for (auto x : cnt) kinds[x.second] += x.second;
    for (int i = 1; i <= n; i++) kinds[i] += kinds[i - 1];
    while (q--)
    {
        int d; cin >> d;
        d = min(d, n);
        cout << n - kinds[d] << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; cin >> t;
    // t = 1;
    while (t--) solve();
    return 0;
}