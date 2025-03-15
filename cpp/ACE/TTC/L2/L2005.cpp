#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
vector<unsigned> a[55];
unordered_set<unsigned> s1, s2;

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m; cin >> m;
        while (m--)
        {
            int t; cin >> t;
            a[i].push_back(t);
        }
    }
    int k; cin >> k;
    while (k--)
    {
        s1.clear(); s2.clear();
        int g1, g2; cin >> g1 >> g2;
        for (unsigned x : a[g1]) s1.insert(x);
        for (unsigned x : a[g2]) s2.insert(x);
        int nc = 0, nt = 0;
        for (unsigned x : s1)
        {
            if (s2.find(x) != s2.end())
                nc++;
            s2.insert(x);
        }
        nt = s2.size();
        //cout << nc << ' ' << nt << endl;
        printf("%.2lf%\n", (double)nc / nt * 100);
    }
    return 0;
}