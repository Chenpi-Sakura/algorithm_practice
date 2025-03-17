/*
题目描述
现在有 N 道题。
天数的编号从 0 开始，每一天你可以做若干道题，你只能做以前推荐过的或者当天推荐的题（每道题只可以做一次）。第一天，智能推荐会推荐 p 道题。

推荐规则如下：
对于第 i 道题，如果有可能被推荐的话，就会有一个题目集合 si。
当且仅当你把 si 中每一道题都做出来并且其中有一道题是当天做的，那么下一天就会推荐第 i 题。
你想做完第 K 道题，问至少第几天你才能满足愿望？

输入格式
第一行三个整数 N,K,p，含义如题目所述。
第二行 p 个整数，表示第一天推荐的题的题号。
第三行一个整数 R，表示有 R 条推荐规则。

接下来 R 行，每行包含一条规则，每行格式如下：

一个整数 vi，表示要推荐的题的题号。接着一个整数 si，表示要使得这道题被推荐，一共要做的题目数量。接下来 si 个整数 pi，表示要做的每道题。

输出格式
一个整数表示最少第几天才能满足愿望。
如无论如何，第 K 题都无法完成，则输出 -1。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e4;
vector<int> adj[N], pList;
int din[N], k;

int toposort()
{
    queue<int> q;
    bool KNotExsit = true;
    for (int x : pList)
    {
        if (din[x] == 0) q.push(x);
        if (x == k) KNotExsit = false;
    }
    if (KNotExsit) return -1;
    //cout << q.size() << endl;
    int res = 0;
    while (q.size())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front(); q.pop();
            if (x == k) return res;
            for (int y : adj[x])
            {
                if (--din[y] == 0) q.push(y);
            }
        }
        res++;
    }
    return -1;
}

int main()
{
    int n, p; cin >> n >> k >> p;
    while (p--)
    {
        int x; cin >> x; 
        pList.push_back(x);
    }
    int r; cin >> r;
    while (r--)
    {
        int v, s; cin >> v >> s;
        pList.push_back(v);
        while (s--)
        {
            int p; cin >> p; 
            din[v]++; 
            adj[p].push_back(v);
        }
    }

    int ans = toposort();
    cout << ans << endl;
    return 0;
}