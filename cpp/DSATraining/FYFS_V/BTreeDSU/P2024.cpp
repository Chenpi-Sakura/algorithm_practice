/*

*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 5e4;
int f[N * 3 + 10];

int find(int x)
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

int main( )
{
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n * 3; i++) f[i] = i;
    while (k--)
    {
        int t, x, y; cin >> t >> x >> y;
        if (x > n || y > n) {ans++; continue;}
        if (t == 1)
        {
            if ((find(x + n) == find(y)) || (find(x) == find(y + n))) ans++;
            else
            {
                f[find(x)] = find(y);
                f[find(x + n)] = find(y + n);
                f[find(x + n + n)] = find(y + n + n);
            }
        }
        else
        {
            if (((find(x) == find(y)) || find(x) == find(y + n))) ans++;
            else
            {
                f[find(x + n)] = find(y);
                f[find(x + n + n)] = find(y + n);
                f[find(x)] = find(y + n + n);
            }
        }
    }
    cout << ans << endl;
    return 0;
}