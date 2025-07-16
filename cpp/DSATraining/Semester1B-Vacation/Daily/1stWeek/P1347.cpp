#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 30;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> g[N];
set<int> ns;
int din[N], d[N], a[N];
int n;

bool topo(int step)
{
    memcpy(d, din, sizeof(din));
    queue<int> q;
    string ans;
    bool uni = true; // 用于判断多分叉情况
    for (int i = 0; i < n; i++) if (ns.count(i) && d[i] == 0) q.push(i);
    while (q.size())
    {
        if (q.size() > 1) uni = false;
        int u = q.front(); q.pop();
        ans.push_back('A' + u);
        for (int v : g[u]) if (--d[v] == 0) q.push(v);
    }
    if (ans.size() < ns.size())
    {
        cout << "Inconsistency found after " << step << " relations.";
        return true;                     
    }
    if (uni && ans.size() == n)
    {
        cout << "Sorted sequence determined after " << step << " relations: " << ans << '.';
        return true; 
    }
    return false;
}

void solve()
{
    int m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string s; cin >> s;
        int u = s[0] - 'A', v = s[2] - 'A';
        ns.insert(u), ns.insert(v);
        g[u].push_back(v);
        din[v]++;
        if (topo(i)) return;
    }
    cout << "Sorted sequence cannot be determined." << endl;
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