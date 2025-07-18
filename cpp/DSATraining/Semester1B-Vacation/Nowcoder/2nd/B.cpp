#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    vector<int> b(100), h(100);
    int n; cin >> n;
    int per = 1;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (!per) continue;
        for (int j = 0;; j++)
        {
            if ((x >> j) == 1)
            {
                if (b[j]) per = 0;
                h[j]++; b[j]++;
                break;
            }
            if (((x >> j) & 1) == 1) 
            {
                if (h[j]) per = 0;
                b[j]++;
            }
        }
    }
    if (!per) cout << "NO" << endl;
    else cout << "YES" << endl;
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