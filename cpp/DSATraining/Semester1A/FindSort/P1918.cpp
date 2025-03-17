/*
#P1918. 保龄球

题目描述
DL看清远方瓶子的个数后从某个位置发球，这样就能打倒一定数量的瓶子。
◯◯◯
◯◯◯◯
◯
◯◯
如上图，每个 “◯” 代表一个瓶子。如果 DL 想要打倒 3 个瓶子就在 1 位置发球，想要打倒 4 个瓶子就在 2 位置发球。
现在他想要打倒 m 个瓶子。他告诉你每个位置的瓶子数，请你给他一个发球位置。

输入格式
第一行包含一个正整数 n，表示位置数。
第二行包含 n 个正整数 ai，表示第 i 个位置的瓶子数，保证各个位置的瓶子数不同。
第三行包含一个正整数 Q，表示 DL 发球的次数。
第四行至文件末尾，每行包含一个正整数 m，表示 DL 需要打倒 m 个瓶子。

输出格式
共 Q 行。每行包含一个整数，第 i 行的整数表示 DL 第 i 次的发球位置。若无解，则输出 0。

Reflection
存入一个二元组，按照瓶子数量排序。
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII> arr;
int n, q;

bool cmp(PII a, PII b)
{
    return a.second < b.second;
}

void find(int m)
{
    int l = 0, r = n; // 大一个1就够了有的时候
    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (arr[mid].second < m)
            l = mid + 1;
        else
            r = mid;
    }
    if (arr[l].second != m)
        cout << "0" << endl;
    else
        cout << arr[l].first << endl;
}

int main()
{
    cin >> n;
    arr.resize(n); // 初始化vector真的很重要啊
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = {i + 1, a};
    }
    sort(arr.begin(), arr.end(), cmp); // 二元组一定要看清楚以谁为标准
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int m;
        cin >> m;
        if (m < arr[0].second || m > arr[n - 1].second)
            cout << "0" << endl;
        else
            find(m);
    }
    return 0;
}