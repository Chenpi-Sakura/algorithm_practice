#include <iostream>
using namespace std;

int main()
{
    int m, n, v = 1;
    cin >> m >> n;
    for (int i = m, temp; i <= n; i++)
    {
        temp = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                temp += j;
            }
        }
        if (temp == i)
        {
            cout << temp << " = 1";
            for (int j = 2; j < i; j++)
            {
                v = 0;
                if (i % j == 0)
                {
                    cout << " + " << j;
                }
            }
            cout << endl;
        }
    }
    if (v)
    {
        cout << "None";
    }

    return 0;
}