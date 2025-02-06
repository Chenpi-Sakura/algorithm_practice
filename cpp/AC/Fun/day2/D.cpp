#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unsigned long long time = 0, result;
    int i = 0;
    int max;
    while (a[i] >= 1)
    {
        a[i]--;
        if (a[i] == 1)
        {
            max = 1;
            for (int j = 0; j < n; j++)
            {
                if (a[j] > max)
                {
                    max = a[j];
                    i = j;
                }
            }
            // cout << max << " ";
        }
        if (!(a[i] == 1 && i != 0))
            time++;
    }
    //cout << time << " " << i << endl;
    result = (time - 1) * n + i + 1;
    cout << result;
    return 0;
}