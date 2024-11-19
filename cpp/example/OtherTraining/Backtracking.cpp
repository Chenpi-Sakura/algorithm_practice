/*
回溯算法
用于解决排列组合的问题
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nums; // 数组
int n, k;         // 输入量与组合数

void backtrack(int start, int count, int sum)   
{
    if (count == k)
    {
        cout << sum << " ";
        return;
    }
    for (int i = start; i < n; i++)
    {
        backtrack(i + 1, count + 1, sum + nums[i]); // 不用++防止原始值被修改(不要修改原始值)
    } // 不是一次性算完的，而是在递归中相加。
}

int main()
{
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    backtrack(0, 0, 0);
}