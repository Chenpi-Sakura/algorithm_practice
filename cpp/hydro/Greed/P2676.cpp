/*
[USACO07DEC] Bookshelf B
题目描述
Farmer John最近为奶牛们的图书馆添置了一个巨大的书架，尽管它是如此的大，但它还是几乎瞬间就被各种各样的书塞满了。现在，只有书架的顶上还留有一点空间。

所有 N(1≤N≤20,000) 头奶牛都有一个确定的身高 (1≤Hi ≤10,000)。设所有奶牛身高的和为S。书架的高度为B，并且保证 1≤B≤S<2,000,000,007。
为了够到比最高的那头奶牛还要高的书架顶，奶牛们不得不像演杂技一般，一头站在另一头的背上，叠成一座“奶牛塔”。当然，这个塔的高度，就是塔中所有奶牛的身高之和。为了往书架顶上放东西，所有奶牛的身高和必须不小于书架的高度。
显然，塔中的奶牛数目越多，整座塔就越不稳定，于是奶牛们希望在能够到书架顶的前提下，让塔中奶牛的数目尽量少。 现在，奶牛们找到了你，希望你帮她们计算这个最小的数目。

输入格式
第 1 行: 2 个用空格隔开的整数：N 和 B；
第 2…N+1 行: 第 i+1 行是 1 个整数：Hi。

输出格式
第 1 行: 输出 1 个整数，即最少要多少头奶牛叠成塔，才能够到书架顶部

很简单的题嘛哼哼哼（开始）
我还想复杂了（晕）以为要刚刚好
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> b;
LL h, num, n, th;

int main()
{
    cin >> n >> h;
    b.resize(n);
    for (LL i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(b.begin(), b.end(), greater<LL>());

    for (int i = 0; th < h; i++)
    {
        th += b[i];
        num++;
    }
    cout << num;
    return 0;
}