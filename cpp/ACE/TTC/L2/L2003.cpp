#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> PDD;
const int N = 1e3 + 5;
double a[N], b[N];
PDD p[N];

bool cmp(PDD x, PDD y)
{
    return x.first > y.first;
}


int main()
{
    int n; double d; cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        double price = b[i] / a[i];
        p[i] = {price, a[i]};
    }
    sort(p, p + n, cmp);
    double ans = 0; int cnt = 0;
    while (d > 1e-6 && cnt < n)
    {
        auto x = p[cnt++];
        if (x.second <= d)
        {
            d -= x.second;
            ans += x.first * x.second;
        }
        else
        {
            ans += d * x.first;
            d = 0;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}