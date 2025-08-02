/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 19:59:59
 * @Link: https://codeforces.com/gym/626001/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n; vector<int> a(n + 1), b(n + 1);
    map<int, int> mp;
    int m = (n + 1) * n / 2;
    for (int i = 1; i < n; i++) 
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        mp[b[i]]++;
    }
    vector<int> nums;
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] != 1) nums.push_back(i);
        if (mp[i] == 2) x = i;
    }
    // for (int x : nums) cout << x << endl;
    for (auto i : mp)
    {
        if (i.first > n)
        {
            nums.push_back(i.first);
            x = i.first;
            break;
        }
    }
    sort(nums.begin(), nums.end());
    // for (int x : nums) cout << x << endl;
    if (nums.size() == 1)
    {
        if ((++mp[nums[0]]) == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if (nums.size() == 3)
    {
        // cout << nums[0] << ' ' << nums[1] << ' ' << x << endl;
        if (nums[0] + nums[1] == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
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