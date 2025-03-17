#include <bits/stdc++.h>
using namespace std;
int d[5000001]; // d[i]表示a[i]-a[i-1]
int a[5000001];
int main()
{
    int n, p, x, y, z, i, min = 1e9;
    cin >> n >> p;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    for (i = 0; i < p; i++)
    {
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    for (i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + d[i];
        if (min > a[i])
        {
            min = a[i];
        }
    }
    cout << min;
    return 0;
}