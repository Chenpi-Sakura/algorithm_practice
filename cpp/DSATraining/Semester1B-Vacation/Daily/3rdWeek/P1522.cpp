/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 16:22:03
 * @Link: https://www.luogu.com.cn/problem/P1522
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<double, double> PDD;
const int N = 155;
const double inf = 1e18;

PDD coords[N];
int fa[N], g[N][N];
double dis[N][N];
double diameter[N];
double maxsp[N];

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

double calDis(PDD a, PDD b)
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> coords[i].first >> coords[i].second;

    for (int i = 1; i <= n; i++) fa[i] = i;

    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        for (int j = 1; j <= n; j++)
        {
            if (s[j - 1] == '1') 
            {
                g[i][j] = 1;
                fa[find(i)] = find(j);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) dis[i][j] = 0; 
            else if (g[i][j]) dis[i][j] = calDis(coords[i], coords[j]);
            else dis[i][j] = inf;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] < inf && dis[k][j] < inf) 
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        maxsp[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] < inf) maxsp[i] = max(maxsp[i], dis[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int fai = find(i);
        diameter[fai] = max(diameter[fai], maxsp[i]);
    }

    double mind = inf, maxd;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int fai = find(i);
            int faj = find(j);
            if (fai != faj)
            {
                maxd = max({diameter[fai], diameter[faj], maxsp[i] + calDis(coords[i], coords[j]) + maxsp[j]});
                mind = min(mind, maxd);
            }
        }
    }
    
    printf("%.6f\n", mind);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
