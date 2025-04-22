#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 4e2 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;
vector<PII> points(N);


int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> points[i].first >> points[i].second;

    if (k <= 1 && n >= 1) 
    {
        cout << -1 << endl;
        return;
    }

    set<tuple<int, int, int>> lines;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) {
            int x1 = points[i].first;
            int y1 = points[i].second;
            int x2 = points[j].first;
            int y2 = points[j].second;

            int a = y1 - y2;
            int b = x2 - x1;
            int c = x1 * y2 - x2 * y1;

            int x = gcd(gcd(abs(a), abs(b)), abs(c));
            if (x > 0) 
            {
                a /= x;
                b /= x;
                c /= x;
            }

            if (a < 0 || (a == 0 && b < 0))
            {
                a = -a;
                b = -b;
                c = -c;
            }

            int count = 0;
            for (int l = 0; l < n; ++l) 
            {
                int x = points[l].first;
                int y = points[l].second;
                if (a * x + b * y + c == 0) 
                {
                    count++;
                }
            }

            if (count >= k) 
            {
                lines.insert(make_tuple(a, b, c));
            }
        }
    }
    cout << lines.size() << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}