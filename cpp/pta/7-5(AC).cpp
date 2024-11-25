#include <bits/stdc++.h>
using namespace std;

int a[6][6];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int max = a[i][0];
        int max_col = 0;

        for (int j = 1; j < n; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
            }
        } // 查找行最大与对应列
        for (int j = 0; j < n; j++)
        {
            if (max == a[i][j])
            {
                max_col = j;
                int is_min = 1;
                for (int j = 0; j < n; j++)
                {
                    if (a[j][max_col] < max)
                    {
                        is_min = 0;
                        break;
                    }
                } // 检验列最小
                if (is_min)
                {
                    cout << i << " " << max_col;
                    return 0;
                }
            }
        }
    }
    cout << "NONE";
    return 0;
}