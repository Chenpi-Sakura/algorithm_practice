#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int sf[N];
vector<int> ans, prime(N, 1);

void pre()
{
    for (int i = 1; i < N; i++) sf[i] = i;
    for (int i = 2; i * i < N; i++)
    {
        int s = i * i;
        for (int j = s; j < N; j += s)
        {
            while (sf[j] % s == 0)
            {
                sf[j] /= s;
            }
        }
    }


    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        if (prime[sf[i]])
        {
            ans.push_back(i);
        }
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n / 2; i++) cout << ans[i] << ' ';
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}