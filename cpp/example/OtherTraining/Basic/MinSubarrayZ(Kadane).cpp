#include <bits/stdc++.h>
using namespace std;

/*
该算法的目的是找到一个最大的子数列
*/

//例如下列数列
int a0[20] = {1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1};
int a1[20] = {1, -1, 1, 1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1};

int BFS(int *arr)//暴力枚举
{
    int max = arr[0];
    for (int i = 0; i < 20; i++)
    {
        int temp = 0;
        for (int j = i; j < 20; j++)
        {
            temp += arr[j];
            if (temp > max)
                max = temp;
        }
    }
    return max;
}

int kadane(int *arr)
{
    int max_global = arr[0];
    int max_current = arr[0];
    for (int i = 1; i < 20; i++)
    {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global)
            max_global = max_current;
    }
    return max_global;
}
//该算法的重点是在对于位置的实时变化

int main()
{
    cout << BFS(a0) <<endl;
    cout << kadane(a1) << endl;

    return 0;
}