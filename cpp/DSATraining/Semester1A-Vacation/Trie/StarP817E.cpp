/*
题意翻译
有一个初始为空的可重集 S。现在有 Q 次操作，每次操作有 3 种类型，分别是：
1, pi，把 pi加入 S。
2, pi，将 pi 从 S 中删除，保证在删除前 pi 已经在 S 中。
3, pi,li，询问 S 中有多少个数按位异或上 pi 的结果小于 li。

【输入格式】
第一行一个整数 Q，后面 Q 行每行如题所述
保证删除操作一定合法
*/

#include<bits/stdc++.h> 
using namespace std;
 
const int N = 1e5 + 10;
int ch[N * 31][2], cnt[N * 31], idx;
 
void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
    }
}
 
void del(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        p = ch[p][j];
        cnt[p]--;
    }
}
 
int query(int p, int l)
{
    int k = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {   
        int x = (p >> i) & 1, y = (l >> i) & 1;
        if (y == 1)
        {
            res += cnt[ch[k][x]];
            if (ch[k][x ^ 1] == 0) break; // 一定要判断 ch[k][x ^ 1] 是否存在，如果ch[k][x ^ 1] 不存在就更新p的值，p会更新为0，导致循环又回到0，res重复计算
            k = ch[k][x ^ 1];
        }
        else
        {
            if (ch[k][x] == 0) break;
            k = ch[k][x];
        }
    }
    return res;
}
 
int main( )
{
    int q; cin >> q;
    while (q--)
    {
        int a; cin >> a;
        if (a == 1) // add
        {
            int p; cin >> p;
            insert(p);
        }
        else if (a == 2) // delete
        {
            int p; cin >> p;
            del(p);
        }
        else if (a == 3) // search
        {
            int p, l; cin >> p >> l;
            int ans = query(p, l);
            cout << ans << endl;
        }
    }
    return 0;
}