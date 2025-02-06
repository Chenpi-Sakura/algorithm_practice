/*
题目描述
现在各大 oj 上有 n 个比赛，每个比赛的开始、结束的时间点是知道的。
yyy 认为，参加越多的比赛，noip 就能考的越好（假的）。
所以，他想知道他最多能参加几个比赛。
由于 yyy 是蒟蒻，如果要参加一个比赛必须善始善终，而且不能同时参加 2 个及以上的比赛。

输入格式
第一行是一个整数 n，接下来 n 行每行是 2 个整数 ai,bi (ai<bi)，表示比赛开始、结束的时间。

输出格式
一个整数最多参加的比赛数目。
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> com;

bool cmp(PII a, PII b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    com.resize(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        com[i] = make_pair(a, b);
    }

    sort(com.begin(), com.end(), cmp);

    int max = 1;
    int end = com[0].second;

    for (int i = 1; i < n; i++)
    {
        if (com[i].first >= end)
        {
            max++;
            end = com[i].second;
        }
    }

    cout << max;
    return 0;
}