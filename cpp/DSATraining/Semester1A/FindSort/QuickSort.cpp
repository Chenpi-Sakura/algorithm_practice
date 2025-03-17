#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;                                      // 递归基线条件
    int i = l - 1, j = r + 1, x = arr[(i + j) >> 1]; // 选择基准元素
    while (i < j)
    {
        do
            i++;
        while (arr[i] < x); // 需要从 l 开始，则 i 应该初始化为i - 1
        do
            j--;
        while (arr[i] > x); // 需要从 r 开始，则 j 应该初始化为i - 1
        if (i < j)
            swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j);     // 递归排序左部分
    quick_sort(arr, j + 1, r); // 递归排序右部分
}

// void sort(first, last, comp)
// 第一个参数：指向要排序的范围的开始位置的地址
// 第二个参数：指向要排序的范围的结束位置的地址这个位置的元素不包括在排序中。注：结束位置的元素不包括在排序中 : [ )
// 第三个参数（可选):自定义比较函数或 lambda 表达式，用于定义元素之间的排序关系。注：不传第三个参数默认升序排序
// 降序参数为greater<int>

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
bool cmp(PII x, PII y)
{
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
int main()
{
    int n;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    return 0;
}