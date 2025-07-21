#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int,int> PII;
const int N = 1e3 + 5;

PII a[N];             

void solve()
{
    int n, B;
    if(!(cin >> n >> B)) return;

    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;

    vector<int> cost(n);
    int ans = 0;

    for(int d = 0; d < n; ++d)       
    {
        for(int i = 0; i < n; ++i) cost[i] = (i == d ? (a[i].first / 2 + a[i].second) : (a[i].first + a[i].second));
        sort(cost.begin(), cost.end()); 

        int sum = 0, cnt = 0;
        for(int c : cost)
        {
            if(sum + c > B) break;
            sum += c;
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;         
    while(T--) solve();
    return 0;
}
