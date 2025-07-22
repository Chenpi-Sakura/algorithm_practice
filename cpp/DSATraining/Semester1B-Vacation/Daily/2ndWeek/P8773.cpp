/*
 * @Author: Chenpi
 * @Date: 2025-07-21 15:15:32
 * @Link: 
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

// int a[N], f[N];
// unordered_map<int, int> lst;

// void solve()
// {
//     int n, m, x; cin >> n >> m >> x;
//     for (int i = 1; i <= n; i++) 
//     {
//         cin >> a[i];
//         lst[a[i]] = i;
//         f[i] = max(f[i - 1], lst[a[i] ^ x]);
//     }
//     while (m--)
//     {
//         int l, r; cin >> l >> r;
//         if (f[r] < l) cout << "no" << endl;
//         else cout << "yes" << endl;
//     }
// }

int a[N], b[N], f[N][20];
unordered_map<int, int> lst;

void solve()
{
    int n, m, x; cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lst[a[i]] = i;
        b[i] = lst[a[i] ^ x];
    }

    for (int i = 1; i <= n; i++) f[i][0] = b[i];
    int t = log2(n) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    
    while (m--)
    {
        int l, r; cin >> l >> r;
        int k = log2(r - l + 1);
        int res = max(f[l][k], f[r - (1 << k) + 1][k]);
        if (res < l) cout << "no" << endl;
        else cout << "yes" << endl;
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