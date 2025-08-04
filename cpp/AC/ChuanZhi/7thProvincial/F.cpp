/** 
 * @Author: Chenpi
 * @Date: 2025-05-18 09:50:28
 * @Link: https://ac.nowcoder.com/acm/contest/99909/F
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e2 + 5;
const int NN = 1e4 + 5;
const int M = 998244353;
const int inf = 0x3f3f3f3f;

int a[N], f1[N][NN], f2[NN];

void solve()
{
    int n; cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    int ans = 0;
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    
    f1[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {// 遍历堆
        for (int j = 0; j <= s; j++)
        {
            f1[i][j] = f1[i - 1][j]; // 不选第 i 堆糖果
            if (j >= a[i]) 
            {
                f1[i][j] = (f1[i][j] + f1[i - 1][j - a[i]]) % M;
            }
        }
    }

    // // f2为后缀dp
    // f2[n + 1][0] = 1;
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         f2[i][j] = f2[i + 1][j];
    //         if (j >= a[i])
    //         {
    //             f2[i][j] = (f2[i][j] + f2[i + 1][j - a[i]]) % M;
    //         }
    //     }
    // }
    // 
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         ans = (ans + f1[i][j] * f2[i + 1][j] % M) % M;
    //     }
    // }

    // 假如我们使用滚动数组来统计

    f2[0] = 1; // 注意此处数组底标的意义
    for (int i = n; i >= 1; i--)
    {
        for (int j = s; j >= a[i]; j--)
        {
            f2[j] = (f2[j] + f2[j - a[i]]) % M;
        }
        for (int j = 0; j <= s; j++)
        {
            ans = (ans + f1[i - 1][j] * f2[j] % M) % M;
        }
    }

    ans = (ans + f1[n][0]) % M;

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; cin >> t;
    // t = 1;
    while (t--) solve();
    return 0;
}