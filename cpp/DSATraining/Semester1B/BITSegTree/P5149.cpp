#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n;
map<string, int> a;
int b[N], c[N];

int lowbit(int x) {return x & (-x);}

void add(int x, int k)
{
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}

int query(int x)
{
    int s = 0;
    while (x)
    {
        s += c[x];
        x -= lowbit(x);
    }
    return s;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name; cin >> name;
        a[name] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string name; cin >> name;
        b[i] = a[name];
        add(b[i], 1);
        ans += b[i] - query(b[i]);
    }
    cout << ans << endl;
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