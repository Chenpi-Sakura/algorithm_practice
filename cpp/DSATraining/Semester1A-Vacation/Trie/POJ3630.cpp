/*
电话列表

问题描述
给定一个电话号码列表，请判断该列表是否是“一致的”。“一致性”的定义是指：列表中**没有任何一个号码是另一个号码的前缀**。
例如，假设电话簿列出了以下号码：

紧急电话 911
爱丽丝 97 625 999
鲍勃 91 12 54 26

在这种情况下，就无法拨打鲍勃的电话，因为当你拨打鲍勃电话号码的前三位数字时，中心交换机就会将你的呼叫转接到紧急线路。 因此，这个列表就不是一致的。

输入
输入的第一行给出一个整数 t，1 <= t <= 40，代表测试用例的数量。
每个测试用例开始于一行，包含一个整数 n，1 <= n <= 10000，代表电话号码的数量。
接下来是 n 行，每行包含一个唯一的电话号码。 电话号码是一个最多包含十位数字的序列。

输出
对于每个测试用例，如果电话号码列表是一致的，输出 “YES”，否则输出 “NO”。
例子

输入:
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

输出:
NO
YES
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 5;
char s[20];
int ch[N][10], idx;
bool numEnd[N];

bool insert()
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - '0';
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        //else if (i == strlen(s) - 1) flag = true; // 如果搜完了，没有插入任何的新节点，则说明该串出现过
        p = ch[p][j];
        if (numEnd[p]) return true; // 情况 1: 在到达当前号码末尾之前，遇到已标记结尾的节点，说明当前号码是已有号码的前缀
    }
    numEnd[p] = true;

    for (int i = 0; i < 10; i++)
    {//情况 2: 插入完成后，当前节点 p 还有子节点，说明已有号码是当前号码的前缀
        if (ch[p][i]) return true;;
    }
    return false;
}

int main( )
{
    int t; cin >> t;
    while (t--)
    {
        memset(ch, 0, sizeof(ch));
        memset(numEnd, false, sizeof(numEnd));
        idx = 0;

        int n; cin >> n;
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (insert ()) check = true;
        }

        if (check) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
