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
    for (int i = 2; i * i <= n; i++)
    {
        if (b[i])
        {
            prime[tot++] = i;
            for (int j = i * i; j <= n; j += i)
            {
                b[j] = false;
            }
        }
    }
    for (int i = (int)sqrt(n) + 1; i <= n; i++)
    {
        if (b[i])
        {
            prime[tot++] = i;
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
/*
i = 2：标记所有 2 的倍数（4, 6, 8, ...）。
i = 3：标记所有 3 的倍数（6, 9, 12, ...）。
i = 5：标记所有 5 的倍数（10, 15, 20, ...）。
i = 7：标记所有 7 的倍数（14, 21, 28, ...）。
尽管 6 和 10 在筛选 i = 2 和 i = 5 时已经被标记过了，但在处理后面的素数时，它们还是会被重复标记。

非最佳筛法
*/