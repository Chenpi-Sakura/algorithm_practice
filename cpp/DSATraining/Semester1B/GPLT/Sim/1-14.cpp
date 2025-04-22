#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct Tup
{int id, income, hb;};

map<int, PII> li;
set<int> hb[N];// id id hongbao

bool cmp(Tup a, Tup b)
{
    if (a.income != b.income) return a.income > b.income;
    if (a.hb != b.hb) return a.hb > b.hb;
    return a.id < b.id;
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        while (k--)
        {
            int j, p; cin >> j >> p;
            if (hb[i].find(j) == hb[i].end())
            {
                hb[i].insert(j);
                li[i].first -= p;
                li[j].first += p;
                li[j].second++;
            }
        }
    }
    vector<Tup> Sli;
    for (int i = 1; i <= n; i++)
    {
        Sli.push_back({i, li[i].first, li[i].second});
    }
    sort(Sli.begin(), Sli.end(), cmp);
    int len = Sli.size();
    for (int i = 0; i < len; i++)
        printf("%d %.2lf\n", Sli[i].id, (double)Sli[i].income / 100.0);
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