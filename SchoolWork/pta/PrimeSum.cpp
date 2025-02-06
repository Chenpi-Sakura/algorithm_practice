#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k, t = 0, v, sum = 0;
    cin >> n >> k;

    for (int i = n; i >= 2; i--)
    {
        v = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                v = 0;
                break;
            }
        }
        if (v)
        {
            t++;
            sum += i;
            if (t <= k && i > 2)
                cout << i << "+";
            else
            {
                cout << i << "=" << sum;
                return 0;
            }
        }
    }
}