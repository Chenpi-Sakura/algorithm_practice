#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int h[N], cnt[N], n;

signed main()
{
    cin >> n;
    int cut = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i]; int temp = h[i];
        while (temp - 1)
        {
            temp = sqrtl(temp / 2 + 1);
            cnt[i]++;
        }
        cut = max(cut, cnt[i]);
    }

    int ans = 0;
    for (int i = cut; i > 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cnt[j] == i)
            {
                if (h[j] != h[j + 1]) ans++;
                cnt[j]--;
                h[j] = sqrtl(h[j] / 2 + 1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}


// map<int, int, greater<int>> bamboo;
// int n;

// signed main()
// {
//     cin >> n;
//     while (n--)
//     {
//         int h; cin >> h;
//         bamboo[h]++;
//     }

//     int ans = 0;

//     while (bamboo.size() > 1)
//     {
//         auto b = bamboo.begin();
//         int height = b->first;
//         int nums = b->second;

//         int bb = sqrt((int)(height / 2) + 1);
//         bamboo[bb] += nums;
//         bamboo.erase(height);
//         ans++;
//     }
    
//     cout << ans << endl;
//     return 0;
// }