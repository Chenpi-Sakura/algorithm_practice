/*字典树，作用与哈希类似*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
char s[N];
// ch[p][j] 儿子数组 储存从节点p沿着j这条边走到的子节点 
// cnt[p] 计数数组 储存以节点p结尾的单词插入次数
// idx 用于编号的变量
int ch[N][26], cnt[N], idx;

void insert()
{// 插入函数
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
    }
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