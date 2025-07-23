#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    int n; cin >> n;
    // vector<int> a;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
        for (auto yy : mp)
        {
            int y = yy.first;
            if (x == y && mp[x] == 1)
            if (y == 1) {continue;}
            int z = gcd(x, y);
            mp[x / z]++; mp[y]--;
            if (mp[y] == 0) mp.erase(y);
            mp[y / z]++;
        }
        
        // a.push_back(x);
        // for (int j = 0; j < i; j++)
        // {
        //     if (a[j] == 1) continue;
        //     int y = gcd(a[j], a[i]);
        //     a[j] /= y; a[i] /= y;
        // }
    }
    cout << mp.size() << endl;
    cout << mp[0] << endl;
    for (auto [x, y] : mp) cout << x << ' ' << y << endl;

    int cnt1 = 0, cnto = 0;
    for (auto x : mp)
    {
        if (x.first == 1) cnt1 += x.second;
        else
        {
            int xx = sqrt(x.first);
            if (x.first == xx * xx && n > 2) cnt1 += x.second;
            else cnto += x.second;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] != 1)
    //     {
    //         int x = sqrt(a[i]);
    //         if (x * x == a[i] && n > 2) cnt1++;
    //         else cnto++;
    //     }
    //     else cnt1++;
    // }

    if (cnto == 0) cout << "YES" << endl;
    else if (cnto % 2 == 0)
    {
        if (cnt1 % 2 == 1) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    else
    {
        if (cnt1 % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

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