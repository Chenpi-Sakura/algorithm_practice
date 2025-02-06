#include <iostream>
#include <cmath>
using namespace std;

int PrimeJudge(long long n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, isPrime, t = 1;
    cin >> n;
    long long temp;
    for (int i = 2; i <= n; i++)
    {
        temp = pow(2, i) - 1;
        isPrime = PrimeJudge(temp);
        if (isPrime)
        {
            cout << temp << endl;
            t = 0;
        }
    }

    if (t)
    {
        cout << "None";
    }

    return 0;
}