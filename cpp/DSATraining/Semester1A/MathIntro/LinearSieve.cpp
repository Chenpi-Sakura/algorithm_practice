#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
bool b[N];    // 判断是否是质数
int prime[N]; // 存质数
int tot = 0;  // 位移

void sieve(int n)
{
    fill(b, b + n + 1, true);
    b[0] = b[1] = false;
    for (int i = 2; i <= n; i++) // 不用i * i
    {
        if (b[i])
        {
            prime[tot++] = i;
        }
        for (int j = 0; i * prime[j] <= n; j++)
        {
            b[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
            // 此步的目的是不一次性把所有的某个数的倍数筛完。    
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    for (int i = 0; i < tot; i++)
    {
        cout << prime[i] << " ";
    }
    return 0;
}
