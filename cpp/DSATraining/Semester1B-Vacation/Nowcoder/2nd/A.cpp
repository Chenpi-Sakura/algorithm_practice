#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 998244353;
const int inf = 0x3f3f3f3f;

int p2[N];

void pre2()
{
    p2[0] = 1;
    for (int i = 1; i < N; i++) p2[i] = (p2[i - 1] * 2) % M;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    int no = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == -1) no++;
    }
    int ans = 0;
    int u = 0, v = a[0];
    if (v == 1) ans = (ans + p2[no]) % M;
    else if (v == -1) ans = (ans + p2[no - 1]) % M;

    for (int i = 0; i < n - 1; i++)
    {
        u = a[i];
        v = a[i + 1];
        if (u == 0 && v == 1) ans = (ans + p2[no]) % M;
        else if ((u == 0 && v == -1) || (u == -1 && v == 1)) ans = (ans + p2[no - 1]) % M;
        else if (u == -1 && v == -1) ans = (ans + p2[no - 2]) % M;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    pre2();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}