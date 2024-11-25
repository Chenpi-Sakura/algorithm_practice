#include <iostream>
using namespace std;

int a[10][10];

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v = 0;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> a[j][k];
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k < j && a[j][k] != 0)
                {
                    v = 1;
                    break;
                }
            }
            if(v)
                break;
        }
        if (v == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}