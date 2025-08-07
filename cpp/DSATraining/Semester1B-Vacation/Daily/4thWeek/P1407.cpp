/** 
 * @Author: Chenpi
 * @Date: 2025-08-06 10:03:44
 * @Link: https://www.luogu.com.cn/problem/P1407
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 3e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
vector<int> e[N];
vector<PII> mar;
unordered_map<string, int> mp;
int idx;

void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    stk[++top] = u; instk[u] = 1;

    for (int v : e[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instk[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u])
    {
        cnt++;
        int v;
        
        do 
        {
            v = stk[top--];
            instk[v] = 0;
            scc[v] = cnt;
            siz[cnt]++;
        }
        while (u != v);
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string n1, n2; cin >> n1 >> n2;
        mp[n1] = ++idx; mp[n2] = ++idx;
        mar.push_back({mp[n1], mp[n2]});
        e[mp[n1]].push_back(mp[n2]);
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string n1, n2; cin >> n1 >> n2;
        e[mp[n2]].push_back(mp[n1]);
    }

    for (int i = 1; i <= idx; i++) if (!dfn[i]) tarjan(i);

    for (auto [x, y] : mar)
    {
        if (scc[x] != scc[y]) cout << "Safe" << endl;
        else cout << "Unsafe" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}