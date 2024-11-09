/*
解题的时候往往会考虑枚举答案然后检验枚举的值是否正确。若满足单调性，则满足使用二分法的条件。把这里的枚举换成二分，就变成了「二分答案」。
也就是之前提到的check()函数,利用check()函数去检查mid是否具备某种性质。

P8647 [蓝桥杯 2017 省 AB] 分巧克力

题目描述
儿童节那天有 K 位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
小明一共有 N 块巧克力，其中第 i 块是Hi×Wi的方格组成的长方形。
为了公平起见，小明需要从这 N 块巧克力中切出 K 块巧克力分给小朋友们。切出的巧克力需要满足：
1.形状是正方形，边长是整数。
2.大小相同。
例如一块6×5的巧克力可以切出6块2×2的巧克力或者2块3×3的巧克力。
当然小朋友们都希望得到的巧克力尽可能大，你能帮小明计算出最大的边长是多少么？

输入格式
第一行包含两个整数N和K。(1≤N,K≤10^5)。
以下N行每行包含两个整数Hi和Wi。(1≤Hi,Wi≤10^5)。
输入保证每位小朋友至少能获得一块1×1的巧克力。

输出格式
输出切出的正方形巧克力最大可能的边长。
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, k;
vector<PII> arr(N); // 存巧克力的长和宽

bool check(int mid)
{
    int cnt = 0;
    for (auto [x, y] : arr)
    {
        cnt += (x / mid) * (y / mid);
    }
    if (cnt >= k)
        return 1; // 正方形边长小，导致数量过多，可以继续增大边长
    else
        return 0;// 正方形边长大，导致数量过少，需要减小边长
} // 检查边长为mid的巧克力是否能满足条件

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;
        arr[i] = {h, w};
    }

    int l = 1, r = N;

    while (r > l)
    {
        int mid = (l + r + 1) >> 1; // 向上取整,左边界会向上一直更新到r的位置，即向右看齐
        if (check(mid))
            l = mid; 
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}