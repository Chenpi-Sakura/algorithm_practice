#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int a[N];
int f[3];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(f, inf, sizeof(f));
    f[a[0] + 1] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == -1)
        {
            f[0] = f[0];
            f[1] = inf;
            f[2] += 2;
        }
        else if (a[i] == 0)
        {
            f[1] = min(f[0], f[1]);
            f[0]++;
            f[2]++;
        }
        else if (a[i] == 1)
        {
            f[2] = min(f[0], min(f[1], f[2]));
            f[1] = f[0] + 1;
            f[0] += 2;
        }
    }
    int ans = min(f[0], min(f[1], f[2]));
    if (ans < inf) cout << ans << endl;
    else cout << "BRAK" << endl;

    return 0;
}