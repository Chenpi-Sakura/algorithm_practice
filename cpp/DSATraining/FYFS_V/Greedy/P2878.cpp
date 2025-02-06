/*
[USACO07JAN] Protecting the Flowers S
题目描述
Farmer John went to cut some wood and left N (2 ≤ N ≤ 100,000) cows eating the grass, as usual. When he returned, he found to his horror that the cluster of cows was in his garden eating his beautiful flowers. Wanting to minimize the subsequent damage, FJ decided to take immediate action and transport each cow back to its own barn.

Each cow i is at a location that is Ti minutes (1 ≤ Ti ≤ 2,000,000) away from its own barn. Furthermore, while waiting for transport, she destroys Di (1 ≤ Di ≤ 100) flowers per minute. No matter how hard he tries, FJ can only transport one cow at a time back to her barn. Moving cow i to its barn requires 2 × Ti minutes (Ti to get there and Ti to return). FJ starts at the flower patch, transports the cow to its barn, and then walks back to the flowers, taking no extra time to get to the next cow that needs transport.

Write a program to determine the order in which FJ should pick up the cows so that the total number of flowers destroyed is minimized.

有 n 头奶牛跑到 FJ 的花园里去吃花儿了，它们分别在距离牛圈 Ti （这里指 FJ 到那里需要 Ti 分钟) 处吃花，每分钟会吃掉 Di 朵花，FJ 现在要将它们给弄回牛圈，但是他每次只能弄一头回去，来回用时总共为 2×Ti 分钟，在这段时间内，其它的奶牛会继续吃 FJ 的花，速度保持不变，当然正在被赶回牛圈的奶牛不能继续吃了。现在求在最好的方案下奶牛吃掉花的最小朵数。

输入格式
Line 1: A single integer N

Lines 2..N+1: Each line contains two space-separated integers, Ti and Di, that describe a single cow's characteristics

输出格式
Line 1: A single integer that is the minimum number of destroyed flowers
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
typedef pair<int, int> PII; // T & D
PII cow[N];

bool cmp(PII a, PII b)
{
    double s1 = (double)a.second / a.first;
    double s2 = (double)b.second / b.first;
    if (s1 == s2) return a.second > b.second;
    return s1 > s2;
}

int main( )
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;
    sort(cow, cow + n, cmp);

    long long ans = 0, tim = 0;
    for (int i = 0; i < n; i++)
    {
        ans += cow[i].second * tim * 2;
        tim += cow[i].first;
    }

    cout << ans << endl;
    return 0;
}