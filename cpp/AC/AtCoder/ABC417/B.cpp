#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int b; cin >> b;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == b)
            {
                a.erase(a.begin() + j);
                break;
            }
        }
    }
    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}