// WRONG

#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 5;
bool isPrime[N];
vector<int> prime;

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i]) prime.push_back(i);
        for (int p : prime)
        {
            if (i * p > N) break;
            isPrime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

int main()
{
    int n; cin >> n;
    sieve();
    while (n--)
    {
        int x; cin >> x;
        if (isPrime[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}