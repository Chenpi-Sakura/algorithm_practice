/*
【模板】字典树 1
题目描述
给出 n 个仅由小写字母组成的字符串，请你求出这些字符串中一共出现了几种不同的字符串。

输入格式
第一行一个整数 n。
接下来 n 行每行一个字符串。

输出格式
一行一个整数表示一共出现过的字符串数量。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
char s[N];
// ch[p][j] 儿子数组 储存从节点p沿着j这条边走到的子节点 
// cnt[p] 计数数组 储存以节点p结尾的单词插入次数
// idx 用于编号的变量
int ch[N][26], cnt[N], idx;
int ans;

void insert()
{// 插入函数
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
    }
    if (cnt[p] == 0) ans++;
    cnt[p]++;
}

int query()
{// 查询函数
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (ch[p][j] == 0) return 0;
        p = ch[p][j];
    }
    return cnt[p];
}

int main( )
{
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert();
    }
    cout << ans << endl;
    
    return 0;
}