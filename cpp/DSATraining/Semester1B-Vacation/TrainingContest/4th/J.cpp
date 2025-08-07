#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    int x = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i != 0) 
        {
            if (a[i] >= x)
            {
                x = a[i];
                idx = i;
            }
        }
    }
    if (n == 1)
    {
        cout << 1 << endl;
        cout << a[0] << endl;
        return;
    }
    if (x != 0)
    {
        a[0] += x;
        a.erase(a.begin() + idx);
        cout << n - 1 << endl;
    }
    else cout << n << endl;
    for (int i : a) cout << i << ' ';
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