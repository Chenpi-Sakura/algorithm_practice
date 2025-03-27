#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII; 
priority_queue<PII> q;
unordered_set<int> s1, s2;

int main()
{   
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        if (s1.find(t) == s1.end())
        {
            s1.insert(t);
            q.push({t, i});
        }
        else s2.insert(t); // s2用于存放不可用数字
    }
    while (q.size())
    {
        auto ans = q.top(); q.pop();
        if (s2.find(ans.first) == s2.end())
        {
            cout << ans.second << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}