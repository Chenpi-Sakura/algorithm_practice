#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
vector<vector<int>> martix;

bool dfs()
{

}

void solve()
{
    cin >> n >> m;
    martix.resize(n + 1);
    for (int i = 0; i <= n; i++) martix[i].resize(m);

    for (int i = 1; i <= n * m; i++)
    {
        
    }
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