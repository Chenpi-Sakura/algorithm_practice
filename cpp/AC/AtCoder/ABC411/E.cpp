#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<double, double> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<PII> a[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        map<int, int> tz;
        for (int j = 1; j <= 6; j++)
        {
            int x; cin >> x;
            tz[x]++;            
        }
        for (auto x : tz)
        {
            a[i].push_back({x.first, x.second / 6});
        }
    }
    for (int i = n; i--; i >= 0)
    {
        
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