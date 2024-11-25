#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int weeks = 1;
    int current = 1, i = 0;
    // current 为 星期几
    // i 为 任务序数
    while (i < n)
    {
        if (a[i] == current)
            i++;
        if (i < n)
        {
            current = (current % 7) + 1;
            if (current == 1)
                weeks++;
        }
    }
    cout << weeks;

    return 0;
}