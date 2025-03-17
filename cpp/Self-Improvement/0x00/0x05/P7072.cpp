/*
题目描述
NOI2130 即将举行。为了增加观赏性，CCF 决定逐一评出每个选手的成绩，并直播即时的获奖分数线。本次竞赛的获奖率为 w%，即当前排名前 w% 的选手的最低成绩就是即时的分数线。
更具体地，若当前已评出了 p 个选手的成绩，则当前计划获奖人数为 max(1,⌊p×w%⌋)，其中 w 是获奖百分比，⌊x⌋ 表示对 x 向下取整，max(x,y) 表示 x 和 y 中较大的数。如有选手成绩相同，则所有成绩并列的选手都能获奖，因此实际获奖人数可能比计划中多。 # 此处说明成绩线更重要
作为评测组的技术人员，请你帮 CCF 写一个直播程序。

输入格式
第一行有两个整数 n,w。分别代表选手总数与获奖率。
第二行有 n 个整数，依次代表逐一评出的选手成绩。

输出格式
只有一行，包含 n 个非负整数，依次代表选手成绩逐一评出后，即时的获奖分数线。相邻两个整数间用一个空格分隔。
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> a;// 小根堆包括分数线
    priority_queue<int> b;// 大根堆

    int n, w;
    cin >> n >> w;
    
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (a.empty() || a.top() <= x) a.push(x);
        else b.push(x);

        int k = max(1, w * i / 100);
        while (a.size() > k) b.push(a.top()), a.pop();
        while (a.size() < k) a.push(b.top()), b.pop();

        cout << a.top() << " ";
    }
    return 0;
}