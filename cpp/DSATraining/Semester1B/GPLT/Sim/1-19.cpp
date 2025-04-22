#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

deque<pair<double, double>> li;
queue<pair<double, double>> q;
vector<int> ck, ckcnt;

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, p; cin >> t >> p;
        li.push_back({t, p});
    }
    int k; cin >> k; 
    ck.resize(k); ckcnt.resize(k);
    double ttl = 0, lt = 0; int fin = 0;
    for (int i = 0; li.size() || q.size(); i++)
    {
        while (!li.empty() && i >= li.front().first)
        {
            q.push({i, li.front().second - 1}); // 进入队列时间 任务时间
            li.pop_front();
        }
        for (int j = 0; j < k; j++)
        {
            if (ck[j] <= i && q.size())
            {
                lt = max(lt, i - q.front().first);
                ttl += i - q.front().first;
                ck[j] = i + q.front().second;
                fin = max(fin, ck[j]);
                ckcnt[j]++;
                q.pop();
            }
        }
    }
    printf("%.1lf %.0lf %lld\n", ttl / n, lt, fin);
    printf("%lld", ckcnt[0]);
    for (int i = 1; i < k; i++) printf(" %lld", ckcnt[i]);
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