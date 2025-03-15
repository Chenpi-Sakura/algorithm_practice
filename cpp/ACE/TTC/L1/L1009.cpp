#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
PII num[105];

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

signed main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld/%lld", &num[i].first, &num[i].second);
        int x = gcd(num[i].first, num[i].second);
        num[i].first /= x; num[i].second  /= x;
    }

    PII last = num[1];
    int z = 0;
    
    for (int i = 2; i <= n; i++)
    {
        int mother = lcm(last.second, num[i].second);
        int child = last.first * mother / last.second + num[i].first * mother / num[i].second;
        z += child / mother; child = child % mother;
        int x = gcd(child, mother);
        child /= x; mother /= x;
        last.first = child; last.second = mother;
    }
    
    if (z != 0) cout << z;
    if (z != 0 && last.first != 0) cout << ' ';
    if (last.first != 0) cout << last.first << '/' << last.second << endl;
    if (z == 0 && last.first == 0) cout << 0;
    return 0;
}