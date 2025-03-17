/*
动态中位数

依次读入一个整数序列，每当已经读入的整数个数为奇数时，输出已读入的整数构成的序列的中位数。

输入格式
第一行输入一个整数 P，代表后面数据集的个数，接下来若干行输入各个数据集。
每个数据集的第一行首先输入一个代表数据集的编号的整数。
然后输入一个整数 M，代表数据集中包含数据的个数，M 一定为奇数，数据之间用空格隔开。

数据集的剩余行由数据集的数据构成，每行包含 10 个数据，最后一行数据量可能少于 10 个，数据之间用空格隔开。

输出格式
对于每个数据集，第一行输出两个整数，分别代表数据集的编号以及输出中位数的个数（应为数据个数加一的二分之一），数据之间用空格隔开。
数据集的剩余行由输出的中位数构成，每行包含 10 个数据，最后一行数据量可能少于 10 个，数据之间用空格隔开。
输出中不应该存在空行。

数据范围
1≤P≤1000,
1≤M≤99999,
所有 M 相加之和不超过 5×105。
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
long long a[N];

int main()
{
    int p;
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        int index, m;
        cin >> index >> m;
        cout << index << ' ' << m / 2 + 1 << endl;
        priority_queue<int, vector<int>, greater<int>> a; // 小根堆包括中位数
        priority_queue<int> b; // 大根堆
        int j, cnt = 0;
        for (j = 1; j <= m; j++)
        {
            int x; cin >> x;
            if (a.empty() || a.top() <= x) a.push(x);
            else b.push(x);
            
            while (a.size() > b.size()) b.push(a.top()), a.pop();
            while (a.size() < b.size()) a.push(b.top()), b.pop();
            
            if (j & 1) 
            {
                cout << a.top() << ' ', cnt++;
                if (cnt % 10 == 0) cout  << endl;
            }
        }
        if (cnt % 10 != 0) cout << endl;
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                      