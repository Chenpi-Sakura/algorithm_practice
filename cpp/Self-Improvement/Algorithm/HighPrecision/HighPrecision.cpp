/*
    高精度计算是为了避免因数据表示范围不够的一种计算方法或数字表示方法，
    是用数组来模拟数字来进行加减乘除操作。
*/

#include <bits/stdc++.h>
using namespace std;

// 高精度乘法
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0; // 用于储存进位
    
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

// 高精度除法
vector<int> div(vector<int> a, int b)
{
    vector<int> c;
    bool is_first = true;
    for (int i = a.size() - 1, t = 0; i >= 0; i--)
    {
        t = t * 10 + a[i];
        int x = t / b;
        if (!is_first || x)
        {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

// 高精度加法
vector<int> plu(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        t = t + a[i];
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main()
{

}