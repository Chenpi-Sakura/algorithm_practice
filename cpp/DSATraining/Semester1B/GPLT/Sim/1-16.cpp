#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

map<string, double> rec;
map<string, double> qq;
set<string> gzli;
vector<string> qqgz;

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        gzli.insert(s);
    }
    int m; cin >> m;
    double ttl = 0;
    for (int i = 0; i < m; i++)
    {
        string na; double dz;
        cin >> na >> dz;
        if (gzli.find(na) != gzli.end()) rec[na] = dz;
        else qq[na] = dz;
        ttl += dz;
    }
    ttl /= m;

    for (auto x : qq)
    {
        if (x.second > ttl)
        {
            qqgz.push_back(x.first);
        }
    }
    if (qqgz.size() == 0) cout << "Bing Mei You\n";
    else
    {
        for (auto x : qqgz) cout << x << endl;
    }
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