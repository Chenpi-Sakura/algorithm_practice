/*
题目描述
这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间，有 N 块岩石（不含起点和终点的岩石）。在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。
为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多从起点和终点之间移走M块岩石（不能移走起点和终点的岩石）

输入格式
第一行包含三个整数L，N，M，分别表示起点到终点的距离，起点和终点之间的岩石数，以及组委会至多移走的岩石数。保证 L ≥ 1且 N ≥ M ≥ 0。
接下来N行，每行一个整数，第 i 行的整数 Di (0 < Di < L)，表示第i块岩石与起点的距离。这些岩石按与起点距离从小到大的顺序给出，且不会有两个岩石出现在同一个位置。

输出格式
一个整数，即最短跳跃距离的最大值。

Reflection
算出 n + 1 的石头间距，差分
除去之间最短的 m 个石头：
两个排序
一个原序排列，便于合并距离
一个升序排列，便于找到最短

非最佳思路的说，其实可以用二分答案来搜索
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int l, n, m;
int a[N];

bool check(int mid)
{
    int t = 0;       // 用于记忆跳过了几个石头
    int current = 0; // 用于记录从第几个石头跳
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] - a[current] < mid)
            t++; // 如果两石头之间的距离小于mid则搬走石头，计数
        else
            current = i; // 如果两石头之间的距离大于mid则跳到下一个石头，不搬走石头，不计数
    }
    return t <= m;
}

int main()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = l;                // 将终点加入数组
    int left = 1, right = l + 1; // right 取不到，所以 right 初始化为 l + 1

    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (check(mid))
            left = mid + 1;
        else
            right = mid;
    }
    cout << left - 1;

    return 0;
}

//-------------错误思路-------------//
/*
#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, mid = arr[(i + j) >> 1];
    while (i < j)
    {
        do
            i++;
        while (mid > arr[i]);
        do
            j--;
        while (mid < arr[j]);
        if (j > i)
            swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}

int l, m, n;
vector<int> a, d;
int main()
{
    cin >> l >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    d[0] = 0; // 初始化d[0]的位置
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[i] - d[i - 1]; // 用差分得出两块石头的距离
        if (i == n)
        {
            d[i + 1] = l - a[i]; // 最后一个间距特殊处理
        }
    }
    while(m--)
    {
        vector<int> dc = d;
        quick_sort(dc, 1, d.size()); // 排序来找到最小的数字
        int min = dc[1];
        for (int i = 1; i <= n + 1; i++)
        {
            if (min == d[i])
            {
                if ((min + d[i - 1]) <= (min + d[i + 1]))
                {
                    d[i - 1] += min;
                    d.erase(d.begin() + i);
                    break;
                }
                else
                {
                    d[i + 1] += min;
                    d.erase(d.begin() + i);
                    break;
                }
            }
        }
        n--;
    }
    quick_sort(d, 1, d.size() - 1);
    cout << d[1];
}
*/
//-------------错误思路-------------//
