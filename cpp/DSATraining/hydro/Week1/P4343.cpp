/*
题目背景
曾经发明了信号增幅仪的发明家 SHTSC 又公开了他的新发明：自动刷题机——一种可以自动 AC 题目的神秘装置。

题目描述
自动刷题机刷题的方式非常简单：首先会瞬间得出题目的正确做法，然后开始写程序。每秒，自动刷题机的代码生成模块会有两种可能的结果：

1.写了 x 行代码
2.心情不好，删掉了之前写的 y 行代码。（如果 y 大于当前代码长度则相当于全部删除。）

对于一个 OJ，存在某个固定的正整数长度 n，一旦自动刷题机在某秒结束时积累了大于等于 n 行的代码，它就会自动提交并 AC 此题，然后新建一个文件（即弃置之前的所有代码）并开始写下一题。SHTSC 在某个 OJ 上跑了一天的自动刷题机，得到了很多条关于写代码的日志信息。他突然发现自己没有记录这个 OJ 的 n 究竟是多少。所幸他通过自己在 OJ 上的 Rank 知道了自动刷题机一共切了 k 道题，希望你计算 n 可能的最小值和最大值。

输入格式
第一行两个整数 l,k，表示刷题机的日志一共有 l 行，一共了切了 k 题。
接下来 l 行，每行一个整数 xi ，依次表示每条日志。若 xi ≥ 0，则表示写了 xi 行代码，若 xi < 0，则表示删除了 −xi 行代码。

输出格式
输出一行两个整数，分别表示 n 可能的最小值和最大值。
如果这样的 n 不存在，请输出一行一个整数 -1。
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<LL> report;

// 用于测出n下能过多少题
LL canAppect(int l, LL n)
{
    LL appect = 0;
    LL current = 0;
    for (int i = 0; i < l; i++)
    {
        current += report[i];
        if (current < 0)
        {
            current = 0;
        }
        if (current >= n)
        {
            appect++;
            current = 0;
        }
    }
    return appect;
}

int main()
{
    LL l, k;
    cin >> l >> k;
    report.resize(l);
    // 输入数据
    for (int i = 0; i < l; i++)
    {
        cin >> report[i];
    }

    // 找到生成代码中能出现的最大值
    LL maxLine = 0;
    LL temp = 0;
    for (int i = 0; i < l; i++)
    {
        temp += report[i];
        if (temp < 0)
        {
            temp = 0;
        }
        if (temp >= maxLine)
        {
            maxLine = temp;
        }
    }

    // 查询最小值
    LL min = -1;
    LL left = 1, right = maxLine;
    while (left <= right)
    {
        LL mid = (left + right) / 2;
        LL cnt = canAppect(l, mid);
        if (cnt == k)
        {
            min = mid;
            right = mid - 1;
        }
        else if (cnt < k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (min == -1)
    { // 找不到最小值，则证明无法找到这样的n
        cout << -1 << endl;
        return 0;
    }

    // 能找到最小值，现在开始寻找最大值
    LL max = min;
    left = min + 1, right = maxLine;
    while (left <= right)
    {
        LL mid = (left + right) / 2;
        LL cnt = canAppect(l, mid);
        if (cnt == k)
        {
            max = mid;
            left = mid + 1;
        }
        else if (cnt > k)
        { 
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << min << " " << max << endl;
    return 0;
}