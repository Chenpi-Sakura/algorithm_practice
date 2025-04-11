#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

PII p[105];
map<int, int, greater<int>> ra;

void solve()
{
    int n; cin >> n;
    int r = 1;
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i].first;
        ra[p[i].first]++;
    }
    for (auto x : ra)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].first == x.first)
            {
                p[i].second = r;
            }
        }
        r += x.second;
    }
    for (int i = 0; i < n; i++) cout << p[i].second << endl;
}

signed main()
{
    int t; t = 1;
    while (t--) solve();
    return 0;
}