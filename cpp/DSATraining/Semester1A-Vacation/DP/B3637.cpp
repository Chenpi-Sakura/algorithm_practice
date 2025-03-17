/*

最长上升子序列
题目描述
这是一个简单的动规板子题。
给出一个由 n(n≤5000) 个不超过 10^6 的正整数组成的序列。请输出这个序列的最长上升子序列的长度。
最长上升子序列是指，从原序列中按顺序取出一些数字排在一起，这些数字是逐渐增大的。

输入格式
第一行，一个整数 n，表示序列长度。
第二行有 n 个整数，表示这个序列。

输出格式
一个整数表示答案。

输入数据 1
6
1 2 4 1 3 4
输出数据 1
4

*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 5e3 + 10;
int a[N], dp[N]; // a[i]序列 dp[i] 储存以第 i 个数结尾的最长上升子序列的长度
int n;


int main( )
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) dp[i] = 1;
    int maxL = 0;    

    for (int i = 1; i < n; i++)
    { // 当前考虑的元素位置
        for (int j = 0; j < i; j++)
        { // 遍历当前元素之前的所有位置
            if (a[i] > a[j]) dp[i] = max(dp[j] + 1, dp[i]);
        }
        maxL = max(dp[i], maxL); 
    }

    cout << maxL << endl;
    return 0;
}
