#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int bgn = h[k - 1];
    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());
    int idx = 0;
    while (h[idx] < bgn) idx++;
    // cout << bgn << ' ' << idx << endl;
    int time = 1, ans = 1;
    for (int i = idx; i < h.size() - 1; i++)
    {
        int gc = h[i + 1] - h[i];
        if (time + gc - 1 > h[i])
        {
            ans = 0;
            break;
        }
        time += gc;
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
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