/*
题目描述
英语老师留了 N 篇阅读理解作业，但是每篇英文短文都有很多生词需要查字典，为了节约时间，现在要做个统计，算一算某些生词都在哪几篇短文中出现过。

输入格式
第一行为整数 N ，表示短文篇数，其中每篇短文只含空格和小写字母。
按下来的 N 行，每行描述一篇短文。每行的开头是一个整数 L ，表示这篇短文由 L 个单词组成。接下来是 L 个单词，单词之间用一个空格分隔。
然后为一个整数 M ，表示要做几次询问。后面有 M 行，每行表示一个要统计的生词。

输出格式
对于每个生词输出一行，统计其在哪几篇短文中出现过，并按从小到大输出短文的序号，序号不应有重复，序号之间用一个空格隔开（注意第一个序号的前面和最后一个序号的后面不应有空格）。如果该单词一直没出现过，则输出一个空行。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 5e6 + 10;
char s[30];
int ch[N][26], idx;
vector<int> cnt[N];

void insert(int x)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
    }
    if (cnt[p].empty() || cnt[p].back() != x) cnt[p].push_back(x);
}

int query()
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (ch[p][j] == 0) return -1;
        p = ch[p][j];
    }
    return p;
}

int main( )
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l; cin >> l;
        while (l--)
        {
            cin >> s;
            insert(i);
        }
    }

    int m; cin >> m;
    while (m--)
    {
        cin >> s;
        int index = query();
        if (index >= 0)
        {
            int len = cnt[index].size();
            for (int i = 0; i < len - 1; i++)
            {
                cout << cnt[index][i] << ' ';
            }
            if (len != 0) cout << cnt[index][len - 1];
        }
        cout << endl;
    }

    return 0;
}