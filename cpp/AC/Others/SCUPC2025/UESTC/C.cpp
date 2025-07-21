#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
char s[N];

void solve()
{
    memset(s, '*', sizeof(s));
    int n, m; cin >> n >> m;
    while (m--)
    {
        int p, l; cin >> p >> l;
        s[l] = '>';
        for (int i = l; i <= p + l - 4)
    }
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
    return 0;
}