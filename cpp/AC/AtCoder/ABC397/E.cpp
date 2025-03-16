#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> e[N];

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i < n * k; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bool ans;
    for (int i = 1; i <= n * k; i += k)
    {
        ans = false;
        for (int j : e[i])
        {
            if (j == i + 1)
            {
                ans = true; 
                break;
            }
        }
        if (ans == false) break;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}