/*
题目描述
给出一个长度为 n 的序列 a，选出其中连续且非空的一段使得这段和最大。

输入格式
第一行是一个整数，表示序列的长度 n
第二行有 n 个整数，第 i 个整数表示序列的第 i 个数字 a
输出格式
输出一行一个整数表示答案。
*/
/*
#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        a[i] = a[i - 1] + temp;
    }
    temp = a[1];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((a[j] - a[i]) > temp)
                temp = (a[j] - a[i]);
        }
    }

    cout << temp;

    return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n]; // 使用 n 的长度

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxSum = a[0];     // 初始化最大和为第一个元素
    int currentSum = a[0]; // 当前和

    for (int i = 1; i < n; i++)
    {
        // 更新当前和，选择当前元素或者前面的和
        currentSum = max(a[i], currentSum + a[i]);
        // 更新最大和
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}
