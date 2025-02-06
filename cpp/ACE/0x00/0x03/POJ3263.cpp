/*
题目描述
FarmerJohn 有 n 头牛，它们按顺序排成一列。FarmerJohn 只知道其中最高的奶牛的序号及它的高度，其他奶牛的高度都是未知的。现在 FarmerJohn 手上有 R 条信息，每条信息上有两头奶牛的序号（a 和 b），其中 b 奶牛的高度一定大于等于 a 奶牛的高度，且 a 和 b 之间的所有奶牛的高度都比 a 小。现在 FarmerJohn 想让你根据这些信息求出每一头奶牛的可能的最大的高度。（数据保证有解）

输入格式
第一行：四个以空格分隔的整数：n, i, h, R（n 和 R 意义见题面；i 和 h 表示第 i 头牛的高度为 h，它是最高的奶牛）
接下来 R 行：两个不同的整数 a 和 b（1 ≤ a, b ≤ n）

输出格式
一共 n 行，表示每头奶牛的最大可能高度。

数据范围
1 ≤ n ≤ 10000
1 ≤ h ≤ 1000000
0 ≤ R ≤ 10000
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int diff[N];
int height[N];
int n, t, h, r;
map<pair<int, int>, bool> existed;

int main()
{
    cin >> n >> t >> h >> r;
    for (int i = 0; i < r; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (existed[make_pair(a, b)]) continue;
        diff[a + 1]--;
        diff[b]++;
        existed[make_pair(a, b)] = true;
    }
    height[0] = h;
    for (int i = 1; i <= n; i++)
    {
        height[i] = diff[i] + height[i - 1];
        cout << height[i] << endl;
    }
    return 0;
}