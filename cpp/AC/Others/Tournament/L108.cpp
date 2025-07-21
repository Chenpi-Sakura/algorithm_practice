#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
typedef pair<int, int> PII;
PII a[N];

int main()
{
    int n, m, k, p; cin >> n >> m >> k >> p;
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + m);

    int current = 0;
    bool isArrived = true;
    for (int i = 0; i < m; i++)
    {
        int dis = a[i].first - current;
        if (k == 0)
        {
            isArrived = false;
            break;
        }
        else if (dis > k && p) 
        {
            k--; 
        }
        else if (dis > k && !p)
        {
            isArrived = false;
            break;
        }
        current = a[i].second;
        if (current == n) break;
    }

    if (isArrived) cout << "YES" << ' ' << k << endl;
    else cout << "buguanle" << ' ' << current << endl; 
    return 0;
}