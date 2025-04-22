#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> li[N];
vector<double> ans;

void solve()
{
    int n, k, m; cin >> n >> k >> m;
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        li[i].resize(k);
        for (int j = 0; j < k; j++) cin >> li[i][j];
        sort(li[i].begin(), li[i].end());
        li[i].erase(li[i].begin()); li[i].pop_back();
        double res = 0;
        for (int j = 0; j < k - 2; j++) res += li[i][j];
        ans[i] = res / (k - 2);
    }
    sort(ans.begin(), ans.end());
    printf("%.3lf", ans[n - m]);
    for (int i = n - m + 1; i < n; i++)
        printf(" %.3lf", ans[i]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}