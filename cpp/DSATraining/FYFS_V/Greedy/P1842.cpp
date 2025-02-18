/*
[USACO05NOV] 奶牛玩杂技
题目背景
Farmer John 养了 N 头牛，她们已经按 1∼N 依次编上了号。FJ 所不知道的是，他的所有牛都梦想着从农场逃走，去参加马戏团的演出。可奶牛们很快发现她们那笨拙的蹄子根本无法在钢丝或晃动的的秋千上站稳（她们还尝试过把自己装在大炮里发射出去，但可想而知，结果是悲惨的） 。最终，她们决定练习一种最简单的杂技：把所有牛都摞在一起， 比如说， 第一头牛站在第二头的身上， 同时第二头牛又站在第三头牛的身上...最底下的是第 N 头牛。

题目描述
每头牛都有自己的体重以及力量，编号为 i 的奶牛的体重为 Wi，力量为 Si。
当某头牛身上站着另一些牛时它就会在一定程度上被压扁，我们不妨把它被压扁的程度叫做它的压扁指数。对于任意的牛，她的压扁指数等于摞在她上面的所有奶牛的总重（当然不包括她自己）减去它的力量。奶牛们按照一定的顺序摞在一起后， 她们的总压扁指数就是被压得最扁的那头奶牛的压扁指数。

你的任务就是帮助奶牛们找出一个摞在一起的顺序，使得总压扁指数最小。

输入格式
第一行一个整数 N。
接下来 N 行，每行两个整数 Wi 和 Si。

输出格式
一行一个整数表示最小总压扁指数。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
typedef pair<int, int> PII; // W & S
PII cow[N];

bool cmp(PII a, PII b)
{
    long long s1 = a.second + a.first;
    long long s2 = b.second + b.first;
    
    return s1 < s2;
}

int main( )
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> cow[i].first >> cow[i].second;
    sort(cow, cow + n, cmp);

    int sum = 0, ans = -N;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, sum - cow[i].second);
        sum += cow[i].first;
    }

    cout << ans << endl;
    return 0;
}