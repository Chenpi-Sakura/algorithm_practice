#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

// 反其道而行之，我们使用最小公倍数来进行构造原数列，再进行验证
void solve()
{
    int n; cin >> n;
    vector<int> p(n), s(n), a(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) a[i] = lcm(p[i], s[i]);
    int cp = 0, cs = 0;
    for (int i = 0; i < n; i++)
    {
        cp = gcd(cp, a[i]);
        if (cp != p[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cs = gcd(cs, a[i]);
        if (cs != s[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

// 该解法只有必要性没有充分性
// 仅仅是从已有的特点进行筛选
// 检查的过程中没有验证数组中的数字是否是最大公约数
// void solve()
// {
//     int n; cin >> n;
//     vector<int> p(n), s(n);
//     int ans = 1;
//     for (int i = 0; i < n; i++) cin >> p[i];
//     for (int i = 0; i < n; i++) cin >> s[i];
//     for (int i = 1; i < n; i++)
//     {
//         if (p[i - 1] % p[i] != 0)
//         {
//             ans = 0;
//             break;
//         }
//     }
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (s[i + 1] % s[i] != 0)
//         {
//             ans = 0;
//             break;
//         }
//     }
//     if (p[n - 1] != s[0]) ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (gcd(p[i], s[i]) != s[0])
//         {
//             ans = 0;
//             break;
//         }
//     }
    // if (s[0] == 1 && p[0] % s[1] == 0) ans = 0;
    // if (p[n - 1] == 1 && s[n - 1] % p[n - 2] == 0) ans = 0;
    // if (p[0] % s[0] != 0 || s[n - 1] % p[n - 1] != 0) ans = 0;
//     if (ans) cout << "YES" << endl;
//     else cout << "NO" << endl;
// }

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