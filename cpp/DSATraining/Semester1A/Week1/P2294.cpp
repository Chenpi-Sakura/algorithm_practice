/*
题目描述
刁姹接到一个任务，为税务部门调查一位商人的账本，看看账本是不是伪造的。账本上记录了 n 个月以来的收入情况，其中第 i 个月的收入额为 ai，i=1,2,…,n-1,n。当 ai>0 时表示这个月盈利 ai 元，当 ai<0 时表示这个月亏损 ai 元。所谓一段时间内的总收入，就是这段时间内每个月的收入额的总和。
刁姹的任务是秘密进行的，为了调查商人的账本，她只好跑到商人那里打工。她趁商人不在时去偷看账本，可是她无法将账本偷出来，每次偷看账本时她都只能看某段时间内账本上记录的收入情况，并且她只能记住这段时间内的总收入。
现在，姹总共偷看了 m 次账本，当然也就记住了 m 段时间内的总收入，你的任务是根据记住的这些信息来判断账本是不是假的。

输入格式
第一行为一个正整数 w，其中 w<100，表示有 w 组数据，即 w 个账本，需要你判断。
每组数据的第一行为两个正整数 n 和 m，其中 n<100,m<1000，分别表示对应的账本记录了多少个月的收入情况以及偷看了多少次账本。
接下来的 m 行表示刁姹偷看 m 次账本后记住的 m 条信息，每条信息占一行，有三个整数 s,t 和 v，表示从第 s 个月到第 t 个月（包含第 t 个月）的总收入为 v，这里假设 s 总是小于等于 t。

输出格式
包含 w 行，每行是 true 或 false，其中第 i 行为 true 当且仅当第 i 组数据，即第 i 个账本不是假的；第 i 行为 false 当且仅当第 i 组数据，即第 i 个账本是假的。
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
struct edge
{int v, w;};
vector<edge> e[105];
queue<int> q; // 储存待遍历的点
int dis[105], vis[105], cnt[105];
int n, m;

bool spfa(int s)
{
    memset(dis, inf, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0; vis[s] = 1; q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (auto x : e[u])
        {
            int v = x.v, w = x.w;
            if (dis[v] == inf || dis[v] == dis[u] + w) 
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return false; // 存在负环
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
            else if (dis[v] != dis[u] + w) return false;
        }
    }
    return true;
}

int main()
{
    int w; cin >> w;
    while (w--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) e[i].clear();
        while (m--)
        {
            int u, v, w; cin >> u >> v >> w;
            e[u].push_back({v, w});
        }
        for (int i = 1; i <= n; i++) e[0].push_back({i, 0});
        if (spfa(0)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}