#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct player {int i, x, y;};

bool cmp(player a, player b)
{
    if (a.x == b.x) return a.i < b.i;
    else return a.x > b.x;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<player> p(n), tp(n);
    for (int i = 0; i < n; i++)
    {
        p[i].i = i + 1;
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end(), cmp);
    vector<player> win(n / 2), los(n / 2);
    while (m--)
    {
        int idx = 0;
        for (int i = 0; i < n; i+=2)
        {
            if (p[i].y > p[i + 1].y)
            {
                p[i].x++;
                win[idx] = p[i];
                los[idx++] = p[i + 1];
            }
            else
            {
                p[i + 1].x++;
                win[idx] = p[i + 1];
                los[idx++] = p[i];
            }
        }
        merge(win.begin(), win.end(), los.begin(), los.end(), tp.begin(), cmp);
        p.swap(tp);
    }
    for (int i = 0; i < n; i++) cout << p[i].i << ' ';
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