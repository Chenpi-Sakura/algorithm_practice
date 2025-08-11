#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

const int base1 = 131, mod1 = 1e9 + 7;
const int base2 = 13331, mod2 = 998244353;

int p1[N], p2[N];     
int h1[N], h2[N];     
int rh1[N], rh2[N];  
int n, q;
string s;

PII get(int l, int r)
{
    int len = r - l + 1;
    int v1 = (h1[r] - h1[l - 1] * p1[len] % mod1 + mod1) % mod1;
    int v2 = (h2[r] - h2[l - 1] * p2[len] % mod2 + mod2) % mod2;
    return {v1, v2};
}

PII get1(int l, int r)
{
    int rl = n - r + 1, rr = n - l + 1;
    int len = rr - rl + 1;
    int v1 = (rh1[rr] - rh1[rl - 1] * p1[len] % mod1 + mod1) % mod1;
    int v2 = (rh2[rr] - rh2[rl - 1] * p2[len] % mod2 + mod2) % mod2;
    return {v1, v2};
}

bool judge(int l, int r)
{
    return get(l, r) == get1(l, r);
}

void solve()
{
    int n, q; cin >> n >> q;
    string s; cin >> s;
    string ss = {s.rbegin(), s.rend()};
    s = " " + s; ss = " " + ss;
    p1[0] = p2[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        p1[i] = p1[i - 1] * base1 % mod1;
        p2[i] = p2[i - 1] * base2 % mod2;
        h1[i] = (h1[i - 1] * base1 + s[i]) % mod1;
        h2[i] = (h2[i - 1] * base2 + s[i]) % mod2;
        rh1[i] = (rh1[i - 1] * base1 + ss[i]) % mod1;
        rh2[i] = (rh2[i - 1] * base2 + ss[i]) % mod2;
    }

    while (q--)
    {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        if (judge(l, r)) cout << "Budada" << endl;
        else
        {
            if (len % 2 == 1) cout << "Putata" << endl;
            else cout << "Budada" << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}