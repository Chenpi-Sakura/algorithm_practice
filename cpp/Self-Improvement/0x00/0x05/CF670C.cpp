/*
有m部正在上映的电影，每部电影的语音和字幕都采用不同的语言，用一个 int 范围内的整数来表示语言。
有n个人相约一起去看其中一部电影，每个人只会一种语言，如果一个人能听懂电影的语音，他会很高兴；如果能看懂字幕，他会比较高兴；如果语音和字幕都不懂，他会不开心。
请你选择一部电影让这n个人一起看，使很高兴的人最多。若答案不唯一，则在此前提下再让比较高兴的人最多，
n,m ≤ 2*10^5。

此处涉及到离散化, 我将结合代码，题目及注释还有带佬的题解来简单介绍
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 200500;

int tot = 0, k = 0;
int n, m;
int a[N], b[N], c[N], lang[N * 3], uni[N * 3], ans[N * 3]; 
// lang 储存所有的语言 uni 储存独特的语言（稠密下标） ans 储存有多少人说这种语言（稠密下标）

int find(int x)
{
    int l = 0, r = k;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (uni[mid] == x) return mid;
        else if (uni[mid] < x) l = mid + 1;
        else if (uni[mid] > x) r = mid - 1;
    }
    return l;
}// 离散稠密化
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], lang[++tot] = a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i], lang[++tot] = b[i];
    for (int i = 1; i <= m; i++) cin >> c[i], lang[++tot] = c[i];
    
    sort(lang + 1, lang + tot + 1); // 整理lang, 方便后续的去重, uni的选取
    
    for (int i = 1; i <= tot; i++)
    {
        if (i == 1 || (lang[i - 1] != lang[i])) uni[++k] = lang[i];
    }// 稠密化
    
    // 统计说各种语言的人数，需要实现稠密化转化下标
    for (int i = 1; i <= tot; i++) ans[find(a[i])]++;
    
    // 寻找答案
    int ans0 = 0, ans1 = 0, ans2 = 0; // ans0 为最终结果 ans1,ans2 为中间结果
    for (int i = 1; i <= m; i++) // 线性查找不同电影中喜欢和比较的人数
    {
        int ansx = ans[find(b[i])], ansy = ans[find(c[i])];
        if (ansx > ans1 || (ansx == ans1 && ansy > ans2)) ans0 = i, ans1 = ansx, ans2 = ansy;
    }
    
    if (ans0 == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << ans0 << endl;
    }
    
    return 0;
}
