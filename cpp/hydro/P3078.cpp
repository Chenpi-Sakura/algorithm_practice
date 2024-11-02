/*
#P3078. [USACO13MAR] Poker Hands S

题目描述
Bessie and her friends are playing a unique version of poker involving a deck with N (1 <= N <= 100,000) different ranks, conveniently numbered 1..N (a normal deck has N = 13). In this game, there is only one type of hand the cows can play: one may choose a card labeled i and a card labeled j and play one card of every value from i to j. This type of hand is called a "straight".

Bessie's hand currently holds a_i cards of rank i (0 <= a_i <= 100000). Help her find the minimum number of hands she must play to get rid of all her cards.

贝茜和她的朋友们正在玩一种独特的扑克游戏，使用了一副有 N 张不同牌值的牌（1 <= N <= 100000），并且牌的数值依次编号为 1 到 N（普通的扑克牌有 N = 13）。在这个游戏中，玩家只能打出一种类型的牌组：她们可以选择一个标号为 i 的牌和一个标号为 j 的牌，然后从 i 到 j 之间的所有牌各打一张。这种类型的牌组称为“顺子”。

贝茜手上当前持有 ai 张牌，其中牌的牌值为 i（0 <= ai <= 100000）。请帮助她找到打出所有手牌所需的最小牌组数量。

输入格式
* Line 1: The integer N.

* Lines 2..1+N: Line i+1 contains the value of a_i.

输出格式
* Line 1: The minimum number of straights Bessie must play to get rid of all her cards.

5
2 4  1 2 3
2 2 -3 1 1
0 0  0 0 0
Reflection:
这个题目运用一维差分进行标记
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n + 1] = {0}, s[n + 1] = {0};
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i] - a[i - 1];
    }
    long long sum1 = 0;
    for (long long i = 1; i <= n; i++)
    {
        if (s[i] > 0)
            sum1 += s[i];
    }

    cout << s[i];
    return 0;
}