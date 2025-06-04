#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    double x, y; cin >> x >> y;
    double total = 36;
    double res = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i + j >= x && abs(i - j) >= y) res++;
            else if (i + j >= x) res++;
            else if (abs(i - j) >= y) res++;
        }
    }
    printf("%.12lf", res / total);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    // cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}