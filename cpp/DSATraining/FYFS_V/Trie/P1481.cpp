/*
题目描述
花花：……咦好冷我们现在要解决的是魔族的密码问题（自我陶醉：搞不好魔族里面还会有人用密码给我和菜虫写情书咧，哦活活，当然是给我的比较多拉*^_^*）。

魔族现在使用一种新型的密码系统。每一个密码都是一个给定的仅包含小写字母的英文单词表，每个单词至少包含 1 个字母，至多 75 个字母。如果在一个由一个词或多个词组成的表中，除了最后一个以外，每个单词都被其后的一个单词所包含，即前一个单词是后一个单词的前缀，则称词表为一个词链。例如下面单词组成了一个词链：
i；
int；
integer。
但下面的单词不组成词链：
integer；
intern。
现在你要做的就是在一个给定的单词表中取出一些词，组成最长的词链，就是包含单词数最多的词链。将它的单词数统计出来，就得到密码了。

风之子：密码就是最长词链所包括的单词数阿……

输入格式
这些文件的格式是，第一行为单词表中的单词数 N（1≤N≤2000），下面每一行有一个单词，按字典顺序排列，中间也没有重复的单词。

输出格式
输出共一行，一个整数，表示密码。
*/
#include <algorithm>
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e4;
char s[100];
int ch[N][26], idx;
bool wordEnd[N];

void insert()
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
    } 
    wordEnd[p] = true;
}

int dfs(int index, int depth)
{
    int maxDepth = depth;
    for (int i = 0; i < 26; i++)
    {
        if (ch[index][i] != 0 && wordEnd[index])
        {
            maxDepth = max(dfs(ch[index][i], depth + 1), maxDepth);
        }
        else if (ch[index][i] != 0 && !wordEnd[index])
        {
            maxDepth = max(dfs(ch[index][i], depth), maxDepth);
        }
        else if (ch[index][i] == 0 && wordEnd[index])
        {
            maxDepth = max(maxDepth, depth + 1);
        }
    }
    return  maxDepth;
}

int main( )
{
    int n; cin >> n;
    while (n--)
    {
        cin >> s;
        insert();
    }
    int ans = dfs(0, 0);
    cout << ans << endl;

    return 0;
}
