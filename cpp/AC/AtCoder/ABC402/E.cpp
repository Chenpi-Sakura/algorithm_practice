#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct pb
{double s, c, p;};

double f[10][N]; // 题目数，钱数
vector<int> ch[10][N]; // 选择过哪些题目
vector<pb> pbs;

void solve()
{
    int n, x; cin >> n >> x;
    pbs.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pbs[i].s >> pbs[i].c >> pbs[i].p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            for (auto x : pbs)
            {
                
            }
        }
    }
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