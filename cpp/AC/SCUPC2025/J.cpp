#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    int s; cin >> s;
    int flag = 1;
    if (s >= n) flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (s == 0) flag = 0;
        s--;
        int x; cin >> x;
        if (x > n - i) flag = 0;
        s += x - 1;
    }
    if (flag && s == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
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