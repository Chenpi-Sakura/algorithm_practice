#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> q;
vector<queue<int>> vs;
int a[N];
vector<int> ms;

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        q.push_back(t);
    }
    int cur = n;
    for (int x : q)
    {
        if (x == cur)
        {
            cur--;
            while (vs.size() > a[cur] && vs[a[cur]].front() == cur)
            {
                cur--;
                
            }
        }
        else
        {
            bool found = false;
            sort(ms.begin(), ms.end());
            int le = 0, ri = vs.size();
            while (le + 1 < ri)
            { // 此处我们找第一个大于 X 的位置
                int mid = (le + ri) / 2;
                if (ms[ri] <= x) le = mid;
                else ri = mid;
            }
            if (ri < vs.size())
            {
                a[x] = ri;
                found = true; 
                vs[ri].push(x);
                ms[ri] = x;
            }
            else
            {
                a[x] = vs.size();
                queue<int> s;
                s.push(x);
                vs.push_back(s);
                ms.push_back(x);
            }
        }
    }
    cout << vs.size() + 1 << endl;
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