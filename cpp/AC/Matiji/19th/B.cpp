#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, w[15], b[15][15], nedlist[15];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int wi; cin >> wi;
        w[i] = -wi;
    } 
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a; cin >> a;
            b[i][a]++; 
        }
        int c; cin >> c;
        b[i][c] = c;
    }
    int m; cin >> m;
    
    for (int i = 1; i <= n; i++)
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