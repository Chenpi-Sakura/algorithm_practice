#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, sum = 0;
    cin >> num;
    if (num < 100 || num > 999)
    {
        cout << "Invalid Value.";
        return 0;
    }
    for (int n = num; n > 0; n /= 10)
    {
        sum += pow((n % 10), 3);
    }
    if (sum == num)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}