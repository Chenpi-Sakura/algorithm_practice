/** 
 * @Author: Chenpi
 * @Date: 2025-07-22 19:54:08
 * @Link: https://www.luogu.com.cn/problem/P5903
 */
#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int
// #define int long long
#define endl "\n"

typedef pair<int, int> PII;
typedef long long LL;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<LL> e[N];
LL fa[N], dep[N], son[N], sz[N], top[N], id[N], ID[N], cnt;

void dfs1(LL u, LL p)
{
    fa[u] = p, dep[u] = dep[p] + 1; sz[u] = 1;
    for (LL v : e[u])
    {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(LL u, LL t)
{
    id[u] = ++cnt;
    ID[cnt] = u;
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (LL v : e[u])
    {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

LL rt;
LL jump(LL x, LL k)
{
    while (k >= id[x] - id[top[x]] + 1 && x != rt)
    {
        k -= (id[x] - id[top[x]] + 1);
        x = fa[top[x]];
    }
    return ID[id[x] - k];
}


ui s;

inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

void solve()
{
    LL n, q; cin >> n >> q >> s;
    rt = 1;
    for (LL i = 1; i <= n; i++)
    {
        cin >> fa[i];
        if (!fa[i]) rt = i;
        else e[fa[i]].push_back(i);
    }
    dep[rt] = 1; 
    dfs1(rt, 0);
    dfs2(rt, rt);
    LL ans = 0, lstans = 0;
    for (LL i = 1; i <= q; i++)
    {
        LL x = (get(s) ^ lstans) % n + 1;
        LL k = (get(s) ^ lstans) % dep[x];
        // cout << x << ' ' << k << endl;
        lstans = jump(x, k);
        ans ^= i * lstans;
        // cout << ans << endl;
    }
    cout << ans << endl;
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