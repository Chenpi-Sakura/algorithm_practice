#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string num;
    for (int i = 1, t = 0, len, sum; i <= 1000; i++)
    {
        num = to_string(i);
        len = num.size();
        sum = 0;
        for (int j = 0; j < len; j++)
        {
            sum += num[j] - '0';
        }
        if (sum == n)
        {
            printf("%8d", i);
            t++;
            if (t % 6 == 0)
            {
                cout << endl;
            }
        }
    }
    cout << endl;
    return 0;
}