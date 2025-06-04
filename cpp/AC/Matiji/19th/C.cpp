#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct p {int i, x, y;};
vector<p> ps;
queue<p> win, los;

bool cmp(p a, p b)
{
    if (a.x == b.x) return a.i < b.i;
    else return a.x > b.x;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y; cin >> x >> y;
        ps.push_back({i, x, y});
    }
    sort(ps.begin(), ps.end(), cmp);
    while (m--)
    {
        for (int i = 0; i < n; i+=2)
        {
            if (ps[i].y < ps[i + 1].y) 
            {
                ps[i + 1].x++;
                win.push(ps[i + 1]);
                los.push(ps[i]);
            }
            else
            {
                ps[i].x++;
                win.push(ps[i]);
                los.push(ps[i + 1]);
            }
        }
        int cnt = 0;
        while (win.size() || los.size())
        {
            if (win.size() && los.size())
            {
                if (win.front().x > los.front().x)
                {
                    ps[cnt++] = win.front();
                    win.pop();
                }
                else if (win.front().x < los.front().x)
                {
                    ps[cnt++] = los.front();
                    los.pop();
                }
                else 
                {
                    if (win.front().i < los.front().i)
                    {
                        ps[cnt++] = win.front();
                        win.pop();
                    }
                    else 
                    {
                        ps[cnt++] = los.front();
                        los.pop();
                    }
                }
            }
            while (win.size() && los.empty())
            {
                ps[cnt++] = win.front();
                win.pop();
            }
            while (los.size() && win.empty())
            {
                ps[cnt++] = los.front();
                los.pop();
            }
        }
    }
    for (int i = 0; i < n; i++) cout << ps[i].i << ' ';
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