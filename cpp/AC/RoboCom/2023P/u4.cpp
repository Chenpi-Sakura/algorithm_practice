/** 
 * @Author: Chenpi
 * @Date: 2025-08-14 10:20:01
 * @Link: https://pintia.cn/problem-sets/1680597991209951232/exam/problems/type/7?problemSetProblemId=1680598077168017411
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 4e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

struct Info {string s1, s2; int p1, p2;};

vector<PII> g[N];
unordered_map<string, int> mp;
vector<string> names;
vector<Info> infos;

int minLen = inf;
vector<int> ans;

int id(string s)
{
    if (!mp.count(s))
    {
        names.push_back(s);
        mp[s] = names.size();
    }
    return mp[s];
}

void bfs(int s, int e)
{
    vector<int> dis(N, inf);
    vector<PII> pre(N);
    queue<int> q;
    q.push(s);
    dis[s] = 0;

    int found = 0;
    while (q.size())
    {
        int u = q.front();
        if (u == e) {found = 1; break;}
        for (auto [v, i] : g[u])
        {
            if (dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                pre[v] = {u, i};
                q.push(v);
            }
        }
    }

    if (found && dis[e] < minLen)
    {
        minLen = dis[e];
        ans.clear();
        int c = e;
        while (c != s)
        {
            ans.push_back(pre[c].second);
            c = pre[c].first;
        }
        reverse(ans.begin(), ans.end());
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2; int p1, p2;
        cin >> s1 >> p1 >> s2 >> p2;
        int u = id(s1) * 2 + p1;
        int v = id(s2) * 2 + p2;
        g[u].push_back({v, i});
        infos.push_back({s1, s2, p1, p2});
    }

    for (int i = 1; i <= names.size(); i++)
    {
        bfs(i * 2, i * 2 + 1);
        bfs(i * 2 + 1, i * 2);
    }

    int first = 1;
    for (int i : ans)
    {
        if (!first) cout << " ";
        cout << infos[i].s1 << " " << infos[i].p1 << " " << infos[i].s2 << " " << infos[i].p2;
        first = 0;
    }
    int s = ans.front(), e = ans.back();
    cout << " = " << infos[s].s1 << " " << infos[s].p1 << " " << infos[e].s2 << " " << infos[e].p2;
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