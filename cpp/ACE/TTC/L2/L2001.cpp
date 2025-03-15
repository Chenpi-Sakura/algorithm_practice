#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int inf = 0x3f3f3f3f;
struct edge
{int v, w;};
vector<edge> e[N];
priority_queue<pair<int, int>> q;
int vis[N], dis[N], team[N], pre[N], help[N], nums[N], n, m, s, d;

void printroad(int x)
{
    if (pre[x] != x) printroad(pre[x]);
    else {cout << x; return;}
    cout << ' ' << x;
}

void dijkstra(int s)
{
    memset(dis, inf, sizeof(dis));
    for (int i = 0; i <= n; i++) pre[i] = i;
    dis[s] = 0; 
    nums[s] = 1;
    help[s] = team[s];
    q.push({0, s}); 

    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : e[u])
        {
            int v = x.v; int w = x.w;
            if (dis[v] > dis[u] + w)    
            {
                pre[v] = u;
                help[v] = help[u] + team[v]; 
                nums[v] += nums[u];
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
            else if (dis[v] == dis[u] + w)
            {
                nums[v] += nums[u];
                if (help[v] < help[u] + team[v])
                {
                    help[v] = help[u] + team[v];
                    pre[v] = u;
                }
            }
        }
    }
}

int main()
{   
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++) cin >> team[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    dijkstra(s);
    cout << nums[d] << ' ' << help[d] << endl;
    printroad(d);
    cout << endl;
    return 0;
}