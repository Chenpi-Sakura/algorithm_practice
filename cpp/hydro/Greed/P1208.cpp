/*
题目描述
由于乳制品产业利润很低，所以降低原材料（牛奶）价格就变得十分重要。帮助 Marry 乳业找到最优的牛奶采购方案。
Marry 乳业从一些奶农手中采购牛奶，并且每一位奶农为乳制品加工企业提供的价格可能相同。此外，就像每头奶牛每天只能挤出固定数量的奶，每位奶农每天能提供的牛奶数量是一定的。每天 Marry 乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。
给出 Marry 乳业每天对牛奶的需求量，还有每位奶农提供的牛奶单价和产量。计算采购足够数量的牛奶所需的最小花费。
注：每天所有奶农的总产量大于 Marry 乳业的需求量。

输入格式
第一行二个整数 n,m，表示需要牛奶的总量，和提供牛奶的农民个数。
接下来 m 行，每行两个整数 pi,ai ，表示第 i 个农民牛奶的单价，和农民 i 一天最多能卖出的牛奶量。

输出格式
单独的一行包含单独的一个整数，表示 Marry 的牛奶制造公司拿到所需的牛奶所要的最小费用。
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII> milk;

bool cmp(PII a, PII b)
{
    return a.first < b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    milk.resize(m);

    for (int i = 0; i < m; i++)
    {
        int p, a;
        cin >> p >> a;
        milk[i] = make_pair(p, a);
    }

    sort(milk.begin(), milk.end(), cmp);

    int i = 0;
    int t = 0;
    while (n > 0)
    {
        if (milk[i].second > n)
        {
            t += n * milk[i].first;
            n = 0;
        }
        else
        {
            n -= milk[i].second;
            t += milk[i].first * milk[i].second;
            i++;
        }
    }

    cout << t << endl;

    return 0;
}