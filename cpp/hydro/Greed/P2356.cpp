/*
弹珠游戏

题目描述
MedalPluS 和他的小伙伴 NOIRP 发掘了一个骨灰级别的游戏——超级弹珠。

游戏的内容是：在一个 n×n 的矩阵里，有若干个敌人，你的弹珠可以摧毁敌人，但只能攻击你所在的行、列里的所有敌人，然后你就可以获得他们的分数之和，现在请你选择一个你的位置，使得能击杀的敌人最多，注意，你不能和敌人在一个地方。

输入格式
输入有两行，第一行一个正整数 n，接下来 n 行，每行 n 列，如果有敌人则为一个正整数，否则为 0。

输出格式
输出共一行，最多分数，如果连你的容身之地都没有，请输出“Bad Game!”

对于 100% 的数据，1≤n≤1000，保证容身之地的数量小于 10000。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a[1010][1010], s[1010], r[1010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            r[i] += a[i][j];
            s[j] += a[i][j];
        }
    }
    LL max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                LL temp = r[i] + s[j];
                if (temp > max)
                    max = temp;
            }
        }
    }
    if (max == -1)
    {
        cout << "Bad Game!";
        return 0;
    }
    cout << max;
    return 0;
}