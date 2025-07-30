#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int num[N], nnum[N];

void solve()
{
    int n, t; cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> num[i];
    while (t--)
    {
        int k; cin >> k;
        int a = 0, b = 1;
        for (int i = 1; i <= n; i++)
        {
            if (k * a + b > n)
            {
                a = 0;
                b++;
            }
            nnum[i] = num[a * k + b];
            a++;
        }
        for (int i = 1; i <= n; i++) 
        {
            num[i] = nnum[i];
        }
    }
    for (int i = 1; i <= n; i++) cout << num[i] << ' ';
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

// #include <cstdio>
// #include <vector>

// inline int read() {
//     int x = 0, f = 1;
//     char ch = getchar_unlocked();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar_unlocked();
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = x * 10 + ch - '0';
//         ch = getchar_unlocked();
//     }
//     return x * f;
// }

// inline void write(int x) {
//     if (x == 0) {
//         putchar_unlocked('0');
//         return;
//     }
//     char buf[12];
//     int len = 0;
//     if (x < 0) {
//         putchar_unlocked('-');
//         x = -x;
//     }
//     while (x) {
//         buf[len++] = x % 10 + '0';
//         x /= 10;
//     }
//     while (len--) {
//         putchar_unlocked(buf[len]);
//     }
// }

// inline void write_space(int x, bool last) {
//     write(x);
//     if (!last) putchar_unlocked(' ');
//     else putchar_unlocked('\n');
// }

// int main() {
//     int n = read(), T = read();
//     std::vector<int> a(n);
//     for (int i = 0; i < n; ++i)
//         a[i] = read();

//     for (int t = 0; t < T; ++t) {
//         int k = read();
//         std::vector<std::vector<int>> buckets(k);
//         for (int i = 0; i < n; ++i)
//             buckets[i % k].push_back(a[i]);
//         std::vector<int> new_a;
//         new_a.reserve(n);
//         for (int i = 0; i < k; ++i)
//             for (int x : buckets[i])
//                 new_a.push_back(x);
//         a = std::move(new_a);
//     }

//     for (int i = 0; i < n; ++i)
//         write_space(a[i], i == n - 1);

//     return 0;
// }
