#include<bits/stdc++.h> 
using namespace std;
#define int long long

const int N = 1e4 + 5;
const int M = 1e9 + 7;
int a[505][505], s[505][505];
int n, m, k;

int find(int a, int b)
{
    int res = 0;
    for(int i = a; i <= n; i++)
    {
        for (int j = b; j <= m; j++)
        {
            int t = s[i][j] + s[i - a][j - b] - s[i - a][j] - s[i][j - b];
            if (t <= k) res++;
        }
    }
    return res;
}

signed main( )
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += find(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}