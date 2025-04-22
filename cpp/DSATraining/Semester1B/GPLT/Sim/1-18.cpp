/*
    模拟题一般不考察思维，所以我们一般就不要从去思考较难的思维，选择更加保险的直接模拟即可
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

string s1, s2;
stack<char> s3;
vector<string> ans;

void solve()
{
    cin >> s1 >> s2;
    deque<char> q1(s1.begin(), s1.end());

    int cnt = 0, len = s1.size();
    while (cnt < len)
    {
        char t = s2[cnt];
        if(!s3.empty() && s3.top() == t)
        {
            ans.push_back("3->2");
            s3.pop(); cnt++;
        }
        else if (!q1.empty() && q1.front() == t)
        {
            ans.push_back("1->2");
            q1.pop_front(); cnt++;
        }
        else if (!q1.empty())
        {
            ans.push_back("1->3");
            s3.push(q1.front()); q1.pop_front();
        }
        else
        {
            cout << "Are you kidding me?" << endl;
            return;
        }
    }
    for (auto x : ans) cout << x << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}