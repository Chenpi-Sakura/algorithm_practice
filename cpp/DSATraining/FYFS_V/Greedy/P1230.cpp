/*
智力大冲浪
题目描述
小伟报名参加中央电视台的智力大冲浪节目。本次挑战赛吸引了众多参赛者，主持人为了表彰大家的勇气，先奖励每个参赛者 m 元。先不要太高兴，因为这些钱还不一定都是你的。接下来主持人宣布了比赛规则：

首先，比赛时间分为 n 个时段，它又给出了很多小游戏，每个小游戏都必须在规定期限 ti 前完成。如果一个游戏没能在规定期限前完成，则要从奖励费 m 元中扣去一部分钱 wi ，wi 为自然数，不同的游戏扣去的钱是不一样的。当然，每个游戏本身都很简单，保证每个参赛者都能在一个时段内完成，而且都必须从整时段开始。主持人只是想考考每个参赛者如何安排组织自己做游戏的顺序。作为参赛者，小伟很想赢得冠军，当然更想赢取最多的钱！注意：比赛绝对不会让参赛者赔钱!

输入格式
第一行为 m，表示一开始奖励给每位参赛者的钱；
第二行为 n，表示有 n 个小游戏；
第三行有 n 个数，分别表示游戏 1 到 n 的规定完成期限；
第四行有 n 个数，分别表示游戏 1 到 n 不能在规定期限前完成的扣款数。

输出格式
输出仅一行，表示小伟能赢取最多的钱。
*/

#include<bits/stdc++.h> 
using namespace std;

typedef pair<int, int> PII;
const int N = 1e6;
PII a[N];
bool tt[N];

bool cmp(PII a, PII b)
{
    return a.second > b.second;
}

int main( )
{
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
    {
        int temp = a[i].first;
        while (temp > 0 && tt[temp])
        {
            temp--;
        }
        if (temp <= 0) m -= a[i].second;
        else tt[temp] = true;
    }

    cout << m << endl;
    return 0;
}