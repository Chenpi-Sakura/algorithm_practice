#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int a[N], ps[N], bs[N];
unordered_set<int> s1, s2, s3;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        s1.insert(a[i]);
        ps[i] = s1.size();
    }
    for (int k = 0; k < n; k++)
    {
        s2.clear();
        for (int i = k; i < n; i++)
        {
            s2.insert(a[i]);
            s3.clear();
            for (int j = n - 1; j > i; j--)
            {
                s3.insert(a[j]);
            }
            bs[i] = max(bs[i], (int)(s2.size() + s3.size()));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, ps[i] + bs[i + 1]);
    }
    cout << ans << endl;
    return 0;
}