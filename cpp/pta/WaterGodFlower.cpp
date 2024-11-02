#include <iostream>
using namespace std;

long long power(long long x, int n)
{
    int r = x;
    for (int i = 1; i < n; i++)
    {
        r *= x;
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    for (int i = power(10, n-1), sum; i < power(10, n); i++)
    {
        sum = 0;
        for (int j = i; j > 0; j /= 10)
        {
            sum += power(j % 10, n);
        }
        if (sum == i)
        {
            cout << i << endl;
        }
    }
    return 0;
}