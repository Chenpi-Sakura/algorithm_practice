#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct p{int w, a, b;} prst[N];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> prst[i].w >> prst[i].a >> prst[i].b;
    }
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}