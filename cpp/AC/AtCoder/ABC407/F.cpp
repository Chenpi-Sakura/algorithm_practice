#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], s[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    } 
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        multiset<int> ms;
        for (int j = 1; j <= n; j++)
        {
            ms.insert(a[i]);
            if (ms.size() > i;)
        }
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