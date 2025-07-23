#include<bits/stdc++.h>
using namespace std;

// const int N = 2e5 + 5;
// int a[N];
priority_queue<int, vector<int>, greater<int>> a;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            a.push(x);
        }
        while (a.size() > 1)
        {
            int x = a.top(); a.pop();
            int y = a.top(); a.pop();
            a.push(x + y - 1);
        }
        cout << a.top() << endl;
        a.pop();
    }
    return 0;
}