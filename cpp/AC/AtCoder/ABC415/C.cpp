#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n;
vector<int> vis;
set<int> ans;
map<set<int>, int> d;

bool dfs(int deep)
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans.insert(i);
            if (d[ans] == 1) ans.erase(i);
            else 
            {
                vis[i] = 1;
                if (deep == n) return true;
                if (dfs(deep + 1)) return true;
                else vis[i] = 0;
            }
        }
    }
    if (ans.size() != deep)
    {
        return false;
    }
}

void solve()
{
    string s; cin >> n >> s;
    vis.resize(n + 1);
    vis.clear();
    ans.clear();
    d.clear();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            set<int> re;
            int x = i + 1, idx = 1;
            while (x > 0)
            {
                if (x & 1 == 1) re.insert(idx);
                x = x >> 1;
                idx++;
            }
            d[re]++;
        }
    }

    if (dfs(1)) cout << "Yes" << endl;
    else cout << "No" << endl;

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}