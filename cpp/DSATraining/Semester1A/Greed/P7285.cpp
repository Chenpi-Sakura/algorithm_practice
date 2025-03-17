/*
题目描述
给定一个长度为 n、元素由 0 或 1 组成的数组。
现在可以选择若干（可以为 0）个值为 0 的元素，将其修改为 1。
记：x 为数组中最长连续 1 子段的长度（规定，若所有数均为 0，则 x 为 0）；y 为修改的元素的个数。
求要怎么修改才能使 x−y 最大，并构造一个方案（输出修改后的数组）。

输入格式
本题含有多组数据。
第一行一个整数 T 表示数据组数。
接下来 2×T 行，每 2 行表示一组数据。
在一组数据中，第一行一个整数 n，表示数组的长度；
第二行 n 个整数（0 或 1），表示给定的数组。

输出格式
共 2×T 行，每 2 行表示一组数据。
在一组数据中，第一行输出一个整数表示 x−y 的最大值；
第二行 n 个整数（0 或 1）表示修改以后的数组。如有多个方案，任意输出一种即可。
*/

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> a;

// int kadane(int &ml, int &mr)
// {
//     int gmax = a[0];
//     int cmax = a[0];
//     int length = a.size();
//     int cl = ml, cr = mr;
//     for (int i = 1; i < length; i++)
//     {
//         if (a[i] > cmax + a[i])
//         {
//             cmax = a[i];
//             cl = i;
//             cr = i;
//         }
//         else
//         {
//             cmax = cmax + a[i];
//             cr = i;
//         }
//         // cmax = max(a[i], cmax + a[i]);
//         if (cmax > gmax)
//         {
//             gmax = cmax;
//             ml = cl;
//             mr = cr;
//         }
//     }
//     return gmax;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         int n;
//         cin >> n;
//         a.resize(n);
//         // 初始化

//         for (int j = 0; j < n; j++)
//         {
//             cin >> a[j];
//             if (a[j] == 0)
//                 a[j] = -1;
//         } // 输入

//         int left = 0, right = 0;

//         int max = kadane(left, right);
//         for (int i = left; i < right; i++)
//         {
//             a[i] = 1;
//         }

//         cout << max << endl;
//         int len = a.size();
//         for (int i = 0; i < len; i++)
//         {
//             cout << a[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 几近完工的模拟QWQ
/*
但实际上这是一个思维题目
其实我已经知道了每改一个 0 不会使总数变化，
所以此时就无脑全加上就完事了，
怪不得是入门题目
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        a.resize(n);
        // 初始化

        int max = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (a[j] == 1)
                max++;
            else if (a[j] == 0)
                a[j] = 1;
        } // 输入    

        cout << max << endl;
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}